/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#ifndef ___Class_JpegImage
#define ___Class_JpegImage

#include "Color.h"

using UCHAR = unsigned char;
using IFPtr = int (*)(int);

class JpegImage {
private:
	int width;
	int height;
	int bytepp;
	UCHAR* buffer;
	IFPtr func;

private:
	void allocateFromScratch(int width, int height, int bytepp);
	void write_JPEG_file(char* filename, int quality);
	void write_JPEG_file(char* filename);
	int read_JPEG_file(char* filename);


public:
	JpegImage();
	JpegImage(int width, int height, int bytepp);

	Color getColor(int x, int y);
	void setColor(int x, int y, const Color& color);
	int getWidth(void) const;
	int getHeight(void) const;
	int getBytepp(void) const;
	int readJpeg(char* filename);
	void writeJpeg(char* filename);
	void setFunc(IFPtr func);

	void operator=(const JpegImage& jpegImage);
	void operator|=(const JpegImage& jpegImage);
};

inline int JpegImage::getWidth(void) const
{
	return width;
}

inline int JpegImage::getHeight(void) const
{
	return height;
}

inline int JpegImage::getBytepp(void) const
{
	return bytepp;
}

inline void JpegImage::setFunc(IFPtr func)
{
	this->func = func;	
}

#endif

