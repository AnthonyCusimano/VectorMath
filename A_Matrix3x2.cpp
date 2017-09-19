#include "A_Matrix3x2.h"

A_Matrix3x2::A_Matrix3x2() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] =
		this->demensions[3] = this->demensions[4] = this->demensions[5] = 0.0f;

}

A_Matrix3x2::A_Matrix3x2(A_Matrix3x2* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];
	this->demensions[4] = _AM->demensions[4];
	this->demensions[5] = _AM->demensions[5];

}

A_Matrix3x2::A_Matrix3x2(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();

	this->demensions[2] = _AV2->getX();
	this->demensions[3] = _AV2->getY();

	this->demensions[4] = _AV3->getX();
	this->demensions[5] = _AV2->getY();

}

A_Matrix3x2::A_Matrix3x2(float const _f[]) {

	for (int i = 0; i < 6; ++i) {

		this->demensions[i] = _f[i];

	}

}

const A_Vector2 A_Matrix3x2::GetRowAtAddress(int _ad) {

	A_Vector2 T_Result;

	//0*2 || 1*2
	_ad *= 2;

	T_Result.SetX(this->demensions[_ad]);
	T_Result.SetY(this->demensions[_ad + 1]);

	return T_Result;

}

void A_Matrix3x2::SetRowAtAddress(int _ad, A_Vector2* const _AV) {

	//0*2 || 1*2
	_ad *= 2;

	this->demensions[_ad] = _AV->getX();
	this->demensions[_ad + 1] = _AV->getY();

}

A_Matrix3x2::~A_Matrix3x2() {

	//=D

}