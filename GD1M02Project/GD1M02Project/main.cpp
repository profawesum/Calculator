//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: main.cpp
// Description	: Calls all other functions for each calculator
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz,  Harrison.ors7919@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <array>
#include "utils.h"
#include "resource.h"
#include "Quaternion.h"
#include "SLERP.h"
#include "Matrix.h"
#include "Gaussian.h"
#include "Transformation.h"


#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;
Matrix matrix;
Transformation trans;

int checkedRotation;


void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,UINT _msg,WPARAM _wparam,LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

					// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{

			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
		//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
		//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
		//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

	default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

BOOL CALLBACK MatrixDlgProc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{


	//Matrix A
	static float _valueA11, _valueA12, _valueA13, _valueA14;
	static float _valueA21, _valueA22, _valueA23, _valueA24;
	static float _valueA31, _valueA32, _valueA33, _valueA34;
	static float _valueA41, _valueA42, _valueA43, _valueA44;

	//Matrix B
	static float _valueB11, _valueB12, _valueB13, _valueB14;
	static float _valueB21, _valueB22, _valueB23, _valueB24;
	static float _valueB31, _valueB32, _valueB33, _valueB34;
	static float _valueB41, _valueB42, _valueB43, _valueB44;

	static float multNumA;
	static float multNumB;

	//matrix arrays
	std::array<float, 16> matrixArrayA = { _valueA11, _valueA12, _valueA13, _valueA14 ,
		_valueA21, _valueA22, _valueA23, _valueA24 ,
		_valueA31, _valueA32, _valueA33, _valueA34 ,
		_valueA41, _valueA42, _valueA43, _valueA44 };


	std::array<float, 16> matrixArrayB = { _valueB11, _valueB12, _valueB13, _valueB14 ,
		_valueB21, _valueB22, _valueB23, _valueB24 ,
		_valueB31, _valueB32, _valueB33, _valueB34 ,
		_valueB41, _valueB42, _valueB43, _valueB44 };


	//2D arrays
	int arrayA[4][4] = { { _valueA11, _valueA12, _valueA13, _valueA14 },
	{ _valueA21, _valueA22, _valueA23, _valueA24 },
	{ _valueA31, _valueA32, _valueA33, _valueA34 },
	{ _valueA41, _valueA42, _valueA43, _valueA44 } };

	int arrayB[4][4] = { { _valueB11, _valueB12, _valueB13, _valueB14 },
	{ _valueB21, _valueB22, _valueB23, _valueB24 },
	{ _valueB31, _valueB32, _valueB33, _valueB34 },
	{ _valueB41, _valueB42, _valueB43, _valueB44 } };

	int arrayI[4][4] = { { 1,0,0,0 },
	{ 0,1,0,0 },
	{ 0,0,1,0 },
	{ 0,0,0,1 } };



	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{

			//Matrix A Input Boxes
		case IDC_EDIT_A11: {
			_valueA11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			break;
		}
		case IDC_EDIT_A12: {

			_valueA12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			break;
		}
		case IDC_EDIT_A13: {

			_valueA13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			break;
		}
		case IDC_EDIT_A14: {
			_valueA14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			break;
		}
		case IDC_EDIT_A21: {

			_valueA21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			break;
		}
		case IDC_EDIT_A22: {

			_valueA22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			break;
		}
		case IDC_EDIT_A23: {

			_valueA23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			break;
		}
		case IDC_EDIT_A24: {

			_valueA24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			break;
		}
		case IDC_EDIT_A31: {

			_valueA31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			break;
		}
		case IDC_EDIT_A32: {

			_valueA32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			break;
		}
		case IDC_EDIT_A33: {

			_valueA33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			break;
		}
		case IDC_EDIT_A34: {

			_valueA34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			break;
		}
		case IDC_EDIT_A41: {

			_valueA41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			break;
		}
		case IDC_EDIT_A42: {

			_valueA42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			break;
		}
		case IDC_EDIT_A43: {

			_valueA43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			break;
		}
		case IDC_EDIT_A44: {

			_valueA44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
			break;
		}

						   //Matrix B Input Boxes
		case IDC_EDIT_B11: {
			_valueB11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			break;
		}
		case IDC_EDIT_B12: {

			_valueB12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			break;
		}
		case IDC_EDIT_B13: {

			_valueB13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			break;
		}
		case IDC_EDIT_B14: {
			_valueB14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
			break;
		}
		case IDC_EDIT_B21: {

			_valueB21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			break;
		}
		case IDC_EDIT_B22: {

			_valueB22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			break;
		}
		case IDC_EDIT_B23: {

			_valueB23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			break;
		}
		case IDC_EDIT_B24: {

			_valueB24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
			break;
		}
		case IDC_EDIT_B31: {

			_valueB31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			break;
		}
		case IDC_EDIT_B32: {

			_valueB32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			break;
		}
		case IDC_EDIT_B33: {

			_valueB33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			break;
		}
		case IDC_EDIT_B34: {

			_valueB34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
			break;
		}
		case IDC_EDIT_B41: {

			_valueB41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			break;
		}
		case IDC_EDIT_B42: {

			_valueB42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			break;
		}
		case IDC_EDIT_B43: {

			_valueB43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			break;
		}
		case IDC_EDIT_B44: {

			_valueB44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);
			break;
		}

						   //scalar multiplication values for matrix A and B
		case IDC_EDIT_AScaled: {

			multNumA = ReadFromEditBox(_hwnd, IDC_EDIT_AScaled);
			break;

		}
		case IDC_EDIT_BScaled: {

			multNumB = ReadFromEditBox(_hwnd, IDC_EDIT_BScaled);
			break;

		}


							   //Scalar Multiplication Matrix A DONE
		case IDOK6: {

			float box = 2000;
			matrix.ScalarMultiply(matrixArrayA, _hwnd, multNumA, box);
			break;

		}

					//Transpose Matrix A DONE
		case IDOK9: {

			float box = 2000;
			matrix.Transpose(arrayA, _hwnd, box);
			break;
		}

					//Scalar Multiplication Matrix B DONE
		case IDOK10: {

			float box = 1070;
			matrix.ScalarMultiply(matrixArrayB, _hwnd, multNumB, box);
			break;
		}

					 //Transpose Matrix B DONE
		case IDOK11: {

			float box = 1070;
			matrix.Transpose(arrayB, _hwnd, box);
			break;

		}

					 //Matrix A+B DONE
		case IDOK: {
			float box = 3000;
			matrix.Addition(matrixArrayA, matrixArrayB, box, _hwnd);
			break;
		}

				   // Matrix A-B DONE
		case IDCANCEL: {
			float box = 3000;
			matrix.Subtraction(matrixArrayA, matrixArrayB, box, _hwnd);
			break;

		}

					   //Matrix A*B DONE
		case IDOK2: {
			float box = 3000;
			matrix.AMultiplyB(arrayA, arrayB, _hwnd, box);
			break;
		}

					//Matrix B * A DONE
		case IDOK5: {
			float box = 3000;
			matrix.BMultiplyA(arrayB, arrayA, _hwnd, box);
			break;
		}

					//determinant of Matrix A DONE
		case IDOK3: {
			float box = 1069;
			matrix.Determinant(arrayA, _hwnd, box);
			break;
		}

					//determinant of Matrix B DONE
		case IDOK7: {
			float box = 1098;
			matrix.Determinant(arrayB, _hwnd, box);
		}

					//Inverse Matrix A DONE
		case IDCANCEL2: {

			float box = 2000;
			matrix.Inverse(arrayA, _hwnd, box);

			break;
		}

						//Inverse Matrix B DONE
		case IDCANCEL3: {

			float box = 1070;
			matrix.Inverse(arrayB, _hwnd, box);

			break;

		}

						//Set A to I DONE
		case IDOK4: {
			float A = true;
			float box = 2000;
			matrix.SetToI(matrixArrayA, _hwnd, box, A);
			break;
		}

					//Set B to I DONE
		case IDOK8: {
			float A = false;
			float box = 1070;
			matrix.SetToI(matrixArrayB, _hwnd, box, A);
			break;
		}

					//default case
		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,UINT _msg,WPARAM _wparam,LPARAM _lparam)
{
	 bool translation = false;
	 bool rotation = false;
	 bool projection = false;
	 bool scaling = false;

	 static int axisOfRot; //0 is x, 1 is y, 2 is z

	 static float angle;
	 static float distance;

	 static float a11 = 1, a12 = 0, a13 = 0, a14 = 0;
	 static float b11 = 0, b12 = 1, b13 = 0, b14 = 0;
	 static float c11 = 0, c12 = 0, c13 = 1, c14 = 0;
	 static float d11 = 0, d12 = 0, d13 = 0, d14 = 1;

	 static float Edit1;
	 static float Edit2;
	 static float Edit3;
	 static float Edit4;
	 static float Edit5;
	 static float Edit6;


	 float arrayA1[16]{a11, a12, a13, a14, b11, b12, b13, b14, c11, c12, c13, c14, d11, d12, d13, d14};

	 float arrayA[4][4]{ {a11,a12,a13,a14},
						 {b11,b12,b13,b14},
						 {c11,c12,c13,c14},
						 {d11,d12,d13,d14} };



	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{

		//X Scalar Value (a11)
		case IDC_EDIT1: {
		
			Edit1 = ReadFromEditBox(_hwnd, IDC_EDIT1);
			break;
		}
		//Y Scalar Value (b12)
		case IDC_EDIT2: {

			Edit2 = ReadFromEditBox(_hwnd, IDC_EDIT2);
			break;
		}
		//Z Scalar Value (c13)
		case IDC_EDIT3: {

			Edit3 = ReadFromEditBox(_hwnd, IDC_EDIT3);
			break;
		}
		//X Translation Value(a14)
		case IDC_EDIT4: {
			Edit4 = ReadFromEditBox(_hwnd, IDC_EDIT4);
			
			break;
		}
		//Y Translation Value(b14)
		case IDC_EDIT5: {
			Edit5 = ReadFromEditBox(_hwnd, IDC_EDIT5);
			break;
		}
		//Z Translation Value(c14)
		case IDC_EDIT6: {
			Edit6 = ReadFromEditBox(_hwnd, IDC_EDIT6);
			break;
		}
		//angle value for rotation
		case IDC_EDIT13: {
			angle = ReadFromEditBox(_hwnd, IDC_EDIT13);
			break;
		}
		//projection distance
		case IDC_EDIT15: {
			distance = ReadFromEditBox(_hwnd, IDC_EDIT15);
			break;
		}


		//Rotation about X Axis Checkbox
		case IDC_CHECK1: {
			axisOfRot = 0;

			break;
		}		
		//Rotation about Y Axis Checkbox
		case IDC_CHECK2: {
			axisOfRot = 1;
			break;
		}
		//Rotation about Z Axis Checkbox
		case IDC_CHECK7: {
			axisOfRot = 2;
			break;
		}


		//Scaling and Skewing
		case IDC_CHECK3: {
			float box = 1047;
			trans.Scaling(_hwnd, a11, b12, c13, Edit1, Edit2, Edit3, arrayA1, box);
			break;
		}
		//Rotation
		case IDC_CHECK4: {
			trans.Rotation(_hwnd, axisOfRot, angle);
			break;
		}
		//Projection
		case IDC_CHECK5: {
			trans.Projection(_hwnd, distance);
			break;
		}
		//Translation
		case IDC_CHECK6: {
			trans.Translation(_hwnd, arrayA1, a14, b14, c14, Edit4, Edit5, Edit6);
			break;
		}
		////compute button
		case IDC_BUTTON4: {
			
			float box = 1047;
			trans.Compute(_hwnd, box);
			break;
		}

		default:
			break;
		}	
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}

	default:
		break;
	}
		return FALSE;

}

