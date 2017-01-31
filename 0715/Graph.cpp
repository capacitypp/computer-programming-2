/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <algorithm>
#include <stack>

template <typename T>
std::vector<int> Graph<T>::getTerminationVertexIndexes(void) const
{
	std::vector<int> indexes;
	for (unsigned i = 0; i < adjList.size(); i++) {
		const std::vector<int>& row = adjList[i];
		if (!row.size())
			indexes.push_back(i);
		if (row.size() == 1 && row[0] == i)
			indexes.push_back(i);
	}
	return indexes;
}

template <typename T>
void Graph<T>::eraseEdges(int index)
{
	for (auto itr = adjList.begin(); itr != adjList.end(); ++itr) {
		std::vector<int>& row = *itr;
		for (auto itr = row.begin(); itr != row.end(); ++itr) {
			if (*itr == index) {
				itr = row.erase(itr);
				break;
			}
		}
	}
}

template <typename T>
void Graph<T>::updateIndex(int index)
{
	for (auto itr = adjList.begin(); itr != adjList.end(); ++itr) {
		std::vector<int>& row = *itr;
		for (auto itr = row.begin(); itr != row.end(); ++itr) {
			int& v = *itr;
			if (v >= index)
				v--;
		}
	}
}

template <typename T>
Graph<T>::Graph()
{
	
}

template <typename T>
void Graph<T>::addVertex(const T& value)
{
	vertices.push_back(Vertex<T>(value));
	adjList.push_back(std::vector<int>());
}

template <typename T>
bool Graph<T>::searchVertex(const T& value)
{
	if (std::find(vertices.begin(), vertices.end(), Vertex<T>(value)) != vertices.end())
		return true;
	return false;
}

template <typename T>
void Graph<T>::addEdge(const T& value1, const T& value2)
{
	auto itr = std::find(vertices.begin(), vertices.end(), Vertex<T>(value1));
	if (itr == vertices.end())
		return;
	int idx1 = itr - vertices.begin();
	itr = std::find(vertices.begin(), vertices.end(), Vertex<T>(value2));
	if (itr == vertices.end())
		return;
	int idx2 = itr - vertices.begin();
	std::vector<int>& row = adjList[idx1];
	row.push_back(idx2);
}

template <typename T>
std::vector<T> Graph<T>::topologicalSort(void) const
{
	Graph<T> graph(*this);
	std::stack<T> st;
	while (graph.getVerticesNum()) {
		std::vector<int> indexes = graph.getTerminationVertexIndexes();
		int index = indexes[0];
		graph.eraseEdges(index);
		st.push(graph.vertices[index].getValue());
		graph.vertices.erase(graph.vertices.begin() + index);
		graph.adjList.erase(graph.adjList.begin() + index);
		graph.updateIndex(index);
	}
	std::vector<T> ret;
	while (!st.empty()) {
		ret.push_back(st.top());
		st.pop();
	}
	return ret;
}

template <typename T>
int Graph<T>::getVerticesNum(void) const
{
	return vertices.size();
}

template <typename T>
int Graph<T>::getEdgesNum(void) const
{
	unsigned num = 0;
	for (auto itr = adjList.begin(); itr != adjList.end(); ++itr) {
		const std::vector<int>& row = *itr;
		num += row.size();
	}
	return num;
}

