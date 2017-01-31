/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月17日
 * プログラムの内容	: Regressionクラスの定義
 */
#include "Regression.h"

using namespace std;

/* 平均値を求める */
float Regression::average(const std::vector<float>& xs) const
{
	float sum = 0.0F;

	/* 合計を求める */
	for (unsigned i = 0; i < xs.size(); i++) {
		float x = xs[i];
		sum += x;
	}

	/* 要素数で割る */
	return sum / xs.size();
}

/* Sxyを求める */
float Regression::calcSxy(const std::vector<float>& xs, float xVar, const std::vector<float>& ys, float yVar) const
{
	float sxy = 0.0;

	for (unsigned i = 0; i < xs.size(); i++) {
		float x = xs[i];
		float y = ys[i];
		sxy += (x - xVar) * (y - yVar);
	}

	return sxy;
}

/* データを追加する */
void Regression::add(float x, float y)
{
	xs.push_back(x);
	ys.push_back(y);
}

/* 係数a,b,ならびに寄与率R2を計算しプリントし、呼び出し側に寄与率を返す */
float Regression::computeAndPrintAndGetR2()
{
	/* 平均値を求める */
	xVar = average(xs);
	yVar = average(ys);
	/* Sxx, Syy, Sxyを求める */
	float sxx = calcSxy(xs, xVar, xs, xVar);
	float syy = calcSxy(ys, yVar, ys, yVar);
	float sxy = calcSxy(xs, xVar, ys, yVar);
	/* 係数a,bを求める */
	a = sxy / sxx;
	b = yVar - a * xVar;
	/* Seを求める */
	float se = syy - a * sxy;
	/* 寄与率を求める */
	R2 = 1 - se / syy;

	/* 計算結果を表示する */
	cout << "a (回帰係数) = " << a << endl;
	cout << "b (回帰切片) = " << b << endl;
	cout << "Se (誤差平方和) = " << se << endl;
	cout << "R2 (寄与率) = 1 - (Se/Syy) = " << R2 << endl;

	return R2;
}

