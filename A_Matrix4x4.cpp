#include "A_Matrix4x4.h"

A_Matrix4x4::A_Matrix4x4() {

	for (int i = 0; i < 16; ++i) {

		this->dimensions[i] = 0.0f;

	}

}

A_Matrix4x4::A_Matrix4x4(float const _f) {

	if (_f == 0) {

		for (char i = 0; i < 16; ++i) {

			if (i == 0 || i == 5 || i == 10 || i == 15) {

				this->dimensions[i] = 1.0f;

			}

			else dimensions[i] = 0.0f;

		}

	}

	else {

		for (char i = 0; i < 16; ++i) {

			this->dimensions[i] = _f;

		}

	}

}

A_Matrix4x4::A_Matrix4x4(A_Matrix4x4* const _AM) {

	for (char i = 0; i < 16; ++i) {

		this->dimensions[i] = _AM->dimensions[i];

	}

}

A_Matrix4x4::A_Matrix4x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3, A_Vector4* const _AV4) {
	
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

	this->dimensions[12] = _AV4->getX();
	this->dimensions[13] = _AV4->getY();
	this->dimensions[14] = _AV4->getZ();
	this->dimensions[15] = _AV4->getW();

}

A_Matrix4x4::A_Matrix4x4(A_Vector4* const _AV1, A_Vector4* const _AV2, A_Vector4* const _AV3, A_Vector4* const _AV4, char const unUsedColumnConstructor) {

	this->dimensions[0] = _AV1->getX();
	this->dimensions[4] = _AV1->getY();
	this->dimensions[8] = _AV1->getZ();
	this->dimensions[12] = _AV1->getW();

	this->dimensions[1] = _AV2->getX();
	this->dimensions[5] = _AV2->getY();
	this->dimensions[9] = _AV2->getZ();
	this->dimensions[13] = _AV2->getW();

	this->dimensions[2] = _AV3->getX();
	this->dimensions[6] = _AV3->getY();
	this->dimensions[10] = _AV3->getZ();
	this->dimensions[14] = _AV3->getW();

	this->dimensions[3] = _AV4->getX();
	this->dimensions[7] = _AV4->getY();
	this->dimensions[11] = _AV4->getZ();
	this->dimensions[15] = _AV4->getW();

}

A_Matrix4x4::A_Matrix4x4(float const _f[]) {

	for (char i = 0; i < 16; ++i) {

		this->dimensions[i] = _f[i];

	}

}

A_Vector4 A_Matrix4x4::GetColumnAtAddress(int const _ad) {

	A_Vector4 T_Result;

	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[_ad + 4]);
	T_Result.setZ(this->dimensions[_ad + 8]);
	T_Result.setW(this->dimensions[_ad + 12]);

	return T_Result;

}

void A_Matrix4x4::SetColumnAtAddress(int const _ad, A_Vector4 *_AQ) {

	this->dimensions[_ad] = _AQ->getX();
	this->dimensions[_ad + 4] = _AQ->getY();
	this->dimensions[_ad + 8] = _AQ->getZ();
	this->dimensions[_ad + 12] = _AQ->getW();

}

A_Vector4 A_Matrix4x4::GetRowAtAddress(int _ad) {

	_ad *= 4;
	A_Vector4 T_Result;

	//incrumenting through the row
	T_Result.setX(this->dimensions[_ad]);
	T_Result.setY(this->dimensions[++_ad]);
	T_Result.setZ(this->dimensions[++_ad]);
	T_Result.setW(this->dimensions[++_ad]);

	return T_Result;

}

void A_Matrix4x4::SetRowAtAddress(int _ad, A_Vector4 *_AQ) {

	_ad *= 4;

	//incrumenting through the row
	this->dimensions[_ad] = _AQ->getX();
	this->dimensions[++_ad] = _AQ->getY();
	this->dimensions[++_ad] = _AQ->getZ();
	this->dimensions[++_ad] = _AQ->getW();

}

void A_Matrix4x4::SetIdentity() {

	for (char i = 0; i < 16; ++i) {

		if (i == 0 || i == 5 || i == 10 || i == 15) {

			this->dimensions[i] = 1.0f;

		}

		else dimensions[i] = 0.0f;

	}

}

