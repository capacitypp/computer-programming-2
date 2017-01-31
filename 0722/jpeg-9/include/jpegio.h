#ifndef _JPEGIO
#define _JPEGIO
#include <cstdio>
#include <cstdlib>
#include <csetjmp>
#include <cstring>
#include <cmath>
#include "jpeglib.h"
#define OUTPUT_QUALITY 100    /* JPEG���Ϥβ��(1-100) */
typedef unsigned char UCHAR;/* unsigned char */

class JpegImage {	/* JPEG���饹 */
	int image_width;		/* ���ϲ������� */
	int image_height;		/* ���ϲ����ι⤵ */
	int image_bytepp;		/* �����Ǥ�ͭ����Х��ȿ� */
	UCHAR *image_buffer;	/* ���ϲ�����RGB�ǡ����ؤΥݥ��� */
	int (*func)(int); /* �������������Ԥ��ؿ��ؤΥݥ��� */
public:
	JpegImage(){} 
	JpegImage(int w, int h, int b) : image_width(w), image_height(h), image_bytepp(b){
		image_buffer = new UCHAR[w * h * b];
	}
	void write_JPEG_file (char * filename, int quality);
	void write_JPEG_file (char * filename);/* JPEG�ե�����񤭽Ф� */
	int  read_JPEG_file (char * filename);/* JPEG�ե������ɹ� */
	void setFunc(int (*f)(int)){ func = f; }/* ���������ؿ������� */
	void rgb2Lab(int r, int g, int b, float *Lv, float *av, float *bv);/* RGB->Lab */
	UCHAR operator [ ] (int n) {return image_buffer[n];};/* ����黻�ҥ����С����� */
	void  operator = (const JpegImage &A){/* RGB�ǡ�������ؤ����������С�����*/
		for ( int y = 0 ; y < A.image_height ; y++ ){
			for ( int x = 0 ; x < A.image_width ; x++ ){
				/* ��ɸ(x,y)�β��ǤΥ��ɥ쥹��׻����� */
				int addr = x * A.image_bytepp + y * A.image_width * A.image_bytepp;
				/* RGB�����ο�ȿž�򷫤��֤� */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+0]);/* ����ʬ�˴ؿ� */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+1]);/* ����ʬ�˴ؿ� */
				image_buffer[addr+0] = (*A.func)(A.image_buffer[addr+2]);/* ����ʬ�˴ؿ� */
			}
		}
	}
	void  operator |= (const JpegImage &A){/* RGB�ǡ�������Υӥå�OR���������С����� */
		for ( int y = 0 ; y < A.image_height ; y++ ){
			for ( int x = 0 ; x < A.image_width ; x++ ){
				/* ��ɸ(x,y)�β��ǤΥ��ɥ쥹��׻����� */
				int addr = x * A.image_bytepp + y * A.image_width * A.image_bytepp;
				/* RGB������­������ */
				image_buffer[addr+0] |= A.image_buffer[addr + 0];/* �ֿ���ʬ�ؤβû� */
				image_buffer[addr+1] |= A.image_buffer[addr + 1];/* �п���ʬ�ؤβû� */
				image_buffer[addr+2] |= A.image_buffer[addr + 2];/* �Ŀ���ʬ�ؤβû� */
			}
		}
	}
	int iH(){ return image_height;}
	int iW(){ return image_width;}
	int iB(){ return image_bytepp;}
};
#endif
