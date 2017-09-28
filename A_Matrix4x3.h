#ifndef A_MATRIX_4X3
#define A_MATRIX_4X3

#include "A_Vector3.h"

class A_Matrix4x3 {

public:

	/**
	default constructor
	*/
	A_Matrix4x3();

	/**
	copy constructor
	*/
	A_Matrix4x3(A_Matrix4x3* const _AM);

	/**
	uses the four matricies as the ROWS for this matrix
	*/
	A_Matrix4x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, A_Vector3* const _AV4);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [12]
	*/
	A_Matrix4x3(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix4x3();

	/**
	sets the selected row to the values in _AV
	the row are 0, 1, 2, and 3
	*/
	void SetRowAtAddress(int _ad, A_Vector3* const _AV);

	/**
	returns the demension found at address _f
	*/
	const float GetDemensionAtAddress(char const _f) {

		return this->demensions[_f];

	}

private:

	//1 2 3
	//4 5 6
	//7 8 9
	//A B C
	float demensions[12];

};

#endif