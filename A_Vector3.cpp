#include "A_Vector3.h"

A_Vector3::A_Vector3() {

	this->dimensions[0] = 0;
	this->dimensions[1] = 0;
	this->dimensions[2] = 0;

}

A_Vector3::A_Vector3(float const _n) {

	this->dimensions[0] = _n;
	this->dimensions[1] = _n;
	this->dimensions[2] = _n;

}

A_Vector3::A_Vector3(const float const _x, const float const _y, const float const _z) {

	this->dimensions[0] = _x;
	this->dimensions[1] = _y;
	this->dimensions[2] = _z;

}

A_Vector3::A_Vector3( A_Vector3* const _AV) {

	this->dimensions[0] = _AV->dimensions[0];
	this->dimensions[1] = _AV->dimensions[1];
	this->dimensions[2] = _AV->dimensions[2];

}

A_Vector3::A_Vector3(A_Vector2* const _AV, float const _z) {

	this->dimensions[0] = _AV->getX();
	this->dimensions[1] = _AV->getY();
	this->dimensions[2] = _z;

}

float A_Vector3::GetMagnatude() {

	float T_Mag = this->dimensions[0] * this->dimensions[0];
	T_Mag += (this->dimensions[1] * this->dimensions[1]);
	T_Mag += (this->dimensions[2] * this->dimensions[2]);
	T_Mag = ::sqrt(T_Mag);
	return T_Mag;
}

float A_Vector3::DotProduct(const A_Vector3 const *_AV)const {

	float T_Dot;
	T_Dot = _AV->dimensions[0] * this->dimensions[0];
	T_Dot += _AV->dimensions[1] * this->dimensions[1];
	T_Dot += _AV->dimensions[2] * this->dimensions[2];

	return T_Dot;

}

const A_Vector3 A_Vector3::CrossProduct(A_Vector3 const *_AV) {

	A_Vector3 T_Cross;

	T_Cross.dimensions[0] = (this->dimensions[1] * _AV->dimensions[2]) - (this->dimensions[2] * _AV->dimensions[1]);
	T_Cross.dimensions[1] = (this->dimensions[2] * _AV->dimensions[0]) - (this->dimensions[0] * _AV->dimensions[2]);
	T_Cross.dimensions[2] = (this->dimensions[0] * _AV->dimensions[1]) - (this->dimensions[1] * _AV->dimensions[0]);

	return T_Cross;

}

const A_Vector3 A_Vector3::Normal() {

	float T_Mag = this->GetMagnatude();
	A_Vector3 T_Vec = *this;

	T_Vec.dimensions[0] /= T_Mag;
	T_Vec.dimensions[1] /= T_Mag;
	T_Vec.dimensions[2] /= T_Mag;

	return T_Vec;


}

void A_Vector3::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->dimensions[0] /= T_Mag;
	this->dimensions[1] /= T_Mag;
	this->dimensions[2] /= T_Mag;

}

A_Vector3::~A_Vector3() {



}