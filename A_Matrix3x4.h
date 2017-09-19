#ifndef A_MATRIX_3X4
#define A_MATRIX_3X4

#include "A_Vector4.h"

class A_Matrix3x4 {

public:

	/**
	default constructor
	*/
	A_Matrix3x4();

	/**
	copy constructor
	*/
	A_Matrix3x4(A_Matrix3x4* const _AM);

	/**
	uses the four matricies as the ROWS for this matrix
	*/
	A_Matrix3x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [12]
	*/
	A_Matrix3x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix3x4();

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1, and 2
	*/
	void SetRowAtAddress(int _ad, A_Vector4* const _AV);

	/**
	returns the demension found at address _f
	*/
	const float GetDemensionAtAddress(char const _f) {

		return this->demensions[_f];

	}

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	float demensions[12];

};


#endif