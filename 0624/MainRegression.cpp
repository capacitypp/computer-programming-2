/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月24日
 * プログラムの内容	: 「食べ物」データを読み込み、Foodクラスを生成する。また、Regressionクラスによって単回帰の係数a,b,ならびに寄与率R2を計算し、2つの単回帰においてどちらがよりよい回帰であるかを判定する
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "Food.h"
#include "Regression.h"

using namespace std;

/* strをdelimで区切り、vectorとして返す */
vector<string> split(const string& str, char delim)
{
	vector<string> ret;
	string::size_type current = 0;
	string::size_type found;

	while ((found = str.find_first_of(delim, current)) != string::npos) {
		/* 現在の位置からデリミタ手前までを区切る */
		ret.push_back(str.substr(current, found - current));
		current = found + 1;
	}
	/* 最後の要素を取り出す */
	ret.push_back(str.substr(current, str.size() - 1));
	return ret;
}

int main(int argc, char** argv)
{
	/* コマンドライン引数のチェック */
	if (argc != 2) {
		cout << argv[0] << " [input]" << endl;
		return 1;
	}

	cout << "**************************" << endl;
	cout << "課題3 : 佐野和輝, 163334" << endl;
	cout << "**************************" << endl;
	cout << endl;

	/* ファイルを開く */
	string fname(argv[1]);
	ifstream fin(fname, ios::in);

	string line;
	fin >> line;
	Regression regression1;
	Regression regression2;
	while (true) {
		fin >> line;
		/* EOFであれば終了 */
		if (!fin)
			break;
		/* カンマで区切る */
		vector<string> token = split(line, ',');
		/* 正しく区切られているかチェックする */
		if (token.size() != 6)
			continue;

		string name;
		float GI;
		float carbon;
		float calorie;
		float fat;
		float protein;

		/* Foodクラスのメンバの型に合わせる */
		name = token[0];
		GI = atof(token[1].c_str());
		carbon = atof(token[2].c_str());
		calorie = atof(token[3].c_str());
		fat = atof(token[4].c_str());
		protein = atof(token[5].c_str());

		/* フードクラスを生成する */
		Food food(name, GI, carbon, calorie, fat, protein);
		/* Regressionクラスにデータを追加する */
		regression1.add(food.getFat(), food.getCalorie());
		regression2.add(food.getCarbon(), food.getCalorie());
	}
	/* 係数a,b,ならびに寄与率R2を計算する */
	cout << "****************************************" << endl;
	cout << "カロリーを脂質で表す単回帰" << endl;
	cout << "****************************************" << endl;
	float R2_1 = regression1.computeAndPrintAndGetR2();
	cout << endl;
	cout << "****************************************" << endl;
	cout << "カロリーを炭水化物で表す単回帰" << endl;
	cout << "****************************************" << endl;
	float R2_2 = regression2.computeAndPrintAndGetR2();
	cout << endl;
	/* どちらの回帰がよりよいか判定する */
	cout << "****************************************" << endl;
	cout << "判定結果" << endl;
	cout << "****************************************" << endl;
	float v1 = 1.0F - R2_1;
	float v2 = 1.0F - R2_2;
	v1 = (v1 > 0.0F) ? v1 : -v1;
	v2 = (v2 > 0.0F) ? v2 : -v2;
	string str = (v1 < v2) ? "脂質" : "炭水化物";
	cout << "カロリーを" << str << "で表す単回帰の方がより良い回帰です" << endl;

	return 0;
}

