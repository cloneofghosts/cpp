/***************************************************************************************************
Filename:			Frame.cpp
Version:			1.0
Purpose:			The Frame of the Animation which holds multiple displays. The Frames can be combined
					together to create a concatinated version of the two Frames.
**************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "Frame.h"

/***************************************************************************************************
Function name:		operator+
Purpose:			Creates a new Frame with the information of the two frames added together
In parameters:		frame
Out parameters:		frame
Version:			1.0
***************************************************************************************************/
Frame Frame::operator+(Frame& f) {
	string name;
	vector<Display> d;
	vector<Display>::iterator it;

	//adds the filenames of the two Frames together
	name = fileName + "_" + f.fileName;

	//sets the vector to be the one from the first frame
	d = displays;

	//loops through the vector of the other frame and adding it to the end of the vector
	for (it = f.displays.begin(); it != f.displays.end(); ++it) {
		d.push_back(*it);
	}

	//new frame that now holds the information of the two Frames added together
	Frame newFrame(name, d);

	//retuns the frame so that it can get added to the Animation
	return newFrame;
}

/***************************************************************************************************
Function name:		ostream<<
Purpose:			Returns the name of the Frame and the information about the Display vectors to ostream
In parameters:		ostream, frame
Out parameters:		ostream
Version:			1.0
***************************************************************************************************/
std::ostream& operator<<(std::ostream& os, Frame& f) {
	//adds the fileName of the Frame to the ostream
	os << "\tfileName = " << f.fileName << endl;

	//loops through the vector of displays and adds the information to the ostream
	for (int i = 0; i < (signed int)f.displays.size(); i++) {
		os << "\tDisplay #" << i << ": \t" << f.displays[i];
	}

	//returns the ostream
	return os;
}