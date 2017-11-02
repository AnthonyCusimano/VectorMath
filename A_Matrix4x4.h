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
	uses the four vectors as the ROWS for this matrix
	*/
	A_Matrix4x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3, A_Vector4* const _AV4);

	/**
	uses the four vectors as the COLUMNS for this matrix
	*/
	A_Matrix4x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3, A_Vector4* const _AV4, char const unUsedColumnConstructor);

	/**
	assigns the dimensions of this matrix to the elements of _f, in order
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
	A_Vector4 GetColumnAtAddress(int const _ad);

	/**
	sets the selected column to the values in _AQ
	the columns are 0, 1, 2, and 3
	*/
	void SetColumnAtAddress(int const _ad, A_Vector4* _AQ);

	/**
	returns the selected row
	the row are 0, 1, 2, and 3
	*/
	A_Vector4 GetRowAtAddress(int _ad);

	/**
	sets the selected row to the values in _AQ
	the row are 0, 1, 2, and 3
	*/
	void SetRowAtAddress(int _ad, A_Vector4* _AQ);

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
	void SetIdentity();

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
	A_Matrix4x4 GetRotationXAxis(float const _f);

	/**
	returns a matrix rotated about the Y axis by _f
	_f is a degree amount
	*/
	A_Matrix4x4 GetRotationYAxis(float const _f);

	/**
	returns a matrix rotated about the Z axis by _f
	_f is a degree amount
	*/
	A_Matrix4x4 GetRotationZAxis(float const _f);

	/**
	returns an identity matrix translated by the values of _x, _y, and _z
	*/
	A_Matrix4x4 GetTranslate(float const _x, float const _y, float const _z);

	/**
	returns an identity matrix translated by the values of _AV
	*/
	A_Matrix4x4 GetTranslate(A_Vector3 const *_AV);

	/**
	returns an identity matrix scaled by the values of _x, _y, and _z
	*/
	A_Matrix4x4 GetScale(float const _x, float const _y, float const _z);

	/**
	returns an identity matrix scaled by the values of _AV
	*/
	A_Matrix4x4 GetScale(A_Vector3* const _AV);

	/**
	tests to make sure the matrix can be inverted, and inverts it if it can (then returns true) if not, method returns false
	*/
	const bool Invert();

	/**
	returns the transposed version of this matrix
	*/
	A_Matrix4x4 GetTransposed();

	/**
	assings to this matrix, the transposed version of itself
	*/
	void SetTranposed();

	/**
	sets this quaternion to the viewspace of a camera in 3D space
	_pos (of the viewpoint) _viewDir (direction camera faces) _up and _right is 
	*/
	void SetViewMatrix(A_Vector3* const _pos, A_Vector3* const _viewDir, A_Vector3* const _up, A_Vector3* const _right);

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
	A_Matrix4x4 operator +(A_Matrix4x4& const _AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] + _AM.dimensions[i];

		}

		return T_Result;

	}

	/**
	adds to this matrix another 4x4 matrix
	*/
	void operator +=(A_Matrix4x4& const _AM) {

		for (char i = 0; i < 16; ++i) {

			this->dimensions[i] += _AM.dimensions[i];

		}

	}

	/**
	subtracts from this matrix another 4x4 matrix and returns the result
	*/
	A_Matrix4x4 operator -(A_Matrix4x4& const _AM) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] - _AM.dimensions[i];

		}

		return T_Result;

	}

	/**
	subtracts from this matrix another 4x4 matrix
	*/
	void operator -=(A_Matrix4x4& const _AM) {

		for (char i = 0; i < 16; ++i) {

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
	A_Matrix4x4 operator *(float const _f) {

		A_Matrix4x4 T_Result;

		for (char i = 0; i < 16; ++i) {

			T_Result.dimensions[i] = this->dimensions[i] * _f;

		}
		
		return T_Result;

	}

	/**
	multiplies THIS matrix by ANOTHER 4x4 matrix, resulting in a new 4x4 matrix
	*/
	A_Matrix4x4 operator *(A_Matrix4x4& const _AM) {

	A_Matrix4x4 T_Result;

		//https://wikimedia.org/api/rest_v1/media/math/render/svg/89622b95453d4895904dbd0c72e6beccbe63772c
		T_Result.dimensions[0] = this->dimensions[0] * _AM.dimensions[0] + this->dimensions[1] * _AM.dimensions[4] + this->dimensions[2] * _AM.dimensions[8] + this->dimensions[3] * _AM.dimensions[12];
		T_Result.dimensions[1] = this->dimensions[0] * _AM.dimensions[1] + this->dimensions[1] * _AM.dimensions[5] + this->dimensions[2] * _AM.dimensions[9] + this->dimensions[3] * _AM.dimensions[13];
		T_Result.dimensions[2] = this->dimensions[0] * _AM.dimensions[2] + this->dimensions[1] * _AM.dimensions[6] + this->dimensions[2] * _AM.dimensions[10] + this->dimensions[3] * _AM.dimensions[14];
		T_Result.dimensions[3] = this->dimensions[0] * _AM.dimensions[3] + this->dimensions[1] * _AM.dimensions[7] + this->dimensions[2] * _AM.dimensions[11] + this->dimensions[3] * _AM.dimensions[15];
		
		T_Result.dimensions[4] = this->dimensions[4] * _AM.dimensions[0] + this->dimensions[5] * _AM.dimensions[4] + this->dimensions[6] * _AM.dimensions[8] + this->dimensions[7] * _AM.dimensions[12];
		T_Result.dimensions[5] = this->dimensions[4] * _AM.dimensions[1] + this->dimensions[5] * _AM.dimensions[5] + this->dimensions[6] * _AM.dimensions[9] + this->dimensions[7] * _AM.dimensions[13];
		T_Result.dimensions[6] = this->dimensions[4] * _AM.dimensions[2] + this->dimensions[5] * _AM.dimensions[6] + this->dimensions[6] * _AM.dimensions[10] + this->dimensions[7] * _AM.dimensions[14];
		T_Result.dimensions[7] = this->dimensions[4] * _AM.dimensions[3] + this->dimensions[5] * _AM.dimensions[7] + this->dimensions[6] * _AM.dimensions[11] + this->dimensions[7] * _AM.dimensions[15];

		T_Result.dimensions[8] = this->dimensions[8] * _AM.dimensions[0] + this->dimensions[9] * _AM.dimensions[4] + this->dimensions[10] * _AM.dimensions[8] + this->dimensions[11] * _AM.dimensions[12];
		T_Result.dimensions[9] = this->dimensions[8] * _AM.dimensions[1] + this->dimensions[9] * _AM.dimensions[5] + this->dimensions[10] * _AM.dimensions[9] + this->dimensions[11] * _AM.dimensions[13];
		T_Result.dimensions[10] = this->dimensions[8] * _AM.dimensions[2] + this->dimensions[9] * _AM.dimensions[6] + this->dimensions[10] * _AM.dimensions[10] + this->dimensions[11] * _AM.dimensions[14];
		T_Result.dimensions[11] = this->dimensions[8] * _AM.dimensions[3] + this->dimensions[9] * _AM.dimensions[7] + this->dimensions[10] * _AM.dimensions[11] + this->dimensions[11] * _AM.dimensions[15];

		T_Result.dimensions[12] = this->dimensions[12] * _AM.dimensions[0] + this->dimensions[13] * _AM.dimensions[4] + this->dimensions[14] * _AM.dimensions[8] + this->dimensions[15] * _AM.dimensions[12];
		T_Result.dimensions[13] = this->dimensions[12] * _AM.dimensions[1] + this->dimensions[13] * _AM.dimensions[5] + this->dimensions[14] * _AM.dimensions[9] + this->dimensions[15] * _AM.dimensions[13];
		T_Result.dimensions[14] = this->dimensions[12] * _AM.dimensions[2] + this->dimensions[13] * _AM.dimensions[6] + this->dimensions[14] * _AM.dimensions[10] + this->dimensions[15] * _AM.dimensions[14];
		T_Result.dimensions[15] = this->dimensions[12] * _AM.dimensions[3] + this->dimensions[13] * _AM.dimensions[7] + this->dimensions[14] * _AM.dimensions[11] + this->dimensions[15] * _AM.dimensions[15];
		
	return T_Result;

	}

	/**
	multiplies this matrix by a 4 dimensional vector
	*/
	A_Vector4 operator *(A_Vector4& const _AV){
	
	A_Vector4 T_Result;

	T_Result.setX((_AV.getX() * this->dimensions[0]) + (_AV.getY() * this->dimensions[1]) + (_AV.getZ() * this->dimensions[2]) + this->dimensions[3] * _AV.getW());
	T_Result.setY((_AV.getX() * this->dimensions[4]) + (_AV.getY() * this->dimensions[5]) + (_AV.getZ() * this->dimensions[6]) + this->dimensions[7] * _AV.getW());
	T_Result.setZ((_AV.getX() * this->dimensions[8]) + (_AV.getY() * this->dimensions[9]) + (_AV.getZ() * this->dimensions[10]) + this->dimensions[11] * _AV.getW());
	T_Result.setW((_AV.getX() * this->dimensions[12]) + (_AV.getY() * this->dimensions[13]) + (_AV.getZ() * this->dimensions[14]) + this->dimensions[15] * _AV.getW());

	return T_Result;

	}

	/**
	multiplying this matrix by a scalar
	*/
	void operator *=(float const _f) {

		for (char i = 0; i < 16; ++i) {

			this->dimensions[i] *= _f;

		}

	}

	/**
	multiplies this matrix by another 4x4 matrix, and applies the result to this matrix
	*/
	void operator *=(A_Matrix4x4& const _AM) {

		this->dimensions[0] = this->dimensions[0] * _AM.dimensions[0] + this->dimensions[1] * _AM.dimensions[4] + this->dimensions[2] * _AM.dimensions[8] + this->dimensions[3] * _AM.dimensions[12];
		this->dimensions[1] = this->dimensions[0] * _AM.dimensions[1] + this->dimensions[1] * _AM.dimensions[5] + this->dimensions[2] * _AM.dimensions[9] + this->dimensions[3] * _AM.dimensions[13];
		this->dimensions[2] = this->dimensions[0] * _AM.dimensions[2] + this->dimensions[1] * _AM.dimensions[6] + this->dimensions[2] * _AM.dimensions[10] + this->dimensions[3] * _AM.dimensions[14];
		this->dimensions[3] = this->dimensions[0] * _AM.dimensions[3] + this->dimensions[1] * _AM.dimensions[7] + this->dimensions[2] * _AM.dimensions[11] + this->dimensions[3] * _AM.dimensions[15];

		this->dimensions[4] = this->dimensions[4] * _AM.dimensions[0] + this->dimensions[5] * _AM.dimensions[4] + this->dimensions[6] * _AM.dimensions[8] + this->dimensions[7] * _AM.dimensions[12];
		this->dimensions[5] = this->dimensions[4] * _AM.dimensions[1] + this->dimensions[5] * _AM.dimensions[5] + this->dimensions[6] * _AM.dimensions[9] + this->dimensions[7] * _AM.dimensions[13];
		this->dimensions[6] = this->dimensions[4] * _AM.dimensions[2] + this->dimensions[5] * _AM.dimensions[6] + this->dimensions[6] * _AM.dimensions[10] + this->dimensions[7] * _AM.dimensions[14];
		this->dimensions[7] = this->dimensions[4] * _AM.dimensions[3] + this->dimensions[5] * _AM.dimensions[7] + this->dimensions[6] * _AM.dimensions[11] + this->dimensions[7] * _AM.dimensions[15];

		this->dimensions[8] = this->dimensions[8] * _AM.dimensions[0] + this->dimensions[9] * _AM.dimensions[4] + this->dimensions[10] * _AM.dimensions[8] + this->dimensions[11] * _AM.dimensions[12];
		this->dimensions[9] = this->dimensions[8] * _AM.dimensions[1] + this->dimensions[9] * _AM.dimensions[5] + this->dimensions[10] * _AM.dimensions[9] + this->dimensions[11] * _AM.dimensions[13];
		this->dimensions[10] = this->dimensions[8] * _AM.dimensions[2] + this->dimensions[9] * _AM.dimensions[6] + this->dimensions[10] * _AM.dimensions[10] + this->dimensions[11] * _AM.dimensions[14];
		this->dimensions[11] = this->dimensions[8] * _AM.dimensions[3] + this->dimensions[9] * _AM.dimensions[7] + this->dimensions[10] * _AM.dimensions[11] + this->dimensions[11] * _AM.dimensions[15];

		this->dimensions[12] = this->dimensions[12] * _AM.dimensions[0] + this->dimensions[13] * _AM.dimensions[4] + this->dimensions[14] * _AM.dimensions[8] + this->dimensions[15] * _AM.dimensions[12];
		this->dimensions[13] = this->dimensions[12] * _AM.dimensions[1] + this->dimensions[13] * _AM.dimensions[5] + this->dimensions[14] * _AM.dimensions[9] + this->dimensions[15] * _AM.dimensions[13];
		this->dimensions[14] = this->dimensions[12] * _AM.dimensions[2] + this->dimensions[13] * _AM.dimensions[6] + this->dimensions[14] * _AM.dimensions[10] + this->dimensions[15] * _AM.dimensions[14];
		this->dimensions[15] = this->dimensions[12] * _AM.dimensions[3] + this->dimensions[13] * _AM.dimensions[7] + this->dimensions[14] * _AM.dimensions[11] + this->dimensions[15] * _AM.dimensions[15];

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

			this->dimensions[i] = _f;

		}

	}

	/**
	assigns to this matrix the values of another matrix
	*/
	void operator =(A_Matrix4x4& const _AM) {

		for (char i = 0; i < 16; ++i) {

			this->dimensions[i] = _AM.dimensions[i];

		}

	}
	

private:

	//0 1 2 3
	//4 5 6 7
	//8 9 A B
	//C D E F
	float dimensions[16];

};

#endif