#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include "A_Matrix2x2.h"
#include "A_Matrix2x3.h"
#include "A_Matrix2x4.h"

#include "A_Matrix3x2.h"
#include "A_Matrix3x3.h"
#include "A_Matrix3x4.h"

#include "A_Matrix4x2.h"
#include "A_Matrix4x3.h"
#include "A_Matrix4x4.h"

A_Matrix2x3 operator *(A_Matrix2x2 _AM22, A_Matrix2x3 _AM23) {

	A_Matrix2x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x4 operator *(A_Matrix2x2 _AM22, A_Matrix2x4 _AM24) {

	A_Matrix2x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM22.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM22.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	return T_Result;

}

A_Matrix2x2 operator *(A_Matrix2x3 _AM23, A_Matrix3x2 _AM32) {

	A_Matrix2x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x3 operator *(A_Matrix2x3 _AM23, A_Matrix3x3 _AM33) {

	A_Matrix2x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x4 operator *(A_Matrix2x3 _AM23, A_Matrix3x4 _AM34) {

	A_Matrix2x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM23.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM23.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x2 operator *(A_Matrix2x4 _AM24, A_Matrix4x2 _AM42) {

	A_Matrix2x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x3 operator *(A_Matrix2x4 _AM24, A_Matrix4x3 _AM43) {

	A_Matrix2x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix2x4 operator *(A_Matrix2x4 _AM24, A_Matrix4x4 _AM44) {

	A_Matrix2x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(12);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(9);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(13);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(10);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(14);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(11);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(15);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(12);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(9);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(13);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(10);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(14);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM24.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(11);
	T_CurrentOperation += _AM24.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(15);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	return T_Result;

}

A_Matrix3x2 operator *(A_Matrix3x2 _AM32, A_Matrix2x2 _AM22) {

	A_Matrix3x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x3 operator *(A_Matrix3x2 _AM32, A_Matrix2x3 _AM23) {

	A_Matrix3x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[8]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x4 operator* (A_Matrix3x2 _AM32, A_Matrix2x4 _AM24) {

	A_Matrix3x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[9]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM32.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM32.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x2 operator* (A_Matrix3x3 _AM33, A_Matrix3x2 _AM32) {

	A_Matrix3x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x4 operator* (A_Matrix3x3 _AM33, A_Matrix3x4 _AM34) {

	A_Matrix3x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[9]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM33.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM33.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x2 operator* (A_Matrix3x4 _AM34, A_Matrix4x2 _AM42) {

	A_Matrix3x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x3 operator* (A_Matrix3x4 _AM34, A_Matrix4x3 _AM43) {

	A_Matrix3x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[8]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;

}

A_Matrix3x4 operator *(A_Matrix3x4 _AM34, A_Matrix4x4 _AM44) {

	A_Matrix3x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(12);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(9);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(13);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(10);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(14);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(0) * _AM44.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(1) * _AM44.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(2) * _AM44.GetDimensionAtAddress(11);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(3) * _AM44.GetDimensionAtAddress(15);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(12);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(9);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(13);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(10);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(14);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(4) * _AM44.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(5) * _AM44.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(6) * _AM44.GetDimensionAtAddress(11);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(7) * _AM44.GetDimensionAtAddress(15);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM44.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM44.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM44.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM44.GetDimensionAtAddress(12);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[9]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM44.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM44.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM44.GetDimensionAtAddress(9);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM44.GetDimensionAtAddress(13);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM44.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM44.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM44.GetDimensionAtAddress(10);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM44.GetDimensionAtAddress(14);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM34.GetDimensionAtAddress(8) * _AM44.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(9) * _AM44.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(10) * _AM44.GetDimensionAtAddress(11);
	T_CurrentOperation += _AM34.GetDimensionAtAddress(11) * _AM44.GetDimensionAtAddress(15);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	return T_Result;
	
}

A_Matrix4x2 operator *(A_Matrix4x2 _AM42, A_Matrix2x2 _AM22) {

	A_Matrix4x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);
	
	//working out T_Result[2]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM22.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM22.GetDimensionAtAddress(2);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM22.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM22.GetDimensionAtAddress(3);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x3 operator *(A_Matrix4x2 _AM42, A_Matrix2x3 _AM23) {

	A_Matrix4x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;


	//working out T_Result[0]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[8
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[9]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM23.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM23.GetDimensionAtAddress(3);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM23.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM23.GetDimensionAtAddress(4);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM23.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM23.GetDimensionAtAddress(5);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x4 operator *(A_Matrix4x2 _AM42, A_Matrix2x4 _AM24) {

	A_Matrix4x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(0) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(1) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is now done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(2) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(3) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is now done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[9]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(4) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(5) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 2 is now done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[12]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM24.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM24.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[13]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM24.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM24.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[14]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM24.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM24.GetDimensionAtAddress(6);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[15]
	T_CurrentOperation = _AM42.GetDimensionAtAddress(6) * _AM24.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM42.GetDimensionAtAddress(7) * _AM24.GetDimensionAtAddress(7);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 3 is now done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x2 operator *(A_Matrix4x3 _AM43, A_Matrix3x2 _AM32) {

	A_Matrix4x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM32.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM32.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM32.GetDimensionAtAddress(4);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM32.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM32.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM32.GetDimensionAtAddress(5);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x3 operator *(A_Matrix4x3 _AM43, A_Matrix3x3 _AM33) {

	A_Matrix4x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[8]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[9]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM33.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM33.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM33.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM33.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM33.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM33.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM33.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM33.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM33.GetDimensionAtAddress(8);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x4 operator *(A_Matrix4x3 _AM43, A_Matrix3x4 _AM34) {

	A_Matrix4x4 T_Result;
	A_Vector4 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(0) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(1) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(2) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[6]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(3) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(4) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(5) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[8]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[9]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[10]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(6) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(7) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(8) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[12]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM34.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM34.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM34.GetDimensionAtAddress(8);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[13]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM34.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM34.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM34.GetDimensionAtAddress(9);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[14]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM34.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM34.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM34.GetDimensionAtAddress(10);

	T_Placehold.setZ(T_CurrentOperation);

	//working out T_Result[15]
	T_CurrentOperation = _AM43.GetDimensionAtAddress(9) * _AM34.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(10) * _AM34.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM43.GetDimensionAtAddress(11) * _AM34.GetDimensionAtAddress(11);

	T_Placehold.setW(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x2 operator *(A_Matrix4x4 _AM44, A_Matrix4x2 _AM42) {

	A_Matrix4x2 T_Result;
	A_Vector2 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(0) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(1) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(2) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(3) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[2]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[3]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(4) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(5) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(6) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(7) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[4]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(8) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(9) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(10) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(11) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(8) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(9) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(10) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(11) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(12) * _AM42.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(13) * _AM42.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(14) * _AM42.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(15) * _AM42.GetDimensionAtAddress(6);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(12) * _AM42.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(13) * _AM42.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(14) * _AM42.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(15) * _AM42.GetDimensionAtAddress(7);

	T_Placehold.setY(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

A_Matrix4x3 operator *(A_Matrix4x4 _AM44, A_Matrix4x3 _AM43) {

	A_Matrix4x3 T_Result;
	A_Vector3 T_Placehold;
	float T_CurrentOperation;

	//working out T_Result[0]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[1]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[2]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(0) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(1) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(2) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(3) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 0 is done
	T_Result.SetRowAtAddress(0, &T_Placehold);

	//working out T_Result[3]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[4]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[5]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(4) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(5) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(6) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(7) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 1 is done
	T_Result.SetRowAtAddress(1, &T_Placehold);

	//working out T_Result[6]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[7]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[8]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(8) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(9) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(10) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(11) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 2 is done
	T_Result.SetRowAtAddress(2, &T_Placehold);

	//working out T_Result[9]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(12) * _AM43.GetDimensionAtAddress(0);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(13) * _AM43.GetDimensionAtAddress(3);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(14) * _AM43.GetDimensionAtAddress(6);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(15) * _AM43.GetDimensionAtAddress(9);

	T_Placehold.setX(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(12) * _AM43.GetDimensionAtAddress(1);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(13) * _AM43.GetDimensionAtAddress(4);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(14) * _AM43.GetDimensionAtAddress(7);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(15) * _AM43.GetDimensionAtAddress(10);

	T_Placehold.setY(T_CurrentOperation);

	//working out T_Result[11]
	T_CurrentOperation = _AM44.GetDimensionAtAddress(12) * _AM43.GetDimensionAtAddress(2);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(13) * _AM43.GetDimensionAtAddress(5);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(14) * _AM43.GetDimensionAtAddress(8);
	T_CurrentOperation += _AM44.GetDimensionAtAddress(15) * _AM43.GetDimensionAtAddress(11);

	T_Placehold.setZ(T_CurrentOperation);

	//T_Result row 3 is done
	T_Result.SetRowAtAddress(3, &T_Placehold);

	return T_Result;

}

#endif