A_Matrix4x4 A_Matrix4x4::GetRotationXAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	T_Result.dimensions[5] = ::cosf(_f);
	T_Result.dimensions[6] = -::cosf(_f);
	T_Result.dimensions[9] = ::sinf(_f);
	T_Result.dimensions[10] = ::cosf(_f);

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetRotationYAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	T_Result.dimensions[0] = ::cosf(_f);
	T_Result.dimensions[2] = ::sinf(_f);
	T_Result.dimensions[8] = -::sinf(_f);
	T_Result.dimensions[10] = ::cosf(_f);

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetRotationZAxis(float const _f) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	T_Result.dimensions[0] = ::cosf(_f);
	T_Result.dimensions[1] = -::sinf(_f);
	T_Result.dimensions[4] = ::sinf(_f);
	T_Result.dimensions[5] = ::cosf(_f);

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetTranslate(float const _x, float const _y, float const _z) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	this->dimensions[3] = _x;
	this->dimensions[7] = _y;
	this->dimensions[11] = _z;

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetTranslate(A_Vector3 const *_AV) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	this->dimensions[3] = _AV->getX();
	this->dimensions[7] = _AV->getY();
	this->dimensions[11] = _AV->getZ();

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetScale(float const _x, float const _y, float const _z) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	T_Result.dimensions[0] = _x;
	T_Result.dimensions[5] = _y;
	T_Result.dimensions[10] = _z;

	return T_Result;

}

A_Matrix4x4 A_Matrix4x4::GetScale(A_Vector3* const _AV) {

	A_Matrix4x4 T_Result;
	T_Result.SetIdentity();

	T_Result.dimensions[0] = _AV->getX();
	T_Result.dimensions[5] = _AV->getY();
	T_Result.dimensions[10] = _AV->getZ();

	return T_Result;

}

