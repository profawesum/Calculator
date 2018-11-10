//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: SLERP.cpp
// Description	: Cpp file for Slerp calculator
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz, Harrison.ors7919@mediadesign.school.nz

#include <cmath>
#include "SLERP.h"

SLERP::SLERP()
{
}

SLERP::~SLERP()
{
}


float MULTreal(float tempEDIT1, float tempEDIT2, float tempEDIT3, float tempEDIT4, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	return ((tempEDIT4 * EDIT4) - (tempEDIT1*EDIT1) - (tempEDIT2* EDIT2) - (tempEDIT3 *EDIT3));
}

float MULTi(float tempEDIT1, float tempEDIT2, float tempEDIT3, float tempEDIT4, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	return((tempEDIT4 * EDIT1) + (tempEDIT1 * EDIT4) + (tempEDIT2 * EDIT3) - (tempEDIT3 * EDIT2));
}
	
float MULTj(float tempEDIT1, float tempEDIT2, float tempEDIT3, float tempEDIT4, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	return ((tempEDIT4 * EDIT2) - (tempEDIT1 * EDIT3) + (tempEDIT2 * EDIT4) + (tempEDIT3 * EDIT1));
}

float MULTk(float tempEDIT1, float tempEDIT2, float tempEDIT3, float tempEDIT4, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	return  ((tempEDIT4 * EDIT3) + (tempEDIT1 * EDIT2) - (tempEDIT2 * EDIT1) + (tempEDIT3 * EDIT4));
}

float SLERP::SLERPQUART(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4, float EDIT5, float EDIT6, float EDIT7, float EDIT8, float EDIT9)
{
	float tempEDIT1 = 0.0f; //i
	float tempEDIT2 = 0.0f; //j
	float tempEDIT3 = 0.0f; //k
	float tempEDIT4 = 0.0f; //r
	float tempEDIT5 = 0.0f;
	float tempEDIT6 = 0.0f;
	float tempEDIT7 = 0.0f;
	float tempEDIT8 = 0.0f;


	float DOT = ((EDIT1 * EDIT5) + (EDIT2 * EDIT6) + (EDIT3 * EDIT7) + (EDIT4 * EDIT8));

	if (DOT < 1 && DOT > 0)
	{
		float theta = acosf(DOT);
		float invTheta = (1 / sin(theta));
		float scale = sin(theta * (1 - EDIT9));
		float invScale = (sin(theta * EDIT9) * invTheta * 1);

		tempEDIT1 = EDIT1 * scale;
		tempEDIT2 = EDIT2 * scale;
		tempEDIT3 = EDIT3 * scale;
		tempEDIT4 = EDIT4 * scale;
		tempEDIT5 = EDIT5 * invScale;
		tempEDIT6 = EDIT6 * invScale;
		tempEDIT7 = EDIT7 * invScale;
		tempEDIT8 = EDIT8 * invScale;

		tempEDIT1 = tempEDIT1 + tempEDIT5;
		tempEDIT2 = tempEDIT2 + tempEDIT6;
		tempEDIT3 = tempEDIT3 + tempEDIT7;
		tempEDIT4 = tempEDIT4 + tempEDIT8;

		WriteToEditBox(_hwnd, IDC_EDIT10, (tempEDIT1));
		WriteToEditBox(_hwnd, IDC_EDIT11, (tempEDIT2));
		WriteToEditBox(_hwnd, IDC_EDIT12, (tempEDIT3));
		WriteToEditBox(_hwnd, IDC_EDIT13, (tempEDIT4));

		return 0.0f;
	}
	else
	{
		tempEDIT1 = EDIT5 - EDIT1;
		tempEDIT2 = EDIT6 - EDIT2;
		tempEDIT3 = EDIT7 - EDIT3;
		tempEDIT4 = EDIT8 - EDIT4;

		tempEDIT1 = tempEDIT1 * EDIT9;
		tempEDIT2 = tempEDIT2 * EDIT9;
		tempEDIT3 = tempEDIT3 * EDIT9;
		tempEDIT4 = tempEDIT4 * EDIT9;

		tempEDIT1 = EDIT1 + tempEDIT1;
		tempEDIT2 = EDIT2 + tempEDIT2;
		tempEDIT3 = EDIT3 + tempEDIT3;
		tempEDIT4 = EDIT4 + tempEDIT4;

		float ans = sqrt(tempEDIT1 + tempEDIT2 + tempEDIT3 + tempEDIT4);

		WriteToEditBox(_hwnd, IDC_EDIT10, (0));
		WriteToEditBox(_hwnd, IDC_EDIT11, (0));
		WriteToEditBox(_hwnd, IDC_EDIT12, (0));
		WriteToEditBox(_hwnd, IDC_EDIT13, (ans));

	}
		
	return 0.0f;
}

float SLERP::MATRIXABS(HWND _hwnd, float EDIT1, float EDIT2, float EDIT3, float EDIT4)
{
	float tempEDIT1 = -EDIT1; //i
	float tempEDIT2 = -EDIT2; //j
	float tempEDIT3 = -EDIT3; //k
	float tempEDIT4 = EDIT4; //r

	float i = 0.0f;
	float j = 0.0f;
	float k = 0.0f;
	float real = 0.0f;
	real = MULTreal(tempEDIT1, tempEDIT2, tempEDIT3, tempEDIT4, EDIT1, EDIT2, EDIT3, EDIT4);
	i = MULTi(tempEDIT1, tempEDIT2, tempEDIT3, tempEDIT4, EDIT1, EDIT2, EDIT3, EDIT4);
	j = MULTj(tempEDIT1, tempEDIT2, tempEDIT3, tempEDIT4, EDIT1, EDIT2, EDIT3, EDIT4);
	k = MULTk(tempEDIT1, tempEDIT2, tempEDIT3, tempEDIT4, EDIT1, EDIT2, EDIT3, EDIT4);

	i = sqrt(i + k + j + real);

	float s = 0.0f;
	s = pow(i,-2.0);
	
	float MATray[4][4] = {	(1.0f - (2.0f * s)*((pow(EDIT1,2))+(pow(EDIT2, 2)))),	((2.0f * s)*((EDIT1*EDIT2)-(EDIT3 * EDIT4))),		((2.0f * s)*((EDIT1 * EDIT3)-(EDIT2 * EDIT4))),			(0.0f),
							((2.0f * s) * ((EDIT1 * EDIT2)+(EDIT3 * EDIT4))),		(1.0f-(2.0f * s)*((pow(EDIT1,2))+(pow(EDIT3,2)))),	((2.0f * s)*((EDIT2 * EDIT3)-(EDIT1 * EDIT4))),			(0.0f),
							((2.0f * s)*((EDIT1 * EDIT3) - (EDIT2 * EDIT4))),		((2.0f * s) * ((EDIT2 * EDIT3)+(EDIT1 * EDIT4))),	(1.0f-(2.0f * s)*((pow(EDIT1,2))+(pow(EDIT2 , 2)))),	(0.0f),
							(0.0f),													(0.0f),												(0.0f),													(1.0f)};

	int box = 1034;

	for (int ss = 0; ss < 4; ss++)
	{
		for (int tt = 0; tt < 4; tt++)
		{
			WriteToEditBox(_hwnd, box , (MATray[ss][tt]));
			box++;

		}
	}



	return 0.0f;
}


