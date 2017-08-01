#include "A_Matrix4x4.h"

A_Matrix4x4::A_Matrix4x4() {

	for (int i = 0; i < 16; ++i) {

		this->demensions[i] = 0.0f;

	}

}

A_Matrix4x4::A_Matrix4x4(float const _f) {

	if (_f == 0) {

		for (char i = 0; i < 16; ++i) {

			if (i == 0 || i == 5 || i == 10 || i == 15) {

				this->demensions[i] = 1.0f;

			}

			else demensions[i] = 0.0f;

		}

	}

	else {

		for (char i = 0; i < 16; ++i) {

			this->demensions[i] = _f;

		}

	}

}

A_Matrix4x4::A_Matrix4x4(A_Matrix4x4 const *_AM) {

	for (char i = 0; i < 16; ++i) {

		this->demensions[i] = _AM->demensions[i];

	}

}

A_Matrix4x4::A_Matrix4x4(A_Quaternion *_AQ1, A_Quaternion *_AQ2, A_Quaternion *_AQ3, A_Quaternion *_AQ4) {
	
	this->demensions[0] = _AQ1->getX();
	this->demensions[1] = _AQ1->getY();
	this->demensions[2] = _AQ1->getZ();
	this->demensions[3] = _AQ1->getW();

	this->demensions[4] = _AQ2->getX();
	this->demensions[5] = _AQ2->getY();
	this->demensions[6] = _AQ2->getZ();
	this->demensions[7] = _AQ2->getW();

	this->demensions[8] = _AQ3->getX();
	this->demensions[9] = _AQ3->getY();
	this->demensions[10] = _AQ3->getZ();
	this->demensions[11] = _AQ3->getW();

	this->demensions[12] = _AQ4->getX();
	this->demensions[13] = _AQ4->getY();
	this->demensions[14] = _AQ4->getZ();
	this->demensions[15] = _AQ4->getW();

}

A_Matrix4x4::A_Matrix4x4(float const _f[]) {

	for (char i = 0; i < 16; ++i) {

		this->demensions[i] = _f[i];

	}

}

A_Matrix4x4::~A_Matrix4x4() {



}