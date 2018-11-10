//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: Quaternion.cpp
// Description	: Cpp file for Quaternion calculator
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz,  Harrison.ors7919@mediadesign.school.nz
#include <cmath>
#include "Quaternion.h"

Quart::Quart()
{
}

Quart::~Quart()
{
}

float Quart::Addition(HWND _hwnd,float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8)
{
	WriteToEditBox(_hwnd, IDC_EDIT10, (EDIT1 + EDIT5));
	WriteToEditBox(_hwnd, IDC_EDIT11, (EDIT2 + EDIT6));
	WriteToEditBox(_hwnd, IDC_EDIT12, (EDIT3 + EDIT7));
	WriteToEditBox(_hwnd, IDC_EDIT13, (EDIT4 + EDIT8));
	return 0.0f;
}

float Quart::Subtraction(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8)
{

		WriteToEditBox(_hwnd, IDC_EDIT10, (EDIT1 - EDIT5));
		WriteToEditBox(_hwnd, IDC_EDIT11, (EDIT2 - EDIT6));
		WriteToEditBox(_hwnd, IDC_EDIT12, (EDIT3 - EDIT7));
		WriteToEditBox(_hwnd, IDC_EDIT13, (EDIT4 - EDIT8));
	return 0.0f;
}

float Quart::multiplication(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8)
{
		float i = 0.0f;
		float j = 0.0f;
		float k = 0.0f;
		float real = 0.0f;
		real =	(EDIT4 * EDIT8) - (EDIT1 * EDIT5) - (EDIT2 * EDIT6) - (EDIT3 * EDIT7);
		i =		(EDIT4 * EDIT5) + (EDIT1 * EDIT8) + (EDIT2 * EDIT7) - (EDIT3 * EDIT6);
		j =		(EDIT4 * EDIT6) - (EDIT1 * EDIT7) + (EDIT2 * EDIT8) + (EDIT3 * EDIT5);
		k =		(EDIT4 * EDIT7) + (EDIT1 * EDIT6) - (EDIT2 * EDIT5) + (EDIT3 * EDIT8);
		WriteToEditBox(_hwnd, IDC_EDIT10, (i));
		WriteToEditBox(_hwnd, IDC_EDIT11, (j));
		WriteToEditBox(_hwnd, IDC_EDIT12, (k));
		WriteToEditBox(_hwnd, IDC_EDIT13, (real));
		return 0.0f;
}

float Quart::DOT(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8)
{

	float dot = ((EDIT1 * EDIT5) + (EDIT2 * EDIT6) + (EDIT3 * EDIT7) + (EDIT4 * EDIT8));
	WriteToEditBox(_hwnd, IDC_EDIT10, (0));
	WriteToEditBox(_hwnd, IDC_EDIT11, (0));
	WriteToEditBox(_hwnd, IDC_EDIT12, (0));
	WriteToEditBox(_hwnd, IDC_EDIT13, dot);

	return 0.0f;
}

float Quart::conjugate(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, int type )
{
	if (type == 1)
	{
		WriteToEditBox(_hwnd, IDC_EDIT1, (-EDIT1));
		WriteToEditBox(_hwnd, IDC_EDIT2, (-EDIT2));
		WriteToEditBox(_hwnd, IDC_EDIT3, (-EDIT3));
		WriteToEditBox(_hwnd, IDC_EDIT4, (EDIT4));
	}
	if (type == 2)
	{
		WriteToEditBox(_hwnd, IDC_EDIT5, (-EDIT1));
		WriteToEditBox(_hwnd, IDC_EDIT6, (-EDIT2));
		WriteToEditBox(_hwnd, IDC_EDIT7, (-EDIT3));
		WriteToEditBox(_hwnd, IDC_EDIT8, (EDIT4));

	}
	return 0.0f;
}

float Quart::mag(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	float tempEDIT1 = -EDIT1;
	float tempEDIT2 = -EDIT2;
	float tempEDIT3 = -EDIT3;
	float tempEDIT4 = EDIT4;


	float i = 0.0f;
	float j = 0.0f;
	float k = 0.0f;
	float real = 0.0f;
	real = (tempEDIT4 * EDIT4) - (tempEDIT1*EDIT1) - (tempEDIT2* EDIT2) - (tempEDIT3 *EDIT3);
	i = (tempEDIT4 * EDIT1) + (tempEDIT1 * EDIT4) + (tempEDIT2 * EDIT3) - (tempEDIT3 * EDIT2);
	j = (tempEDIT4 * EDIT2) - (tempEDIT1 * EDIT3) + (tempEDIT2 * EDIT4) + (tempEDIT3 * EDIT1);
	k = (tempEDIT4 * EDIT3) + (tempEDIT1 * EDIT2) - (tempEDIT2 * EDIT1) + (tempEDIT3 * EDIT4);

	i = sqrt(i+k+j+real);

	WriteToEditBox(_hwnd, IDC_EDIT10, (0));
	WriteToEditBox(_hwnd, IDC_EDIT11, (0));
	WriteToEditBox(_hwnd, IDC_EDIT12, (0));
	WriteToEditBox(_hwnd, IDC_EDIT13, (i));


	return 0.0f;
}

float Quart::inver(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{

	float tempEDIT1 = -EDIT1;
	float tempEDIT2 = -EDIT2;
	float tempEDIT3 = -EDIT3;
	float tempEDIT4 = EDIT4;

	float ansI = 0.0f;
	float ansJ = 0.0f;
	float ansK = 0.0f;
	float ansREAL = 0.0f;
	float denominator = 0.0f;

	denominator = ((EDIT1 * EDIT1) + (EDIT2*EDIT2) + (EDIT3*EDIT3) + (EDIT4*EDIT4));

	ansREAL = (tempEDIT4 / denominator);
	ansI = (tempEDIT1 / denominator);
	ansJ = (tempEDIT2 / denominator);
	ansK = (tempEDIT3 / denominator);

	WriteToEditBox(_hwnd, IDC_EDIT10, (ansI));
	WriteToEditBox(_hwnd, IDC_EDIT11, (ansJ));
	WriteToEditBox(_hwnd, IDC_EDIT12, (ansK));
	WriteToEditBox(_hwnd, IDC_EDIT13, (ansREAL));

	return 0.0f;
}

float Quart::scale(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT9, int type)
{
	if (type == 1)
	{
		WriteToEditBox(_hwnd, IDC_EDIT1, (EDIT1 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT2, (EDIT2 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT3, (EDIT3 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT4, (EDIT4 * EDIT9));
	}
	if (type == 2)
	{
		WriteToEditBox(_hwnd, IDC_EDIT5, (EDIT1 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT6, (EDIT2 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT7, (EDIT3 * EDIT9));
		WriteToEditBox(_hwnd, IDC_EDIT8, (EDIT4 * EDIT9));
	}
	return 0.0f;
}



