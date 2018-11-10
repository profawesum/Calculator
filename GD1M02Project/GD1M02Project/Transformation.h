#pragma once




#define WIN32_LEAN_AND_MEAN

#include <windowsx.h>
#include <windows.h>
#include "utils.h"
#include "resource.h"



class Transformation {

public:


	void Scaling(HWND _hwnd, float a11, float b12, float c13, float scaleX, float scaleY, float scaleZ, float _arrayA[], float box);

	void Rotation(HWND _hwnd,int axisOfRot, float angle);

	void Translation(HWND _hwnd, float arrayA[], float a14, float b14, float c14, float transX, float transY, float transZ);

	void Projection(HWND _hwnd, float distance);


	void Compute(HWND _hwnd, float box);

};