const bool A_Matrix4x4::Invert() {
	
	//determinant of this
	float T_determinant;
	//temp floats needed to assist in finding the determinant, and later assist in finding the final inverse of the matrix
	//names reflect first opperations done to these variables between the underscores, the second is after the underscores
	float T_2736_051C, T_2B3A_0918, T_6B7A_4958, T_6F7E_4D5C, T_AFBE_8D9C, T_E3F2_C1D0;
	//don't need any matrix functions, just need to store info here
	float T_matrix[16];

	T_2736_051C = this->dimensions[2] * this->dimensions[7] - this->dimensions[3] * this->dimensions[6];
	T_2B3A_0918 = this->dimensions[2] * this->dimensions[11] - this->dimensions[3] * this->dimensions[10];
	T_6B7A_4958 = this->dimensions[6] * this->dimensions[11] - this->dimensions[7] * this->dimensions[10];
	T_6F7E_4D5C = this->dimensions[6] * this->dimensions[15] - this->dimensions[7] * this->dimensions[14];
	T_AFBE_8D9C = this->dimensions[10] * this->dimensions[15] - this->dimensions[11] * this->dimensions[14];
	T_E3F2_C1D0 = this->dimensions[14] * this->dimensions[3] - this->dimensions[15] * this->dimensions[2];

	T_matrix[0] = this->dimensions[5] * T_AFBE_8D9C - this->dimensions[9] * T_6F7E_4D5C + this->dimensions[13] * T_6B7A_4958;
	T_matrix[1] = -(this->dimensions[1] * T_AFBE_8D9C + this->dimensions[9] * T_E3F2_C1D0 + this->dimensions[13] * T_2B3A_0918);
	T_matrix[2] = this->dimensions[1] * T_6F7E_4D5C + this->dimensions[5] * T_E3F2_C1D0 + this->dimensions[13] * T_2736_051C;
	T_matrix[3] = -(this->dimensions[1] * T_6F7E_4D5C - this->dimensions[5] * T_2B3A_0918 + this->dimensions[9] * T_2736_051C);

	T_determinant = this->dimensions[0] * T_matrix[0] + this->dimensions[4] * T_matrix[1] + this->dimensions[8] * T_matrix[2] + this->dimensions[12] * T_matrix[3];

	if (T_determinant == 0.0f) {

		//this matrix cannot be inverted
		this->SetIdentity();
		return false;

	}

	//inverse of this matrix's determinant
	float T_INVDeterminant = 1.0f / T_determinant;

	T_matrix[0] *= T_INVDeterminant;
	T_matrix[1] *= T_INVDeterminant;
	T_matrix[2] *= T_INVDeterminant;
	T_matrix[3] *= T_INVDeterminant;

	//continuing filling out the T_matrix
	T_matrix[4] = -(this->dimensions[4] * T_AFBE_8D9C - this->dimensions[8] * T_6F7E_4D5C + this->dimensions[12] * T_6B7A_4958) * T_INVDeterminant;
	T_matrix[5] = this->dimensions[0] * T_AFBE_8D9C + this->dimensions[8] * T_E3F2_C1D0 + this->dimensions[12] * T_2B3A_0918 * T_INVDeterminant;
	T_matrix[6] = -(this->dimensions[0] * T_6F7E_4D5C + this->dimensions[4] * T_E3F2_C1D0 + this->dimensions[12] * T_2B3A_0918) * T_INVDeterminant;
	T_matrix[7] = this->dimensions[0] * T_6B7A_4958 - this->dimensions[4] * T_2B3A_0918 + this->dimensions[8] * T_2736_051C * T_INVDeterminant;

	//reusing the temporary variables from above, use portion of the name after the second underscore from here
	T_2736_051C = this->dimensions[0] * this->dimensions[5] - this->dimensions[1] * this->dimensions[12];
	T_2B3A_0918 = this->dimensions[0] * this->dimensions[9] - this->dimensions[1] * this->dimensions[8];
	T_6B7A_4958 = this->dimensions[4] * this->dimensions[9] - this->dimensions[5] * this->dimensions[8];
	T_6F7E_4D5C = this->dimensions[4] * this->dimensions[13] - this->dimensions[5] * this->dimensions[12];
	T_AFBE_8D9C = this->dimensions[8] * this->dimensions[13] - this->dimensions[9] * this->dimensions[12];
	T_E3F2_C1D0 = this->dimensions[12] * this->dimensions[1] - this->dimensions[13] * this->dimensions[0];

	T_matrix[8] = this->dimensions[7] * T_AFBE_8D9C - this->dimensions[11] * T_6F7E_4D5C + this->dimensions[15] * T_6B7A_4958 * T_INVDeterminant;
	T_matrix[9] = -(this->dimensions[3] * T_AFBE_8D9C + this->dimensions[11] * T_E3F2_C1D0 + this->dimensions[15] * T_2B3A_0918) * T_INVDeterminant;
	T_matrix[10] = this->dimensions[3] * T_6F7E_4D5C + this->dimensions[7] * T_E3F2_C1D0 + this->dimensions[15] * T_2736_051C * T_INVDeterminant;
	T_matrix[11] = -(this->dimensions[3] * T_6B7A_4958 - this->dimensions[7] * T_2B3A_0918 + this->dimensions[11] * T_2736_051C) * T_INVDeterminant;
	T_matrix[12] = -(this->dimensions[6] * T_AFBE_8D9C - this->dimensions[10] * T_6F7E_4D5C + this->dimensions[14] * T_6B7A_4958) * T_INVDeterminant;
	T_matrix[13] = this->dimensions[2] * T_AFBE_8D9C + this->dimensions[10] * T_E3F2_C1D0 + this->dimensions[14] * T_2B3A_0918 * T_INVDeterminant;
	T_matrix[14] = -(this->dimensions[2] * T_6F7E_4D5C + this->dimensions[6] * T_E3F2_C1D0 + this->dimensions[14] * T_2736_051C) * T_INVDeterminant;
	T_matrix[15] = this->dimensions[2] * T_6B7A_4958 - this->dimensions[6] * T_2B3A_0918 + this->dimensions[10] * T_2736_051C * T_INVDeterminant;

	this->dimensions[0] = T_matrix[0];
	this->dimensions[1] = T_matrix[1];
	this->dimensions[2] = T_matrix[2];
	this->dimensions[3] = T_matrix[3];
	this->dimensions[4] = T_matrix[4];
	this->dimensions[5] = T_matrix[5];
	this->dimensions[6] = T_matrix[6];
	this->dimensions[7] = T_matrix[7];
	this->dimensions[8] = T_matrix[8];
	this->dimensions[9] = T_matrix[9];
	this->dimensions[10] = T_matrix[10];
	this->dimensions[11] = T_matrix[11];
	this->dimensions[12] = T_matrix[12];
	this->dimensions[13] = T_matrix[13];
	this->dimensions[14] = T_matrix[14];
	this->dimensions[15] = T_matrix[15];

	return true;

}

