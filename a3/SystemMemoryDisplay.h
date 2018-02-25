/***************************************************************************************************
Filename:			SystemMemoryDisplay.h
Version:			1.0
Purpose:			SystemMemoryDisplay header file.
**************************************************************************************************/
#pragma once

class  SystemMemoryDisplay : public Display
{
public:
	SystemMemoryDisplay(int x, int y, int duration, char* name) :Display(x, y, duration, name) {};
	SystemMemoryDisplay(const SystemMemoryDisplay& RGMD) :Display(RGMD) {}
	int BufferSize() { return pixel_x*pixel_y * sizeof(double); }
};