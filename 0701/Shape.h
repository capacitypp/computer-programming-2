/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月1日
 * プログラムの内容	: Shapeクラスの宣言
 */

#ifndef ___Class_Shape
#define ___Class_Shape

class Shape {
private:
	/* 色R,G,B */
	double r;
	double g;
	double b;
public:
	Shape(double r, double g, double b);
	/* R,G,Bのゲッタ */
	double getR(void) const;
	double getG(void) const;
	double getB(void) const;
	/* 面積を求める */
	virtual double area(void) const = 0;
	/* 総長を求める */
	virtual double perimeter(void) const = 0;
	/* 図形をPostScript形式で出力する */
	virtual void print(void) const = 0;
	/* 図形に共通な部分（上部）を出力する */
	void printStart(void) const;
	/* 図形に共通な部分（下部）を出力する */
	void printEnd(void) const;
};

inline double Shape::getR(void) const
{
	return r;
}

inline double Shape::getG(void) const
{
	return g;
}

inline double Shape::getB(void) const
{
	return b;
}

#endif

