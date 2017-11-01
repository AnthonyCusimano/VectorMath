#include "A_Matrix2x2.h"

A_Matrix2x2::A_Matrix2x2() {

	this->demensions[0] = this->demensions[1] = 0.0f;
	this->demensions[2] = this->demensions[3] = 0.0f;

}

A_Matrix2x2::A_Matrix2x2(float const _f) {

	if (_f == 0.0f) {

		this->demensions[0] = this->demensions[3] = 1.0f;
		this->demensions[1] = this->demensions[2] = 0.0f;

	}

	else {

		this->demensions[0] = this->demensions[3] =
			this->demensions[1] = this->demensions[2] = _f;

	}

}

A_Matrix2x2::A_Matrix2x2(A_Matrix2x2* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];

}

A_Matrix2x2::A_Matrix2x2(A_Vector2* const _AV1, A_Vector2* const _AV2) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();

	this->demensions[2] = _AV2->getX();
	this->demensions[3] = _AV2->getY();

}

A_Matrix2x2::A_Matrix2x2(float const _f[]) {

	this->demensions[0] = _f[0];
	this->demensions[1] = _f[1];
	this->demensions[2] = _f[2];
	this->demensions[3] = _f[3];

}


const A_Vector2 A_Matrix2x2::GetColumnAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.SetAll(this->demensions[_ad], this->demensions[_ad + 2]);

	return T_Result;

}

void A_Matrix2x2::SetColumnAtAddress(int const _ad, A_Vector2 * _AQ) {

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 2] = _AQ->getY();

}

const A_Vector2 A_Matrix2x2::GetRowAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.SetAll(this->demensions[_ad], this->demensions[_ad + 1]);

	return T_Result;

}

void A_Matrix2x2::SetRowAtAddress(int _ad, A_Vector2* const _AQ) {

	_ad *= 2;

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 1] = _AQ->getY();

}

void A_Matrix2x2::setIdentity() {

	this->demensions[0] = this->demensions[3] = 1.0f;
	this->demensions[1] = this->demensions[2] = 0.0f;

}

void A_Matrix2x2::Invert() {

	float T_Determinant;

	T_Determinant = this->demensions[0] * this->demensions[3] - this->demensions[1] * this->demensions[2];

	this->demensions[0] /= T_Determinant;
	this->demensions[1] /= T_Determinant;
	this->demensions[2] /= T_Determinant;
	this->demensions[3] /= T_Determinant;

}

const A_Matrix2x2 A_Matrix2x2::GetTransposed() {

	A_Matrix2x2 T_Result;

	float T_Placehold = this->demensions[1];

	T_Result.demensions[0] = this->demensions[0];
	T_Result.demensions[1] = this->demensions[2];
	T_Result.demensions[2] = T_Placehold;
	T_Result.demensions[3] = this->demensions[3];

	return T_Result;

}

void A_Matrix2x2::SetTranposed() {

	float T_Placehold = this->demensions[1];

	//this->demensions[0] stays the same
	this->demensions[1] = this->demensions[2];
	this->demensions[2] = T_Placehold;
	//this->demensions[3] stays the same

}

A_Matrix2x2::~A_Matrix2x2() {

	//=D

}