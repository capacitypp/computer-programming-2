/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Circleクラスの宣言
 */

#ifndef ___Class_Circle
#define ___Class_Circle

#include "Shape.h"

class Circle : public Shape {
private:
	/* 中心座標 */
	double x;
	double y;
	/* 半径 */
	double radius;

public:
	Circle(double r, double g, double b, double x, double y, double radius);
	/* 面積を求める */
	double area(void) const;
	/* 総長を求める */
	double perimeter(void) const;
	/* 図形をPostScript形式で出力する */
	void print(void) const;
};

#endif

