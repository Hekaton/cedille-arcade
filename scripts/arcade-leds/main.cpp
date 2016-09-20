#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <math.h>
#include "ws2812-rpi.h"

using namespace std;

static unsigned int PIXELS_W = 64;
static unsigned int PIXELS_H = 8;
static unsigned int PIXELS = PIXELS_H * PIXELS_W;
static unsigned int MAX_VALUE = 16;

bool run = true;

int main(int, char**){

    NeoPixel *n = new NeoPixel(PIXELS);

    Display *d = XOpenDisplay(0);
    Screen* screen = DefaultScreenOfDisplay(d);

    unsigned int side = floor(min(screen->height / PIXELS_H, screen->width / PIXELS_W));
    unsigned int square = side * side;
    unsigned int width = side * PIXELS_W;
    unsigned int height = side * PIXELS_H;

    double process = 1/square/65536*MAX_VALUE;

    while(run){
        // get screen pixels
        XImage *image = NULL;
        Window win = RootWindowOfScreen ( screen);
        image = XGetImage (d, win, 0, 0, width, height, AllPlanes, XYPixmap);

        for(int ix = 0; ix < PIXELS_W; ix++){
            for(int iy = 0; iy < PIXELS_H; iy++) {

                double red, green, blue;
                for(int i = 0; i<square; i++){
                    XColor c;
                    c.pixel = XGetPixel(image, ix * side + (i%side), iy * side + floor(i/side));
                    XQueryColor (d, DefaultColormapOfScreen(screen), &c);

                    red += c.red * process;
                    green += c.green * process;
                    blue += c.blue * process;
                }

                // TODO send neopixel matrix data;
                int pixel = ix*PIXELS_H + iy; // LED matrix coords are {y, x} instead of {x, y}
                n->setPixelColor(pixel, (char)floor(red), (char)floor(green), (char)floor(blue));
            }
        }
        n->show();
        XFree (image);
    }

    delete n;
    return 0;

}
