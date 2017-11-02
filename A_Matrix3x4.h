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
	uses the three vectors as the ROWS for this matrix
	*/
	A_Matrix3x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3);

	/**
	use the four vectors as the COLUMNS for this matrix
	*/
	A_Matrix3x4(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, A_Vector3* const _AV4);

	/**
	assigns the dimensions of this matrix to the elements of _f, in order
	_f should be [12]
	*/
	A_Matrix3x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix3x4();

	/**
	returns the selected column
	the columns are 0, 1, 2, and 3
	*/
	const A_Vector3 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AV
	the columns are 0, 1, 2, and 3
	*/
	void SetColumnAtAddress(int const _ad, A_Vector3* const _AV);

	/**
	returns the selected row
	the rows are 0, 1, 2, and 3
	*/
	const A_Vector4 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AQ
	the rows are 0, 1, 2, and 3
	*/
	void SetRowAtAddress(int _ad, A_Vector4* const _AV);

	/**
	returns the dimension found at address _f
	*/
	const float GetDimensionAtAddress(char const _f) {

		return this->dimensions[_f];

	}

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	float dimensions[12];

};


#endif