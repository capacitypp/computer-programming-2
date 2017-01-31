/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Polygon.cpp
 */

#include <iostream>
#include <cmath>

#include "Polygon.h"

using namespace std;

Polygon::Polygon(double r, double g, double b)
	: Shape(r, g, b)
{

}

void Polygon::addVertex(double x, double y)
{
	xs.push_back(x);
	ys.push_back(y);
}

double Polygon::area(void) const
{
	double sum = 0.0;
	unsigned size = xs.size();
	for (unsigned i = 0; i < size; i++) {
		double x1 = xs[i];
		double y1 = ys[i];
		double x2 = xs[(i + 1) % size];
		double y2 = ys[(i + 1) % size];
		sum += x1 * y2 - x2 * y1;
	}
	return sum / 2.0;
}

double Polygon::perimeter(void) const
{
	double sum = 0.0;
	unsigned size = xs.size();

	for (unsigned i = 0; i < size; i++) {
		double x1 = xs[i];
		double y1 = ys[i];
		double x2 = xs[(i + 1) % size];
		double y2 = ys[(i + 1) % size];
		double dx = x2 - x1;
		double dy = y2 - y1;
		/* (x1,y1),(x2,y2)のユークリッド距離を加算する */
		sum += sqrt(dx * dx + dy * dy);
	}
	return sum;
}

void Polygon::print(void) const
{
	printStart();
	for (unsigned i = 0; i < xs.size(); i++) {
		double x = xs[i];
		double y = ys[i];
		/* 1行目は"lineto"、2行目以降は"moveto"を出力する */
		cout << x << " " << y << " " << (i ? "lineto" : "moveto") << endl;
	}
	cout << "closepath" << endl;
	printEnd();
}

