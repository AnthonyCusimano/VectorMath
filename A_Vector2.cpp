#include "A_Vector2.h"

A_Vector2::A_Vector2(float const _x, float const _y) {

	this->demensions[0] = _x;
	this->demensions[1] = _y;

}

A_Vector2::A_Vector2() {

	this->demensions[0] = 0;
	this->demensions[1] = 0;

}

A_Vector2::A_Vector2(A_Vector2 const *_AV) {

	this->demensions[0] = _AV->demensions[0];
	this->demensions[1] = _AV->demensions[1];

}

const float A_Vector2::GetMagnatude() const{

	float T_Mag = this->demensions[0] * this->demensions[0];
	T_Mag += (this->demensions[1] * this->demensions[1]);

	T_Mag = ::sqrt(T_Mag);
	return T_Mag;
}

const float A_Vector2::DotProduct(A_Vector2 const *_AV)const {

	float T_Dot;
	T_Dot = _AV->demensions[0] * this->demensions[0];
	T_Dot += _AV->demensions[1] * this->demensions[1];

	return T_Dot;

}

const A_Vector2 A_Vector2::Normal() {

	float T_Mag = this->GetMagnatude();
	
	A_Vector2 T_Vec;

	T_Vec.SetAll(this->demensions[0], this->demensions[1]);

	T_Vec.demensions[0] /= T_Mag;
	T_Vec.demensions[1] /= T_Mag;

	return T_Vec;

}

void A_Vector2::Normalize() {

	float T_Mag = this->GetMagnatude();

	this->demensions[0] /= T_Mag;
	this->demensions[1] /= T_Mag;

}

A_Vector2::~A_Vector2() {

	

}