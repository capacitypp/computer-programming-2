/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月17日
 * プログラムの内容	: 加算、減算、表示などの基本的な機能を実装した位置（ベクトル）クラス
 */

#ifndef ___Class_Point3
#define ___Class_Point3

#include <iostream>

class Point3 {
private:
	double x, y, z;

public:
	/* デフォルトコンストラクタ */
	Point3(void) : x(0.0), y(0.0), z(0.0) {}
	Point3(double x, double y, double z) : x(x), y(y), z(z) {}
	/* 2-ノルムを求める */
	double norm(void) const {
		return sqrt(x * x + y * y + z * z);
	}
	/* (-x, -y, -z)を返す */
	Point3 negate(void) const {
		return Point3(-x, -y, -z);
	}
	/* *this + point を返す */
	Point3 add(const Point3& point) const {
		return Point3(x + point.x, y + point.y, z + point.z);
	}
	/* *this - point を返す */
	Point3 sub(const Point3& point) const {
		return add(point.negate());
	}
	/* point1 + point2 を返す */
	static Point3 add(const Point3& point1, const Point3& point2) {
		return point1.add(point2);
	}
	/* point1 - point2を返す */
	static Point3 sub(const Point3& point1, const Point3& point2) {
		return point1.sub(point2);
	}
	/* 要素を表示する */
	void print(void) const {
			std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
	}
	/* w1, w2, w3で囲まれた三角形の面積を求める */
	static double area3(Point3 w1, Point3 w2, Point3 w3) {
		Point3 a = w2.sub(w1);
		Point3 b = w3.sub(w1); 
		Point3 cross(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y);
		return 0.5 * cross.norm();
		double t = (w2.x - w1.x) * (w3.y - w1.y) - (w3.x - w1.x) * (w2.y - w1.y);
		t = (t < 0.0) ? -t : t;
		return 0.5 * t;
	}
};

#endif

