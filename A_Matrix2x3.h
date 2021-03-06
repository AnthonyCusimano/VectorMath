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
	uses the two vectors as the ROWS for this matrix
	*/
	A_Matrix2x3(A_Vector3* const _AV1, A_Vector3* const _AV2);

	/**
	uses the three vectors as the COLUMNS for this matrix
	*/
	A_Matrix2x3(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3);

	/**
	assigns the dimensions of this matrix to the elements of _f, in order
	_f should be [6]
	*/
	A_Matrix2x3(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix2x3();

	/**
	returns the selected column
	the columns are 0, 1, and 2
	*/
	const A_Vector2 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AV
	the columns are 0, 1, and 2
	*/
	void SetColumnAtAddress(int const _ad, A_Vector2* const _AV);

	/**
	returns the selected row
	the row are 0, 1
	*/
	const A_Vector3 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AV
	the row are 0, 1
	*/
	void SetRowAtAddress(int _ad, A_Vector3* const _AV);


	/**
	returns the dimension found at address _f
	*/
	const float GetDimensionAtAddress(char const _f) {

		return this->dimensions[_f];

	}

private:

	//0 1 2
	//3 4 5
	float dimensions[6];

};

#endif