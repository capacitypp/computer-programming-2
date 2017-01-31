/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#ifndef ___Class_ImageRetrieval
#define ___Class_ImageRetrieval

#include <iostream>
#include <vector>

#include "DifferenceWithURL.h"

class ImageRetrieval {
private:
	std::vector<std::string> fpaths;
	std::vector<std::vector<std::vector<std::vector<int>>>> hs;

private:
	unsigned long calcDifference(const std::vector<std::vector<std::vector<int>>>& h1, const std::vector<std::vector<std::vector<int>>>& h2) const;

public:
	ImageRetrieval(const std::vector<std::string>& fpaths, const std::vector<std::vector<std::vector<std::vector<int>>>>& hs);
	std::vector<DifferenceWithURL> compute(int index) const;
};

#endif

