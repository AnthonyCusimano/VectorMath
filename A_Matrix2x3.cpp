#include "A_Matrix2x3.h"

A_Matrix2x3::A_Matrix2x3() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] =
		this->demensions[3] = this->demensions[4] = this->demensions[5] = 0.0f;

}

A_Matrix2x3::A_Matrix2x3(A_Matrix2x3* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];
	this->demensions[4] = _AM->demensions[4];
	this->demensions[5] = _AM->demensions[5];

}

A_Matrix2x3::A_Matrix2x3(A_Vector3* const _AV1, A_Vector3* const _AV2) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getX();
	this->demensions[2] = _AV1->getX();

	this->demensions[3] = _AV2->getX();
	this->demensions[4] = _AV2->getY();
	this->demensions[5] = _AV2->getZ();

}

A_Matrix2x3::A_Matrix2x3(float const _f[]) {

	for (int i = 0; i < 6; ++i) {

		this->demensions[i] = _f[i];

	}

}

const A_Vector2 A_Matrix2x3::GetColumnAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.SetX(this->demensions[_ad]);
	T_Result.SetY(this->demensions[3 + _ad]);

	return T_Result;

}

void A_Matrix2x3::SetColumnAtAddress(int const _ad, A_Vector2* const _AQ) {

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 3] = _AQ->getY();

}

const A_Vector3 A_Matrix2x3::GetRowAtAddress(int _ad) {

	A_Vector3 T_Result;

	//0*3 || 1*3
	_ad *= 3;

	T_Result.SetX(this->demensions[_ad]);
	T_Result.SetY(this->demensions[_ad + 1]);
	T_Result.SetZ(this->demensions[_ad + 2]);

	return T_Result;

}

void A_Matrix2x3::SetRowAtAddress(int _ad, A_Vector3* const _AV) {

	//0*3 || 1*3
	_ad *= 3;

	this->demensions[_ad] = _AV->getX();
	this->demensions[_ad + 1] = _AV->getY();
	this->demensions[_ad + 2] = _AV->getZ();

}

A_Matrix2x3::~A_Matrix2x3() {

	//=D

}