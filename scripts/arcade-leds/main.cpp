#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "ws2812-rpi.h"

using namespace std;

static unsigned int PIXELS = 8*32;
static unsigned int MAX_VALUE = 16;

bool run = true;

int main(int, char**)
{
    XColor c;
    Display *d = XOpenDisplay(0);

	//TODO: get screen width and height
    int x=720;  // Pixel x
    int y=64;  // Pixel y

    XImage *image = XGetImage (d, RootWindow (d, DefaultScreen (d)), x, y, 1, 1, AllPlanes, XYPixmap);
	c.pixel = XGetPixel (image, 0, 0);

	XFree (image);

	XQueryColor (d, DefaultColormap(d, DefaultScreen (d)), &c);
    cout << c.red/256 << " " << c.green/256 << " " << c.blue/256 << "\n";

	NeoPixel *n = new NeoPixel(PIXELS);

	while (run) n->effectsDemo();

	delete n;
	delete image;
    return 0;
}