#include "A_Quaternion.h"

const float A_Quaternion::S_QuaternionNormalThreshold = 0.0001f;

A_Quaternion::A_Quaternion() {

	this->dimensions[0] = 0.0f;
	this->dimensions[1] = 0.0f;
	this->dimensions[2] = 0.0f;
	this->dimensions[3] = 0.0f;

}

A_Quaternion::A_Quaternion(A_Quaternion* const _AQ) {

	this->dimensions[0] = _AQ->dimensions[0];
	this->dimensions[1] = _AQ->dimensions[1];
	this->dimensions[2] = _AQ->dimensions[2];
	this->dimensions[3] = _AQ->dimensions[3];

}

A_Quaternion::A_Quaternion(A_Vector4* const _AV) {

	this->dimensions[0] = _AV->getX();
	this->dimensions[1] = _AV->getY();
	this->dimensions[2] = _AV->getZ();
	this->dimensions[3] = _AV->getW();


}

A_Quaternion::A_Quaternion(float const _n) {

	this->dimensions[0] = _n;
	this->dimensions[1] = _n;
	this->dimensions[2] = _n;
	this->dimensions[3] = _n;

}

A_Quaternion::A_Quaternion(float const _x, float const _y, float const _z, float const _w) {

	this->dimensions[0] = _x;
	this->dimensions[1] = _y;
	this->dimensions[2] = _z;
	this->dimensions[3] = _w;
	
}

A_Quaternion::A_Quaternion(A_Vector3 const *_AV, float const _w) {

	this->dimensions[0] = _AV->getX();
	this->dimensions[1] = _AV->getY();
	this->dimensions[2] = _AV->getZ();
	this->dimensions[3] = _w;

}

const A_Quaternion A_Quaternion::GetQuaternion(float _angle, A_Vector3 _axis) const{

	return A_Quaternion(_axis.getX(), _axis.getY(), _axis.getZ(), _angle);

}

const A_Quaternion A_Quaternion::GetQuaternion(float _x, float _y, float _z, float _w) const{

	return A_Quaternion(_x, _y, _z, _w);

}

const A_Vector4 A_Quaternion::GetVector4()const {

	A_Vector4 T_Result;

	T_Result.SetAll(this->dimensions[0], this->dimensions[1], this->dimensions[2], this->dimensions[3]);

	return T_Result;

}


const float A_Quaternion::GetMagnatude() {

	float T_Mag = this->dimensions[0] * this->dimensions[0];
	T_Mag += (this->dimensions[1] * this->dimensions[1]);
	T_Mag += (this->dimensions[2] * this->dimensions[2]);
	T_Mag += (this->dimensions[3] * this->dimensions[3]);
	T_Mag = ::sqrtf(T_Mag);

	return T_Mag;

}

void A_Quaternion::Normalize() {

	//before normalizing the quaternion checking
	//to see it is outside of the "normal threshold"

	//first, squaring the quaternion
	float T_Squared = (this->dimensions[0] * this->dimensions[0]) +
		(this->dimensions[1] * this->dimensions[1]) +
		(this->dimensions[2] * this->dimensions[2]) +
		(this->dimensions[3] * this->dimensions[3]);

	//next find the absolute value of T_Squared
	if (T_Squared - 1.0f < 0.0f) T_Squared *= -1.0f;

	//now compare T_Squared with the threshold
	if (T_Squared != 0.0f && T_Squared > A_Quaternion::S_QuaternionNormalThreshold) {
		//if it is outside of the threshold, normalize

		float T_Mag = this->GetMagnatude();

		this->dimensions[0] /= T_Mag;
		this->dimensions[1] /= T_Mag;
		this->dimensions[2] /= T_Mag;
		this->dimensions[3] /= T_Mag;

	}

	//else, don't normalize

}

const float A_Quaternion::GetNormal() {

	float T_Mag = this->GetMagnatude();

	this->dimensions[0] /= T_Mag;
	this->dimensions[1] /= T_Mag;
	this->dimensions[2] /= T_Mag;
	this->dimensions[3] /= T_Mag;

	return T_Mag;

}

void A_Quaternion::Conjugate() {

	this->dimensions[0] *= -1.0f;
	this->dimensions[1] *= -1.0f;
	this->dimensions[2] *= -1.0f;

}

const A_Quaternion A_Quaternion::GetConjugate() {

	A_Quaternion T_Result;

	T_Result.dimensions[0] = this->dimensions[0] * -1.0f;
	T_Result.dimensions[1] = this->dimensions[1] * -1.0f;
	T_Result.dimensions[2] = this->dimensions[2] * -1.0f;
	T_Result.dimensions[3] = this->dimensions[3];

	return T_Result;

}

