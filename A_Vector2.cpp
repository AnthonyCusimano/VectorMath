#include "A_Vector2.h"

A_Vector2::A_Vector2() {

	this->dimensions[0] = 0;
	this->dimensions[1] = 0;

}

A_Vector2::A_Vector2(float const _n) {

	this->dimensions[0] = this->dimensions[1] = _n;

}

A_Vector2::A_Vector2(float const _x, float const _y) {

	this->dimensions[0] = _x;
	this->dimensions[1] = _y;

}

A_Vector2::A_Vector2(A_Vector2 const *_AV) {

	this->dimensions[0] = _AV->dimensions[0];
	this->dimensions[1] = _AV->dimensions[1];

}

const float A_Vector2::GetMagnatude() const{

	float T_Mag = this->dimensions[0] * this->dimensions[0];
	T_Mag += (this->dimensions[1] * this->dimensions[1]);

	T_Mag = ::sqrt(T_Mag);
	return T_Mag;
}

const float A_Vector2::DotProduct(A_Vector2 const *_AV)const {

	float T_Dot;
	T_Dot = _AV->dimensions[0] * this->dimensions[0];
	T_Dot += _AV->dimensions[1] * this->dimensions[1];

	return T_Dot;

}

const A_Vector2 A_Vector2::Normal() {

	float T_Mag = this->GetMagnatude();
	
	A_Vector2 T_Vec;

	T_Vec.SetAll(this->dimensions[0], this->dimensions[1]);

	T_Vec.dimensions[0] /= T_Mag;
	T_Vec.dimensions[1] /= T_Mag;

	return T_Vec;

}

void A_Vector2::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->dimensions[0] /= T_Mag;
	this->dimensions[1] /= T_Mag;

}

A_Vector2::~A_Vector2() {

	

}