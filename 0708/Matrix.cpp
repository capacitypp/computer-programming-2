/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: Matrixクラスの定義
 */

#include <iostream>

#include "Matrix.h"

using namespace std;

void Matrix::alloc(void)
{
	try {
		table = new double*[rows];
		for (int i = 0; i < rows; i++)
			table[i] = new double[cols];
	}
	//newに失敗したら例外を投げる
	catch (const bad_alloc& e) {
		throw CannotAllocateException();
	}
}

void Matrix::free(void)
{
	if (table == nullptr)
		return;
	for (int i = 0; i < rows; i++) {
		if (table[i] == nullptr)
			continue;
		delete[] table[i];
	}
	delete[] table;
}

void Matrix::init(void)
{
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		table[i][j] = 0.0;
}

Matrix::Matrix(int rows, int cols)
	: rows(rows), cols(cols)
{
	alloc();
	init();
}

Matrix::Matrix(const Matrix& m)
	: rows(m.rows), cols(m.cols)
{
	alloc();
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		table[i][j] = m.table[i][j];
}

Matrix::~Matrix()
{
	free();
}

Matrix Matrix::operator+(const Matrix& m) const
{
	//行列の大きさが合っていなかったら自分自信を返す
	if (rows != m.rows || cols != m.cols) {
		cerr << "行列の次元があっていません" << endl;
		return *this;
	}

	Matrix ret(rows, cols);
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		ret.table[i][j] = table[i][j] + m.table[i][j];

	return ret;
}

Matrix Matrix::operator*(const Matrix& m) const
{
	//行列の大きさが合っていなかったら例外を投げる
	if (cols != m.rows)
		throw InvalidSizeException();

	Matrix ret(rows, m.cols);
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < m.cols; j++)
	for (int k = 0; k < cols; k++)
		ret.table[i][j] += table[i][k] * m.table[k][j];

	return ret;
}

double* Matrix::operator[](int idx)
{
	//不正な添え字であれば例外を投げる
	if (idx < 0 || idx >= rows)
		throw InvalidIndexException();

	return table[idx];
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.rows; i++) {
		cout << "|";
		for (int j = 0; j < m.cols; j++)
			cout << " " <<  m.table[i][j] << " |";
		if (i != m.rows - 1)
			cout << endl;
	}
	return os;
}

