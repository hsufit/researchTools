#include<stdio.h>
#include"./bmpRW.h"
#include"./papers.h"

int main()
{
	int i;

	struct bmpD *Img;
	unsigned char *block;
	int *waveblock;

	//bmpRFunc("./lake_gray.bmp",&Img);
	//bmpRFunc("./lake.bmp",&Img);
	//bmpRFunc("./LENA.bmp",&Img);
	//bmpRFunc("./lena512.bmp",&Img);
	//bmpRFunc("./output.bmp",&Img);
	//bmpRFunc("./test.bmp",&Img);
	bmpRFunc("./lena512color.bmp",&Img);
	//bmpRFunc("./flower.bmp",&Img);


	y2010_fast_wavelet(&(Img->C), Img->Width, Img->Height, 5, 5, 80);


	blockinsert(Img->C.GU,Img->Width,Img->Height,0,0,Img->C.RY,Img->Width,Img->Height);
	blockinsert(Img->C.BV,Img->Width,Img->Height,0,0,Img->C.RY,Img->Width,Img->Height);
//	blockinsert(Img->C.BV,600,600,300,300,block,300,300);

	bmpWFunc("./output.bmp",Img,0);

	return 0;
}
