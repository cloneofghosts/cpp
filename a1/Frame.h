/***************************************************************************************************
Filename:			Frame.h
Version:			1.0
Purpose:			Header file for the Frames
**************************************************************************************************/
#pragma once

class Frame {
	char* fileName;
	Frame* pNext;
public:
	Frame();
	~Frame();
	char*& GetfileName() { return fileName; }
	Frame*& GetpNext() { return pNext; };
};