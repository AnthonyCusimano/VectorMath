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

const A_Quaternion A_Matrix4x4::GetColumnAtAddress(int const _ad) {

	//could error check _ad
	char i = (_ad * 4);
	A_Quaternion T_Result;

	T_Result.setX(this->demensions[i]);
	T_Result.setY(this->demensions[i + 1]);
	T_Result.setZ(this->demensions[i + 2]);
	T_Result.setW(this->demensions[i + 3]);

	return T_Result;

}

void A_Matrix4x4::SetColumnAtAddress(int const _ad, A_Quaternion *_AQ) {

	char i = (_ad * 4);

	this->demensions[i] = _AQ->getX();
	this->demensions[i + 1] = _AQ->getY();
	this->demensions[i + 2] = _AQ->getZ();
	this->demensions[i + 3] = _AQ->getW();

}

const A_Quaternion A_Matrix4x4::GetRowAtAddress(int const _ad) {

	A_Quaternion T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[_ad + 4]);
	T_Result.setZ(this->demensions[_ad + 8]);
	T_Result.setW(this->demensions[_ad + 12]);

	return T_Result;

}

void A_Matrix4x4::SetRowAtAddress(int const _ad, A_Quaternion *_AQ) {

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 4] = _AQ->getY();
	this->demensions[_ad + 8] = _AQ->getZ();
	this->demensions[_ad + 12] = _AQ->getW();

}

void A_Matrix4x4::setIdentity() {

	for (char i = 0; i < 16; ++i) {

		if (i == 0 || i == 5 || i == 10 || i == 15) {

			this->demensions[i] = 1.0f;

		}

		else demensions[i] = 0.0f;

	}

}



const A_Matrix4x4 A_Matrix4x4::GetTransposed() {

	A_Matrix4x4 T_Result;

	//this->demensions[0] stays the same
	T_Result.demensions[1] = this->demensions[4];
	T_Result.demensions[2] = this->demensions[8];
	T_Result.demensions[3] = this->demensions[12];
	T_Result.demensions[4] = this->demensions[1];
	//this->demensions[5] stays the same
	T_Result.demensions[6] = this->demensions[9];
	T_Result.demensions[7] = this->demensions[13];
	T_Result.demensions[8] = this->demensions[2];
	T_Result.demensions[9] = this->demensions[6];
	//this->demensions[10] stays the same
	T_Result.demensions[11] = this->demensions[14];
	T_Result.demensions[12] = this->demensions[3];
	T_Result.demensions[13] = this->demensions[7];
	T_Result.demensions[14] = this->demensions[11];
	//this->demensions[15] stays the same

	return T_Result;

}

void A_Matrix4x4::SetTranposed() {

	A_Matrix4x4 T_Placehold;

	//this->demensions[0] stays the same

	//need to preserve this->demensions[1] for later
	T_Placehold.demensions[1] = this->demensions[1];
	this->demensions[1] = this->demensions[4];

	//need to preserve this->demensions[2] for later
	T_Placehold.demensions[2] = this->demensions[2];
	this->demensions[2] = this->demensions[8];

	//need to preserve this->demensions[3] for later
	T_Placehold.demensions[3] = this->demensions[3];
	this->demensions[3] = this->demensions[12];

	//held the old demensions[1] in T_Placehold
	this->demensions[4] = T_Placehold.demensions[1];

	//this->demensions[5] stays the same

	//need to preserve this->demensions[6] for later
	T_Placehold.demensions[6] = this->demensions[6];
	this->demensions[6] = this->demensions[9];

	//need to preserve this->demensions[7] for later
	T_Placehold.demensions[7] = this->demensions[7];
	this->demensions[7] = this->demensions[13];

	//held the old demensions[2] in T_Placehold
	this->demensions[8] = T_Placehold.demensions[2];

	//held the old demensions[6] in T_Placehold
	this->demensions[9] = T_Placehold.demensions[6];

	//this0->demensions[10] stays the same

	//need to preserve this->demensions[11] until later
	T_Placehold.demensions[11] = this->demensions[11];
	this->demensions[11] = this->demensions[14];

	//held the old this->demensions[3] in T_Placehold
	this->demensions[12] = T_Placehold.demensions[3];

	//held the old this->demensions[7] in T_Placehold
	this->demensions[13] = T_Placehold.demensions[7];

	//held the old this->demensions[11] in T_Placehold
	this->demensions[14] = T_Placehold.demensions[11];

	//this->demensions[15] stays the same

}

A_Matrix4x4::~A_Matrix4x4() {



}