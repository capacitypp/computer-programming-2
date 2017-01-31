/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Circleクラスの定義
 */

#include <iostream>
/* 円周率M_PIを使用するため */
#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.h"

using namespace std;

Circle::Circle(double r, double g, double b, double x, double y, double radius)
	: Shape(r, g, b), x(x), y(y), radius(radius)
{

}

double Circle::area(void) const
{
	return M_PI * radius * radius;
}

double Circle::perimeter(void) const
{
	return 2 * M_PI * radius;
}

void Circle::print(void) const
{
	printStart();
	cout << x << " " << y << " " << radius << " 0 360 arc" << endl;
	printEnd();
}

