#pragma once

#include "PipelineMath.hpp"

void testMat4() {
	Mat4 m1;
	m1.debugShow();
	m1.setValue(2, 2, -100);
	m1.debugShow();
}

void testMat4_2() {
	Mat4 m1;
	Mat4 m2;

	m2.data[0][0] = 100;
	m2.data[1][1] = 100;
	m2.data[2][2] = 100;
	m2.data[3][3] = 100;

	m1.debugShow();
	m2.debugShow();

	std::cout << "after assign" << std::endl;
	m1 = m2;

	m1.debugShow();
	m2.debugShow();
}

void testMat4_add() {
	Mat4 m1;
	Mat4 m2;

	m2.data[0][0] = 100;
	m2.data[1][1] = 100;
	m2.data[2][2] = 100;
	m2.data[3][3] = 100;

	m1.debugShow();
	m2.debugShow();

	std::cout << "after add " << std::endl;
	m1 + m2;
	m1.debugShow();
}

void testMat4_sub() {
	Mat4 m1;
	Mat4 m2;

	m2.data[0][0] = 2;
	m2.data[1][1] = 2;
	m2.data[2][2] = 2;
	m2.data[3][3] = 2;

	m1.debugShow();
	m2.debugShow();

	std::cout << "after sub " << std::endl;
	m1 = m1 - m2;

	m1.debugShow();
	m2.debugShow();
	//sub.debugShow();
}

void testMat4_add2() {
	Mat4 m1;
	Mat4 m2;

	m2.data[0][0] = 2;
	m2.data[1][1] = 2;
	m2.data[2][2] = 2;
	m2.data[3][3] = 2;

	m1.debugShow();
	m2.debugShow();

	m1 += m2;
	m1.debugShow();
	m2.debugShow();
}

void testMat4_sub2() {
	Mat4 m1;
	Mat4 m2;

	m1.data[0][0] = 2;
	m1.data[1][1] = 2;
	m1.data[2][2] = 2;
	m1.data[3][3] = 2;

	m1.debugShow();
	m2.debugShow();

	m2 -= m2;
	m1.debugShow();
	m2.debugShow();
}

void testMat4_mul() {
	Mat4 m1;
	Mat4 m2;

	m1.data[0][0] = 1;
	m1.data[1][1] = 1;
	m1.data[2][2] = 0;
	m1.data[3][3] = 1;

	m2.data[0][0] = 2;
	m2.data[1][1] = 3;
	m2.data[2][2] = 4;
	m2.data[3][3] = 5;

	m1.debugShow();
	m2.debugShow();

	Mat4 m = m1 * m2;
	m.debugShow();
}

void testMat4_mul2() {
	Mat4 m1;
	Mat4 m2;

	m1.data[0][0] = 1;
	m1.data[1][1] = 1;
	m1.data[2][2] = 0;
	m1.data[3][3] = 1;

	m2.data[0][0] = 2;
	m2.data[1][1] = 3;
	m2.data[2][2] = 4;
	m2.data[3][3] = 5;

	m1.debugShow();
	m2.debugShow();

	m1 *= m2;
	m1.debugShow();
	m2.debugShow();
}

void testMat4_mul3() {
	Mat4 m2;

	m2.data[0][0] = 2;
	m2.data[1][1] = 3;
	m2.data[2][2] = 4;
	m2.data[3][3] = 5;

	Mat4 m = m2 * 2;
	
	m.debugShow();
	m2.debugShow();
}

void testMat4_mul4() {
	Mat4 m2;

	m2.data[0][0] = 2;
	m2.data[1][1] = 3;
	m2.data[2][2] = 4;
	m2.data[3][3] = 5;

	m2 *= 10;

	m2.debugShow();
}

void test_vec_1() {
	Vec4 v1; 
	v1.debugShow();
}

void test_vec_2() {
	Vec3 v1(1,1,1);
	v1 = v1 * 3;
	v1.debugShow();

	v1.normalize();
	v1.debugShow();


	std::cout << std::endl;

	std::cout << v1.length() << std::endl;
}

void test_vec_3() {
	Vec3 v1(1, 1, 1);
	v1 *= 100;
	v1.debugShow();
}

void test_vec_transform() {
	Vec3 v1(1, 2, 3);
	Mat4 m;
	m.data[0][3] = 100;
	m.data[1][3] = 200;
	m.data[2][3] = 300;

	Vec3 v = m * v1;

	v.debugShow();
}

void doTestUnit() {
	//testMat4();
	//testMat4_2();

	//testMat4_add();
	//testMat4_sub();

	//testMat4_sub2();

	//testMat4_mul();
	//testMat4_mul2();
	//testMat4_mul3();

	//testMat4_mul4();
	//test_vec_1();
	//test_vec_2();
	//test_vec_3();
	test_vec_transform();
}
