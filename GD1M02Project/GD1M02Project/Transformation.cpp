



#define WIN32_LEAN_AND_MEAN

#include "Transformation.h"
#include <windows.h>
#include <math.h>

//row major a11->a12->a13->a21->a22->a23
//column major a11->a21->a31->a41->a12->a22


void Transformation::Scaling(HWND _hwnd, float a11, float b12, float c13, float scaleX, float scaleY, float scaleZ, float _arrayA[], float box){

	float num = a11*scaleX;
	if (num == 0) {
		num = 1;
	}
	WriteToEditBox(_hwnd, IDC_EDIT47, num);

	num = b12*scaleY;
	if (num == 0) {
		num = 1;
	}
	WriteToEditBox(_hwnd, IDC_EDIT52, num);

	num = c13*scaleZ;
	if (num == 0) {
		num = 1;
	}
	WriteToEditBox(_hwnd, IDC_EDIT57, num); 

}

void Transformation::Rotation(HWND _hwnd, int axisOfRot, float angle){
	
	//rotation about x
	if (axisOfRot == 0) {
	
		//1,	0,		0
		//0,	cos,	-sin
		//0,	sin,	cos

		float num = cos(angle);
		WriteToEditBox(_hwnd, IDC_EDIT52, num);
		WriteToEditBox(_hwnd, IDC_EDIT57, num);
		num = sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT56, num);
		num = -sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT53, num);

	}
	//rotation about y
	if (axisOfRot == 1) {
	
		//cos,	0,	sin
		//0,	1,	0
		//-sin,	0,	cos
	
		float num = cos(angle);
		WriteToEditBox(_hwnd, IDC_EDIT47, num);
		WriteToEditBox(_hwnd, IDC_EDIT57, num);
		num = sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT49, num);
		num = -sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT55, num);

	}
	//rotation about z
	if (axisOfRot == 2) {
	
		//cos,	-sin,	0
		//sin,	cos,	0
		//0,	0,		1

		float num = cos(angle);
		WriteToEditBox(_hwnd, IDC_EDIT47, num);
		WriteToEditBox(_hwnd, IDC_EDIT52, num);
		num = sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT51, num);
		num = -sin(angle);
		WriteToEditBox(_hwnd, IDC_EDIT48, num);

	}



}

void Transformation::Translation(HWND _hwnd, float arrayA[], float a14, float b14, float c14, float transX, float transY, float transZ) {

	float box = 1047;

	float num = a14 + transX;
	WriteToEditBox(_hwnd, IDC_EDIT50, num);
	num = b14 + transY;
	WriteToEditBox(_hwnd, IDC_EDIT54, num);
	num = c14 + transZ;
	WriteToEditBox(_hwnd, IDC_EDIT58, num);

}

//TODO: Finish this
void Transformation::Projection(HWND _hwnd, float distance){

	float num = 1 / distance;

	WriteToEditBox(_hwnd, IDC_EDIT61, num);

	//   1/distancefromplayer


	WriteToEditBox(_hwnd, IDC_EDIT16, 4);
}

void Transformation::Compute(HWND _hwnd, float box){

	static float a11 = 1, a12 = 0, a13 = 0, a14 = 0;
	static float b11 = 0, b12 = 1, b13 = 0, b14 = 0;
	static float c11 = 0, c12 = 0, c13 = 1, c14 = 0;
	static float d11 = 0, d12 = 0, d13 = 0, d14 = 1;

	float arrayA1[16]{ a11, a12, a13, a14, b11, b12, b13, b14, c11, c12, c13, c14, d11, d12, d13, d14 };


	//sets identity matrix
	for (int i = 0; i < 16; i++) {
		float num = arrayA1[i];
		WriteToEditBox(_hwnd, box, num);
		box++;
	}


}
