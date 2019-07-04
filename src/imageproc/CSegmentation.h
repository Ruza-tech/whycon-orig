#ifndef __CSEGMENTATION_
#define __CSEGMENTATION_

#include "CRawImage.h"
#include "CTimer.h"
#include <math.h>
#include "cmath.h"
#include "CCircleDetect.h"

class CSegmentation
{
	public:
		//constructor, wi and he correspond to the image dimensions 
		CSegmentation(int wi,int he,int ID = -1);

		//deallocate the detector's structures
		~CSegmentation();

		//main detection method, implements Algorithm 2 of [1] 
		SSegment findSegment(CRawImage* image, SSegment init);

//	private:
		int width,height,len,siz;
		int threshold; 
		bool debug,draw,drawAll,lastTrackOK;
		int numberIDs;
		bool localSearch;
		int *buffer;
		unsigned char *ptr;
		int numSegments;
		bool lastPositive;
};

#endif

/* end of CSegmentation.h */
