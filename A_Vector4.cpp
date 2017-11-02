#include "A_Vector4.h"

A_Vector4::A_Vector4() {

	this->dimensions[0] = 0.0f;
	this->dimensions[1] = 0.0f;
	this->dimensions[2] = 0.0f;
	this->dimensions[3] = 0.0f;

}

A_Vector4::A_Vector4(float const _n) {

	this->dimensions[0] = _n;
	this->dimensions[1] = _n;
	this->dimensions[2] = _n;
	this->dimensions[3] = _n;

}

A_Vector4::A_Vector4(A_Vector4* const _AV) {

	this->dimensions[0] = _AV->dimensions[0];
	this->dimensions[1] = _AV->dimensions[1];
	this->dimensions[2] = _AV->dimensions[2];
	this->dimensions[3] = _AV->dimensions[3];

}

A_Vector4::A_Vector4(float const _x, float const _y, float const _z, float const _w) {

	this->dimensions[0] = _x;
	this->dimensions[1] = _y;
	this->dimensions[2] = _z;
	this->dimensions[3] = _w;
	
}

A_Vector4::A_Vector4(A_Vector2* const _AV, float const _z, float const _w) {

	this->dimensions[0] = _AV->getX();
	this->dimensions[1] = _AV->getY();
	this->dimensions[2] = _z;
	this->dimensions[3] = _w;

}

A_Vector4::A_Vector4(A_Vector3* const _AV, float _w) {

	this->dimensions[0] = _AV->getX();
	this->dimensions[1] = _AV->getY();
	this->dimensions[2] = _AV->getZ();
	this->dimensions[3] = _w;

}

float A_Vector4::GetMagnatude() {

	float T_Mag;

	T_Mag = this->dimensions[0] * this->dimensions[0];
	T_Mag += this->dimensions[1] * this->dimensions[1];
	T_Mag += this->dimensions[2] * this->dimensions[2];
	T_Mag += this->dimensions[3] * this->dimensions[3];

	T_Mag = ::sqrt(T_Mag);

	return T_Mag;

}

float A_Vector4::DotProduct(A_Vector4* const _AV) const {

	float T_Dot;

	T_Dot = this->dimensions[0] * _AV->dimensions[0];
	T_Dot += this->dimensions[1] * _AV->dimensions[1];
	T_Dot += this->dimensions[2] * _AV->dimensions[2];
	T_Dot += this->dimensions[3] * _AV->dimensions[3];

	return T_Dot;

}

const A_Vector4 A_Vector4::Normal() {

	float T_Mag = this->GetMagnatude();
	A_Vector4 T_Vec = *this;

	T_Vec.dimensions[0] /= T_Mag;
	T_Vec.dimensions[1] /= T_Mag;
	T_Vec.dimensions[2] /= T_Mag;
	T_Vec.dimensions[3] /= T_Mag;

	return T_Vec;

}

void A_Vector4::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->dimensions[0] /= T_Mag;
	this->dimensions[1] /= T_Mag;
	this->dimensions[2] /= T_Mag;
	this->dimensions[3] /= T_Mag;

}

A_Vector4::~A_Vector4() {

	//:)

}