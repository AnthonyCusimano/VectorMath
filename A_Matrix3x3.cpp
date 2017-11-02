#include "A_Matrix3x3.h"

A_Matrix3x3::A_Matrix3x3() {

	for (char i = 0; i < 9; ++i) {

		this->dimensions[i] = 0.0f;

	}

}

A_Matrix3x3::A_Matrix3x3(float const _f) {

	if (_f == 0) {

		for (char i = 0; i < 9; ++i) {

			if (i == 0 || i == 4 || i == 8) {

				this->dimensions[i] = 1.0f;

			}

			else dimensions[i] = 0.0f;

		}

	}

	else {

		for (char i = 0; i < 9; ++i) {

			this->dimensions[i] = _f;

		}

	}

}

A_Matrix3x3::A_Matrix3x3(A_Matrix3x3* const _AM) {

	for (char i = 0; i < 9; ++i) {

		this->dimensions[i] = _AM->dimensions[i];

	}

}

A_Matrix3x3::A_Matrix3x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[1] = _AV1->getY();
	this->dimensions[2] = _AV1->getZ();

	this->dimensions[3] = _AV2->getX();
	this->dimensions[4] = _AV2->getY();
	this->dimensions[5] = _AV2->getZ();

	this->dimensions[6] = _AV3->getX();
	this->dimensions[7] = _AV3->getY();
	this->dimensions[8] = _AV3->getZ();

}

A_Matrix3x3::A_Matrix3x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3, char const unUsedColumnConstructor) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[3] = _AV1->getY();
	this->dimensions[6] = _AV1->getZ();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[4] = _AV2->getY();
	this->dimensions[7] = _AV2->getZ();

	this->dimensions[2] = _AV3->getX();
	this->dimensions[5] = _AV3->getY();
	this->dimensions[8] = _AV3->getZ();

}

A_Matrix3x3::A_Matrix3x3(float const _f[]) {

	for (char i = 0; i < 9; ++i) {

		this->dimensions[i] = _f[i];

	}

}

A_Vector3 A_Matrix3x3::GetColumnAtAddress(int const _ad) {

	int i = (_ad * 3);
	A_Vector3 T_Result;

	T_Result.setX(this->dimensions[i]);
	T_Result.setY(this->dimensions[i + 3]);
	T_Result.setZ(this->dimensions[i + 6]);

	return T_Result;

}

void A_Matrix3x3::SetColumnAtAddress(int const _ad, A_Vector3* const _AV) {

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[_ad + 3] = _AV->getY();
	this->dimensions[_ad + 6] = _AV->getZ();

}

A_Vector3 A_Matrix3x3::GetRowAtAddress(int _ad) {

	A_Vector3 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[++_ad]);
	T_Result.setZ(this->dimensions[++_ad]);

	return T_Result;

}

void A_Matrix3x3::SetRowAtAddress(int _ad, A_Vector3 *_AV) {

	_ad *= 3;

	this->dimensions[_ad] = _AV->getX();
	this->dimensions[++_ad] = _AV->getY();
	this->dimensions[++_ad] = _AV->getZ();

}

void A_Matrix3x3::setIdentity() {

	this->dimensions[0] = 1.0f;
	this->dimensions[1] = this->dimensions[2] = this->dimensions[3] = 0.0f;
	this->dimensions[4] = 1.0f;
	this->dimensions[5] = this->dimensions[6] = this->dimensions[7] = 0.0f;
	this->dimensions[8] = 1.0f;

}

