/***************************************************************************************************
Filename:			Animation.h
Version:			1.0
Purpose:			Header file for the Animation
**************************************************************************************************/
#pragma once

class Animation {
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void DeleteFrames();
	void RunFrames();
};