/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: Matrixクラスの宣言。課題で指示された機能の他に、挿入子によってプリミティブ型と同様に出力できるようにした。
 */

#include <iostream>

class Matrix {
public:
	class CannotAllocateException{};
	class InvalidSizeException{};
	class InvalidIndexException{};
private:
	double **table;
	int rows, cols;

private:
	void alloc(void);	//行列の生成
	void free(void);	//行列の解放
	void init(void);	//行列の要素を0に設定

public:
	Matrix(int rows, int cols);
	Matrix(const Matrix& m);
	~Matrix();

	int getRows(void) const;
	int getCols(void) const;

	Matrix operator+(const Matrix& m) const;
	Matrix operator*(const Matrix& m) const;
	double* operator[](int idx);

	//挿入子のオーバーロード
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

inline int Matrix::getRows(void) const
{
	return rows;
}

inline int Matrix::getCols(void) const
{
	return cols;
}

