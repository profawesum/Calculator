//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: SLERP.h
// Description	: Slerp Header File
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz,  Harrison.ors7919@mediadesign.school.nz

#pragma once

#include <windowsx.h>
#include "utils.h"
#include "resource.h"

class SLERP
{
public:
	SLERP();
	~SLERP();
	static float SLERPQUART(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8, float EDIT9);
	static float MATRIXABS(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4);
	//static float MATRIXSLERP();



private:

	float EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8, EDIT9, EDIT10, EDIT11, EDIT12, EDIT13;
};