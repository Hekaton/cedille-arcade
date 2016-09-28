#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

#include <signal.h>
#include <getopt.h>
#include "ws2812-rpi.h"
#include "ws2812-rpi-defines.h"
#include <time.h>

using namespace std;

static unsigned int PIXELS_W = 64;
static unsigned int PIXELS_H = 8;
static unsigned int PIXELS = PIXELS_H * PIXELS_W;
static unsigned int MAX_VALUE = 16;

bool run = true;

int main(int, char**){

	NeoPixel *n = new NeoPixel(8);
	n->begin();
	n->show();

	while(run){
		//n->clear();
		for(int i = 0; i<8; i++){
			n->setPixelColor(i, (char)160, (char)0, (char)0);
		}
		n->show();
	}

	delete n;
	return 0;

}

