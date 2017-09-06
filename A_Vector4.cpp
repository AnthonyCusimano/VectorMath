#include "A_Vector4.h"

A_Vector4::A_Vector4() {

	this->demensions[0] = 0.0f;
	this->demensions[1] = 0.0f;
	this->demensions[2] = 0.0f;
	this->demensions[3] = 0.0f;

}

A_Vector4::A_Vector4(A_Vector4* const _AV) {

	this->demensions[0] = _AV->demensions[0];
	this->demensions[1] = _AV->demensions[1];
	this->demensions[2] = _AV->demensions[2];
	this->demensions[3] = _AV->demensions[3];

}

A_Vector4::A_Vector4(float const _x, float const _y, float const _z, float const _w) {

	this->demensions[0] = _x;
	this->demensions[1] = _y;
	this->demensions[2] = _z;
	this->demensions[3] = _w;

}

A_Vector4::A_Vector4(A_Vector2* const _AV, float const _z, float const _w) {

	this->demensions[0] = _AV->getX();
	this->demensions[1] = _AV->getY();
	this->demensions[2] = _z;
	this->demensions[3] = _w;

}

A_Vector4::A_Vector4(A_Vector3* const _AV, float _w) {

	this->demensions[0] = _AV->getX();
	this->demensions[1] = _AV->getY();
	this->demensions[2] = _AV->getZ();
	this->demensions[3] = _w;

}

float A_Vector4::GetMagnatude() {

	float T_Mag;

	T_Mag = this->demensions[0] * this->demensions[0];
	T_Mag += this->demensions[1] * this->demensions[1];
	T_Mag += this->demensions[2] * this->demensions[2];
	T_Mag += this->demensions[3] * this->demensions[3];

	T_Mag = ::sqrt(T_Mag);

	return T_Mag;

}

float A_Vector4::DotProduct(A_Vector4* const _AV) const {

	float T_Dot;

	T_Dot = this->demensions[0] * _AV->demensions[0];
	T_Dot += this->demensions[1] * _AV->demensions[1];
	T_Dot += this->demensions[2] * _AV->demensions[2];
	T_Dot += this->demensions[3] * _AV->demensions[3];

	return T_Dot;

}

const A_Vector4 A_Vector4::Normal() {

	float T_Mag = this->GetMagnatude();
	A_Vector4 T_Vec = *this;

	T_Vec.demensions[0] /= T_Mag;
	T_Vec.demensions[1] /= T_Mag;
	T_Vec.demensions[2] /= T_Mag;
	T_Vec.demensions[3] /= T_Mag;

	return T_Vec;

}

void A_Vector4::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->demensions[0] /= T_Mag;
	this->demensions[1] /= T_Mag;
	this->demensions[2] /= T_Mag;
	this->demensions[3] /= T_Mag;

}

A_Vector4::~A_Vector4() {

	//:)

}