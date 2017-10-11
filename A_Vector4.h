#ifndef A_VECTOR_4
#define A_VECTOR_4

#include "A_Vector3.h"

class A_Vector4 {

public:

	/*
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***********Constructors and destructor*******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	default constructor
	initializes demensions to 0
	*/
	A_Vector4();

	/**
	initializes each demension to _n
	*/
	A_Vector4(float const n);

	/**
	copy constructor
	initializes demensions to the values of _AV
	*/
	A_Vector4(A_Vector4* const _AV);

	/**
	constructor initializes demensions to the corresponding arguments
	*/
	A_Vector4(float const _x, float const _y, float const _z, float const _w);

	/**
	constructor copies X and Y values of AV to this
	and uses _z and _w to fill out the vector
	*/
	A_Vector4(A_Vector2* const _AV, float const _z, float const _w);

	/**
	constructor copies X, Y, and values of AV to this
	and uses _w to fill out the vector
	*/
	A_Vector4(A_Vector3* const _AV, float const _w);

	/**
	destructor
	*/
	~A_Vector4();

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*****************vector operations***********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	getting this vector's magnatude
	*/
	float GetMagnatude();

	/**
	finding the dot product between this vector and the passed vector
	*/
	float DotProduct(A_Vector4* const _AV) const;

	/**
	finds this vector's normal
	*/
	const A_Vector4 Normal();


	/**
	finds this vector's normal and assigns it to itself
	*/
	void Normalize();

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************member access*****************************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	returns this vector's X value
	*/
	const float getX() {

		return this->demensions[0];

	}

	/**
	access for setting X
	*/
	void setX(float const _x) {

		this->demensions[0] = _x;

	}

	/**
	returns this vector's Y value
	*/
	const float getY() {

		return this->demensions[1];

	}

	/**
	access for setting Y
	*/
	void setY(float const _y) {

		this->demensions[1];

	}

	/**
	returns this vector's Z value
	*/
	const float getZ() {

		return this->demensions[2];

	}

	/**
	access for setting Z
	*/
	void setZ(float _z) {

		this->demensions[2];

	}

	/**
	returns this vector's Z value
	*/
	const float getW() {

		return this->demensions[3];

	}

	/**
	access for setting W
	*/
	void setW(float const _w) {

		this->demensions[3] = _w;

	}

	/**
	access for quickly setting each value
	*/
	void SetAll(float const _x, float const _y, float const _z, float const _w) {

		this->demensions[0] = _x;
		this->demensions[1] = _y;
		this->demensions[2] = _z;
		this->demensions[3] = _w;

	}

	/**
	access for quickly setting each value
	equal to the corresponding value in _AV
	*/
	void SetAll(A_Vector4* const _AV) {

		this->demensions[0] = _AV->demensions[0];
		this->demensions[1] = _AV->demensions[1];
		this->demensions[2] = _AV->demensions[2];
		this->demensions[3] = _AV->demensions[3];

	}

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*************multiplication operators********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	operator for scaling a vector by a float
	*/
	A_Vector4 operator *(float _f) {

		A_Vector4 t_v;

		t_v.demensions[0] = this->demensions[0] * _f;
		t_v.demensions[1] = this->demensions[1] * _f;
		t_v.demensions[2] = this->demensions[2] * _f;
		t_v.demensions[3] = this->demensions[3] * _f;

		return t_v;

	}

	/**
	operator for scaling this vector by a float
	*/
	void operator *=(float _f) {


		this->demensions[0] *= _f;
		this->demensions[1] *= _f;
		this->demensions[2] *= _f;
		this->demensions[3] *= _f;

	}

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//****************addition operators***********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	operator for adding two vectors together
	*/
	A_Vector4 operator +(A_Vector4& const _A) {

		A_Vector4 T_A;
		T_A.demensions[0] = _A.demensions[0] + this->demensions[0];
		T_A.demensions[1] = _A.demensions[1] + this->demensions[1];
		T_A.demensions[2] = _A.demensions[2] + this->demensions[2];
		T_A.demensions[3] = _A.demensions[2] + this->demensions[2];

	}

	/**
	operator for adding to a vector with a float
	*/
	A_Vector4 operator +(float const _f) {

		A_Vector4 t_v;
		t_v.demensions[0] = this->demensions[0] + _f;
		t_v.demensions[1] = this->demensions[1] + _f;
		t_v.demensions[2] = this->demensions[2] + _f;
		t_v.demensions[3] = this->demensions[2] + _f;

		return t_v;
	}
	
	/**
	operator for subtracting from a vector with another vector
	*/
	A_Vector4 operator -(A_Vector4& const _A) {

		A_Vector4 T_A;
		T_A.demensions[0] = _A.demensions[0] - this->demensions[0];
		T_A.demensions[1] = _A.demensions[1] - this->demensions[1];
		T_A.demensions[2] = _A.demensions[2] - this->demensions[2];
		T_A.demensions[3] = _A.demensions[2] - this->demensions[2];

		return T_A;

	}

	/**
	operator for adding to a vector with a float
	*/
	A_Vector4 operator -(float const _f) {

		A_Vector4 t_v;
		t_v.demensions[0] = this->demensions[0] - _f;
		t_v.demensions[1] = this->demensions[1] - _f;
		t_v.demensions[2] = this->demensions[2] - _f;
		t_v.demensions[3] = this->demensions[2] - _f;

		return t_v;
	}

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***********addition assignment operators*****************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	operator for adding another vector to this vector
	*/
	void operator += (A_Vector4& const _A) {

		this->demensions[0] += _A.demensions[0];
		this->demensions[1] += _A.demensions[1];
		this->demensions[2] += _A.demensions[2];
		this->demensions[3] += _A.demensions[2];

	}

	/**
	operator for adding a float to this vector
	*/
	void operator += (float const _f) {

		this->demensions[0] += _f;
		this->demensions[1] += _f;
		this->demensions[2] += _f;
		this->demensions[3] += _f;

	}

	/**
	operator for subtracting another vector from this vector
	*/
	void operator -= (A_Vector4& const _A) {

		this->demensions[0] -= _A.demensions[0];
		this->demensions[1] -= _A.demensions[1];
		this->demensions[2] -= _A.demensions[2];
		this->demensions[3] += _A.demensions[2];

	}

	/**
	operator for subtracting a float from this vector
	*/
	void operator -= (float const _f) {

		this->demensions[0] -= _f;
		this->demensions[1] -= _f;
		this->demensions[2] -= _f;
		this->demensions[3] -= _f;

	}

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//****************equality operators***********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	assigns one vector's value to another
	*/
	void operator = (A_Vector4 const &_A) {

		this->demensions[0] = _A.demensions[0];
		this->demensions[1] = _A.demensions[1];
		this->demensions[2] = _A.demensions[2];
		this->demensions[3] = _A.demensions[3];

	}

	/**
	sets all of this vector's demensions to _f
	*/
	void operator = (float const _f) {

		this->demensions[0] = _f;
		this->demensions[1] = _f;
		this->demensions[2] = _f;
		this->demensions[3] = _f;

	}

private:

	//x, y, z, w
	float demensions[4];

};

#endif