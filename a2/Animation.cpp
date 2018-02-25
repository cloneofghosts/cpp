/***************************************************************************************************
Filename:			Animation.cpp
Version:			1.0
Purpose:			Adds/Deletes frames in the Animation. Also prints out each Frame that is contained
					in the list of Frames.
**************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "Animation.h"

/***************************************************************************************************
Function name:		InsertFrames
Purpose:			Inserts a frame into the animation and allows the user to add multiple Displays
					to each frame in the Animation
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::InsertFrame() {
	//local variable declarations
	vector<Display> d;
	string fileName;
	char displayName[255];
	int numDisplays, pixel_x, pixel_y, duration, count;
	forward_list<Frame>::iterator it;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Enter the Frame filename: ";
	cin >> fileName;
	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Enter the number of Displays: ";
	cin >> numDisplays;

	//loops for the number of displays specifed and gets the information of the display
	for (int i = 0; i < numDisplays; i++) {
		cout << "Please enter pixel x for Display #" << i << " pixel_x:";
		cin >> pixel_x;
		cout << "Please enter pixel y for Display #" << i << " pixel_y:";
		cin >> pixel_y;
		cout << "Please enter the duration sec for this Display: ";
		cin >> duration;
		cout << "Please enter the name of this display: ";
		cin >> displayName;

		//create a new display with the information provided
		Display dis (Display(pixel_x, pixel_y, duration, displayName));

		//add the display to the end of the vector
		d.push_back(dis);
	}

	//create a frame with the fileName and the vector of displays
	Frame f (fileName, d);

	count = 0;
	//gets the number of frames in the list
	for (it = frames.begin(); it != frames.end(); ++it) {
		count++;
	}

	//sets the iterator to be at the front of the list
	it = frames.begin();

	//if there are no frames then add it to the front
	if (frames.empty()) {
		cout << "This is the first frame in the list" << endl << endl;
		frames.push_front(f);
	}
	//if there is one frame add it after the first one
	else if (count == 1) {
		cout << endl;

		//inserts the frame after the first frame
		frames.insert_after(it, f);
	}
	else {
		//asks the user where they would like to add the frame after
		cout << "There are " << count << " Frame(s) in the list" << endl;
		cout << "Please specify the position, between 0 and " << count-1 << " to insert after: ";
		cin >> count;
		cout << endl;

		//advances the iterator the specified number
		advance(it, count);

		//inserts the frame after the iterators position
		frames.insert_after(it, f);
	}

}

/***************************************************************************************************
Function name:		DeleteFrames
Purpose:			Deletes all the current frames in the forward_list
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::DeleteFrames() {
	frames.clear();
}

/***************************************************************************************************
Function name:		operator[]
Purpose:			Overloaded operator which gets the frame at the index specified by i
In parameters:		index
Out parameters:		Frame
Version:			1.0
***************************************************************************************************/
Frame& Animation::operator[](unsigned int i) {
	//creats an iterator to get the frame at the position
	forward_list<Frame>::iterator it = frames.begin();

	//advances the iterator to the position specified
	advance(it, i);

	//returns a pointer to the iterator
	return *it;
}

/***************************************************************************************************
Function name:		operator+=
Purpose:			Adds the Frame to the front of the forward_list
In parameters:		Frame
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::operator+=(Frame& f) {
	frames.push_front(f);
}

/***************************************************************************************************
Function name:		operator<<
Purpose:			Overloaded operator that prints out all the frames in the forward_list
In parameters:		ostream, Animation
Out parameters:		ostream
Version:			1.0
***************************************************************************************************/
ostream & operator<<(ostream& os, Animation& a) {
	int num = 0;

	//if there are no frames in the animation
	if (a.frames.empty())
		os << "Empty Animation" << endl;
	else {
		//prints out the name of the Animation
		os << "Animation " << a.name << endl;
		os << "Run the Animation" << endl;

		//iterates through the list and prints out the information about the frame
		for (forward_list<Frame>::iterator it = a.frames.begin(); it != a.frames.end(); ++it) {
			os << "Frame #" << num++ << ":" << endl;
			os << *it;
		}
		os << endl << "Output finished" << endl;
	}

	//returns the ostream
	return os;
}