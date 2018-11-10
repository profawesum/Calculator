//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: Matrix.cpp
// Description	: Cpp file for Matrix calculator
// Author		: Vaughan Webb, Harrison Orsbourne
// Mail			: Vaughan.web8091@mediadesign.school.nz,  Harrison.ors7919@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN
#include <array>
#include "Matrix.h"
#include <windows.h>

Matrix::Matrix() {

}

Matrix::~Matrix() {

}

void Matrix::Transpose(int a[][4], HWND _hwnd, float box) {



	for (int i = 0; i < 4; i++) {
		//float num = 0;
		for (int j = 0; j < 4; j++) {
			float num = a[j][i];
			WriteToEditBox(_hwnd, box, num);
			box += 1;
		}

	}


}

void Matrix::ScalarMultiply(std::array<float, 16> _array, HWND _hwnd, float multNum, float box) {

	for (int i = 0; i < 16; i++) {

		float num = multNum * _array.at(i);
		WriteToEditBox(_hwnd, box, num);
		box += 1;
	}
}

void Matrix::Addition(std::array<float, 16> _arrayA, std::array<float, 16> _arrayB, float box, HWND _hwnd) {

	for (int i = 0; i < 16; i++) {

		float num = _arrayA.at(i) + _arrayB.at(i);
		WriteToEditBox(_hwnd, box, num);
		box += 1;
	}

}

void Matrix::Subtraction(std::array<float, 16> _arrayA, std::array<float, 16> _arrayB, float box, HWND _hwnd) {


	for (int i = 0; i < 16; i++) {

		float num = _arrayA.at(i) - _arrayB.at(i);
		WriteToEditBox(_hwnd, box, num);
		box += 1;
	}
}

void Matrix::AMultiplyB(int a[][4], int b[][4], HWND _hwnd, float box) {


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float num = 0;
			for (int k = 0; k < 4; k++) {
				num += a[i][k] * b[k][j];

			}
			WriteToEditBox(_hwnd, box, num);
			box += 1;
		}
	}
}

void Matrix::BMultiplyA(int b[][4], int a[][4], HWND _hwnd, float box) {


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float num = 0;
			for (int k = 0; k < 4; k++) {
				num += b[i][k] * a[k][j];
			}
			WriteToEditBox(_hwnd, box, num);
			box += 1;
		}
	}
}

void Matrix::SetToI(std::array<float, 16> _arrayA, HWND _hwnd, float box, bool A) {

	float num = 0.0f;

	for (int i = 0; i < 16; i++) {

		num = _arrayA[i] = 0;
		WriteToEditBox(_hwnd, box, num);
		box++;
	}



	if (A == true) {
		box = 2000;
		num = _arrayA[0] = 1;
		WriteToEditBox(_hwnd, box, num);


		box = 2005;
		num = _arrayA[5] = 1;
		WriteToEditBox(_hwnd, box, num);

		box = 2010;
		num = _arrayA[10] = 1;
		WriteToEditBox(_hwnd, box, num);

		box = 2015;
		num = _arrayA[15] = 1;
		WriteToEditBox(_hwnd, box, num);
	}
	else {
		box = 1070;
		num = _arrayA[0] = 1;
		WriteToEditBox(_hwnd, box, num);


		box = 1075;
		num = _arrayA[5] = 1;
		WriteToEditBox(_hwnd, box, num);

		box = 1080;
		num = _arrayA[10] = 1;
		WriteToEditBox(_hwnd, box, num);

		box = 1085;
		num = _arrayA[15] = 1;
		WriteToEditBox(_hwnd, box, num);

	}

}

