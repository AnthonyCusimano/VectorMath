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

A_Matrix2x3::~A_Matrix2x3() {

	//=D

}