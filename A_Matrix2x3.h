#ifndef A_MATRIX_2X3
#define A_MATRIX_2X3

#include "A_Vector3.h"

class A_Matrix2x3 {

public:

	/**
	default constructor
	*/
	A_Matrix2x3();

	/**
	copy constructor
	*/
	A_Matrix2x3(A_Matrix2x3* const _AM);

	/**
	uses the two matricies as the ROWS for this matrix
	*/
	A_Matrix2x3(A_Vector3* const _AV1, A_Vector3* const _AV2);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [6]
	*/
	A_Matrix2x3(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix2x3();

	const float GetDemensionAtAddress(char const _f) {

		return this->demensions[_f];

	}

private:

	//0 1 2
	//3 4 5
	float demensions[6];

};

#endif