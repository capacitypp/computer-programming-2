/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Shapeクラスの定義
 */

#include <iostream>

#include "Shape.h"

using namespace std;

Shape::Shape(double r, double g, double b)
	: r(r), g(g), b(b)
{

}

void Shape::printStart(void) const
{
	/* 色R,G,Bを出力する */
	cout << r << " " << g << " " << b << " setrgbcolor" << endl;
	cout << "newpath" << endl;
}

void Shape::printEnd(void) const
{
	cout << "stroke" << endl;
}

