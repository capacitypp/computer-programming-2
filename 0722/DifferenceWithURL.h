/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#ifndef ___Class_DifferenceWithURL
#define ___Class_DifferenceWithURL

#include <iostream>

class DifferenceWithURL {
private:
	unsigned long difference;
	std::string url;

public:
	DifferenceWithURL();
	DifferenceWithURL(unsigned long difference, const std::string& url);

	unsigned long getDifference(void) const;
	std::string getURL(void) const;

	bool operator<=(const DifferenceWithURL& differenceWithURL) const;
};

inline unsigned long DifferenceWithURL::getDifference(void) const
{
	return difference;
}

inline std::string DifferenceWithURL::getURL(void) const
{
	return url;
}

inline bool DifferenceWithURL::operator<=(const DifferenceWithURL& differenceWithURL) const
{
	return difference <= differenceWithURL.difference;
}

#endif

