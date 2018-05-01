#ifndef __CGUI_H__
#define __CGUI_H__

#include "CRawImage.h"
#include "CTransformation.h"
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class CGui
{
public:
  CGui(int wi,int he,int scale);
  ~CGui();

  void drawImage(CRawImage* image);
  void drawStats(int x,int y,STrackedObject o);
  void drawTimeStats(int evalTime,int numBots);
  void guideCalibration(int calibNum,float a,float b);
  void clearStats();
  void saveScreen(int a = -1);
  void update();
  void setColor(int r,int g,int b);
  void drawEllipse(SSegment s,STrackedObject t);
  void drawLine(float sx1,float sx2,float sy1,float sy2,int color = 0);
  void displayHelp(bool extended);
  void drawStats(int x,int y,STrackedObject o, bool D2);

private:
  SDL_Surface *screen;
  int width,height,scale;
  TTF_Font *smallFont;
  int averageTime,maxTime,numStats,num;
  int red,green,blue;	
};

#endif

/* end of CGui.h */
