#ifndef A_MATRIX_4X3
#define A_MATRIX_4X3

#include "A_Vector4.h"

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
	uses the four vectors as the ROWS for this matrix
	*/
	A_Matrix4x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, A_Vector3* const _AV4);

	/**
	uses the three vectors as the COLUMNS for this matrix
	*/
	A_Matrix4x3(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3);

	/**
	assigns the dimensions of this matrix to the elements of _f, in order
	_f should be [12]
	*/
	A_Matrix4x3(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix4x3();

	/**
	returns the selected column
	the columns are 0, and 1
	*/
	const A_Vector4 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AV
	the columns are 0, 1, and 3
	*/
	void SetColumnAtAddress(int const _ad, A_Vector4* const _AV);

	/**
	returns the selected row
	the rows are 0, 1, 2, and 3
	*/
	const A_Vector3 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AV
	the rows are 0, 1, 2, and 3
	*/
	void SetRowAtAddress(int _ad, A_Vector3* const _AV);

	/**
	returns the dimension found at address _f
	*/
	const float GetDimensionAtAddress(char const _f) {

		return this->dimensions[_f];

	}

private:

	//1 2 3
	//4 5 6
	//7 8 9
	//A B C
	float dimensions[12];

};

#endif