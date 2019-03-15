//---------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <tchar.h>
//---------------------------------------------------------------------------
#define A 1
#define B 2
#define N 1000
float fxy(float x, float y)
{
	return pow(x,2)*(y+2);
}
float yx(float x)
{
	return 2*exp(-((float)1/3))*exp(pow(x,3)/3)-2;
}
int _tmain(int argc, _TCHAR* argv[])
{
	float x,y=0,yi,yr,yir=0,h,k[4];
	int n=0;
	h=((float)(B-A)/N);
	x=yx(1);
	puts("-------------------------------------------------------------------------");
	puts("|N  |xi\t\t|y(x)\t|y\t||y-y(x)|\t|yr\t||yr-y(x)|\t|");
	puts("-------------------------------------------------------------------------");
	for (x=A; x<B+h; x+=h, yi=y, yir=yr) {
	   printf("|%3.d|%.3f\t|%.3f\t|%.3f\t|%.3f\t\t|%.3f\t|%.6f\t\t|\n",n++,x,yx(x),y,fabs(y-yx(x)),yr,fabs(yr-yx(x)));
	   puts("-------------------------------------------------------------------------");
	   y=yi+h*fxy(x,yi);
	   k[0]=h*fxy(x,yir);
	   k[1]=h*fxy(x+h/2,yir+k[0]/2);
	   k[2]=h*fxy(x+h/2,yir+k[1]/2);
	   k[3]=h*fxy(x+h,yir+k[2]);
	   yr=yir+(k[0]+2*k[1]+2*k[2]+k[3])/6;
	}
	getch();
	return 0;
}
//---------------------------------------------------------------------------
