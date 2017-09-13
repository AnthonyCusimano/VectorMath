#ifndef A_QUATERNION_H
#define A_QUATERNION_H

#include "A_Vector4.h"

class A_Quaternion {

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
	constructor which initializes all demensions of the quaternion to zero
	*/
	A_Quaternion();


	/**
	constructor which initializes all demensions of the quaternion
	to the demensions of the vector who's pointer was passed
	*/
	A_Quaternion(A_Quaternion const *_AQ);


	/**
	constructor which initializes all demensions of the quaternion to
	the values passed
	*/
	A_Quaternion(float const _x, float const _y, float const _z, float const _w);

	/**
	Constructor which initializes the X, Y, and the Z of the quaternion to the X, Y, and Z of the 3D vector
	and the W value to _w
	*/
	A_Quaternion(A_Vector3 const *_AV, float const _w);

	/**
	destructor
	*/
	~A_Quaternion();

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************Quaternion Functions**********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	returns the angle and the axis as a quaternion
	*/
	const A_Quaternion GetQuaternion(float _angle, A_Vector3 _axis);

	/**
	returns the four floats in quaternion form
	*/
	const A_Quaternion GetQuaternion(float _x, float _y, float _z, float _w);

	/**
	used to assist in normalizing this quaternion
	*/
	const float GetMagnatude();

	/**
	normalizes this quaternion making it into a unit quaternion
	*/
	void Normalize();

	/**
	returns the normal of this quaternion
	*/
	const float GetNormal();

	/**
	sets this quaternion equal to it's inverse
	*/
	void Conjugate();

	/**
	returns the inverse of this quaternion
	*/
	const A_Quaternion GetConjugate();

	/**
	//*********************************************************
	//*********************************************************
	//*********************************************************
	//***************Quaternion Operators**********************
	//*********************************************************
	//*********************************************************
	//*********************************************************
	*/

	/**
	multiplies this quaternion by a float, to scale it's demensions uniformly and returns that value
	*/
	A_Quaternion operator * (float const _f) {

		A_Quaternion T_Result;

		T_Result.demensions[0] = this->demensions[0] * _f;
		T_Result.demensions[1] = this->demensions[1] * _f;
		T_Result.demensions[2] = this->demensions[2] * _f;
		T_Result.demensions[3] = this->demensions[3] * _f;

		return T_Result;

	}

	/**
	multiplies this quaternion by a float, to scale it's demensions uniformly and assigns that value
	to this quaternion
	*/
	A_Quaternion operator *= (float const _f) {

		this->demensions[0] *= _f;
		this->demensions[1] *= _f;
		this->demensions[2] *= _f;
		this->demensions[3] *= _f;

	}

	/**
	adds to this quaternion _AQ and returns the result
	*/
	A_Quaternion operator + (A_Quaternion const _AQ) {

		A_Quaternion T_Result;

		T_Result.demensions[0] = this->demensions[0] + _AQ.demensions[0];
		T_Result.demensions[1] = this->demensions[1] + _AQ.demensions[1];
		T_Result.demensions[2] = this->demensions[2] + _AQ.demensions[2];
		T_Result.demensions[3] = this->demensions[3] + _AQ.demensions[3];

		return T_Result;

	}

	/**
	adds to this quaternion _AQ
	*/
	void operator += (A_Quaternion const _AQ) {

		this->demensions[0] += _AQ.demensions[0];
		this->demensions[1] += _AQ.demensions[1];
		this->demensions[2] += _AQ.demensions[2];
		this->demensions[3] += _AQ.demensions[3];

	}

	/**
	makes this quaternion into a copy of _AQ
	*/
	void operator = (A_Quaternion const _AQ) {

		this->demensions[0] = _AQ.demensions[0];
		this->demensions[1] = _AQ.demensions[1];
		this->demensions[2] = _AQ.demensions[2];
		this->demensions[3] = _AQ.demensions[3];

	}

