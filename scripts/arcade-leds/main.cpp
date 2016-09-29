#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <math.h>

using namespace std;

static unsigned int PIXELS_W = 64;
static unsigned int PIXELS_H = 8;
static unsigned int PIXELS = PIXELS_H * PIXELS_W;
static unsigned int MAX_VALUE = 16;

bool run = true;

int main(int, char**)
{
    XColor c;
	XImage *image;
	Display *d = XOpenDisplay((char *) NULL);
	Window root = RootWindow(d, DefaultScreen(d));

	image = XGetImage (d, RootWindow (d, DefaultScreen (d)), 0, 0, 1, 1, AllPlanes, XYPixmap);
	//XImage* img = XGetImage (d, root, 0, 0, 1, 1, AllPlanes, ZPixmap);
	//Screen* screen = DefaultScreenOfDisplay(d);

	int x=0;  // Pixel x 
	int y=0;  // Pixel y

    unsigned int side = floor(min(1080 / PIXELS_H, 1920 / PIXELS_W));
	unsigned int square = side * side;
	unsigned int width = side * PIXELS_W;
	unsigned int height = side * PIXELS_H;

	cout << side << " side for " << PIXELS_W << " pixels" << endl;

	//Window win = RootWindowOfScreen (screen);
	//image = XGetImage (d, win, 0, 0, width, height, AllPlanes, XYPixmap);



	//image = XGetImage (d, RootWindow (d, DefaultScreen (d)), x, y, 1, 1, AllPlanes, XYPixmap);
	//c.pixel = XGetPixel (image, 0, 0);
	//XFree (image);
	//XQueryColor (d, DefaultColormap(d, DefaultScreen (d)), &c);
	//cout << c.red/256 << " " << c.green/256 << " " << c.blue/256 << "\n";


    return 0;
}
