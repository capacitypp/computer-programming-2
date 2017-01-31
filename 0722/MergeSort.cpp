/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <iostream>

template <typename T>
void MergeSort<T>::sortSubVector(int low, int high)
{
	if ((high - low) >= 1) {
		int middle1 = (low + high) / 2;
		int middle2 = middle1 + 1;

		sortSubVector(low, middle1);
		sortSubVector(middle2, high);

		merge(low, middle1, middle2, high);
	}
}

template <typename T>
void MergeSort<T>::merge(int left, int middle1, int middle2, int right)
{
	int leftIndex = left;
	int rightIndex = middle2;
	int combinedIndex = left;
	std::vector<T> combined(size);

	while (leftIndex <= middle1 && rightIndex <= right) {
		if (data[leftIndex] <= data[rightIndex])
			combined[combinedIndex++] = data[leftIndex++];
		else
			combined[combinedIndex++] = data[rightIndex++];
	}
	if (leftIndex == middle2)
		while (rightIndex <= right)
			combined[combinedIndex++] = data[rightIndex++];
	else
		while (leftIndex <= middle1)
			combined[combinedIndex++] = data[leftIndex++];
	for (int i = left; i <= right; i++)
		data[i] = combined[i];
}

template <typename T>
void MergeSort<T>::printSubVector(int low, int high) const
{
	for (int i = 0; i < low; i++)
		std::cout << " ";
	for (int i = low; i <= high; i++) {
		const T& gd = data[i];
		gd.print();
	}

}

template <typename T>
MergeSort<T>::MergeSort(const std::vector<T>& data)
	: size(data.size()), data(data)
{

}

template <typename T>
void MergeSort<T>::sort(void)
{
	sortSubVector(0, size - 1);
}

template <typename T>
void MergeSort<T>::printElements(void) const
{
	printSubVector(0, size - 1);
}

template <typename T>
std::vector<T> MergeSort<T>::getData(void) const
{
	return data;
}