A_Matrix4x4 A_Matrix4x4::GetTransposed() {

	A_Matrix4x4 T_Result;

	//this->dimensions[0] stays the same
	T_Result.dimensions[0] = this->dimensions[0];

	T_Result.dimensions[1] = this->dimensions[4];
	T_Result.dimensions[2] = this->dimensions[8];
	T_Result.dimensions[3] = this->dimensions[12];
	T_Result.dimensions[4] = this->dimensions[1];
	//this->dimensions[5] stays the same
	T_Result.dimensions[5] = this->dimensions[5];

	T_Result.dimensions[6] = this->dimensions[9];
	T_Result.dimensions[7] = this->dimensions[13];
	T_Result.dimensions[8] = this->dimensions[2];
	T_Result.dimensions[9] = this->dimensions[6];
	//this->dimensions[10] stays the same
	T_Result.dimensions[10] = this->dimensions[10];

	T_Result.dimensions[11] = this->dimensions[14];
	T_Result.dimensions[12] = this->dimensions[3];
	T_Result.dimensions[13] = this->dimensions[7];
	T_Result.dimensions[14] = this->dimensions[11];
	//this->dimensions[15] stays the same
	T_Result.dimensions[15] = this->dimensions[15];

	return T_Result;

}

void A_Matrix4x4::SetTranposed() {

	A_Matrix4x4 T_Placehold;

	//this->dimensions[0] stays the same

	//need to preserve this->dimensions[1] for later
	T_Placehold.dimensions[1] = this->dimensions[1];
	this->dimensions[1] = this->dimensions[4];

	//need to preserve this->dimensions[2] for later
	T_Placehold.dimensions[2] = this->dimensions[2];
	this->dimensions[2] = this->dimensions[8];

	//need to preserve this->dimensions[3] for later
	T_Placehold.dimensions[3] = this->dimensions[3];
	this->dimensions[3] = this->dimensions[12];

	//held the old dimensions[1] in T_Placehold
	this->dimensions[4] = T_Placehold.dimensions[1];

	//this->dimensions[5] stays the same

	//need to preserve this->dimensions[6] for later
	T_Placehold.dimensions[6] = this->dimensions[6];
	this->dimensions[6] = this->dimensions[9];

	//need to preserve this->dimensions[7] for later
	T_Placehold.dimensions[7] = this->dimensions[7];
	this->dimensions[7] = this->dimensions[13];

	//held the old dimensions[2] in T_Placehold
	this->dimensions[8] = T_Placehold.dimensions[2];

	//held the old dimensions[6] in T_Placehold
	this->dimensions[9] = T_Placehold.dimensions[6];

	//this0->dimensions[10] stays the same

	//need to preserve this->dimensions[11] until later
	T_Placehold.dimensions[11] = this->dimensions[11];
	this->dimensions[11] = this->dimensions[14];

	//held the old this->dimensions[3] in T_Placehold
	this->dimensions[12] = T_Placehold.dimensions[3];

	//held the old this->dimensions[7] in T_Placehold
	this->dimensions[13] = T_Placehold.dimensions[7];

	//held the old this->dimensions[11] in T_Placehold
	this->dimensions[14] = T_Placehold.dimensions[11];

	//this->dimensions[15] stays the same

}

void A_Matrix4x4::SetViewMatrix(A_Vector3* const _pos, A_Vector3* const _viewDir, A_Vector3* const _up, A_Vector3* const _right) {

	//up
	this->dimensions[1] = _up->getX();
	this->dimensions[5] = _up->getY();
	this->dimensions[9] = _up->getZ();
	this->dimensions[13] = _up->DotProduct(_pos);

	//right
	this->dimensions[0] = _right->getX();
	this->dimensions[4] = _right->getY();
	this->dimensions[8] = _right->getZ();
	this->dimensions[12] = _right->DotProduct(_pos);

	//viewDir
	this->dimensions[2] = _viewDir->getX();
	this->dimensions[6] = _viewDir->getY();
	this->dimensions[10] = _viewDir->getZ();
	this->dimensions[14] = _viewDir->DotProduct(_pos);

	this->dimensions[3] = this->dimensions[7] = this->dimensions[11] = 0.0f;
	this->dimensions[15] = 1.0f;

}

A_Matrix4x4::~A_Matrix4x4() {



}