#include<stdlib.h>
#include"./dataOP.h"

void y2010_fast_wavelet(struct charcontainer_3* data, int Width, int Height, int T1, int N,int T2)
{
	int i,j;

	int *waveletData;
	unsigned char *tmp, *tmp2;

	colorRGBtYUV(data, Width, Height);

	waveletData = malloc(sizeof(int)*Width*Height);
	wavelet(data->RY, Width, Height ,&waveletData);

	binerizeItUC(waveletData, Width, Height, &(data->GU), T1);

//merge wavelet data to one image
	blockdrawMirror(data->GU, Width, Height, Width/2, Height/2, &tmp, Width/2, Height/2);
	blockdrawMirror(data->GU, Width, Height, Width/2,0, &tmp2,Width/2,Height/2);
	blockinsert(data->RY, Width, Height, Width/2, 0, tmp2, Width/2, Height/2);
	for(i=0;i<Height/2;i++)
		for(j=0;j<Width/2;j++)
			tmp[i*Width/2+j] |= tmp2[i*Width/2+j];
	free(tmp2);

	blockdrawMirror(data->GU, Width, Height, 0, Height/2, &tmp2,Width/2,Height/2);
	blockinsert(data->RY, Width, Height, 0, Height/2, tmp2, Width/2, Height/2);
	for(i=0;i<Height/2;i++)
		for(j=0;j<Width/2;j++)
			tmp[i*Width/2+j] |= tmp2[i*Width/2+j];
	free(tmp2);

	binerizeItUC(waveletData, Width, Height, &(data->GU), 256);
	blockdrawMirror(data->GU, Width, Height, 0, 0, &tmp2,Width/2,Height/2);
	blockinsert(data->RY, Width, Height, 0, 0, tmp2, Width/2, Height/2);
	free(tmp2);

//test image gen
	blockinsert(data->RY, Width, Height, 0, 0, tmp, Width/2, Height/2);

	avgFilter(tmp,Width/2,Height/2,N);

	binerizeUCtUC(tmp,Width/2,Height/2,&tmp2,T2);

	blockinsert(data->RY, Width, Height, Width/2, Height/2, tmp2, Width/2, Height/2);

	free(tmp);
	free(tmp2);

	free(waveletData);

}



