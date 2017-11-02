#include "A_Matrix2x3.h"

A_Matrix2x3::A_Matrix2x3() {

	this->dimensions[0] = this->dimensions[1] = this->dimensions[2] =
		this->dimensions[3] = this->dimensions[4] = this->dimensions[5] = 0.0f;

}

A_Matrix2x3::A_Matrix2x3(A_Matrix2x3* const _AM) {

	this->dimensions[0] = _AM->dimensions[0];
	this->dimensions[1] = _AM->dimensions[1];
	this->dimensions[2] = _AM->dimensions[2];
	this->dimensions[3] = _AM->dimensions[3];
	this->dimensions[4] = _AM->dimensions[4];
	this->dimensions[5] = _AM->dimensions[5];

}

A_Matrix2x3::A_Matrix2x3(A_Vector3* const _AV1, A_Vector3* const _AV2) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[1] = _AV1->getX();
	this->dimensions[2] = _AV1->getX();

	this->dimensions[3] = _AV2->getX();
	this->dimensions[4] = _AV2->getY();
	this->dimensions[5] = _AV2->getZ();

}

A_Matrix2x3::A_Matrix2x3(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[3] = _AV1->getY();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[4] = _AV2->getY();

	this->dimensions[2] = _AV3->getX();
	this->dimensions[5] = _AV3->getY();

}

A_Matrix2x3::A_Matrix2x3(float const _f[]) {

	for (int i = 0; i < 6; ++i) {

		this->dimensions[i] = _f[i];

	}

}

const A_Vector2 A_Matrix2x3::GetColumnAtAddress(int const _ad) {

	A_Vector2 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[3 + _ad]);

	return T_Result;

}

void A_Matrix2x3::SetColumnAtAddress(int const _ad, A_Vector2* const _AV) {

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[_ad + 3] = _AV->getY();

}

const A_Vector3 A_Matrix2x3::GetRowAtAddress(int _ad) {

	A_Vector3 T_Result;

	//0*3 || 1*3
	_ad *= 3;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[++_ad]);
	T_Result.setZ(this->dimensions[++_ad]);

	return T_Result;

}

void A_Matrix2x3::SetRowAtAddress(int _ad, A_Vector3* const _AV) {

	//0*3 || 1*3
	_ad *= 3;

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[++_ad] = _AV->getY();
	this->dimensions[++_ad] = _AV->getZ();

}

A_Matrix2x3::~A_Matrix2x3() {

	//=D

}