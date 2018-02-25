/***************************************************************************************************
Filename:			Frame.cpp
Version:			1.0
Purpose:			The constructor and destructor for the Frame
**************************************************************************************************/
#include "Frame.h"

Frame::Frame() {
	fileName = nullptr;
	pNext = nullptr;
}

Frame::~Frame() {
	delete[] fileName;
	pNext = nullptr;
}