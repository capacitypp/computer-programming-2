#ifndef _JPEGIO
#define _JPEGIO
#include <cstdio>
#include <cstdlib>
#include <csetjmp>
#include <cstring>
#include <cmath>
#include "jpeglib.h"
#define OUTPUT_QUALITY 100    /* JPEG出力の画質(1-100) */
typedef unsigned char UCHAR;/* unsigned char */

class JpegImage {	/* JPEGクラス */
	int image_width;		/* 入力画像の幅 */
	int image_height;		/* 入力画像の高さ */
	int image_bytepp;		/* １画素が有するバイト数 */
	UCHAR *image_buffer;	/* 入力画像のRGBデータへのポインタ */
	int (*func)(int); /* ある画像処理を行う関数へのポインタ */
public:
	JpegImage(){} 
	JpegImage(int w, int h, int b) : image_width(w), image_height(h), image_bytepp(b){
		image_buffer = new UCHAR[w * h * b];
	}
	void write_JPEG_file (char * filename, int quality);
	void write_JPEG_file (char * filename);/* JPEGファイル書き出し */
	int  read_JPEG_file (char * filename);/* JPEGファイル読込 */
	void setFunc(int (*f)(int)){ func = f; }/* 画像処理関数の設定 */
	void rgb2Lab(int r, int g, int b, float *Lv, float *av, float *bv);/* RGB->Lab */
	UCHAR operator [ ] (int n) {return image_buffer[n];};/* 配列演算子オーバーロード */
	void  operator = (const JpegImage &A){/* RGBデータ配列への代入オーバーロード*/
		for ( int y = 0 ; y < A.image_height ; y++ ){
			for ( int x = 0 ; x < A.image_width ; x++ ){
				/* 座標(x,y)の画素のアドレスを計算する */
				int addr = x * A.image_bytepp + y * A.image_width * A.image_bytepp;
				/* RGB３色の色反転を繰り返す */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+0]);/* 赤成分に関数 */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+1]);/* 緑成分に関数 */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+2]);/* 青成分に関数 */
			}
		}
	}
	void  operator |= (const JpegImage &A){/* RGBデータ配列のビットOR代入オーバーロード */
		for ( int y = 0 ; y < A.image_height ; y++ ){
			for ( int x = 0 ; x < A.image_width ; x++ ){
				/* 座標(x,y)の画素のアドレスを計算する */
				int addr = x * A.image_bytepp + y * A.image_width * A.image_bytepp;
				/* RGB３色を足しこむ */
				image_buffer[addr+0] |= A.image_buffer[addr + 0];/* 赤色成分への加算 */
				image_buffer[addr+1] |= A.image_buffer[addr + 1];/* 緑色成分への加算 */
				image_buffer[addr+2] |= A.image_buffer[addr + 2];/* 青色成分への加算 */
			}
		}
	}
	int iH(){ return image_height;}
	int iW(){ return image_width;}
	int iB(){ return image_bytepp;}
};
#endif
