/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月17日
 * プログラムの内容	: Regressionクラスの宣言
 */
#ifndef ___Class_Regression
#define ___Class_Regression

#include <vector>

#include "Food.h"

class Regression {
private:
	float a, b;				/* 単回帰における係数 */
	float R2;				/* 寄与率 */
	float xVar, yVar;		/* 平均値 */
	std::vector<float> xs;	/* データ系列x */
	std::vector<float> ys;	/* データ系列y */

private:
	/* 平均値を求める */
	float average(const std::vector<float>& xs) const;
	/* Sxyを求める */
	float calcSxy(const std::vector<float>& xs, float xVar, const std::vector<float>& ys, float yVar) const;
public:
	/* データを追加する */
	void add(float x, float y);
	/* 係数a,b,ならびに寄与率R2を計算しプリントし、呼び出し側に寄与率を返す */
	float computeAndPrintAndGetR2();
};

#endif

