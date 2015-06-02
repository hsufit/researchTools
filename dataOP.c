#include<stdio.h>
#include<stdlib.h>
#include"./dataOP.h"


void blockdrawMirror(unsigned char *In, int IWidth, int IHeight, int X, int Y, unsigned char** Out, int OWidth, int OHeight)
{
	unsigned char *block;
	int i,j,k,l;

		block=malloc(sizeof(char)*OWidth*OHeight);

		for(i=0;i<OHeight;i++)
			for(j=0;j<OWidth;j++)
			{
				k=Y+i;
				l=X+j;

				if(l<0)
					l=abs(l)-1;
				else if(l>=IWidth)
					l=IWidth-(l-IWidth+1);

				if(k<0)
					k=abs(k)-1;
				else if(k>=IWidth)
					k=IHeight-(k-IHeight+1);

				block[i*OWidth+j]=In[k*IWidth+l];
//used to print output
//printf("%d,%d:%d,%d : {%u,%u}\n",i,j,k,l,block[i*OWidth+j],In[k*IWidth+l]);
			}

		*Out=block;
}





void blockinsert(unsigned char *In, int IWidth, int IHeight, int X, int Y, unsigned char* Out, int OWidth, int OHeight)
{
	int i,j;

	for(i=0;i<OWidth;i++)
		for(j=0;j<OHeight;j++)
			In[(X+i)*IWidth+Y+j]=Out[i*OWidth+j];

}





void wavelet(unsigned char *block, int Width, int Height, int **pointer)
{
	int i,j;
	unsigned int max=0,min=10000;
	int *tmp,*tmp2;

	if(Width%2 | Height%2)
	{
		printf("error, block's width or height is odd");
		return;
	}

	if(Height<0)
		Height=abs(Height);

	tmp = malloc(sizeof(int)*Width*Height);
	tmp2 = malloc(sizeof(int)*Width*Height);

//vertical
	for(i=0;i<Height;i++)
		for(j=0;j<Width/2;j++)
		{
			tmp[i*Width+j] = block[i*Width+j*2]+block[i*Width+j*2+1];
			tmp[i*Width+j+Width/2] = (int)block[i*Width+j*2]-(int)block[i*Width+j*2+1];
		}

//horizontal
	for(i=0;i<Height/2;i++)
		for(j=0;j<Width;j++)
		{
			tmp2[i*Width+j] = tmp[i*2*Width+j]+tmp[(i*2+1)*Width+j];
			tmp2[(i+Height/2)*Width+j] = tmp[i*2*Width+j]-tmp[(i*2+1)*Width+j];
		}

//normalize
	for(i=0;i<Height;i++)
		for(j=0;j<Width;j++)
		{
			tmp2[i*Width+j] = tmp2[i*Width+j]/4;
		}

	*pointer=tmp2;

	free(tmp);
}

void binerizeItUC(int *In, int Width, int Height, unsigned char**Out, int T)
{
	int i,j;

	int *Iblock;
	unsigned char *Oblock;

	Iblock = malloc(sizeof(int)*Width*Height);
	for(i=0;i<Height;i++)
		for(j=0;j<Width;j++)
			Iblock[i*Width+j] = abs(In[i*Width+j]);

	Oblock = malloc(sizeof(int)*Width*Height);
	for(i=0;i<Height;i++)
		for(j=0;j<Width;j++)
			if(Iblock[i*Width+j]>T)
				Oblock[i*Width+j] = 255;
			else
				Oblock[i*Width+j]=0;

	*Out = Oblock;
	free(Iblock);

}





