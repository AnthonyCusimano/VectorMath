#include "A_Matrix4x2.h"

A_Matrix4x2::A_Matrix4x2() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] = this->demensions[3] =
		this->demensions[4] = this->demensions[5] = this->demensions[6] = this->demensions[7] = 0.0f;

}

A_Matrix4x2::A_Matrix4x2(A_Matrix4x2* const _AM) {

	this->demensions[0] = _AM->demensions[0];
	this->demensions[1] = _AM->demensions[1];
	this->demensions[2] = _AM->demensions[2];
	this->demensions[3] = _AM->demensions[3];
	this->demensions[4] = _AM->demensions[4];
	this->demensions[5] = _AM->demensions[5];
	this->demensions[6] = _AM->demensions[6];
	this->demensions[7] = _AM->demensions[7];

}

A_Matrix4x2::A_Matrix4x2(A_Vector2* const _AV1, A_Vector2* const _AV2, A_Vector2* const _AV3, A_Vector2* const _AV4) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();

	this->demensions[2] = _AV2->getX();
	this->demensions[3] = _AV2->getY();

	this->demensions[4] = _AV3->getX();
	this->demensions[5] = _AV3->getY();
	
	this->demensions[6] = _AV4->getX();
	this->demensions[7] = _AV4->getY();

}

A_Matrix4x2::A_Matrix4x2(float const _f[]) {

	for (int i = 0; i < 8; ++i) {

		this->demensions[i] = _f[i];

	}

}

const A_Vector4 A_Matrix4x2::GetColumnAtAddress(int const _ad) {

	A_Vector4 T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[_ad + 2]);
	T_Result.setZ(this->demensions[_ad + 4]);
	T_Result.setW(this->demensions[_ad + 6]);

	return T_Result;

}

void A_Matrix4x2::SetColumnAtAddress(int const _ad, A_Vector4* const _AV) {

	this->demensions[_ad] = _AV->getX();
	this->demensions[_ad + 2] = _AV->getY();
	this->demensions[_ad + 4] = _AV->getZ();
	this->demensions[_ad + 6] = _AV->getW();

}

const A_Vector2 A_Matrix4x2::GetRowAtAddress(int _ad) {

	A_Vector2 T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[++_ad]);

	return T_Result;

}

void A_Matrix4x2::SetRowAtAddress(int _ad, A_Vector2* const _AV) {

	//0*2 || 1*2 || 2*2 || 3*2
	_ad *= 2;

	this->demensions[_ad] = _AV->getX();
	this->demensions[++_ad] = _AV->getY();

}

A_Matrix4x2::~A_Matrix4x2() {

	//=D

}