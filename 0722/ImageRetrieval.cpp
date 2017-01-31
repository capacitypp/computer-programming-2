/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include "ImageRetrieval.h"
#include "MergeSort.h"

using namespace std;

unsigned long ImageRetrieval::calcDifference(const vector<vector<vector<int>>>& h1, const vector<vector<vector<int>>>& h2) const
{
	unsigned long dist = 0;
	int numBin = h1.size();
	for (int i = 0; i < numBin; i++)
	for (int j = 0; j < numBin; j++)
	for (int k = 0; k < numBin; k++)
		dist += abs(h1[i][j][k] - h2[i][j][k]);
	return dist;
}

ImageRetrieval::ImageRetrieval(const vector<string>& fpaths, const vector<vector<vector<vector<int>>>>& hs)
	: fpaths(fpaths), hs(hs)
{

}

vector<DifferenceWithURL> ImageRetrieval::compute(int index) const
{
	vector<DifferenceWithURL> differenceWithURLs;
	const vector<vector<vector<int>>>& h1 = hs[index];
	const int IMAGE_NUM = fpaths.size();
	for (int i = 0; i < IMAGE_NUM; i++) {
		const vector<vector<vector<int>>>& h2 = hs[i];
		unsigned long dist = (i == index) ? 0 : calcDifference(h1, h2);
		DifferenceWithURL differenceWithURL(dist, fpaths[i]);
		differenceWithURLs.push_back(differenceWithURL);
	}

	MergeSort<DifferenceWithURL> mergeSort(differenceWithURLs);
	mergeSort.sort();
	differenceWithURLs = mergeSort.getData();
	return differenceWithURLs;
}

