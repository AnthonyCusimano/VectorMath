#include "A_Vector3.h"

A_Vector3::A_Vector3() {

	this->demensions[0] = 0;
	this->demensions[1] = 0;
	this->demensions[2] = 0;

}

A_Vector3::A_Vector3(float const _n) {

	this->demensions[0] = _n;
	this->demensions[1] = _n;
	this->demensions[2] = _n;

}

A_Vector3::A_Vector3(const float const _x, const float const _y, const float const _z) {

	this->demensions[0] = _x;
	this->demensions[1] = _y;
	this->demensions[2] = _z;

}

A_Vector3::A_Vector3( A_Vector3* const _AV) {

	this->demensions[0] = _AV->demensions[0];
	this->demensions[1] = _AV->demensions[1];
	this->demensions[2] = _AV->demensions[2];

}

A_Vector3::A_Vector3(A_Vector2* const _AV, float const _z) {

	this->demensions[0] = _AV->getX();
	this->demensions[1] = _AV->getY();
	this->demensions[2] = _z;

}

float A_Vector3::GetMagnatude() {

	float T_Mag = this->demensions[0] * this->demensions[0];
	T_Mag += (this->demensions[1] * this->demensions[1]);
	T_Mag += (this->demensions[2] * this->demensions[2]);
	T_Mag = ::sqrt(T_Mag);
	return T_Mag;
}

float A_Vector3::DotProduct(const A_Vector3 const *_AV)const {

	float T_Dot;
	T_Dot = _AV->demensions[0] * this->demensions[0];
	T_Dot += _AV->demensions[1] * this->demensions[1];
	T_Dot += _AV->demensions[2] * this->demensions[2];

	return T_Dot;

}

const A_Vector3 A_Vector3::CrossProduct(A_Vector3 const *_AV) {

	A_Vector3 T_Cross;

	T_Cross.demensions[0] = (this->demensions[1] * _AV->demensions[2]) - (this->demensions[2] * _AV->demensions[1]);
	T_Cross.demensions[1] = (this->demensions[2] * _AV->demensions[0]) - (this->demensions[0] * _AV->demensions[2]);
	T_Cross.demensions[2] = (this->demensions[0] * _AV->demensions[1]) - (this->demensions[1] * _AV->demensions[0]);

	return T_Cross;

}

const A_Vector3 A_Vector3::Normal() {

	//test

	float T_Mag = this->GetMagnatude();
	A_Vector3 T_Vec = *this;

	T_Vec.demensions[0] /= T_Mag;
	T_Vec.demensions[1] /= T_Mag;
	T_Vec.demensions[2] /= T_Mag;

	return T_Vec;


}

void A_Vector3::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->demensions[0] /= T_Mag;
	this->demensions[1] /= T_Mag;
	this->demensions[2] /= T_Mag;

}

A_Vector3::~A_Vector3() {



}