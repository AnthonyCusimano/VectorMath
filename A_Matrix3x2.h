#ifndef A_MATRIX_3X2
#define A_MATRIX_3X2

#include "A_Vector2.h"

class A_Matrix3x2 {

public:

	/**
	default constructor
	*/
	A_Matrix3x2();

	/**
	copy constructor
	*/
	A_Matrix3x2(A_Matrix3x2* const _AM);

	/**
	uses the three matricies as the ROWS for this matrix
	*/
	A_Matrix3x2(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [6]
	*/
	A_Matrix3x2(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix3x2();

	/**
	returns the selected row
	the row are 0, 1, and 2
	*/
	const A_Vector2 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1, and 2
	*/
	void SetRowAtAddress(int _ad, A_Vector2* const _AV);

	/**
	returns the demension found at address _f
	*/
	const float GetDemensionAtAddress(char const _f) {

		return this->demensions[_f];

	}

private:

	//0 1
	//2 3
	//4 5
	float demensions[6];

};

#endif