	/**
	returns true if all demensions of this quaternion and the demensions of _AQ are equal
	a margin of error could be added but would be computationally expensive
	*/
	bool operator == (A_Quaternion const _AQ) {

		if (this->demensions[0] == _AQ.demensions[0] && this->demensions[1] == _AQ.demensions[1] &&
			this->demensions[2] == _AQ.demensions[2] && this->demensions[3] == _AQ.demensions[3])
			return true;

		else return false;

	}

	/**
	returns TRUE if ANY of the demensions from _AQ ARE NOT equal to that demension within this quaternion
	otherwise returns false
	*/
	bool operator != (A_Quaternion const _AQ) {

		if (this->demensions[0] != _AQ.demensions[0] || this->demensions[1] != _AQ.demensions[1] ||
			this->demensions[2] != _AQ.demensions[2] || this->demensions[3] != _AQ.demensions[3])
			return true;

		else return false;

	}

	/**
	multiplies this quaternion by the quaternion _SQ and returns the result
	*/
	A_Quaternion operator * (A_Quaternion const *_AQ) {

		A_Quaternion T_Result;

		/*x = q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
		y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
		z = q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
		w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;*/

		T_Result.demensions[0] = this->demensions[0] * _AQ->demensions[3] + this->demensions[1] * _AQ->demensions[2] - this->demensions[2] * _AQ->demensions[1] + this->demensions[3] * _AQ->demensions[0];
		T_Result.demensions[1] = -this->demensions[0] * _AQ->demensions[2] + this->demensions[1] * _AQ->demensions[3] + this->demensions[2] * _AQ->demensions[0] + this->demensions[3] * _AQ->demensions[1];
		T_Result.demensions[2] = this->demensions[0] * _AQ->demensions[1] - this->demensions[1] * _AQ->demensions[0] + this->demensions[2] * _AQ->demensions[3] + this->demensions[3] * _AQ->demensions[2];
		T_Result.demensions[3] = -this->demensions[0] * _AQ->demensions[0] - this->demensions[1] * _AQ->demensions[1] - this->demensions[2] * _AQ->demensions[2] + this->demensions[3] * _AQ->demensions[3];

		return T_Result;

	}

	void operator *= (A_Quaternion const *_AQ) {

		this->demensions[0] = this->demensions[0] * _AQ->demensions[3] + this->demensions[1] * _AQ->demensions[2] - this->demensions[2] * _AQ->demensions[1] + this->demensions[3] * _AQ->demensions[0];
		this->demensions[1] = -this->demensions[0] * _AQ->demensions[2] + this->demensions[1] * _AQ->demensions[3] + this->demensions[2] * _AQ->demensions[0] + this->demensions[3] * _AQ->demensions[1];
		this->demensions[2] = this->demensions[0] * _AQ->demensions[1] - this->demensions[1] * _AQ->demensions[0] + this->demensions[2] * _AQ->demensions[3] + this->demensions[3] * _AQ->demensions[2];
		this->demensions[3] = -this->demensions[0] * _AQ->demensions[0] - this->demensions[1] * _AQ->demensions[1] - this->demensions[2] * _AQ->demensions[2] + this->demensions[3] * _AQ->demensions[3];

	}


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
	returns this quaternion's X value
	*/
	const float getX() {

		return this->demensions[0];

	}

	/**
	returns this quaternion's Y value
	*/
	const float getY() {

		return this->demensions[1];

	}

	/**
	returns this quaternion's Z value
	*/
	const float getZ() {

		return this->demensions[2];

	}

	/**
	returns this quaternion's W value
	*/
	const float getW() {

		return this->demensions[3];

	}

	/**
	access for setting X
	*/
	void setX(float const _x) {

		this->demensions[0] = _x;

	}

	/**
	access for setting Y
	*/
	void setY(float const _y) {

		this->demensions[1] = _y;

	}

	/**
	access for setting Z
	*/
	void setZ(float const _z) {

		this->demensions[2] = _z;

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
	allows for setting the fields of this quaternion using euler angles
	*/
	void SetFromEuler(A_Vector3 const &_Euler);

	/**
	allows for setting the fields of this quaternion using euler angles
	*/
	void SetFromEuler(float const _roll, float const _pitch, float const _yaw);


private:

	//x, y, z ,w
	float demensions[4];

};

#endif