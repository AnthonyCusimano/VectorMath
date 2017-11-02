#include "A_Matrix4x2.h"

A_Matrix4x2::A_Matrix4x2() {

	this->dimensions[0] = this->dimensions[1] = this->dimensions[2] = this->dimensions[3] =
		this->dimensions[4] = this->dimensions[5] = this->dimensions[6] = this->dimensions[7] = 0.0f;

}

A_Matrix4x2::A_Matrix4x2(A_Matrix4x2* const _AM) {

	this->dimensions[0] = _AM->dimensions[0];
	this->dimensions[1] = _AM->dimensions[1];
	this->dimensions[2] = _AM->dimensions[2];
	this->dimensions[3] = _AM->dimensions[3];
	this->dimensions[4] = _AM->dimensions[4];
	this->dimensions[5] = _AM->dimensions[5];
	this->dimensions[6] = _AM->dimensions[6];
	this->dimensions[7] = _AM->dimensions[7];

}

A_Matrix4x2::A_Matrix4x2(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3, A_Vector2* const _AV4) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[1] = _AV1->getY();

	this->dimensions[2] = _AV2->getX();
	this->dimensions[3] = _AV2->getY();

	this->dimensions[4] = _AV3->getX();
	this->dimensions[5] = _AV3->getY();
	
	this->dimensions[6] = _AV4->getX();
	this->dimensions[7] = _AV4->getY();

}

A_Matrix4x2::A_Matrix4x2(A_Vector4* const _AV1, A_Vector4* const _AV2) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[2] = _AV1->getY();
	this->dimensions[4] = _AV1->getZ();
	this->dimensions[6] = _AV1->getW();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[3] = _AV2->getY();
	this->dimensions[5] = _AV2->getZ();
	this->dimensions[7] = _AV2->getW();

}

A_Matrix4x2::A_Matrix4x2(float const _f[]) {

	for (int i = 0; i < 8; ++i) {

		this->dimensions[i] = _f[i];

	}

}

const A_Vector4 A_Matrix4x2::GetColumnAtAddress(int const _ad) {

	A_Vector4 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[_ad + 2]);
	T_Result.setZ(this->dimensions[_ad + 4]);
	T_Result.setW(this->dimensions[_ad + 6]);

	return T_Result;

}

void A_Matrix4x2::SetColumnAtAddress(int const _ad, A_Vector4* const _AV) {

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[_ad + 2] = _AV->getY();
	this->dimensions[_ad + 4] = _AV->getZ();
	this->dimensions[_ad + 6] = _AV->getW();

}

const A_Vector2 A_Matrix4x2::GetRowAtAddress(int _ad) {

	A_Vector2 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[++_ad]);

	return T_Result;

}

void A_Matrix4x2::SetRowAtAddress(int _ad, A_Vector2* const _AV) {

	//0*2 || 1*2 || 2*2 || 3*2
	_ad *= 2;

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[++_ad] = _AV->getY();

}

A_Matrix4x2::~A_Matrix4x2() {

	//=D

}