struct charcontainer_3
{
	unsigned char *BV;
	unsigned char *GU;
	unsigned char *RY;
};

struct intcontainer_3
{
	unsigned int *A;
	unsigned int *B;
	unsigned int *C;
};

//input width height X Y outout width height
void blockdrawSimple(unsigned char*, int, int, int, int, unsigned char**, int, int);

//input width height X Y outout width heighti
//X Y is central position output blocksize shoule be odd
void blockdrawMirror(unsigned char*, int, int, int, int, unsigned char**, int, int);


void blockinsert(unsigned char*, int, int, int, int, unsigned char*, int, int);

void wavelet(unsigned char*, int, int, int**);

//int to unsigned char
void binerizeItUC(int *, int, int, unsigned char **, int);

void colorRGBtYUV(struct charcontainer_3 *, int, int);

void avgFilter(unsigned char *, int, int, int);

