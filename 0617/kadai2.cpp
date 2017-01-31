/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月17日
 * プログラムの内容	: Point3クラスを利用して、ノルムの計算や面積の計算を行う
 */

#include <iostream>
#include <random>

#include "Point3.h"

using namespace std;

int main(int argc, char** argv)
{
	/* 乱数を用いるための準備 */
	random_device rnd;
	mt19937 mt(rnd());
	/* [-10.0, 10.0]の範囲で乱数を生成するように設定する */
	uniform_real_distribution<> urd(-10.0, 10.0);

	Point3 p1, p2, p3;
	/* ループで回すためのポインタ配列 */
	Point3* ptr[3] = {&p1, &p2, &p3};
	int n = sizeof(ptr) / sizeof(ptr[0]);

	/* タイトルの表示 */
	cout << "**************************" << endl;
	cout << "課題2 : 佐野和輝, 163334" << endl;
	cout << "**************************" << endl;

	/* 乱数を利用するか問い合わせる */
	cout << "ランダムに入力しますか？(y/n)";
	string str;
	cin >> str;
	/* 真理値として格納する */
	bool isRandom = (str == "y");

	/* p1, p2, p3に値をセット */
	for (int i = 0; i < n; i++) {
		double v[3];
		int m = sizeof(v) / sizeof(v[0]);
		if (!isRandom)
			cout << "第" << (i + 1) << "の座標(x,y,z)を入力してください >";
		for (int j = 0; j < m; j++) {
			/* 乱数を利用する場合 */
			if (isRandom) {
				v[j] = urd(mt);
			/* 乱数を利用しない場合 */
			} else {
				/* 入力を促す */
				cin >> v[j];
			}
		}
		*ptr[i] = Point3(v[0], v[1], v[2]);
		cout << "第" << (i + 1) << "の座標は";
		(*ptr[i]).print();
	}

	/* Point3クラスの中身を表示する */

	/* 2-ノルムを表示する */
	for (int i = 0; i < n; i++) {
		cout << "第" << (i + 1) << "座標のノルムは" << (*ptr[i]).norm() << endl;
	}

	/* 符号反転した結果を表示する */
	cout << "第1座標の正負反転した値は";
	p1.negate().print();

	/* 面積を表示する */
	cout << "三角形の面積は" << Point3::area3(p1, p2, p3) << endl;

	return 0;
}