void A_Quaternion::SetFromEuler(A_Vector3 const &_Euler) {

	float T_cosRoll, T_cosPitch, T_cosYaw, T_sinRoll, T_cosPitch2, T_cosYaw2;

	//I would like to formally apologize to anyone reading this code in the future for the breakdown in naming conventions here
	float T_CosPitchxT_CosYaw, T_CosPitch2xT_CosYaw, T_CosPitchxT_CosYaw2, T_cosPitch2xT_CosYaw;

	float T_roll, T_pitch, T_yaw;

	T_roll = _Euler.getX() * 0.5f;
	T_pitch = _Euler.getY() * 0.5f;
	T_yaw = _Euler.getZ() * 0.5f;

	T_cosRoll = ::cosf(T_roll);
	T_cosPitch = ::cosf(T_pitch);
	T_cosYaw = ::cosf(T_yaw);

	T_sinRoll = ::sinf(T_roll);
	T_cosPitch2 = ::cosf(T_pitch);
	T_cosYaw2 = ::cosf(T_yaw);

	//these variables done this way to avoid making the same multiplication multiple times down below
	//consider trying a different way to ease up on memory slightly while slightly slowing down arithmetic
	//move variable declaration above

	T_CosPitchxT_CosYaw/*T_CYxCZ*/ = T_cosPitch * T_cosYaw;
	T_CosPitch2xT_CosYaw/*2CP2xCY*/ = T_cosPitch2 * T_cosYaw2;
	T_CosPitchxT_CosYaw2/*T_CYxSZ*/ = T_cosPitch * T_cosYaw2;
	T_cosPitch2xT_CosYaw/*T_SYxCZ*/ = T_cosPitch2 * T_cosYaw;

	/*w = cx * cycz + sx * sysz;
	x = sx * cycz - cx * sysz;
	y = cx * sycz + sx * cysz;
	z = cx * cysz - sx * sycz;*/

	this->dimensions[0] = (T_sinRoll * T_CosPitchxT_CosYaw) - (T_cosRoll * T_CosPitch2xT_CosYaw);
	this->dimensions[1] = (T_cosRoll * T_cosPitch2xT_CosYaw) + (T_sinRoll * T_CosPitchxT_CosYaw2);
	this->dimensions[2] = (T_cosRoll * T_CosPitchxT_CosYaw2) - (T_sinRoll * T_cosPitch2xT_CosYaw);
	this->dimensions[3] = (T_cosRoll * T_CosPitchxT_CosYaw) + (T_sinRoll * T_cosPitch2xT_CosYaw);

}

void A_Quaternion::SetFromEuler(float const _rollX, float const _pitchY, float const _yawZ) {

	float T_cosRoll, T_cosPitch, T_cosYaw, T_sinRoll, T_cosPitch2, T_cosYaw2;

	//I would like to formally apologize to anyone reading this code in the future for the breakdown in naming conventions here
	float T_CosPitchxT_CosYaw, T_CosPitch2xT_CosYaw, T_CosPitchxT_CosYaw2, T_cosPitch2xT_CosYaw;

	float T_roll, T_pitch, T_yaw;

	T_roll = _rollX * 0.5f;
	T_pitch = _pitchY * 0.5f;
	T_yaw = _yawZ * 0.5f;

	T_cosRoll = ::cosf(T_roll);
	T_cosPitch = ::cosf(T_pitch);
	T_cosYaw = ::cosf(T_yaw);

	T_sinRoll = ::sinf(T_roll);
	T_cosPitch2 = ::cosf(T_pitch);
	T_cosYaw2 = ::cosf(T_yaw);

	//these variables done this way to avoid making the same multiplication multiple times down below
	//consider trying a different way to ease up on memory slightly while slightly slowing down arithmetic
	//move variable declaration above

	T_CosPitchxT_CosYaw/*T_CYxCZ*/ = T_cosPitch * T_cosYaw;
	T_CosPitch2xT_CosYaw/*2CP2xCY*/ = T_cosPitch2 * T_cosYaw2;
	T_CosPitchxT_CosYaw2/*T_CYxSZ*/ = T_cosPitch * T_cosYaw2;
	T_cosPitch2xT_CosYaw/*T_SYxCZ*/ = T_cosPitch2 * T_cosYaw;

	/*w = cx * cycz + sx * sysz;
	x = sx * cycz - cx * sysz;
	y = cx * sycz + sx * cysz;
	z = cx * cysz - sx * sycz;*/

	this->dimensions[0] = (T_sinRoll * T_CosPitchxT_CosYaw) - (T_cosRoll * T_CosPitch2xT_CosYaw);
	this->dimensions[1] = (T_cosRoll * T_cosPitch2xT_CosYaw) + (T_sinRoll * T_CosPitchxT_CosYaw2);
	this->dimensions[2] = (T_cosRoll * T_CosPitchxT_CosYaw2) - (T_sinRoll * T_cosPitch2xT_CosYaw);
	this->dimensions[3] = (T_cosRoll * T_CosPitchxT_CosYaw) + (T_sinRoll * T_cosPitch2xT_CosYaw);

}

A_Quaternion::~A_Quaternion() {

	

}