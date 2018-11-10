//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: Matrix.h
// Description	: Matrix Header file
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz,  Harrison.ors7919@mediadesign.school.nz


#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windowsx.h>
#include <windows.h>
#include "utils.h"
#include "resource.h"



class Matrix {

public:

	Matrix();
	~Matrix();

	void Transpose(int a[][4], HWND _hwnd, float box);
	void ScalarMultiply(std::array<float, 16>, HWND _hwnd, float multNum, float box);
	void Addition(std::array<float, 16> _arrayA, std::array<float, 16> _arrayB, float box, HWND _hwnd);
	void Subtraction(std::array<float, 16> _arrayA, std::array<float, 16> _arrayB, float box, HWND _hwnd);
	void AMultiplyB(int a[][4], int b[][4], HWND _hwnd, float box);
	void BMultiplyA(int b[][4], int a[][4], HWND _hwnd, float box);
	void SetToI(std::array<float, 16> _arrayA, HWND _hwnd, float box, bool A);
	void Inverse(int m[][4], HWND _hwnd, float box);
	void Determinant(int a[][4], HWND _hwnd, float box);



private:








};
