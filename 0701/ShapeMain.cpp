/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: 乱数に基づいて多角形と円を合計N個（3<=N<=30）生成する。図形の色R,G,Bについて、0<=R,G,B<=1.0とし、円や多角形の頂点の座標x,yについて、0<x<580.0,0<y<700.0とする。また、多角形の辺の数は3~10とすし、円の半径rは0<x<580.0とする。生成したそれぞれの図形について、図形やその面積、総長をPostScript形式で出力する。また、最後に全図形の面積の合計及び総長の合計を出力する.
 */

#include <iostream>
#include <random>
#include <string>

#include "Polygon.h"
#include "Circle.h"

using namespace std;

int main(int argc, char** argv)
{
	/* 乱数の生成に用いる */
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> randomN(3, 30);
	uniform_int_distribution<int> randomEdge(3, 10);
	uniform_int_distribution<int> randomInt(0, 1);
	uniform_real_distribution<double> randomDouble(0.0, 1.0);

	/* 生成する図形の数 */
	int n = randomN(mt);
	/* 面積、総長の総和 */
	double areaSum = 0.0;
	double perimeterSum = 0.0;

	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
	cout << "%% 課題4 : 佐野和輝, 163334" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%"<< endl;
	cout << endl;

	for (int i = 1; i <= n; i++) {
		/* 図形の種類 */
		int type = randomInt(mt);
		/* R,G,Bを生成する */
		double r = randomDouble(mt);
		double g = randomDouble(mt);
		double b = randomDouble(mt);
		/* 円や多角形のポインタを格納する変数 */
		Shape* shape;
		cout << "%%" << i << "番目の図形は";
		/* 多角形を生成する場合 */
		if (type) {
			/* 辺の数 */
			int edge = randomEdge(mt);
			Polygon* polygon = new Polygon(r, g, b);
			/* 頂点を追加する */
			for (int j = 0; j < edge; j++) {
				double x = randomDouble(mt) * 580.0;
				double y = randomDouble(mt) * 700.0;
				polygon->addVertex(x, y);
			}
			shape = polygon;
			cout << edge << "角形";
		/* 円を生成する場合 */
		} else {
			/* 半径 */
			double radius = randomDouble(mt) * 580.0;
			double x = randomDouble(mt) * 580.0;
			double y = randomDouble(mt) * 700.0;
			shape = new Circle(r, g, b, x, y, radius);
			cout << "円";
		}
		cout << "です" << endl;
		string typeString = type ? "多角形" : "円";
		/* 面積、総長を求める */
		double area = shape->area();
		double perimeter = shape->perimeter();
		cout << "%% " << typeString << "：面積 = " << area << endl;
		cout << "%% " << typeString << "：周囲長 = " << perimeter << endl;
		/* 図形をPostScript形式で出力する */
		shape->print();
		cout << endl;
		areaSum += area;
		perimeterSum += perimeter;
	}
	/* 総和を出力する */
	cout << "%% 総面積は " << areaSum << "です。" << endl;
	cout << "%% 総長は " << perimeterSum << "です。" << endl;
	cout << "showpage" << endl;

	return 0;
}

