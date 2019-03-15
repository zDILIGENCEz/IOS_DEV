//---------------------------------------------------------------------------
#include <stdio.h>
#pragma hdrstop
#include <tchar.h>
#include <math.h>
#include <conio.h>
//---------------------------------------------------------------------------
#pragma argsused
//---------------------------------------------------------------------------
#define e 0.001
#define x0 -1
#define y0 -3
//---------------------------------------------------------------------------
float f1x(float x, float y)
{
	return x-0.25*(x-y+2)+0.25*(x*y-3);
}
float f1y(float x,float y)
{
	return y+0.75*(x-y+2)+0.25*(x*y-3);
}
float fwx(float x,float y)
{
	return x-(1/(x+y))*(x*x+2*x-3);
}
float fwy(float x,float y)
{
	return y-(1/(x+y))*(y*y-2*y-3);
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	float xk,x=x0,yk,y=y0;
	int k=0;
 //	FILE *file;
 //	file=fopen("out.csv","w");
	//Метод простых итераций
	printf("ЊҐв®¤ Їа®бвле ЁвҐа жЁ©\n"); //"Метод простых итераций" в cp866
  //	fprintf(file,"Метод простых итераций\n");
	printf("---------------------------------------------------------\n");
	printf("|k\t|Xk\t|Xk+1\t|Xk+1-Xk|Yk\t|Yk+1\t|Yk+1-Yk|\n");
   //	fprintf(file,"k;Xk;Xk+1;Xk+1-Xk;Yk;Yk+1;Yk+1-Yk;\n");
	printf("---------------------------------------------------------\n");
	do
	{
		xk=x;
		yk=y;
		x=f1x(xk,yk);
		y=f1y(xk,yk);
		printf("|%d\t|%.4f|%.4f|%.4f\t|%.4f|%.4f|%.4f\t|\n",k++,xk,x,fabs(x-xk),yk,y,fabs(y-yk));
   //		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;\n",k-1,xk,x,fabs(x-xk),yk,y,fabs(y-yk));
		printf("---------------------------------------------------------\n");
	}
	while ((fabs(x-xk)>e)||(fabs(y-yk)>e));
	//метод ньтона

	x=x0; y=y0; k=0;
	printf("ЊҐв®¤ Ќмов®­ \n"); //"Метод Ньютона" в cp866
   //	fprintf(file,"Метод простых итераций\n");
	printf("---------------------------------------------------------\n");
	printf("|k\t|Xk\t|Xk+1\t|Xk+1-Xk|Yk\t|Yk+1\t|Yk+1-Yk|\n");
   //	fprintf(file,"k;Xk;Xk+1;Xk+1-Xk;Yk;Yk+1;Yk+1-Yk;\n");
	printf("---------------------------------------------------------\n");
	do
	{
		xk=x;
		yk=y;
		x=fwx(xk,yk);
		y=fwy(xk,yk);
		printf("|%d\t|%.4f|%.4f|%.4f\t|%.4f|%.4f|%.4f\t|\n",k++,xk,x,fabs(x-xk),yk,y,fabs(y-yk));
	//	fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;\n",k-1,xk,x,fabs(x-xk),yk,y,fabs(y-yk));
		printf("---------------------------------------------------------\n");
	}
	while ((fabs(x-xk)>e)||(fabs(y-yk)>e));
	getch();
	return 0;
}
//---------------------------------------------------------------------------
