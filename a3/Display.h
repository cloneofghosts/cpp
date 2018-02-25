/***************************************************************************************************
Filename:			Display.h
Version:			1.0
Purpose:			Display header file.
**************************************************************************************************/
#pragma once

class Display
{
protected:	// accessible to derived classes
	int pixel_x;
	int pixel_y;
	int duration;
	char* name;
public:
	Display(int x, int y, int duration, char* name);
	Display(const Display&);
	virtual ~Display()
	{
		if (name)
			delete[]name;
	}
	virtual int BufferSize() = 0;
	friend ostream& operator<<(ostream&, Display&);
};