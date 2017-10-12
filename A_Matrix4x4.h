#ifndef A_MATRIX_4X4
#define A_MATRIX_4X4

#include "A_Quaternion.h"

class A_Matrix4x4 {

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
	A_Matrix4x4();

	/**
	initializes all values to _f
	0 for identity matrix
	*/
	A_Matrix4x4(float const _f);

	/**
	copy constructor
	*/
	A_Matrix4x4(A_Matrix4x4* const _AM);

	/**
	uses the four quaternions as the ROWS for this matrix
	*/
	A_Matrix4x4(A_Vector4* const _AQ1, A_Vector4* const _AQ2, A_Vector4* const _AQ3, A_Vector4* const _AQ4);

	/**
	assigns the demensions of this matrix to the elements of _f, in order
	_f should be [16]
	*/
	A_Matrix4x4(float const _f[]);

	/**
	destructor
	*/
	~A_Matrix4x4();

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
	the columns are 0, 1, 2, and 3
	*/
	const A_Vector4 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AQ
	the columns are 0, 1, 2, and 3
	*/
	void SetColumnAtAddress(int const _ad, A_Vector4* _AQ);

	/**
	returns the selected row
	the row are 0, 1, 2, and 3
	*/
	const A_Vector4 GetRowAtAddress(int const _ad);

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1, 2, and 3
	*/
	void SetRowAtAddress(int const _ad, A_Vector4* _AQ);

	/**
	returns the demension found at address _f
	*/
	const float getDemensionAtAddress(int const _f) const {

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
	returns a matrix rotated about the X axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationXAxis(float const _f);

	/**
	returns a matrix rotated about the Y axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationYAxis(float const _f);

	/**
	returns a matrix rotated about the Z axis by _f
	_f is a degree amount
	*/
	const A_Matrix4x4 GetRotationZAxis(float const _f);

	/**
	returns an identity matrix translated by the values of _x, _y, and _z
	*/
	const A_Matrix4x4 GetTranslate(float const _x, float const _y, float const _z);

	/**
	returns an identity matrix translated by the values of _AV
	*/
	const A_Matrix4x4 GetTranslate(A_Vector3 const *_AV);

	/**
	returns an identity matrix scaled by the values of _x, _y, and _z
	*/
	const A_Matrix4x4 GetScale(float const _x, float const _y, float const _z);

	/**
	returns an identity matrix scaled by the values of _AV
	*/
	const A_Matrix4x4 GetScale(A_Vector3* const _AV);

	/**
	tests to make sure the matrix can be inverted, and inverts it if it can (then returns true) if not, method returns false
	*/
	const bool Invert();

	/**
	returns the transposed version of this matrix
	*/
	const A_Matrix4x4 GetTransposed();

	/**
	assings to this matrix, the transposed version of itself
	*/
	void SetTranposed();

	/**
	sets this quaternion to the viewspace of a camera in 3D space
	_pos (of the viewpoint) _viewDir (direction camera faces) _up and _right is 
	*/
	void SetViewMatrix(A_Vector3 const *_pos, A_Vector3 const *_viewDir, A_Vector3 const *_up, A_Vector3 const *_right);

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
	A_Matrix4x4 operator +(A_Matrix4x4 const *_AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] + _AM->demensions[i];

		}

