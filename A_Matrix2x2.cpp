#include "A_Matrix2x2.h"

A_Matrix2x2::A_Matrix2x2() {

	this->dimensions[0] = this->dimensions[1] = 0.0f;
	this->dimensions[2] = this->dimensions[3] = 0.0f;

}

A_Matrix2x2::A_Matrix2x2(float const _f) {

	if (_f == 0.0f) {

		this->dimensions[0] = this->dimensions[3] = 1.0f;
		this->dimensions[1] = this->dimensions[2] = 0.0f;

	}

	else {

		this->dimensions[0] = this->dimensions[3] =
			this->dimensions[1] = this->dimensions[2] = _f;

	}

}

A_Matrix2x2::A_Matrix2x2(A_Matrix2x2* const _AM) {

	this->dimensions[0] = _AM->dimensions[0];
	this->dimensions[1] = _AM->dimensions[1];
	this->dimensions[2] = _AM->dimensions[2];
	this->dimensions[3] = _AM->dimensions[3];

}

A_Matrix2x2::A_Matrix2x2(A_Vector2* const _AV1, A_Vector2* const _AV2) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[1] = _AV1->getY();

	this->dimensions[2] = _AV2->getX();
	this->dimensions[3] = _AV2->getY();

}

A_Matrix2x2::A_Matrix2x2(A_Vector2* const _AV1, A_Vector2* const _AV2, char const unUsedColumnConstructor) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[2] = _AV1->getY();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[3] = _AV2->getY();

}

A_Matrix2x2::A_Matrix2x2(float const _f[]) {

	this->dimensions[0] = _f[0];
	this->dimensions[1] = _f[1];
	this->dimensions[2] = _f[2];
	this->dimensions[3] = _f[3];

}


const A_Vector2 A_Matrix2x2::GetColumnAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.SetAll(this->dimensions[_ad], this->dimensions[_ad + 2]);

	return T_Result;

}

void A_Matrix2x2::SetColumnAtAddress(int const _ad, A_Vector2 * _AQ) {

	this->dimensions[_ad] = _AQ->getX();
	this->dimensions[_ad + 2] = _AQ->getY();

}

const A_Vector2 A_Matrix2x2::GetRowAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.SetAll(this->dimensions[_ad], this->dimensions[_ad + 1]);

	return T_Result;

}

void A_Matrix2x2::SetRowAtAddress(int _ad, A_Vector2* const _AQ) {

	_ad *= 2;

	this->dimensions[_ad] = _AQ->getX();
	this->dimensions[++_ad] = _AQ->getY();

}

void A_Matrix2x2::setIdentity() {

	this->dimensions[0] = this->dimensions[3] = 1.0f;
	this->dimensions[1] = this->dimensions[2] = 0.0f;

}

void A_Matrix2x2::Invert() {

	float T_Determinant;

	T_Determinant = this->dimensions[0] * this->dimensions[3] - this->dimensions[1] * this->dimensions[2];

	this->dimensions[0] /= T_Determinant;
	this->dimensions[1] /= T_Determinant;
	this->dimensions[2] /= T_Determinant;
	this->dimensions[3] /= T_Determinant;

}

const A_Matrix2x2 A_Matrix2x2::GetTransposed() {

	A_Matrix2x2 T_Result;

	float T_Placehold = this->dimensions[1];

	T_Result.dimensions[0] = this->dimensions[0];
	T_Result.dimensions[1] = this->dimensions[2];
	T_Result.dimensions[2] = T_Placehold;
	T_Result.dimensions[3] = this->dimensions[3];

	return T_Result;

}

void A_Matrix2x2::SetTranposed() {

	float T_Placehold = this->dimensions[1];

	//this->demensions[0] stays the same
	this->dimensions[1] = this->dimensions[2];
	this->dimensions[2] = T_Placehold;
	//this->demensions[3] stays the same

}

A_Matrix2x2::~A_Matrix2x2() {

	//=D

}