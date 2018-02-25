/***************************************************************************************************
Filename:			Frame.h
Version:			1.0
Purpose:			Frame header file.
**************************************************************************************************/
#pragma once

class Frame
{
	string fileName;
	vector<Display*> displays;
public:
	Frame(string s, vector<Display*> d) :fileName(s), displays(d) {}
	Frame(const Frame&);
	~Frame()
	{
		vector<Display*>::iterator it;
		for (it = displays.begin(); it != displays.end(); it++)
			delete *it;
	}
	friend ostream& operator<<(ostream&, Frame&);
};