		return T_Result;

	}

	/**
	adds to this matrix another 4x4 matrix
	*/
	void operator +=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] += _AM->demensions[i];

		}

	}

	/**
	subtracts from this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix4x4 operator -(A_Matrix4x4 const *_AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] - _AM->demensions[i];

		}

		return T_Result;

	}

	/**
	subtracts from this matrix another 4x4 matrix
	*/
	void operator -=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] -= _AM->demensions[i];

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
	
	TODO: ADD SUPPORT FOR OTHER x4 SIZE MATRICIES
	
	*/

	/**
	multiplying this matrix by a scalar and returning the result
	*/
	A_Matrix4x4 operator *(float const _f) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.demensions[i] = this->demensions[i] * _f;

		}
		
		return T_Result;

	}

	/**
	multiplies THIS matrix by ANOTHER 4x4 matrix, resulting in a new 4x4 matrix
	*/
	A_Matrix4x4 operator *(A_Matrix4x4 const *_AM) {

	A_Matrix4x4 T_Result;

		//https://wikimedia.org/api/rest_v1/media/math/render/svg/89622b95453d4895904dbd0c72e6beccbe63772c
		T_Result.demensions[0] = this->demensions[0] * _AM->demensions[0] + this->demensions[1] * _AM->demensions[4] + this->demensions[2] * _AM->demensions[8] + this->demensions[3] * _AM->demensions[12];
		T_Result.demensions[1] = this->demensions[0] * _AM->demensions[1] + this->demensions[1] * _AM->demensions[5] + this->demensions[2] * _AM->demensions[9] + this->demensions[3] * _AM->demensions[13];
		T_Result.demensions[2] = this->demensions[0] * _AM->demensions[2] + this->demensions[1] * _AM->demensions[6] + this->demensions[2] * _AM->demensions[10] + this->demensions[3] * _AM->demensions[14];
		T_Result.demensions[3] = this->demensions[0] * _AM->demensions[3] + this->demensions[1] * _AM->demensions[7] + this->demensions[2] * _AM->demensions[11] + this->demensions[3] * _AM->demensions[15];
		
		T_Result.demensions[4] = this->demensions[4] * _AM->demensions[0] + this->demensions[5] * _AM->demensions[4] + this->demensions[6] * _AM->demensions[8] + this->demensions[7] * _AM->demensions[12];
		T_Result.demensions[5] = this->demensions[4] * _AM->demensions[1] + this->demensions[5] * _AM->demensions[5] + this->demensions[6] * _AM->demensions[9] + this->demensions[7] * _AM->demensions[13];
		T_Result.demensions[6] = this->demensions[4] * _AM->demensions[2] + this->demensions[5] * _AM->demensions[6] + this->demensions[6] * _AM->demensions[10] + this->demensions[7] * _AM->demensions[14];
		T_Result.demensions[7] = this->demensions[4] * _AM->demensions[3] + this->demensions[5] * _AM->demensions[7] + this->demensions[6] * _AM->demensions[11] + this->demensions[7] * _AM->demensions[15];

		T_Result.demensions[8] = this->demensions[8] * _AM->demensions[0] + this->demensions[9] * _AM->demensions[4] + this->demensions[10] * _AM->demensions[8] + this->demensions[11] * _AM->demensions[12];
		T_Result.demensions[9] = this->demensions[8] * _AM->demensions[1] + this->demensions[9] * _AM->demensions[5] + this->demensions[10] * _AM->demensions[9] + this->demensions[11] * _AM->demensions[13];
		T_Result.demensions[10] = this->demensions[8] * _AM->demensions[2] + this->demensions[9] * _AM->demensions[6] + this->demensions[10] * _AM->demensions[10] + this->demensions[11] * _AM->demensions[14];
		T_Result.demensions[11] = this->demensions[8] * _AM->demensions[3] + this->demensions[9] * _AM->demensions[7] + this->demensions[10] * _AM->demensions[11] + this->demensions[11] * _AM->demensions[15];

		T_Result.demensions[12] = this->demensions[12] * _AM->demensions[0] + this->demensions[13] * _AM->demensions[4] + this->demensions[14] * _AM->demensions[8] + this->demensions[15] * _AM->demensions[12];
		T_Result.demensions[13] = this->demensions[12] * _AM->demensions[1] + this->demensions[13] * _AM->demensions[5] + this->demensions[14] * _AM->demensions[9] + this->demensions[15] * _AM->demensions[13];
		T_Result.demensions[14] = this->demensions[12] * _AM->demensions[2] + this->demensions[13] * _AM->demensions[6] + this->demensions[14] * _AM->demensions[10] + this->demensions[15] * _AM->demensions[14];
		T_Result.demensions[15] = this->demensions[12] * _AM->demensions[3] + this->demensions[13] * _AM->demensions[7] + this->demensions[14] * _AM->demensions[11] + this->demensions[15] * _AM->demensions[15];
		
	return T_Result;

	}

	/**
	multiplies this matrix by a 3 demensional vector
	*/
	A_Vector3 operator *(A_Vector3 const *_AV) {

		A_Vector3 T_Result;

		T_Result.setX((_AV->getX() * this->demensions[0]) + (_AV->getY() * this->demensions[1]) + (_AV->getZ() * this->demensions[2]) + this->demensions[3]);
		T_Result.setY((_AV->getX() * this->demensions[4]) + (_AV->getY() * this->demensions[5]) + (_AV->getZ() * this->demensions[6]) + this->demensions[7]);
		T_Result.setZ((_AV->getX() * this->demensions[8]) + (_AV->getY() * this->demensions[9]) + (_AV->getZ() * this->demensions[10]) + this->demensions[11]);

		return T_Result;

	}

	/**
	multiplies this matrix by a 4 demensional vector
	*/
	A_Vector4 operator *(A_Vector4* const _AV){
	
	A_Vector4 T_Result;

	T_Result.setX((_AV->getX() * this->demensions[0]) + (_AV->getY() * this->demensions[1]) + (_AV->getZ() * this->demensions[2]) + this->demensions[3]);
	T_Result.setY((_AV->getX() * this->demensions[4]) + (_AV->getY() * this->demensions[5]) + (_AV->getZ() * this->demensions[6]) + this->demensions[7]);
	T_Result.setZ((_AV->getX() * this->demensions[8]) + (_AV->getY() * this->demensions[9]) + (_AV->getZ() * this->demensions[10]) + this->demensions[11]);
	T_Result.setW((_AV->getX() * this->demensions[12]) + (_AV->getY() * this->demensions[13]) + (_AV->getZ() * this->demensions[14]) + this->demensions[15]);

	return T_Result;

	}

	/**
	multiplying this matrix by a scalar
	*/
	void operator *=(float const _f) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] *= _f;

		}

	}

	/**
	multiplies this matrix by another 4x4 matrix, and applies the result to this matrix
	*/
	void operator *=(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] *= _AM->demensions[i];

		}

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

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _f;

		}

	}

	/**
	assigns to this matrix the values of another matrix
	*/
	void operator =(A_Matrix4x4 const *_AM) {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _AM->demensions[i];

		}

	}
	

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	//C D E F
	float demensions[16];

};

#endif