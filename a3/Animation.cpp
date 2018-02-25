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
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
#include "Frame.h"
#include "Animation.h"

/***************************************************************************************************
Function name:		InsertFrames
Purpose:			Inserts a frame into the animation and allows the user to add multiple Displays which
					can be a GPUMemoryDisplay or SystemMemoryDisplay to each frame in the Animation
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::InsertFrame() {
	//local variable declarations
	vector<Display*> d;
	string fileName, shaderName;
	char displayName[255];
	int numDisplays, pixel_x, pixel_y, duration, count;
	forward_list<Frame>::iterator it;
	int displayNum = 0;
	Display* dis;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Enter the Frame filename: ";
	cin >> fileName;
	cout << "Entering the Frame Displays (the sets of dimensions and durations)" << endl;
	cout << "Enter the number of Displays: ";
	cin >> numDisplays;

	//loops for the number of displays specifed and gets the information of the display
	for (int i = 0; i < numDisplays; i++) {
		cout << "Please enter pixel x-width for Display #" << i << " pixel_x:";
		cin >> pixel_x;
		cout << "Please enter pixel y-width for Display #" << i << " pixel_y:";
		cin >> pixel_y;
		cout << "Please enter the duration sec for this Display: ";
		cin >> duration;
		cout << "Please enter the name of this display: ";
		cin >> displayName;
		cout << "Please enter the type for this display (1 = SystemMemoryDisplay, 2 = GPUMemoryDisplay): ";
		cin >> displayNum;

		//checks to see what type of Display we have 1 = SystemMemoryDisplay; 2 = GPUMemoryDisplay
		if (displayNum == 1) {
			//create a new SystemMemoryDisplay with the information provided
			dis = new SystemMemoryDisplay(pixel_x, pixel_y, duration, displayName);
		}
		else if(displayNum == 2) {
			//promts the user to ender a shader name for the GPUMemoryDisplay
			cout << "Please enter the file name of the associated GPU Shader: ";
			cin >> shaderName;
			//create a new GPUMemoryDisplay with the information provided
			dis = new GPUMemoryDisplay(pixel_x, pixel_y, duration, displayName, shaderName);
		}

		cout << endl;

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
		cout << "Please specify the position, between 0 and " << count - 1 << " to insert after: ";
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
Function name:		operator<<
Purpose:			Overloaded operator that prints out all the frames in the forward_list
In parameters:		ostream, Animation
Out parameters:		ostream
Version:			1.0
***************************************************************************************************/
ostream& operator<<(ostream& os, Animation& a){
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
			os << "Frame #" << num++ << ":";
			os << *it;
		}
		os << endl << "Output finished" << endl;
	}

	//returns the ostream
	return os;
}
