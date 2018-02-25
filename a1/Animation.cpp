/***************************************************************************************************
Filename:			Animation.cpp
Version:			1.0
Purpose:			Adds and Deletes Frames from the Animation. The Animation can also be run which
					displays each Frame in the Animation which a second delay between each one.
**************************************************************************************************/

#include <iostream>
#include <time.h>
#include "Frame.h"
#include "Animation.h"

#pragma warning (disable : 4996)

using namespace std;


Animation::Animation() {
	frames = nullptr;
}

Animation::~Animation() {
	DeleteFrames();
}

/***************************************************************************************************
Function name:		InsertFrames
Purpose:			Inserts a frame into the animation
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::InsertFrame() {
	char name[256];
	Frame *newFrame = new Frame();
	int count = 0, pos;
	Frame *iterator = frames;

	cout << "Please enter the Frame filename: ";
	cin >> name;

	//gets the length of the input string and creates memory for the string and the \0 character
	newFrame->GetfileName() = new char[strlen(name)+1];
	//copies the string from name to the newFrame
	strcpy(newFrame->GetfileName(), name);

	//checks if there are any Frames in the Animation and if not then add the new frame to the beginning
	if (frames == nullptr) {
		cout << "This is the first frame in the animation" << endl;
		frames = newFrame;
		return;
	}

	//counts the number of Frames in the Animation
	while (iterator) {
		count++;
		iterator = iterator->GetpNext();
	}

	cout << "There are " << count << " frame(s) in the list. Please specify the position (<=" << count << ") to insert at ";
	cin >> pos;

	//checks if the inputted position is bigger than the number of Frames in the Animation and if it is add it to the end
	if (pos > count)
		pos = count;

	count = 0;
	iterator = frames;

	//loops through until the one before the inputted position to add it to the Animation
	while (iterator && count < pos - 1) {
		count++;
		iterator = iterator->GetpNext();
	}

	//if the position chosen is at the start of the list
	if (pos == 0) {
		newFrame->GetpNext() = frames;
		frames = newFrame;
	}
	//otherwise add it to the one after the current Frame
	else {
		newFrame->GetpNext() = iterator->GetpNext();
		iterator->GetpNext() = newFrame;
	}
	return;
}

/***************************************************************************************************
Function name:		DeleteFrames
Purpose:			To delete all the current frames in the animation
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::DeleteFrames() {
	Frame *temp = frames;
	Frame *nextFrame;

	//nullptr check on Frames
	if (!frames)
		return;

	cout << "Delete all frames in the animation" << endl;

	//loops through the frames to delete each one
	while (temp) {
		nextFrame = temp->GetpNext();
		delete temp;
		temp = nextFrame;
	}

	//sets frames to nullptr
	frames = nullptr;
	return;
}

/***************************************************************************************************
Function name:		RunFrames
Purpose:			Runs the animation displaying all the current frames
In parameters:		none
Out parameters:		none
Version:			1.0
***************************************************************************************************/
void Animation::RunFrames() {
	int counter = 0;
	time_t startSec, oldSec, newSec;
	Frame *iterator = frames;

	//nullptr check on frames
	if (!frames) {
		cout << "No frames in the animation!" << endl;
		return;
	}

	//runs the animation
	cout << "Run the animation" << endl;
	startSec = oldSec = time(nullptr);

	//runs the animation printing out each frame
	while (iterator) {
		newSec = time(nullptr);
		if (newSec > oldSec) {
			cout << "Frame #" << counter++ << ", time = " << newSec - startSec << " sec" << endl;
			cout << "Image file name = " << iterator->GetfileName() << endl;
			iterator = iterator->GetpNext();
			oldSec = newSec;
		}
	}
	return;
}