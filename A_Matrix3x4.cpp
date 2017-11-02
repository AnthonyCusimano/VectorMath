#include "A_Matrix3x4.h"

A_Matrix3x4::A_Matrix3x4() {

	this->dimensions[0] = this->dimensions[1] = this->dimensions[2] = this->dimensions[3] =
		this->dimensions[4] = this->dimensions[5] = this->dimensions[6] = this->dimensions[7] =
		this->dimensions[8] = this->dimensions[9] = this->dimensions[10] = this->dimensions[11] = 0.0f;

}

A_Matrix3x4::A_Matrix3x4(A_Matrix3x4* const _AM) {

	this->dimensions[0] = _AM->dimensions[0];
	this->dimensions[1] = _AM->dimensions[1];
	this->dimensions[2] = _AM->dimensions[2];
	this->dimensions[3] = _AM->dimensions[3];
	this->dimensions[4] = _AM->dimensions[4];
	this->dimensions[5] = _AM->dimensions[5];
	this->dimensions[6] = _AM->dimensions[6];
	this->dimensions[7] = _AM->dimensions[7];
	this->dimensions[8] = _AM->dimensions[8];
	this->dimensions[9] = _AM->dimensions[9];
	this->dimensions[10] = _AM->dimensions[10];
	this->dimensions[11] = _AM->dimensions[11];

}

A_Matrix3x4::A_Matrix3x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[1] = _AV1->getY();
	this->dimensions[2] = _AV1->getZ();
	this->dimensions[3] = _AV1->getW();

	this->dimensions[4] = _AV2->getX();
	this->dimensions[5] = _AV2->getY();
	this->dimensions[6] = _AV2->getZ();
	this->dimensions[7] = _AV2->getW();

	this->dimensions[8] = _AV3->getX();
	this->dimensions[9] = _AV3->getY();
	this->dimensions[10] = _AV3->getZ();
	this->dimensions[11] = _AV3->getW();

}

A_Matrix3x4::A_Matrix3x4(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, A_Vector3* const _AV4) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[4] = _AV1->getY();
	this->dimensions[8] = _AV1->getZ();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[5] = _AV2->getY();
	this->dimensions[9] = _AV2->getZ();

	this->dimensions[2] = _AV3->getX();
	this->dimensions[6] = _AV3->getY();
	this->dimensions[10] = _AV3->getZ();

	this->dimensions[3] = _AV4->getX();
	this->dimensions[7] = _AV4->getY();
	this->dimensions[11] = _AV4->getZ();

}

A_Matrix3x4::A_Matrix3x4(float const _f[]) {

	for (int i = 0; i < 12; ++i) {

		this->dimensions[i] = _f[i];

	}

}

const A_Vector3 A_Matrix3x4::GetColumnAtAddress(int const _ad) {

	A_Vector3 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[_ad + 4]);
	T_Result.setZ(this->dimensions[_ad + 8]);


	return T_Result;

}

void A_Matrix3x4::SetColumnAtAddress(int const _ad, A_Vector3* const _AV) {

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[_ad + 4] = _AV->getY();
	this->dimensions[_ad + 8] = _AV->getZ();


}

const A_Vector4 A_Matrix3x4::GetRowAtAddress(int _ad) {

	A_Vector4 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[++_ad]);
	T_Result.setZ(this->dimensions[++_ad]);
	T_Result.setW(this->dimensions[++_ad]);

	return T_Result;

}

void A_Matrix3x4::SetRowAtAddress(int _ad, A_Vector4* const _AV) {

	//0*4 || 1*4 || 2*4
	_ad *= 4;

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[++_ad] = _AV->getY();
	this->dimensions[++_ad] = _AV->getZ();
	this->dimensions[++_ad] = _AV->getW();

}

A_Matrix3x4::~A_Matrix3x4() {

	//=D

}