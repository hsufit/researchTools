#include<stdio.h>
#include"./bmpRW.h"

int main()
{
	int i;

	struct bmpD *Img;
	unsigned char *block;

	bmpRFunc("./lake_gray.bmp",&Img);
	//bmpRFunc("./lake.bmp",&Img);
	//bmpRFunc("./LENA.bmp",&Img);
	//bmpRFunc("./output.bmp",&Img);

	blockdrawMirror(Img->C.RY,826,619,0,0,&block,5,5);

	bmpWFunc("./output.bmp",Img,0);

	return 0;
}
