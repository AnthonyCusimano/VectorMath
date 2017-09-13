#include "A_Matrix3x4.h"

A_Matrix3x4::A_Matrix3x4() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] = this->demensions[3] =
		this->demensions[4] = this->demensions[5] = this->demensions[6] = this->demensions[7] =
		this->demensions[8] = this->demensions[9] = this->demensions[10] = this->demensions[11] = 0.0f;

}

A_Matrix3x4::A_Matrix3x4(A_Matrix3x4* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];
	this->demensions[4] = _AM->demensions[4];
	this->demensions[5] = _AM->demensions[5];
	this->demensions[6] = _AM->demensions[6];
	this->demensions[7] = _AM->demensions[7];
	this->demensions[8] = _AM->demensions[8];
	this->demensions[9] = _AM->demensions[9];
	this->demensions[10] = _AM->demensions[10];
	this->demensions[11] = _AM->demensions[11];

}

A_Matrix3x4::A_Matrix3x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();
	this->demensions[2] = _AV1->getZ();
	this->demensions[3] = _AV1->getW();

	this->demensions[4] = _AV2->getX();
	this->demensions[5] = _AV2->getY();
	this->demensions[6] = _AV2->getZ();
	this->demensions[7] = _AV2->getW();

	this->demensions[8] = _AV3->getX();
	this->demensions[9] = _AV3->getY();
	this->demensions[10] = _AV3->getZ();
	this->demensions[11] = _AV3->getW();

}

A_Matrix3x4::A_Matrix3x4(float const _f[]) {

	for (int i = 0; i < 12; ++i) {

		this->demensions[i] = _f[i];

	}

}

A_Matrix3x4::~A_Matrix3x4() {

	//=D

}