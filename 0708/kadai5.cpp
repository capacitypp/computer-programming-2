/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <iostream>
#include <cmath>
#include <random>

#include "Matrix.h"

using namespace std;

//課題の[2](ア)を行う
void func1(void)
{
	Matrix a(2, 2);
	for (int i = 0; i < a.getRows(); i++)
	for (int j = 0; j < a.getCols(); j++)
		a[i][j] = 1 / sqrt(2.0);
	a[1][1] *= -1.0;

	Matrix b(2, 3);
	b[0][0] = sqrt(12.0);
	b[1][1] = sqrt(10.0);

	Matrix c(3, 3);
	c[0][0] = 1 / sqrt(6.0);
	c[0][1] = c[0][2] = c[0][0];
	c[1][0] = 2 / sqrt(5.0);
	c[1][1] = c[1][0] / -2;
	c[2][0] = 1 / sqrt(30.0);
	c[2][1] = c[2][0] * 2;
	c[2][2] = c[2][0] * -5;

	Matrix d = a * b * c;

	cout << "(ア)" << endl;
	cout << "Matrix A:--------------------------" << endl;
	cout << a << endl;
	cout << "Matrix B:--------------------------" << endl;
	cout << b << endl;
	cout << "Matrix C:--------------------------" << endl;
	cout << c << endl;
	cout << "Matrix D = A * B * C:--------------------------" << endl;
	cout << d << endl;
}

//各要素を乱数とするrows行cols列の行列を生成する
Matrix randomMatrix(int rows, int cols)
{
	random_device rd;
	mt19937 mt(rd());
	//-10.0~10.0の乱数
	uniform_real_distribution<double> randomDouble(-10.0, 10.0);

	Matrix m(rows, cols);
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)
		m[i][j] = randomDouble(mt);

	return m;
}

//課題の[2](イ)~(カ)を行う
void func2(int m, int n, int r)
{
	Matrix a = ::randomMatrix(m, r);
	Matrix b = ::randomMatrix(r, n);
	Matrix c = ::randomMatrix(m, n);
	Matrix d = a * b;
	Matrix e = c + d;

	cout << endl << "(イ)~(カ)" << endl;
	cout << " M = " << m << " R = " << r << " N = " << n << endl;
	cout << "Matrix A:--------------------------" << endl;
	cout << a << endl;
	cout << "Matrix B:--------------------------" << endl;
	cout << b << endl;
	cout << "Matrix C:--------------------------" << endl;
	cout << c << endl;
	cout << "Matrix D = A * B:--------------------------" << endl;
	cout << d << endl;
	cout << "Matrix E = C + D:--------------------------" << endl;
	cout << e << endl;

	//最小値と最大値を求める
	double min = a[0][0], max = a[0][0];
	double minI = 0, minJ = 0, maxI = 0, maxJ = 0;
	for (int i = 0; i < a.getRows(); i++) {
		for (int j = 0; j < a.getCols(); j++) {
			double v = a[i][j];
			if (v < min) {
				min = v;
				minI = i;
				minJ = j;
			}
			else if (v > max) {
				max = v;
				maxI = i;
				maxJ = j;
			}
		}
	}
	cout << endl;
	cout << "最小値：A[" << minI << "][" << minJ << "] = " << min << endl;
	cout << "最大値：A[" << maxI << "][" << maxJ << "] = " << max << endl;
}

int main(int argc, char** argv)
{
	if (argc != 4) {
		cerr << argv[0] << " M N R" << endl;
		return 1;
	}
	//コマンドライン引数からM,N,Rを読み取る
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	int r = atoi(argv[3]);

	cout << "**************************" << endl;
	cout << "課題5 : 佐野和輝, 163334" << endl;
	cout << "**************************" << endl;
	cout << endl;

	try {
		::func1();
		::func2(m, n, r);
	}
	//行列の生成に失敗した場合
	catch (const Matrix::CannotAllocateException& e) {
		cerr << "行列の生成に失敗しました" << endl;
		return 1;
	}
	//行列の加算や積算において行列の次元が合わなかった場合
	catch (const Matrix::InvalidSizeException& e)
	{
		cerr << "行列の次元があっていません" << endl;
		return 1;
	}
	//operator[]で不正な添え字でアクセスしようとして場合
	catch (const Matrix::InvalidIndexException& e)
	{
		cerr << "不正な要素にアクセスしようとしました" << endl;
		return 1;
	}

	return 0;
}