const bool A_Matrix3x3::Invert() {

	//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//determinant of this
	float T_Determinant = 0.0f;
	//temp floats needed to assist in finding the determinant, and later assist in finding the final inverse of the matrix
	//names reflect demensions used to assign a value to these variables
	float T_4857_, T_3856_, T_3746_, T_1827_, T_0826_, T_0716_, T_1524_, T_0523_, T_0413_;
	//nothing complex needed, but a matrix placeholder is needed
	float T_Matrix[9];

	//minors, cofactors
	T_4857_ = this->dimensions[4] * this->dimensions[8] - this->dimensions[5] * this->dimensions[7];//0
	T_3856_ = -(this->dimensions[3] * this->dimensions[8] - this->dimensions[5] * this->dimensions[6]);//1
	T_3746_ = this->dimensions[3] * this->dimensions[7] - this->dimensions[4] * this->dimensions[6];//2
	T_1827_ = -(this->dimensions[1] * this->dimensions[8] - this->dimensions[2] * this->dimensions[7]);//3
	T_0826_ = this->dimensions[0] * this->dimensions[8] - this->dimensions[2] * this->dimensions[6];//4
	T_0716_ = -(this->dimensions[0] * this->dimensions[7] - this->dimensions[1] * this->dimensions[6]);//5
	T_1524_ = this->dimensions[1] * this->dimensions[5] - this->dimensions[2] * this->dimensions[4];//6
	T_0523_ = -(this->dimensions[0] * this->dimensions[5] - this->dimensions[2] * this->dimensions[3]);//7
	T_0413_ = this->dimensions[0] * this->dimensions[4] - this->dimensions[1] * this->dimensions[3];//8

	//transpose
	T_Matrix[0] = T_4857_;//0
	T_Matrix[1] = T_1827_;//3
	T_Matrix[2] = T_1524_;//6
	T_Matrix[3] = T_3856_;//1
	T_Matrix[4] = T_0826_;//4
	T_Matrix[5] = T_0523_;//7
	T_Matrix[6] = T_3746_;//2
	T_Matrix[7] = T_0716_;//5
	T_Matrix[8] = T_0413_;//8

	T_Determinant = (this->dimensions[0] * T_4857_) - (this->dimensions[1] * T_3856_) + (this->dimensions[2] * T_3746_);

	this->dimensions[0] = T_Matrix[0] / T_Determinant;
	this->dimensions[1] = T_Matrix[1] / T_Determinant;
	this->dimensions[2] = T_Matrix[2] / T_Determinant;
	this->dimensions[3] = T_Matrix[3] / T_Determinant;
	this->dimensions[4] = T_Matrix[4] / T_Determinant;
	this->dimensions[5] = T_Matrix[5] / T_Determinant;
	this->dimensions[6] = T_Matrix[6] / T_Determinant;
	this->dimensions[7] = T_Matrix[7] / T_Determinant;
	this->dimensions[8] = T_Matrix[8] / T_Determinant;

	return true;

}

const A_Matrix3x3 A_Matrix3x3::GetTransposed() {

	A_Matrix3x3 T_Result;

	T_Result.dimensions[0] = this->dimensions[0];
	T_Result.dimensions[1] = this->dimensions[3];
	T_Result.dimensions[2] = this->dimensions[6];

	T_Result.dimensions[3] = this->dimensions[1];
	T_Result.dimensions[4] = this->dimensions[4];
	T_Result.dimensions[5] = this->dimensions[7];

	T_Result.dimensions[6] = this->dimensions[2];
	T_Result.dimensions[7] = this->dimensions[5];
	T_Result.dimensions[8] = this->dimensions[8];

	return T_Result;

}

void A_Matrix3x3::SetTranposed() {

	A_Matrix3x3 T_Placehold;

	//this->demensions[0] stays the same

	//need to preserve this->demensions[1] for later
	T_Placehold.dimensions[1] = this->dimensions[1];
	this->dimensions[1] = this->dimensions[3];

	//need to preserve this->demensions[2] for later
	T_Placehold.dimensions[2] = this->dimensions[2];
	this->dimensions[2] = this->dimensions[6];

	////held the old demensions[1] in T_Placehold
	this->dimensions[3] = T_Placehold.dimensions[1];

	//this->demensions[4] stays the same

	//need to preserve this->demensions[5] for later
	T_Placehold.dimensions[5] = this->dimensions[5];
	this->dimensions[5] = this->dimensions[7];

	//held the old demensions[2] in T_Placehold
	this->dimensions[6] = T_Placehold.dimensions[2];

	//held the old demensions[5] in T_Placehold
	this->dimensions[7] = T_Placehold.dimensions[5];

	//this->demensions[8] stays the same

}

A_Matrix3x3::~A_Matrix3x3() {

	//=D

}