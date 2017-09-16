#include "A_Matrix2x4.h"

A_Matrix2x4::A_Matrix2x4() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] = this->demensions[3] =
		this->demensions[4] = this->demensions[5] = this->demensions[6] = this->demensions[7] = 0.0f;

}

A_Matrix2x4::A_Matrix2x4(A_Matrix2x4* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];
	this->demensions[4] = _AM->demensions[4];
	this->demensions[5] = _AM->demensions[5];
	this->demensions[6] = _AM->demensions[6];
	this->demensions[7] = _AM->demensions[7];

}

A_Matrix2x4::A_Matrix2x4(A_Vector4* const _AV1, A_Vector4* const _AV2) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();
	this->demensions[2] = _AV1->getZ();
	this->demensions[3] = _AV1->getW();

	this->demensions[4] = _AV2->getX();
	this->demensions[5] = _AV2->getY();
	this->demensions[6] = _AV2->getZ();
	this->demensions[7] = _AV2->getW();

}

A_Matrix2x4::A_Matrix2x4(float const _f[]) {

	for (int i = 0; i < 8; ++i) {

		this->demensions[i] = _f[i];

	}

}

void A_Matrix2x4::SetRowAtAddress(int _ad, A_Vector4* const _AV) {

	//0*4 || 1*4
	_ad *= 4;

	this->demensions[_ad] = _AV->getX();
	this->demensions[_ad + 1] = _AV->getY();
	this->demensions[_ad + 2] = _AV->getZ();
	this->demensions[_ad + 3] = _AV->getW();

}

A_Matrix2x4::~A_Matrix2x4() {

	//=D

}