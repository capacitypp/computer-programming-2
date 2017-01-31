/*
 * 作成者			: 佐野和輝
 * 日付				: 2016年7月8日
 * プログラムの内容	: 3つの行列の乗算をMatrixクラスによって行い、各行列と計算結果を表示する。つぎに、コマンドライン引数として与えられた整数M,N,R(いずれも2以上10以下)について行列A=(M,R),B=(R,N),C=(M,N)を生成し、それぞれの行列における各要素を-10.0~10.0の乱数で設定する。生成された各行列を表示し、続けてA*BとC+Dを計算して表示する。最後に、行列Aの要素について最小値と最大値を求めて表示する。
 */

#include <iostream>

#include "JpegImage.h"

using namespace std;

void JpegImage::allocateFromScratch(int width, int height, int bytepp)
{
	buffer = new UCHAR[width * height * bytepp];
	func = nullptr;
}

JpegImage::JpegImage()
	: buffer(nullptr)
{

}

JpegImage::JpegImage(int width, int height, int bytepp)
	: width(width), height(height), bytepp(bytepp)
{
	allocateFromScratch(width, height, bytepp);
}

Color JpegImage::getColor(int x, int y)
{
	int addr = (x + y * width) * bytepp;
	int b = buffer[addr + 0];
	int g = buffer[addr + 1];
	int r = buffer[addr + 2];
	float fr = r / 255.0F;
	float fg = g / 255.0F;
	float fb = b / 255.0F;
	return Color(fr, fg, fb);
}

void JpegImage::setColor(int x, int y, const Color& color)
{
	int addr = (x + y * width) * bytepp;
	int r = (int)(color.getR() * 255);
	int g = (int)(color.getG() * 255);
	int b = (int)(color.getB() * 255);
	buffer[addr + 0] = b;
	buffer[addr + 1] = g;
	buffer[addr + 2] = r;
}

int JpegImage::readJpeg(char* filename)
{
	int rc = read_JPEG_file(filename);
	func = nullptr;
	return rc;
}

void JpegImage::writeJpeg(char* filename)
{
	write_JPEG_file(filename);
}

void JpegImage::operator=(const JpegImage& jpegImage)
{
	for (int y = 0; y < jpegImage.height; y++) {
		for (int x = 0; x < jpegImage.width; x++) {
			int addr = (x + y * jpegImage.width) * jpegImage.bytepp;
			buffer[addr + 0] = func(jpegImage.buffer[addr + 0]);
			buffer[addr + 1] = func(jpegImage.buffer[addr + 1]);
			buffer[addr + 2] = func(jpegImage.buffer[addr + 2]);
		}
	}
}

void JpegImage::operator|=(const JpegImage& jpegImage)
{
	for (int y = 0; y < jpegImage.height; y++) {
		for (int x = 0; x < jpegImage.width; x++) {
			int addr = (x * y * jpegImage.width) * jpegImage.bytepp;
			buffer[addr + 0] |= jpegImage.buffer[addr + 0];
			buffer[addr + 1] |= jpegImage.buffer[addr + 1];
			buffer[addr + 2] |= jpegImage.buffer[addr + 2];
		}
	}
}