BOOL CALLBACK GaussianDlgProc(HWND _hwnd,UINT _msg,WPARAM _wparam,LPARAM _lparam)
{
	//do
	static float EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8, EDIT9, EDIT10, EDIT11, EDIT12;



	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK QuaternionDlgProc(HWND _hwnd, UINT _msg,WPARAM _wparam,LPARAM _lparam){

	//a
	static float EDIT1; //realnumber
	static float EDIT2; //i
	static float EDIT3; //j
	static float EDIT4; //k

	//b
	static float EDIT5; //relnumber
	static float EDIT6; //i
	static float EDIT7; //j
	static float EDIT8; //k

	static float EDIT9; //t

	//ans
	static float EDIT10; //real
	static float EDIT11; // i
	static float EDIT12; //j
	static float EDIT13; //k


	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			case IDC_EDIT1:
			{
				EDIT1 = ReadFromEditBox(_hwnd, IDC_EDIT1);
				break;
			}
			case IDC_EDIT2:
			{
				EDIT2 = ReadFromEditBox(_hwnd, IDC_EDIT2);
				break;
			}
			case IDC_EDIT3:
			{
				EDIT3 = ReadFromEditBox(_hwnd, IDC_EDIT3);
				break;
			}
			case IDC_EDIT4:
			{
				EDIT4 = ReadFromEditBox(_hwnd, IDC_EDIT4);
				break;
			}
			case IDC_EDIT5:
			{
				EDIT5 = ReadFromEditBox(_hwnd, IDC_EDIT5);
				break;
			}
			case IDC_EDIT6:
			{
				EDIT6 = ReadFromEditBox(_hwnd, IDC_EDIT6);
				break;
			}
			case IDC_EDIT7:
			{
				EDIT7 = ReadFromEditBox(_hwnd, IDC_EDIT7);
				break;
			}
			case IDC_EDIT8:
			{
				EDIT8 = ReadFromEditBox(_hwnd, IDC_EDIT8);
				break;
			}
			case IDC_EDIT9:
			{
				EDIT9 = ReadFromEditBox(_hwnd, IDC_EDIT9);
				break;
			}
			case IDC_EDIT10:
			{
				EDIT10 = ReadFromEditBox(_hwnd, IDC_EDIT10);
				break;
			}
			case IDC_EDIT11:
			{
				EDIT11 = ReadFromEditBox(_hwnd, IDC_EDIT11);
				break;
			}
			case IDC_EDIT12:
			{
				EDIT12 = ReadFromEditBox(_hwnd, IDC_EDIT12);
				break;
			}
			case IDC_EDIT13:
			{
				EDIT13 = ReadFromEditBox(_hwnd, IDC_EDIT13);
				break;
			}

			//"a + b",
			case IDC_BUTTON1:
			{
				Quart::Addition(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8);
			 break;
			}
			//"a - b",
			case IDC_BUTTON5:
			{
				Quart::Subtraction(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8);
				break;
			}
			//"b - a", 
			case IDC_BUTTON6:
			{
				Quart::Subtraction(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8, EDIT1, EDIT2, EDIT3, EDIT4);
				break;
			}
			//"ab", 
			case IDC_BUTTON2:
			{
				Quart::multiplication(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8);
				break;
			}
			//"ba", 
			case IDC_BUTTON7:
			{
				Quart::multiplication(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8, EDIT1, EDIT2, EDIT3, EDIT4);
				break;
			}
			//"a dot b", 
			case IDC_BUTTON8:
			{
				Quart::DOT(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8);
				break;
			}
			//"a*", 
			case IDC_BUTTON3:
			{
				Quart::conjugate(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, 1);
				break;
			}
			//"b*", 
			case IDC_BUTTON9:
			{
				Quart::conjugate(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8, 2);
				break;
			}
			//"|a|", 
			case IDC_BUTTON10:
			{
				Quart::mag(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4);
				break;
			}
			//"|b|", 
			case IDC_BUTTON11:
			{
				Quart::mag(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8);
				break;
			}
			//"a Inv", 
			case IDC_BUTTON12:
			{
				Quart::inver(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4);
				break;
			}
			//"b Inv", 
			case IDC_BUTTON13:
			{
				Quart::inver(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8);
				break;
			}
			//"ta", 
			case IDC_BUTTON14:
			{
				Quart::scale(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT9, 1);
				break;
			}
			//"tb",
			case IDC_BUTTON15:
			{
				Quart::scale(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8, EDIT9, 2);
				break;
			}
		}
		break;

	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,UINT _msg,WPARAM _wparam,LPARAM _lparam)
{
	static float EDIT1, EDIT2,EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8, EDIT9, EDIT10, EDIT11, EDIT12, EDIT13;

	static float EDIT34, EDIT35, EDIT36, EDIT37;
	static float EDIT38, EDIT39, EDIT40, EDIT41;
	static float EDIT42, EDIT43, EDIT44, EDIT45;
	static float EDIT46, EDIT47, EDIT48, EDIT49;






	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_EDIT1:
		{
			EDIT1 = ReadFromEditBox(_hwnd, IDC_EDIT1);
			break;
		}
		case IDC_EDIT2:
		{
			EDIT2 = ReadFromEditBox(_hwnd, IDC_EDIT2);
			break;
		}
		case IDC_EDIT3:
		{
			EDIT3 = ReadFromEditBox(_hwnd, IDC_EDIT3);
			break;
		}
		case IDC_EDIT4:
		{
			EDIT4 = ReadFromEditBox(_hwnd, IDC_EDIT4);
			break;
		}
		case IDC_EDIT5:
		{
			EDIT5 = ReadFromEditBox(_hwnd, IDC_EDIT5);
			break;
		}
		case IDC_EDIT6:
		{
			EDIT6 = ReadFromEditBox(_hwnd, IDC_EDIT6);
			break;
		}
		case IDC_EDIT7:
		{
			EDIT7 = ReadFromEditBox(_hwnd, IDC_EDIT7);
			break;
		}
		case IDC_EDIT8:
		{
			EDIT8 = ReadFromEditBox(_hwnd, IDC_EDIT8);
			break;
		}
		case IDC_EDIT9:
		{
			EDIT9 = ReadFromEditBox(_hwnd, IDC_EDIT9);
			break;
		}
		case IDC_EDIT10:
		{
			EDIT10 = ReadFromEditBox(_hwnd, IDC_EDIT10);
			break;
		}
		case IDC_EDIT11:
		{
			EDIT11 = ReadFromEditBox(_hwnd, IDC_EDIT11);
			break;
		}
		case IDC_EDIT12:
		{
			EDIT12 = ReadFromEditBox(_hwnd, IDC_EDIT12);
			break;
		}
		case IDC_EDIT13:
		{
			EDIT13 = ReadFromEditBox(_hwnd, IDC_EDIT13);
			break;
		}

		//"slerp(a, b, t)"
		case IDC_BUTTON1:
		{
			SLERP::SLERPQUART(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4, EDIT5, EDIT6, EDIT7, EDIT8, EDIT9);
			break;
		}
		//"a", 
		case IDC_BUTTON2:
		{
			SLERP::MATRIXABS(_hwnd, EDIT1, EDIT2, EDIT3, EDIT4);
			break;
		}
		//"b",
		
		case IDC_BUTTON3:
		{
			SLERP::MATRIXABS(_hwnd, EDIT5, EDIT6, EDIT7, EDIT8);
			break;
		}
		//"slerp(a, b, t)",
		case IDC_BUTTON4:
		{
			SLERP::MATRIXABS(_hwnd, EDIT10, EDIT11, EDIT12, EDIT13);
			break;
		}

		}
		break;

	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,HINSTANCE _hPrevInstance,LPSTR _lpCmdLine,int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

						 // First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Your Basic Window",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, (DLGPROC)MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, (DLGPROC)TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, (DLGPROC)GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, (DLGPROC)QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, (DLGPROC)SLERPDlgProc);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT) {
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}


