/***************************************************************************************************
Filename:			Frame.cpp
Version:			1.0
Purpose:			The Frame of the Animation which holds multiple displays. The displays can either be a
					SystemMemoryDisplay or a GPUMemoryDisplay
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
Function name:		Frame(const Frame&)
Purpose:			Copies all the data from one frame to a new frame
In parameters:		const frame
Out parameters:		none
Version:			1.0
***************************************************************************************************/
Frame::Frame(const Frame& frame){
	//copies the fileName to the new frame
	fileName = frame.fileName;
	
	//loop through the frames display and copy it to the new frame
	for (int i = 0; i < (signed int)frame.displays.size(); i++) {
		//dynamic cast to a SystemMemoryDisplay to determine which type of display it is
		SystemMemoryDisplay* s = dynamic_cast<SystemMemoryDisplay*>(frame.displays[i]);

		//if it is not nullptr then we have a SystemMemoryDisplay
		if (s != nullptr) {
			//call the copy constructor for the SystemMemoryDisplay and push it into the display vector
			displays.push_back(new SystemMemoryDisplay(*s));
		}
		else {
			//dyanmic cast to GPUMemoryDisplay so that we can add it to the vector
			GPUMemoryDisplay* g = dynamic_cast<GPUMemoryDisplay*>(frame.displays[i]);
			//call the copy constructor for the GPUMemoryDisplay and push it into the display vector
			displays.push_back(new GPUMemoryDisplay(*g));
		}
	}
}

/***************************************************************************************************
Function name:		ostream<<
Purpose:			Returns the name of the Frame and the information about the Display vectors to ostream
In parameters:		ostream, frame
Out parameters:		ostream
Version:			1.0
***************************************************************************************************/
ostream& operator<<(ostream& os, Frame& f){
	//adds the fileName of the Frame to the ostream
	os << "\tfileName = " << f.fileName << endl;

	//loops through the vector of displays and adds the information to the ostream
	for (int i = 0; i < (signed int)f.displays.size(); i++) {
		//dynamic cast to see if the current display is a GPUMemoryDisplay
		GPUMemoryDisplay* g = dynamic_cast<GPUMemoryDisplay*>(f.displays[i]);
		os << "\tDisplay #" << i;
		if (g == nullptr) 
			 os << ": System Memory Display" << endl;
		else 
			//If it is a GPUMemoryDisplay then print out the shader 
			os << ": GPU Memory Display. Shader = " << g->GetShader() << endl;
		//prints out the display
		os << "\t" << *f.displays[i];
		//prints out the memory requirements for the current display
		os << "\tMemory Requirements = " << f.displays[i]->BufferSize() << " bytes" << endl << endl;
	}

	//returns the ostream
	return os;
}
