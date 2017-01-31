/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <iostream>

#include "Histogram.h"
#include "DifferenceWithURL.h"
#include "MergeSort.h"
#include "ImageRetrieval.h"

#define IMAGE_NUM	50

using namespace std;

string getFilePath(const string& fpath)
{
	auto pos = fpath.find_last_of("/");
	if (pos == string::npos)
		return "";
	if (pos + 1 == fpath.length())
		return "";
	return string(fpath, pos + 1);
}

string getFileName(const string& fpath)
{
	string fname = getFilePath(fpath);
	auto pos = fname.find_last_of(".");
	if (pos == string::npos)
		return "";
	fname = string(fname, 0, pos);
	return fname;
}

void outputURL(const DifferenceWithURL& differenceWithURL)
{
	cout << "<td bgcolor=\"#ffffff\"><img width=\"192\" height=\"128\" src=\"http://www.kde.cs.tut.ac.jp/~aono/data/" << differenceWithURL.getURL() << "\"></td>" << endl;
}

void outputDifference(const DifferenceWithURL& differenceWithURL)
{
	cout << "<td bgcolor=\"#ccccff\">" << differenceWithURL.getDifference() << "</td>" << endl;
}

void outputHTML(const vector<DifferenceWithURL>& differenceWithURLs)
{
	cout << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">" << endl;
	cout << "<html lang=\"ja\">" << endl;
	cout << "<head>" << endl;
	cout << "<meta http-equiv=Content-Type content=\"text/html; charset=utf-8\">" << endl;
	cout << "<title>Search from 2D</title>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "<center>" << endl;
	cout << "<h2>" << endl;
	cout << "（課題7）検索結果上位3位　（佐野和輝：163334）" << endl;
	cout << "</h2>" << endl;
	cout << "</center>" << endl;
	cout << "<table border=\"1\">" << endl;
	cout << "<thead>" << endl;
	cout << "<tr bgcolor=\"#aaaaaa\">" << endl;
	cout << "<th bgcolor=\"#ccccff\">クエリ画像 " << ::getFilePath(differenceWithURLs[0].getURL()) << "</th>" << endl;
	cout << "<th width=\"100\"></th>" << endl;
	for (int i = 1; i <= 3; i++)
		cout << "<th bgcolor=\"#ccccff\">" << ::getFilePath(differenceWithURLs[i].getURL()) << "</th>" << endl;
	cout << "</thead>" << endl;
	cout << "<tr bgcolor=\"#cccccc\" align=\"center\">" << endl;
	::outputURL(differenceWithURLs[0]);
	cout << "<td width=\"100\">検索結果<br/>上位3位</td>" << endl;
	for (int i = 1; i <= 3; i++)
		::outputURL(differenceWithURLs[i]);
	cout << "<tr bgcolor=\"#cccccc\" align=\"center\">" << endl;
	::outputDifference(differenceWithURLs[0]);
	cout << "<td width=\"100\">相違度</td>" << endl;
	for (int i = 1; i <= 3; i++)
		::outputDifference(differenceWithURLs[i]);
	cout << "</tr>" << endl;
	cout << "</table>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		cout << argv[0] << " filepath" << endl;
		return 1;
	}
	string fpath(argv[1]);
	string fname(::getFileName(fpath));
	int index = atoi(fname.c_str()) - 100 - 1;

	vector<string> fpaths;
	vector<vector<vector<vector<int>>>> hs;
	for (int i = 1; i <= IMAGE_NUM; i++) {
		string fpath = "images/" + to_string(100 + i) + ".jpg";
		fpaths.push_back(fpath);
		JpegImage jpegImage;
		jpegImage.readJpeg((char*)fpath.c_str());
		Histogram hist(jpegImage, 4);
		vector<vector<vector<int>>> h = hist.compRGBHist();
		hs.push_back(h);
	}

	ImageRetrieval imageRetrieval(fpaths, hs);
	vector<DifferenceWithURL> differenceWithURLs = imageRetrieval.compute(index);

	::outputHTML(differenceWithURLs);

	return 0;
}

