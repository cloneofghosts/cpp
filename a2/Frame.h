/***************************************************************************************************
Filename:			Frame.h
Version:			1.0
Purpose:			Frame header file.
**************************************************************************************************/
#pragma once

class Frame
{
	string fileName;
	vector<Display> displays;
public:
	Frame::Frame(string s, vector<Display> d) :fileName(s), displays(d) {}
	Frame operator+(Frame&);
	friend ostream& operator<<(ostream&, Frame&);
};