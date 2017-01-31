/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Polygonクラスの宣言
 */

#ifndef ___Class_Polygon
#define ___Class_Polygon

#include <vector>

#include "Shape.h"

class Polygon : public Shape {
private:
	/* 頂点座標のベクタ */
	std::vector<double> xs;
	std::vector<double> ys;

public:
	Polygon(double r, double g, double b);
	/* 頂点を追加する */
	void addVertex(double x, double y);
	/* 面積を求める */
	double area(void) const;
	/* 総長を求める */
	double perimeter(void) const;
	/* 図形をPostScript形式で出力する */
	void print(void) const;
};

#endif

