#include<stdio.h>
#include"./bmpRW.h"

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
	bmpRFunc("./test.bmp",&Img);

	blockdrawMirror(Img->C.RY,600,600,0,300,&block,300,300);

	wavelet(block,300,300,&waveblock);

	binerizeItUC(waveblock,300,300,&block,0);

	blockinsert(Img->C.RY,600,600,300,300,block,300,300);
	blockinsert(Img->C.GU,600,600,300,300,block,300,300);
	blockinsert(Img->C.BV,600,600,300,300,block,300,300);

	bmpWFunc("./output.bmp",Img,0);

	return 0;
}
