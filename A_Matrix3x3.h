#ifndef A_MATRIX_3x3
#define A_MATRIX_3x3

#include "A_Vector3.h"

class A_Matrix3x3 {

public:

	/**
	initializes all values to 0
	*/
	A_Matrix3x3();

	/**
	initializes all values to _f
	0 for identity matrix
	*/
	A_Matrix3x3(float const _f);

	/**
	copy constructor
	*/
	A_Matrix3x3(A_Matrix3x3* const _AM);

	/**
	uses the three matricies as the ROWS for this matrix
	*/
	A_Matrix3x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3);

	/**
	uses the three matricies as the COLUMNS for this matrix
	*/
	A_Matrix3x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, char const unUsedColumnConstructor);

	/**
	assigns the dimensions of this matrix to the elements of _f, in order
	_f should be [9]
	*/
	A_Matrix3x3(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix3x3();

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
	the columns are 0, 1, and 2*/
	A_Vector3 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AV
	the columns are 0, 1, and 2
	*/
	void SetColumnAtAddress(int const _ad, A_Vector3* const _AV);

	/**
	returns the selected row
	the row are 0, 1, and 2
	*/
	A_Vector3 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AV
	the row are 0, 1, and 2
	*/
	void SetRowAtAddress(int _ad, A_Vector3* _AV);

	/**
	returns the dimension found at address _f
	*/
	const float GetDimensionAtAddress(int const _f) const {

		return this->dimensions[_f];

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
	const bool Invert();

	/**
	returns the transposed version of this matrix
	*/
	const A_Matrix3x3 GetTransposed();

	/**
	assings to this matrix, the transposed version of itself
	*/
	void SetTranposed();

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
	A_Matrix3x3 operator +(A_Matrix3x3& const _AM) {

		A_Matrix3x3 T_Result;

		for (char i = 0; i < 9; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] + _AM.dimensions[i];

		}

		return T_Result;

	}

	/**
	adds to this matrix another 4x4 matrix
	*/
	void operator +=(A_Matrix3x3& const _AM) {

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] += _AM.dimensions[i];

		}

	}

	/**
	subtracts from this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix3x3 operator -(A_Matrix3x3& const _AM) {

		A_Matrix3x3 T_Result;

		for (char i = 0; i < 9; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] - _AM.dimensions[i];

		}

		return T_Result;

	}

	/**
	subtracts from this matrix another 4x4 matrix
	*/
	void operator -=(A_Matrix3x3& const _AM) {

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] -= _AM.dimensions[i];

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

	/**
	multiplying this matrix by a scalar and returning the result
	*/
	A_Matrix3x3 operator *(float const _f) {

		A_Matrix3x3 T_Result;

		for (char i = 0; i < 9; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] * _f;

		}

		return T_Result;

	}

	/**
	multiplying this matrix by a scalar
	*/
	void operator *=(float const _f) {

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] *= _f;

		}

	}

	/**
	multiplying this matrix by a 3D vector and returning the result
	*/
	A_Vector3 operator *(A_Vector3& const _AV) {

		A_Vector3 T_Result;

		T_Result.setX((this->dimensions[0] * _AV.getX()) + (this->dimensions[1] * _AV.getY()) + (this->dimensions[2] * _AV.getZ()));
		T_Result.setY((this->dimensions[3] * _AV.getX()) + (this->dimensions[4] * _AV.getY()) + (this->dimensions[5] * _AV.getZ()));
		T_Result.setZ((this->dimensions[6] * _AV.getX()) + (this->dimensions[7] * _AV.getY()) + (this->dimensions[8] * _AV.getZ()));

		return T_Result;

	}

	/**
	multiplies THIS matrix by ANOTHER 3x3 matrix, resulting in a new 3x3 matrix
	*/
	A_Matrix3x3 operator *(A_Matrix3x3& const _AM) {

		A_Matrix3x3 T_Result;

		//https://wikimedia.org/api/rest_v1/media/math/render/svg/89622b95453d4895904dbd0c72e6beccbe63772c
		T_Result.dimensions[0] = this->dimensions[0] * _AM.dimensions[0] + this->dimensions[1] * _AM.dimensions[3] + this->dimensions[2] * _AM.dimensions[6];
		T_Result.dimensions[1] = this->dimensions[0] * _AM.dimensions[1] + this->dimensions[1] * _AM.dimensions[4] + this->dimensions[2] * _AM.dimensions[7];
		T_Result.dimensions[2] = this->dimensions[0] * _AM.dimensions[2] + this->dimensions[1] * _AM.dimensions[5] + this->dimensions[2] * _AM.dimensions[8];

		T_Result.dimensions[3] = this->dimensions[3] * _AM.dimensions[0] + this->dimensions[4] * _AM.dimensions[3] + this->dimensions[5] * _AM.dimensions[6];
		T_Result.dimensions[4] = this->dimensions[3] * _AM.dimensions[1] + this->dimensions[4] * _AM.dimensions[4] + this->dimensions[5] * _AM.dimensions[7];
		T_Result.dimensions[5] = this->dimensions[3] * _AM.dimensions[2] + this->dimensions[4] * _AM.dimensions[5] + this->dimensions[5] * _AM.dimensions[8];

		T_Result.dimensions[6] = this->dimensions[6] * _AM.dimensions[0] + this->dimensions[7] * _AM.dimensions[3] + this->dimensions[8] * _AM.dimensions[6];
		T_Result.dimensions[7] = this->dimensions[6] * _AM.dimensions[1] + this->dimensions[7] * _AM.dimensions[4] + this->dimensions[8] * _AM.dimensions[7];
		T_Result.dimensions[8] = this->dimensions[6] * _AM.dimensions[2] + this->dimensions[7] * _AM.dimensions[5] + this->dimensions[8] * _AM.dimensions[8];

		return T_Result;

	}

	/**
	multiplies this matrix by another 3x3 matrix, and applies the result to this matrix
	*/
	void operator *=(A_Matrix3x3& const _AM) {

		A_Matrix3x3 T_Result;

		//https://wikimedia.org/api/rest_v1/media/math/render/svg/89622b95453d4895904dbd0c72e6beccbe63772c
		T_Result.dimensions[0] = this->dimensions[0] * _AM.dimensions[0] + this->dimensions[1] * _AM.dimensions[3] + this->dimensions[2] * _AM.dimensions[6];
		T_Result.dimensions[1] = this->dimensions[0] * _AM.dimensions[1] + this->dimensions[1] * _AM.dimensions[4] + this->dimensions[2] * _AM.dimensions[7];
		T_Result.dimensions[2] = this->dimensions[0] * _AM.dimensions[2] + this->dimensions[1] * _AM.dimensions[5] + this->dimensions[2] * _AM.dimensions[8];

		T_Result.dimensions[3] = this->dimensions[3] * _AM.dimensions[0] + this->dimensions[4] * _AM.dimensions[3] + this->dimensions[5] * _AM.dimensions[6];
		T_Result.dimensions[4] = this->dimensions[3] * _AM.dimensions[1] + this->dimensions[4] * _AM.dimensions[4] + this->dimensions[5] * _AM.dimensions[7];
		T_Result.dimensions[5] = this->dimensions[3] * _AM.dimensions[2] + this->dimensions[4] * _AM.dimensions[5] + this->dimensions[5] * _AM.dimensions[8];

		T_Result.dimensions[6] = this->dimensions[6] * _AM.dimensions[0] + this->dimensions[7] * _AM.dimensions[3] + this->dimensions[8] * _AM.dimensions[6];
		T_Result.dimensions[7] = this->dimensions[6] * _AM.dimensions[1] + this->dimensions[7] * _AM.dimensions[4] + this->dimensions[8] * _AM.dimensions[7];
		T_Result.dimensions[8] = this->dimensions[6] * _AM.dimensions[2] + this->dimensions[7] * _AM.dimensions[5] + this->dimensions[8] * _AM.dimensions[8];

		*this = T_Result;

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

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] = _f;

		}

	}

	/**
	assigns to this matrix the values of another matrix
	*/
	void operator =(A_Matrix3x3 const *_AM) {

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] = _AM->dimensions[i];

		}

	}


private:

	//0 1 2
	//3 4 5
	//6 7 8
	float dimensions[9];

};

#endif