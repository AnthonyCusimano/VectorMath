#ifndef A_VECTOR_2
#define A_VECTOR_2

#include <math.h>

class A_Vector2 {

public:

	/**
	default constructor initializes this vector's values to 0
	*/
	A_Vector2();

	/**
	constructor initializes both elements of this vector to _n
	*/
	A_Vector2(float const _n);

	/**
	constructor initializes this vector's values to _X and _Y respectively
	*/
	A_Vector2(float const _X, float const _Y);

	/**
	constructor initializes this vector's values to the X and Y of _AV's
	*/
	A_Vector2(A_Vector2 const *_AV);

	/**
	destructor
	*/
	~A_Vector2();


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
	const float GetMagnatude() const;

	/**
	finding the dot product between this vector and the passed vector
	*/
	const float DotProduct(A_Vector2 const *_AV) const;

	/**
	finds this vector's normal
	*/
	const A_Vector2 Normal();

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
	const float getX()const {

		return this->dimensions[0];

	}

	/**
	returns this vector's Y value
	*/
	const float getY()const {

		return this->dimensions[1];

	}

	/**
	access for setting X
	*/
	void setX(float const _X) {

		this->dimensions[0] = _X;

	}

	/**
	access for setting X
	*/
	void setY(float const _Y) {

		this->dimensions[1] = _Y;

	}

	/**
	access for quickly setting each value
	*/
	void SetAll(float const _X, float const _Y) {

		this->dimensions[0] = _X;
		this->dimensions[1] = _Y;

	}

	/**
	access for quickly setting each value uniformly
	*/
	void SetAll(float const _n) {

		this->dimensions[0] = _n;
		this->dimensions[1] = _n;
		
	}

	/**
	access for quickly setting each value
	equal to the corresponding value in _AV
	*/
	void SetAll(A_Vector2* const _AV) {

		this->dimensions[0] = _AV->dimensions[0];
		this->dimensions[1] = _AV->dimensions[1];

	}

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//*********************operators***************************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	operator for scaling a vector by a float
	*/
	A_Vector2 operator *(float const _f) {

		A_Vector2 t_v;

		t_v.dimensions[0] = this->dimensions[0] * _f;
		t_v.dimensions[1] = this->dimensions[1] * _f;

		return t_v;
	}

	/**
	operator for scaling this vector by a float
	*/
	void operator *= (float const _f) {

		this->dimensions[0] *= _f;
		this->dimensions[1] *= _f;

	}

	/**
	operator for adding two vectors together
	*/
	A_Vector2 operator + (A_Vector2& const _A) {

		A_Vector2 T_A;
		T_A.dimensions[0] = _A.dimensions[0] + this->dimensions[0];
		T_A.dimensions[1] = _A.dimensions[1] + this->dimensions[1];

		return T_A;

	}

	/**
	operator for adding to a vector with a float
	*/
	const A_Vector2 operator + (float const _f) {

		A_Vector2 t_v;
		t_v.dimensions[0] = this->dimensions[0] + _f;
		t_v.dimensions[1] = this->dimensions[1] + _f;

		return &t_v;
	}

	/**
	operator for adding to this vector with a float
	*/
	void operator += (A_Vector2& const _A) {

		this->dimensions[0] += _A.dimensions[0];
		this->dimensions[1] += _A.dimensions[1];

	}

	/**
	operator for subtracting from a vector with a float
	*/
	A_Vector2 operator - (float const _f) {

		A_Vector2 T_V;

		T_V.dimensions[0] = this->dimensions[0] - _f;
		T_V.dimensions[1] = this->dimensions[1] - _f;

		return T_V;

	}

	/**
	operator for subtracting from this vector with a float
	*/
	void operator -= (float const _f) {

		this->dimensions[0] -= _f;
		this->dimensions[1] -= _f;

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
	bool operator == (A_Vector2& const _A) {

		return (_A.dimensions[0] == this->dimensions[0] && _A.dimensions[1] == this->dimensions[1]);

	}

	/**
	returns true if any of the 3 values in this vector
	and the passed vector are not equal
	*/
	bool operator != (A_Vector2& const _A) {

		return (_A.dimensions[0] != this->dimensions[0] || _A.dimensions[1] != this->dimensions[1]);

	}

	/**
	returns true if this vector's magnatude is greater
	than the magnitude of the vector passed into the operator
	*/
	bool operator > (A_Vector2& const _A) {

		return (this->GetMagnatude() > _A.GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is greater
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator >= (A_Vector2& const _A) {

		return (this->GetMagnatude() >= _A.GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than the magnitude of the vector passed into the operator
	*/
	bool operator < (A_Vector2& const _A) {

		return (this->GetMagnatude() < _A.GetMagnatude());

	}

	/**
	returns true if this vector's magnatude is less
	than or equal to the magnitude of the vector passed into the operator
	*/
	bool operator <= (A_Vector2& const _A) {

		return (this->GetMagnatude() <= _A.GetMagnatude());

	}

	/**
	assigns this vector's value to another
	*/
	void operator = (A_Vector2& const _A) {

		this->dimensions[0] = _A.dimensions[0];
		this->dimensions[1] = _A.dimensions[1];

	}

	/**
	assigns this vector's value the float's
	*/
	void operator = (float const _f) {

		this->dimensions[0] = this->dimensions[1] = _f;

	}

private:

	//x, y
	float dimensions[2];

};

#endif