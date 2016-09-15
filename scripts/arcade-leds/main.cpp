#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "ws2812-rpi.h"

using namespace std;

static unsigned int PIXELS_W = 64;
static unsigned int PIXELS_H = 8;
static unsigned int PIXELS = PIXELS_H * PIXELS_W;
static unsigned int MAX_VALUE = 16;

bool run = true;

int main(int, char**)
{

    NeoPixel *n = new NeoPixel(PIXELS);

    Display *d = XOpenDisplay(0);
    Screen *screen = DefaultScreen(d);

    unsigned int side = Math.floor(Math.min(screen->height / PIXELS_H, screen->width / PIXELS_W));
    unsigned int square = side * side;
    unsigned int width = side * PIXELS_W;
    unsigned int height = side * PIXELS_H;

    double process = 1/square/65536*MAX_VALUE;

    while(run){
        // get screen pixels
        XImage *image = XGetImage (d, RootWindow (d, screen), 0, 0, width, height, AllPlanes, XYPixmap);

        for(int ix = 0; ix < PIXELS_W; ix++){
            for(int iy = 0; iy < PIXELS_H; iy++) {

                double red, green, blue;
                for(int i = 0; i<square; i++){
                    Xcolor c;
                    c.pixel = XGetPixel(image, ix * side + (i%side), iy * side + Math.floor(i/side));
                    XQueryColor (d, DefaultColormap(d, screen), &c);

                    // blend color channels
                    // also X11 keeps values as 0-65535, dividing by 256 sets it back to 0-255
                    red += c.red * process;
                    green += c.green * process;
                    blue += c.blue * process;
                }

                // TODO send neopixel matrix data;
                int pixel = ix*PIXELS_H + iy; // LED matrix coords are {y, x} instead of {x, y}
                n->setPixelColor(pixel, (char)Math.floor(red), (char)Math.floor(green), (char)Math.floor(blue));
            }
        }
        n->show();
        XFree (image);
        cout << c.red/256 << " " << c.green/256 << " " << c.blue/256 << "\n";
    }

    delete n;
    return 0;
}