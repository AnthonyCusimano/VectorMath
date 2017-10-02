#include "A_Matrix3x3.h"

A_Matrix3x3::A_Matrix3x3() {

	for (char i = 0; i < 9; ++i) {

		this->demensions[i] = 0.0f;

	}

}

A_Matrix3x3::A_Matrix3x3(float const _f) {

	if (_f == 0) {

		for (char i = 0; i < 9; ++i) {

			if (i == 0 || i == 4 || i == 8) {

				this->demensions[i] = 1.0f;

			}

			else demensions[i] = 0.0f;

		}

	}

	else {

		for (char i = 0; i < 9; ++i) {

			this->demensions[i] = _f;

		}

	}

}

A_Matrix3x3::A_Matrix3x3(A_Matrix3x3* const _AM) {

	for (char i = 0; i < 9; ++i) {

		this->demensions[i] = _AM->demensions[i];

	}

}

A_Matrix3x3::A_Matrix3x3(A_Vector3* const _AV1, A_Vector3* const _AV2, A_Vector3* const _AV3) {

	this->demensions[0] = _AV1->getX();
	this->demensions[1] = _AV1->getY();
	this->demensions[2] = _AV1->getZ();

	this->demensions[3] = _AV2->getX();
	this->demensions[4] = _AV2->getY();
	this->demensions[5] = _AV2->getZ();

	this->demensions[6] = _AV3->getX();
	this->demensions[7] = _AV3->getY();
	this->demensions[8] = _AV3->getZ();

}

A_Matrix3x3::A_Matrix3x3(float const _f[]) {

	for (char i = 0; i < 9; ++i) {

		this->demensions[i] = _f[i];

	}

}

//test
const A_Vector3 A_Matrix3x3::GetColumnAtAddress(char const _ad) {

	char i = (_ad * 3);
	A_Vector3 T_Result;

	T_Result.setX(this->demensions[i]);
	T_Result.setY(this->demensions[i + 1]);
	T_Result.setZ(this->demensions[i + 2]);

	return T_Result;

}

void A_Matrix3x3::SetColumnAtAddress(char const _ad, A_Vector3* const _AQ) {

	char i = (_ad * 3);

	this->demensions[i] = _AQ->getX();
	this->demensions[i + 1] = _AQ->getY();
	this->demensions[i + 2] = _AQ->getZ();

}

const A_Vector3 A_Matrix3x3::GetRowAtAddress(int const _ad) {

	A_Vector3 T_Result;

	T_Result.setX(this->demensions[_ad]);
	T_Result.setY(this->demensions[_ad + 3]);
	T_Result.setZ(this->demensions[_ad + 6]);

	return T_Result;

}

void A_Matrix3x3::SetRowAtAddress(int const _ad, A_Vector3 *_AQ) {

	this->demensions[_ad] = _AQ->getX();
	this->demensions[_ad + 3] = _AQ->getY();
	this->demensions[_ad + 6] = _AQ->getZ();

}

void A_Matrix3x3::setIdentity() {

	this->demensions[0] = 1.0f;
	this->demensions[1] = this->demensions[2] = this->demensions[3] = 0.0f;
	this->demensions[4] = 1.0f;
	this->demensions[5] = this->demensions[6] = this->demensions[7] = 0.0f;
	this->demensions[8] = 1.0f;

}

