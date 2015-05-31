#include<stdio.h>
#include<stdlib.h>
#include"./dataOP.h"


void blockdrawMirror(unsigned char *In, int IWidth, int IHeight, int X, int Y, unsigned char** Out, int OWidth, int OHeight)
{
	unsigned char *block;
	int i,j,k,l;

//	if(OWidth%2 && OHeight%2)
//	{
		block=malloc(sizeof(char)*OWidth*OHeight);

		for(i=0;i<OHeight;i++)
			for(j=0;j<OWidth;j++)
			{
				k=Y-OHeight/2+i;
				l=X-OWidth/2+j;

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
//	}
//	else
//		printf("misused block size of Mirror, it must be odd");

}


void wavelet(unsigned char *block, int Width, int Height)
{





}





