/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#ifndef ___Class_Graph
#define ___Class_Graph

#include <iostream>
#include <vector>

#include "Vertex.h"

template <typename T>
class Graph {
public:
	enum colors {BLACK, WHITE, GRAY};
	
private:
	std::vector<Vertex<T>> vertices;
	std::vector<std::vector<int>> adjList;

private:
	std::vector<int> getTerminationVertexIndexes(void) const;
	void eraseEdges(int index);
	void updateIndex(int index);

public:
	Graph();
	void addVertex(const T& value);
	bool searchVertex(const T& value);
	void addEdge(const T& value1, const T& value2);
	std::vector<T> topologicalSort(void) const;
	int getVerticesNum(void) const;
	int getEdgesNum(void) const;
};

#include "Graph.cpp"

#endif

