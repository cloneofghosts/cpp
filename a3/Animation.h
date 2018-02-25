/***************************************************************************************************
Filename:			Animation.h
Version:			1.0
Purpose:			Animation header file.
**************************************************************************************************/
#pragma once

class Animation
{
	string name;
	forward_list<Frame> frames;
public:
	Animation(string s) : name(s) {}
	void InsertFrame();
	void DeleteFrames();
	friend ostream& operator<<(ostream&, Animation&);
};