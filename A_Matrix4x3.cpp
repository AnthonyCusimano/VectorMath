#include "A_Matrix4x3.h"

A_Matrix4x3::A_Matrix4x3() {

	this->demensions[0] = this->demensions[1] = this->demensions[2] = this->demensions[3] =
		this->demensions[4] = this->demensions[5] = this->demensions[6] = this->demensions[7] = 
		this->demensions[8] = this->demensions[9] = this->demensions[10] = this->demensions[11] = 0.0f;

}

A_Matrix4x3::A_Matrix4x3(A_Matrix4x3* const _AM) {

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

A_Matrix4x3::A_Matrix4x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, A_Vector3* const _AV4) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();
	this->demensions[2] = _AV1->getZ();

	this->demensions[3] = _AV2->getX();
	this->demensions[4] = _AV2->getY();
	this->demensions[5] = _AV2->getZ();

	this->demensions[6] = _AV3->getX();
	this->demensions[7] = _AV3->getY();
	this->demensions[8] = _AV3->getZ();

	this->demensions[9] = _AV4->getX();
	this->demensions[10] = _AV4->getY();
	this->demensions[11] = _AV4->getZ();

}

A_Matrix4x3::A_Matrix4x3(float const _f[]) {

	for (int i = 0; i < 12; ++i) {

		this->demensions[i] = _f[i];

	}

}

const A_Vector4 A_Matrix4x3::GetColumnAtAddress(int const _ad) {

	A_Vector4 T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[_ad + 3]);
	T_Result.setZ(this->demensions[_ad + 6]);
	T_Result.setW(this->demensions[_ad + 9]);
	
	return T_Result;

}

void A_Matrix4x3::SetColumnAtAddress(int const _ad, A_Vector4* const _AV) {

	this->demensions[_ad] = _AV->getX();
	this->demensions[_ad + 3] = _AV->getY();
	this->demensions[_ad + 6] = _AV->getZ();
	this->demensions[_ad + 9] = _AV->getW();

}

const A_Vector3 A_Matrix4x3::GetRowAtAddress(int _ad) {

	A_Vector3 T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[++_ad]);
	T_Result.setZ(this->demensions[++_ad]);

	return T_Result;

}

void A_Matrix4x3::SetRowAtAddress(int _ad, A_Vector3* const _AV) {

	//0*3 || 1*3 || 2*3 || 3*3
	_ad *= 3;

	this->demensions[_ad] = _AV->getX();
	this->demensions[++_ad] = _AV->getY();
	this->demensions[++_ad] = _AV->getZ();

}

A_Matrix4x3::~A_Matrix4x3() {

	//=D

}