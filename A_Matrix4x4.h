#ifndef A_MATRIX_4X4
#define A_MATRIX_4X4

#include "A_Quaternion.h"

class A_Matrix4x4 {

	/**
	initializes all values to 0
	*/
	A_Matrix4x4();

	/**
	initializes all values to _f
	0 for identity matrix
	*/
	A_Matrix4x4(float const _f);

	/**
	copy constructor
	*/
	A_Matrix4x4(A_Matrix4x4 const *_AM);

	/**
	uses the four quaternions as the ROWS for this matrix
	*/
	A_Matrix4x4(A_Quaternion *_AQ1, A_Quaternion *_AQ2, A_Quaternion *_AQ3, A_Quaternion *_AQ4);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	*/
	A_Matrix4x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix4x4();

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	//C D E F
	float demensions[16];

};

#endif