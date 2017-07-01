#ifndef A_VECTOR_3
#define A_VECTOR_3

//used for square root functionality
#include <math.h>

class A_Vector3 {

public:

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***********Constructors and destructor*******************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/


	/**
	constructor which initializes all demensions of the vector to zero
	*/
	A_Vector3();

	/**
	constructor which initializes all demensions of the vector
	to the demensions of the vector who's refrence was passed
	*/
	A_Vector3(const A_Vector3 const &_AV);

	/**
	constructor which initializes all demensions of the vector to
	the values passed
	*/
	A_Vector3(const float const _x, const float const _y, const float const _z);

	/**
	destructor
	*/
	~A_Vector3();



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
	float DotProduct(const A_Vector3 const *_AV) const;

	/**
	finding the cross product between this vector and the passed vector
	*/
	const A_Vector3 CrossProduct(A_Vector3 const *_AV);

	/**
	finds this vector's normal
	*/
	const A_Vector3 Normal();


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
	float getX()const {

		return this->demensions[0];

	}

	/**
	returns this vector's Y value
	*/
	float getY()const {

		return this->demensions[1];

	}

	/**
	returns this vector's Z value
	*/
	float getZ()const {

		return this->demensions[2];

	}

	/**
	access for setting X
	*/
	void SetX(const float const _X) {

		this->demensions[0] = _X;

	}

	/**
	access for setting X
	*/
	void SetY(const float const _Y) {

		this->demensions[1] = _Y;

	}

	/**
	access for setting Z
	*/
	void SetZ(const float const _Z) {

		this->demensions[2] = _Z;

	}

	/**
	access for quickly setting each value
	*/
	void SetAll(const float const _X, const float const _Y, const float const _Z) {

		this->demensions[0] = _X;
		this->demensions[1] = _Y;
		this->demensions[2] = _Z;

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
	operator for multiplying to vector together
	*/
	A_Vector3 operator *(const A_Vector3 const *_a) {

		A_Vector3 t_v;

		t_v.demensions[0] = this->demensions[0] * _a->demensions[0];
		t_v.demensions[1] = this->demensions[1] * _a->demensions[1];
		t_v.demensions[2] = this->demensions[2] * _a->demensions[2];

		return t_v;
	}

	/**
	operator for scaling a vector by a float
	*/
	A_Vector3 operator *(const float const _f) {

		A_Vector3 t_v;

		t_v.demensions[0] = this->demensions[0] * _f;
		t_v.demensions[1] = this->demensions[1] * _f;
		t_v.demensions[2] = this->demensions[2] * _f;

		return t_v;
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
	A_Vector3 operator +(const A_Vector3 const &_A) {

		A_Vector3 T_A;
		T_A.demensions[0] = _A.demensions[0] + this->demensions[0];
		T_A.demensions[1] = _A.demensions[1] + this->demensions[1];
		T_A.demensions[2] = _A.demensions[2] + this->demensions[2];

	}


	/**
	operator for adding to a vector with a float
	*/
	A_Vector3 operator +(const float const _f) {

		A_Vector3 t_v;
		t_v.demensions[0] = this->demensions[0] + _f;
		t_v.demensions[1] = this->demensions[1] + _f;
		t_v.demensions[2] = this->demensions[2] + _f;

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

	void operator += (const A_Vector3 const &_A) {

		this->demensions[0] += _A.demensions[0];
		this->demensions[1] += _A.demensions[1];
		this->demensions[2] += _A.demensions[2];

	}

	void operator -= (const A_Vector3 const &_A) {

		this->demensions[0] -= _A.demensions[0];
		this->demensions[1] -= _A.demensions[1];
		this->demensions[2] -= _A.demensions[2];

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
	bool operator == (const A_Vector3 const &_A) {

		return (_A.demensions[0] == this->demensions[0] && _A.demensions[1] == this->demensions[1] &&
			_A.demensions[2] == this->demensions[2]);

	}

	/**
	returns true if any of the 3 values in this vector
	and the passed vector are not equal
	*/
	bool operator != (const A_Vector3 const &_A) {

		return (_A.demensions[0] != this->demensions[0] || _A.demensions[1] != this->demensions[1] ||
			_A.demensions[2] != this->demensions[2]);

	}

	/**
	returns true if this vector's magnatude is greater
	than the magnitude of the vector passed into the operator
	*/
	bool operator > (A_Vector3 *_A) {

		return (this->GetMagnatude() > _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is greater
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator >= (A_Vector3 *_A) {

		return (this->GetMagnatude() >= _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than the magnitude of the vector passed into the operator
	*/
	bool operator < (A_Vector3 *_A) {

		return (this->GetMagnatude() < _A->GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator <= (A_Vector3 *_A) {

		return (this->GetMagnatude() <= _A->GetMagnatude());

	}

	/**
	assigns one vevectorktor's value to another
	*/
	void operator = (const A_Vector3 const &_A) {

		this->demensions[0] = _A.demensions[0];
		this->demensions[1] = _A.demensions[1];
		this->demensions[2] = _A.demensions[2];

	}

private:

	float demensions[3];

};

#endif