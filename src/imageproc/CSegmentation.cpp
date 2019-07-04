#include "CSegmentation.h"

//Variable initialization
CSegmentation::CSegmentation(int wi,int he,int idi)
{
	/*initialization of supporting structures according to the image size provided*/ 
	width = wi;
	height = he;
	len = width*height;
	siz = len*3;
	buffer = (int*)malloc(len*sizeof(int));
	threshold = 128;
	numSegments=1;
	lastPositive = false;
}

CSegmentation::~CSegmentation()
{
		free(buffer);
}

SSegment CSegmentation::findSegment(CRawImage* image, SSegment init)
{
	numSegments = 0;

	for (int i=0;i<len;i++)
	{
		ptr = &image->data[i*3];
		if ((ptr[0]+ptr[1]+ptr[2]) < threshold){
			if (lastPositive)
			{
				blobSize[numSegments]++;
				buffer[i] = numSegments;
			}else{
				buffer[i] = ++numSegments;
				blobSize[numSegments]=0;
			}
			lastPositive=true;
		}else{
			buffer[i] = 0;
			lastPositive=false;
		}

	}


	int pos = 0;
	if (draw){
		for (int i=0;i<len;i++){
			image->data[3*i+0] = buffer[i]%256;
			image->data[3*i+1] = buffer[i]%256;
			image->data[3*i+2] = buffer[i]%256;
		}
	}
	SSegment outer;
	return outer;
}
