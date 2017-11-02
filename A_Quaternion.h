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
	constructor which initializes all dimensions of the quaternion to zero
	*/
	A_Quaternion();


	/**
	constructor which initializes all dimensions of the quaternion
	to the dimensions of the quaternion who's pointer was passed
	*/
	A_Quaternion(A_Quaternion* const _AQ);

	/**
	constructor which initializes all dimensions of the quaternion
	to the dimensions of the vector who's pointer was passed
	*/
	A_Quaternion(A_Vector4* const _AV);

	/**
	constructor which initializes all dimensions of the quaternion to _n
	*/
	A_Quaternion(float const _n);

	/**
	constructor which initializes all dimensions of the quaternion to
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
	const A_Quaternion GetQuaternion(float _angle, A_Vector3 _axis)const;

	/**
	returns the four floats in quaternion form
	*/
	const A_Quaternion GetQuaternion(float _x, float _y, float _z, float _w)const;

	/**
	returns this quaternion as a A_Vector4
	*/
	const A_Vector4 GetVector4()const;

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
	multiplies this quaternion by a float, to scale it's dimensions uniformly and returns that value
	*/
	A_Quaternion operator * (float const _f) {

		A_Quaternion T_Result;

		T_Result.dimensions[0] = this->dimensions[0] * _f;
		T_Result.dimensions[1] = this->dimensions[1] * _f;
		T_Result.dimensions[2] = this->dimensions[2] * _f;
		T_Result.dimensions[3] = this->dimensions[3] * _f;

		return T_Result;

	}

	/**
	multiplies this quaternion by a float, to scale it's dimensions uniformly and assigns that value
	to this quaternion
	*/
	A_Quaternion operator *= (float const _f) {

		this->dimensions[0] *= _f;
		this->dimensions[1] *= _f;
		this->dimensions[2] *= _f;
		this->dimensions[3] *= _f;

	}

	/**
	adds to this quaternion _AQ and returns the result
	*/
	A_Quaternion operator + (A_Quaternion const _AQ) {

		A_Quaternion T_Result;

		T_Result.dimensions[0] = this->dimensions[0] + _AQ.dimensions[0];
		T_Result.dimensions[1] = this->dimensions[1] + _AQ.dimensions[1];
		T_Result.dimensions[2] = this->dimensions[2] + _AQ.dimensions[2];
		T_Result.dimensions[3] = this->dimensions[3] + _AQ.dimensions[3];

		return T_Result;

	}

	/**
	adds to this quaternion _AQ
	*/
	void operator += (A_Quaternion const _AQ) {

		this->dimensions[0] += _AQ.dimensions[0];
		this->dimensions[1] += _AQ.dimensions[1];
		this->dimensions[2] += _AQ.dimensions[2];
		this->dimensions[3] += _AQ.dimensions[3];

	}

	/**
	makes this quaternion into a copy of _AQ
	*/
	void operator = (A_Quaternion const _AQ) {

		this->dimensions[0] = _AQ.dimensions[0];
		this->dimensions[1] = _AQ.dimensions[1];
		this->dimensions[2] = _AQ.dimensions[2];
		this->dimensions[3] = _AQ.dimensions[3];

	}

	/**
	makes this quaternion into a copy of _AV
	*/
	void operator = (A_Vector4 _AV) {

		this->dimensions[0] = _AV.getX();
		this->dimensions[1] = _AV.getY();
		this->dimensions[2] = _AV.getZ();
		this->dimensions[3] = _AV.getW();

	}

	/**
	returns true if all dumensions of this quaternion and the dumensions of _AQ are equal
	a margin of error could be added but would be computationally expensive
	*/
	bool operator == (A_Quaternion const _AQ) {

		if (this->dimensions[0] == _AQ.dimensions[0] && this->dimensions[1] == _AQ.dimensions[1] &&
			this->dimensions[2] == _AQ.dimensions[2] && this->dimensions[3] == _AQ.dimensions[3])
			return true;

		else return false;

	}

	/**
	returns TRUE if ANY of the dumensions from _AQ ARE NOT equal to that dumension within this quaternion
	otherwise returns false
	*/
	bool operator != (A_Quaternion const _AQ) {

		if (this->dimensions[0] != _AQ.dimensions[0] || this->dimensions[1] != _AQ.dimensions[1] ||
			this->dimensions[2] != _AQ.dimensions[2] || this->dimensions[3] != _AQ.dimensions[3])
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

		T_Result.dimensions[0] = this->dimensions[0] * _AQ->dimensions[3] + this->dimensions[1] * _AQ->dimensions[2] - this->dimensions[2] * _AQ->dimensions[1] + this->dimensions[3] * _AQ->dimensions[0];
		T_Result.dimensions[1] = -this->dimensions[0] * _AQ->dimensions[2] + this->dimensions[1] * _AQ->dimensions[3] + this->dimensions[2] * _AQ->dimensions[0] + this->dimensions[3] * _AQ->dimensions[1];
		T_Result.dimensions[2] = this->dimensions[0] * _AQ->dimensions[1] - this->dimensions[1] * _AQ->dimensions[0] + this->dimensions[2] * _AQ->dimensions[3] + this->dimensions[3] * _AQ->dimensions[2];
		T_Result.dimensions[3] = -this->dimensions[0] * _AQ->dimensions[0] - this->dimensions[1] * _AQ->dimensions[1] - this->dimensions[2] * _AQ->dimensions[2] + this->dimensions[3] * _AQ->dimensions[3];

		return T_Result;

	}

	void operator *= (A_Quaternion const *_AQ) {

		this->dimensions[0] = this->dimensions[0] * _AQ->dimensions[3] + this->dimensions[1] * _AQ->dimensions[2] - this->dimensions[2] * _AQ->dimensions[1] + this->dimensions[3] * _AQ->dimensions[0];
		this->dimensions[1] = -this->dimensions[0] * _AQ->dimensions[2] + this->dimensions[1] * _AQ->dimensions[3] + this->dimensions[2] * _AQ->dimensions[0] + this->dimensions[3] * _AQ->dimensions[1];
		this->dimensions[2] = this->dimensions[0] * _AQ->dimensions[1] - this->dimensions[1] * _AQ->dimensions[0] + this->dimensions[2] * _AQ->dimensions[3] + this->dimensions[3] * _AQ->dimensions[2];
		this->dimensions[3] = -this->dimensions[0] * _AQ->dimensions[0] - this->dimensions[1] * _AQ->dimensions[1] - this->dimensions[2] * _AQ->dimensions[2] + this->dimensions[3] * _AQ->dimensions[3];

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

		return this->dimensions[0];

	}

	/**
	returns this quaternion's Y value
	*/
	const float getY() {

		return this->dimensions[1];

	}

	/**
	returns this quaternion's Z value
	*/
	const float getZ() {

		return this->dimensions[2];

	}

	/**
	returns this quaternion's W value
	*/
	const float getW() {

		return this->dimensions[3];

	}

	/**
	access for setting X
	*/
	void setX(float const _x) {

		this->dimensions[0] = _x;

	}

	/**
	access for setting Y
	*/
	void setY(float const _y) {

		this->dimensions[1] = _y;

	}

	/**
	access for setting Z
	*/
	void setZ(float const _z) {

		this->dimensions[2] = _z;

	}

	/**
	access for setting W
	*/
	void setW(float const _w) {

		this->dimensions[3] = _w;

	}

	/**
	access for quickly setting each value
	*/
	void setAll(float const _x, float const _y, float const _z, float const _w) {

		this->dimensions[0] = _x;
		this->dimensions[1] = _y;
		this->dimensions[2] = _z;
		this->dimensions[3] = _w;

	}

	/**
	access for quickly setting each value uniformly
	*/
	void SetAll(float const _n) {

		this->dimensions[0] = _n;
		this->dimensions[1] = _n;
		this->dimensions[2] = _n;
		this->dimensions[3] = _n;

	}

	/**
	access for quickly setting each value
	equal to the corresponding value in _AQ
	*/
	void SetAll(A_Quaternion* const _AQ) {

		this->dimensions[0] = _AQ->dimensions[0];
		this->dimensions[1] = _AQ->dimensions[1];
		this->dimensions[2] = _AQ->dimensions[2];
		this->dimensions[3] = _AQ->dimensions[3];

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

	//threshold used for Normalze method
	static const float S_QuaternionNormalThreshold;

	//x, y, z ,w
	float dimensions[4];

};

#endif