//need to return using this method?
const bool A_Matrix3x3::Invert() {

	//https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//determinant of this
	float T_Determinant;
	//temp floats needed to assist in finding the determinant, and later assist in finding the final inverse of the matrix
	//names reflect demensions used to assign a value to these variables
	float T_4857_, T_3856_, T_3746_, T_1827_, T_0826_, T_0716_, T_1524_, T_0523_, T_0413_;
	//nothing complex needed, but a matrix placeholder is needed
	float T_Matrix[9];

	//minors, cofactors
	T_4857_ = this->demensions[4] * this->demensions[8] - this->demensions[5] * this->demensions[7];//0
	T_3856_ = -(this->demensions[3] * this->demensions[8] - this->demensions[5] * this->demensions[6]);//1
	T_3746_ = this->demensions[3] * this->demensions[7] - this->demensions[4] * this->demensions[6];//2
	T_1827_ = -(this->demensions[1] * this->demensions[8] - this->demensions[2] * this->demensions[7]);//3
	T_0826_ = this->demensions[0] * this->demensions[8] - this->demensions[2] * this->demensions[6];//4
	T_0716_ = -(this->demensions[0] * this->demensions[7] - this->demensions[1] * this->demensions[6]);//5
	T_1524_ = this->demensions[1] * this->demensions[5] - this->demensions[2] * this->demensions[4];//6
	T_0523_ = -(this->demensions[0] * this->demensions[5] - this->demensions[2] * this->demensions[3]);//7
	T_0413_ = this->demensions[0] * this->demensions[4] - this->demensions[1] * this->demensions[3];//8

	//transpose
	T_Matrix[0] = T_4857_;
	T_Matrix[1] = T_1827_;
	T_Matrix[2] = T_1524_;
	T_Matrix[3] = T_4857_;
	T_Matrix[4] = T_0826_;
	T_Matrix[5] = T_0523_;
	T_Matrix[6] = T_3746_;
	T_Matrix[7] = T_0716_;
	T_Matrix[8] = T_0413_;

	T_Determinant = (this->demensions[0] * T_4857_) - (this->demensions[1] * T_3856_) + (this->demensions[2] * T_3746_);

	this->demensions[0] = T_Matrix[0] / T_Determinant;
	this->demensions[1] = T_Matrix[1] / T_Determinant;
	this->demensions[2] = T_Matrix[2] / T_Determinant;
	this->demensions[3] = T_Matrix[3] / T_Determinant;
	this->demensions[4] = T_Matrix[4] / T_Determinant;
	this->demensions[5] = T_Matrix[5] / T_Determinant;
	this->demensions[6] = T_Matrix[6] / T_Determinant;
	this->demensions[7] = T_Matrix[7] / T_Determinant;
	this->demensions[8] = T_Matrix[8] / T_Determinant;

	return true;

}

const A_Matrix3x3 A_Matrix3x3::GetTransposed() {

	A_Matrix3x3 T_Result;

	T_Result.demensions[0] = this->demensions[0];
	T_Result.demensions[1] = this->demensions[3];
	T_Result.demensions[2] = this->demensions[6];

	T_Result.demensions[3] = this->demensions[1];
	T_Result.demensions[4] = this->demensions[4];
	T_Result.demensions[5] = this->demensions[7];

	T_Result.demensions[6] = this->demensions[2];
	T_Result.demensions[7] = this->demensions[5];
	T_Result.demensions[8] = this->demensions[8];

	return T_Result;

}

void A_Matrix3x3::SetTranposed() {

	A_Matrix3x3 T_Placehold;

	//this->demensions[0] stays the same

	//need to preserve this->demensions[1] for later
	T_Placehold.demensions[1] = this->demensions[1];
	this->demensions[1] = this->demensions[3];

	//need to preserve this->demensions[2] for later
	T_Placehold.demensions[2] = this->demensions[2];
	this->demensions[2] = this->demensions[6];

	////held the old demensions[1] in T_Placehold
	this->demensions[3] = T_Placehold.demensions[1];

	//this->demensions[4] stays the same

	//need to preserve this->demensions[5] for later
	T_Placehold.demensions[5] = this->demensions[5];
	this->demensions[5] = this->demensions[7];

	//held the old demensions[2] in T_Placehold
	this->demensions[6] = T_Placehold.demensions[2];

	//held the old demensions[5] in T_Placehold
	this->demensions[7] = T_Placehold.demensions[5];

	//this->demensions[8] stays the same

}

A_Matrix3x3::~A_Matrix3x3() {

	//=D

}