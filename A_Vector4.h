#ifndef A_VECTOR_4
#define A_VECTOR_4

#include "A_Vector3.h"

class A_Vector4 {

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
	void setAll(float const _x, float const _y, float const _z, float const _w) {

		this->demensions[0] = _x;
		this->demensions[1] = _y;
		this->demensions[2] = _z;
		this->demensions[3] = _w;

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
	A_Vector4 operator +(A_Vector4 const &_A) {

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
	
	A_Vector4 operator -(A_Vector4 const &_A) {

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
	
	*/
	void operator += (A_Vector4 const &_A) {

		this->demensions[0] += _A.demensions[0];
		this->demensions[1] += _A.demensions[1];
		this->demensions[2] += _A.demensions[2];
		this->demensions[3] += _A.demensions[2];

	}

	/**
	
	*/
	void operator += (float const _f) {

		this->demensions[0] += _f;
		this->demensions[1] += _f;
		this->demensions[2] += _f;
		this->demensions[3] += _f;

	}

	/**
	
	*/
	void operator -= (A_Vector4 const &_A) {

		this->demensions[0] -= _A.demensions[0];
		this->demensions[1] -= _A.demensions[1];
		this->demensions[2] -= _A.demensions[2];
		this->demensions[3] += _A.demensions[2];

	}

	/**
	
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
	tests to see if the X Y Z values of this vector, and the
	vector passed into the method are all equal
	*/
	bool operator == (A_Vector4 const &_A) {

		return (_A.demensions[0] == this->demensions[0] && _A.demensions[1] == this->demensions[1] &&
			_A.demensions[2] == this->demensions[2] && _A.demensions[3] == this->demensions[3]);

	}

	/**
	returns true if any of the 3 values in this vector
	and the passed vector are not equal
	*/
	bool operator != (A_Vector4 const &_A) {

		return (_A.demensions[0] != this->demensions[0] || _A.demensions[1] != this->demensions[1] ||
			_A.demensions[2] != this->demensions[2] || _A.demensions[3] != this->demensions[3]);

	}

	/**
	returns true if this vector's magnatude is greater
	than the magnitude of the vector passed into the operator
	*/
	bool operator > (A_Vector4 *_A) {

		return (this->GetMagnatude() > _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is greater
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator >= (A_Vector4 *_A) {

		return (this->GetMagnatude() >= _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than the magnitude of the vector passed into the operator
	*/
	bool operator < (A_Vector4 *_A) {

		return (this->GetMagnatude() < _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator <= (A_Vector4 *_A) {

		return (this->GetMagnatude() <= _A->GetMagnatude());

	}

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