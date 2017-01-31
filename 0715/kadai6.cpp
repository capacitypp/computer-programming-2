/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Graph.h"

using namespace std;

void eraseSpace(string& str)
{
	while (str[0] == ' ')
		str.erase(0, 1);
	while (str[str.length() - 1] == ' ')
		str.erase(str.length() - 1, 1);
}

void eraseDoubleQuotation(string& str)
{
	while (str[0] == '"')
		str.erase(0, 1);
	while (str[str.length() - 1] == '"')
		str.erase(str.length() - 1, 1);
}

vector<string> getTokens(void)
{
	string str;
	getline(cin, str);
	if (str[str.length() - 1] == '\r')
		str.erase(str.length() - 1, 1);
	vector<string> tokens;
	while (str.length()) {
		size_t pos = str.find(",");
		if (pos == string::npos) {
			tokens.push_back(str);
			break;
		}
		string token(str, 0, pos);
		tokens.push_back(token);
		str.erase(0, pos + 1);
	}
	for (auto itr = tokens.begin(); itr != tokens.end(); ++itr) {
		string& str = *itr;
		::eraseSpace(str);
	}
	return tokens;
}


int main(int argc, char** argv)
{
	vector<string> tokens;
	tokens = ::getTokens();
	int edgesNum = atoi(tokens[1].c_str());

	Graph<string> graph;
	
	for (int i = 0; i < edgesNum; i++) {
		tokens = ::getTokens();
		for (auto itr = tokens.begin(); itr != tokens.end(); ++itr) {
			string& name = *itr;
			::eraseDoubleQuotation(name);
			if (!graph.searchVertex(name))
				graph.addVertex(name);
		}
		graph.addEdge(tokens[0], tokens[1]);
	}

	vector<string> ret = graph.topologicalSort();
	for (unsigned i = 0; i < ret.size(); i++) {
		cout << ret[i] << endl;
	}

	return 0;
}

