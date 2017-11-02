#ifndef A_MATRIX_2X4
#define A_MATRIX_2X4

#include "A_Vector4.h"

class A_Matrix2x4 {

public:

	/**
	default constructor
	*/
	A_Matrix2x4();

	/**
	copy constructor
	*/
	A_Matrix2x4(A_Matrix2x4* const _AM);

	/**
	uses the four matricies as the ROWS for this matrix
	*/
	A_Matrix2x4(A_Vector4* const _AV1, A_Vector4* const _AV2);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [8]
	*/
	A_Matrix2x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix2x4();

	/**
	returns the selected column
	the columns are 0, and 1
	*/
	const A_Vector2 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AV
	the columns are 0, and 1
	*/
	void SetColumnAtAddress(int _ad, A_Vector2* const _AV);

	/**
	returns the selected row
	the row are 0, and 1
	*/
	const A_Vector4 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AV
	the row are 0, 1
	*/
	void SetRowAtAddress(int _ad, A_Vector4* _AQ);

	/**
	returns the demension found at address _f
	*/
	const float GetDemensionAtAddress(char const _f) {

		return this->demensions[_f];

	}



private:

	//0 1 2 3
	//4 5 6 7
	float demensions[8];

};

#endif