/***************************************************************************************************
Filename:			Display.cpp
Version:			1.0
Purpose:			Holds information about the pixels of each display and how long their duration lasts
**************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <time.h>

using namespace std;

#include "Display.h"

#pragma warning (disable : 4996)

Display::Display(int x, int y, int duration, char* name) {
	Display::name = new char[strlen(name) + 1];
	Display::pixel_x = x;
	Display::pixel_y = y;
	Display::duration = duration;
	strcpy(Display::name, name);
}

Display::Display(const Display& display) {
	Display::name = new char[strlen(display.name)+1];
	pixel_x = display.pixel_x;
	pixel_y = display.pixel_y;
	duration = display.duration;
	strcpy(name, display.name);
}

Display::~Display() {
	delete[] name;
}

/***************************************************************************************************
Function name:		operator<<
Purpose:			Returns the information associated with the Display to the ostream
In parameters:		ostream, display
Out parameters:		ostream
Version:			1.0
***************************************************************************************************/
ostream& operator<<(ostream& os, Display& d) {
	int count = 0;
	time_t newSec, oldSec, startSec;

	startSec = oldSec = time(nullptr);

	//adds the information of the display to the ostream
	os << "name = " << d.name << "; pixel_x = " << d.pixel_x << "; pixel_y = " << d.pixel_y << "; duration = " << d.duration << endl;
	os << "\tCounting the seconds for this Display: ";

	while (count < d.duration) {
		newSec = time(nullptr);
		if (newSec > oldSec) {
			os << newSec - startSec << ", ";
			oldSec = newSec;
			count++;
		}
	}

	//newline for spacing
	os << endl;
	
	//returns the ostream
	return os;
}