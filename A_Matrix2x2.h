#ifndef A_MATRIX_2X2
#define A_MATRIX_2X2

#include "A_Vector2.h"

class A_Matrix2x2 {

public:

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************Constructors, destructor******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	initializes all values to 0
	*/
	A_Matrix2x2();

	/**
	initializes all values to _f
	0 for identity matrix
	*/
	A_Matrix2x2(float const _f);

	/**
	copy constructor
	*/
	A_Matrix2x2(A_Matrix2x2* const _AM);

	/**
	uses the two vectors as the ROWS for this matrix
	*/
	A_Matrix2x2(A_Vector2* const _AV1, A_Vector2* const _AV2);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [4]
	*/
	A_Matrix2x2(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix2x2();

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*******************Member access*************************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	returns the selected column
	the columns are 0, 1
	*/
	const A_Vector2 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AQ
	the columns are 0, 1
	*/
	void SetColumnAtAddress(int const _ad, A_Vector2 * _AQ);

	/**
	returns the selected row
	the row are 0, 1
	*/
	const A_Vector2 GetRowAtAddress(int const _ad);

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1
	*/
	void SetRowAtAddress(int _ad, A_Vector2* const _AQ);

	/**
	returns the demension found at address _f
	*/
	const float GetDemensionAtAddress(int const _f) const {

		return this->demensions[_f];

	}

	/**
	sets the object this matrix POINTER is assigned to, to the identity matrix
	this method will not function when using an object directly
	*/
	void setIdentity();

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*****************matrix operations***********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	tests to make sure the matrix can be inverted, and inverts it if it can (then returns true) if not, method returns false
	*/
	void Invert();

	/**
	returns the transposed version of this matrix
	*/
	const A_Matrix2x2 GetTransposed();

	/**
	assings to this matrix, the transposed version of itself
	*/
	void SetTranposed();


	//TODO: all 2D matrix operators

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*********addition  & subtraction operators***************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	adds to this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix2x2 operator +(A_Matrix2x2& const _AM) {

		A_Matrix2x2 T_Result;

		for (char i = 0; i < 4; ++i) {

			T_Result.demensions[i] = this->demensions[i] + _AM.demensions[i];

		}

		return T_Result;

	}

	/**
	adds to this matrix another 4x4 matrix
	*/
	void operator +=(A_Matrix2x2& const _AM) {

		for (char i = 0; i < 4; ++i) {

			this->demensions[i] += _AM.demensions[i];

		}

	}

	/**
	subtracts from this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix2x2 operator -(A_Matrix2x2& const _AM) {

		A_Matrix2x2 T_Result;

		for (char i = 0; i < 4; ++i) {

			T_Result.demensions[i] = this->demensions[i] - _AM.demensions[i];

		}

		return T_Result;

	}

	/**
	subtracts from this matrix another 4x4 matrix
	*/
	void operator -=(A_Matrix2x2& const _AM) {

		for (char i = 0; i < 4; ++i) {

			this->demensions[i] -= _AM.demensions[i];

		}

	}

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************multiplication operators******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/*

	TODO: ADD SUPPORT FOR OTHER x2 SIZE MATRICIES

	*/

	/**
	multiplying this matrix by a scalar and returning the result
	*/
	A_Matrix2x2 operator *(float const _f) {

		A_Matrix2x2 T_Result;

		for (char i = 0; i < 4; ++i) {

			T_Result.demensions[i] = this->demensions[i] * _f;

		}

		return T_Result;

	}

	/**
	multiplying this matrix by a scalar
	*/
	void operator *=(float const _f) {

		for (char i = 0; i < 4; ++i) {

			this->demensions[i] *= _f;

		}

	}

	/**
	multiplying this matrix by a 2D vector and returning the result
	*/
	A_Vector2 operator *(A_Vector2& const _AV) {

		A_Vector2 T_Result;

		T_Result.setX((this->demensions[0] * _AV.getX()) + (this->demensions[1] * _AV.getY()));
		T_Result.setY((this->demensions[3] * _AV.getX()) + (this->demensions[4] * _AV.getY()));

		return T_Result;

	}

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************assignment operators**********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	assigns to each value of this matrix _f
	*/
	void operator =(float const _f) {

		for (char i = 0; i < 4; ++i) {

			this->demensions[i] = _f;

		}

	}

	/**
	assigns to this matrix the values of another matrix
	*/
	void operator =(A_Matrix2x2 const *_AM) {

		for (char i = 0; i < 4; ++i) {

			this->demensions[i] = _AM->demensions[i];

		}

	}

private:

	//0 1
	//2 3
	float demensions[4];

};

#endif