void Matrix::Inverse(int m[][4], HWND _hwnd, float box) {

	float value = 0;

	float num = m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
		m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
		m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
		m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
		m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
		m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
		m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
		m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
		m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
		m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
		m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
		m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
	//1
	value = (1 / num)*(m[1][1] * ((m[2][2] * m[3][3]) - (m[3][2] * m[2][3])) - m[1][2] * ((m[2][1] * m[3][3]) - (m[3][1] * m[2][3])) + m[1][3] * ((m[2][1] * m[3][2]) - (m[3][1] * m[2][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//2
	value = (-1 / num) * (m[0][1] * ((m[2][2] * m[3][3]) - (m[3][2] * m[2][3])) - m[0][2] * ((m[2][1] * m[3][3]) - (m[3][1] * m[2][3])) + m[0][3] * ((m[2][1] * m[3][2]) - (m[3][1] * m[2][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//3
	value = (1 / num)*(m[0][1] * ((m[1][2] * m[3][3]) - (m[3][2] * m[1][3])) - m[0][2] * ((m[1][1] * m[3][3]) - (m[3][1] * m[1][3])) + m[0][3] * ((m[1][1] * m[3][2]) - (m[3][1] * m[1][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//4
	value = (-1 / num)* (m[0][1] * ((m[1][2] * m[2][3]) - (m[2][2] * m[1][3])) - m[0][2] * ((m[1][1] * m[2][3]) - (m[2][1] * m[1][3])) + m[0][3] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//5
	value = (-1 / num)* (m[1][0] * ((m[2][2] * m[3][3]) - (m[3][2] * m[2][3])) - m[1][2] * ((m[2][0] * m[3][3]) - (m[3][0] * m[2][3])) + m[1][3] * ((m[2][0] * m[3][2]) - (m[3][0] * m[2][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//6
	value = (1 / num)*(m[0][0] * ((m[2][2] * m[3][3]) - (m[3][2] * m[2][3])) - m[0][2] * ((m[2][0] * m[3][3]) - (m[3][0] * m[2][3])) + m[0][3] * ((m[2][0] * m[3][2]) - (m[3][0] * m[2][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//7
	value = (-1 / num)* (m[0][0] * ((m[1][2] * m[3][3]) - (m[3][2] * m[1][3])) - m[0][2] * ((m[1][0] * m[3][3]) - (m[3][0] * m[1][3])) + m[0][3] * ((m[1][0] * m[3][2]) - (m[3][0] * m[1][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//8
	value = (1 / num)*(m[0][0] * ((m[1][2] * m[2][3]) - (m[2][2] * m[1][3])) - m[0][2] * ((m[1][0] * m[2][3]) - (m[2][0] * m[1][3])) + m[0][3] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//9
	value = (1 / num)*(m[1][0] * ((m[2][1] * m[3][3]) - (m[3][1] * m[2][3])) - m[1][1] * ((m[2][0] * m[3][3]) - (m[3][0] * m[2][3])) + m[1][3] * ((m[2][0] * m[3][1]) - (m[3][0] * m[2][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//10
	value = (-1 / num)* (m[0][0] * ((m[2][1] * m[3][3]) - (m[3][1] * m[2][3])) - m[0][1] * ((m[2][0] * m[3][3]) - (m[3][0] * m[2][3])) + m[0][3] * ((m[2][0] * m[3][1]) - (m[3][0] * m[2][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//11
	value = (1 / num)*(m[0][0] * ((m[1][1] * m[3][3]) - (m[3][1] * m[1][3])) - m[0][1] * ((m[1][0] * m[3][3]) - (m[3][0] * m[1][3])) + m[0][3] * ((m[1][0] * m[3][1]) - (m[3][0] * m[1][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//12
	value = (-1 / num)* (m[0][0] * ((m[1][1] * m[2][3]) - (m[2][1] * m[1][3])) - m[0][1] * ((m[1][0] * m[2][3]) - (m[2][0] * m[1][3])) + m[0][3] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//13
	value = (-1 / num)* (m[1][0] * ((m[2][1] * m[3][2]) - (m[3][1] * m[2][2])) - m[1][1] * ((m[2][0] * m[3][2]) - (m[3][0] * m[2][2])) + m[1][2] * ((m[2][0] * m[3][1]) - (m[3][0] * m[2][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//14
	value = (1 / num)*(m[0][0] * ((m[2][1] * m[3][2]) - (m[3][1] * m[2][2])) - m[0][1] * ((m[2][0] * m[3][2]) - (m[3][0] * m[2][2])) + m[0][2] * ((m[2][0] * m[3][1]) - (m[3][0] * m[2][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//15
	value = (-1 / num)* (m[0][0] * ((m[1][1] * m[3][2]) - (m[3][1] * m[1][2])) - m[0][1] * ((m[1][0] * m[3][2]) - (m[3][0] * m[1][2])) + m[0][2] * ((m[1][0] * m[3][1]) - (m[3][0] * m[1][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;
	//16
	value = (1 / num)*(m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2])) - m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])) + m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1])));
	WriteToEditBox(_hwnd, box, value);
	box++;

}

void Matrix::Determinant(int m[][4], HWND _hwnd, float box) {

	//4x4 matrix only
	float num = m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
		m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
		m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
		m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
		m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
		m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
		m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
		m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
		m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
		m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
		m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
		m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];


	WriteToEditBox(_hwnd, box, num);

}
