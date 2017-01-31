/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年6月10日
 * プログラムの内容	: 与えられたファイル内における、アルファベットで構成される単語をカウントして、単語を小文字に変換したうえで、単語とその出現回数をkadai1.txtに出力する。単語とその出現回数の管理には、連想配列std::mapを利用する。
 */

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

/* 単語の読み取りに使うバッファのサイズ */
#define BUFFER_MAX	512

int main(int argc, char** argv)
{
	/* コマンドライン引数のチェックを行う */
	if (argc != 2) {
		/* 引数の与え方を表示する */
		cerr << argv[0] << " ファイル名" << endl;
		return 1;
	}

	string fpath = argv[1];
	/* 読み取りモードでファイルを開く */
	ifstream fin(fpath.c_str(), ios::in);
	if (fin.fail()) {
		/* ファイルがオープンできなければ終了 */
		cerr << "ファイル：" << fpath << "がオープンできませんでした" << endl;
		return 1;
	}

	/* 単語とカウントの保持に連想配列を用いる */
	map<string, int> words;
	/* ファイルの読み取り */
	while (true) {
		/* バッファの宣言 */
		char buffer[BUFFER_MAX];
		/* バッファをゼロクリアする */
		fill(buffer, buffer + BUFFER_MAX, '\0');
		int i = 0;
		char c;
		/* アルファベットによる単語を、小文字に変換しながら読み取る */
		while ((c = fin.get()) && isalpha(c))
			buffer[i++] = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
		/* 1文字以上の単語をカウントする */
		if (i)
			words[buffer]++;
		/* EOFに到達していたら読み取りを終了する */
		if (fin.eof())
			break;
	}

	/* 書き込みモードでファイルを開く  */
	ofstream fout("kadai1.txt", ios::out);
	if (fout.fail()) {
		/* ファイルがオープンできなければ終了 */
		cerr << "ファイル：" << fpath << "がオープンできませんでした" << endl;
		return 1;
	}

	/* カウント結果などを出力する */
	fout << "*******************************" << endl;
	fout << "課題1 : 佐野和輝 163334" << endl;
	fout << "ファイル名：" << fpath << endl;
	fout << "英語ニュースからの単語切り出し" << endl;
	fout << "*******************************" << endl;
	for (map<string, int>::iterator iter = words.begin(); iter != words.end(); ++iter)
		fout << "  単語：" << iter->first << "\t出現回数：" << iter->second << endl;
	fout << "　単語総数　全部で" << words.size() << " 種類の単語が現れました。" << endl;

	return 0;
}

