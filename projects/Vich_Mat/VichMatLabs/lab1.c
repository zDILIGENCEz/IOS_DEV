//---------------------------------------------------------------------------
#include <conio.h>
#include <stdio.h>
#pragma hdrstop
#include <math.h>
#include <tchar.h>
//---------------------------------------------------------------------------

#pragma argsused

#define e 0.001
#define delta 0.01
#define c 0.5
#define x0 -2.5

float f(float x)
{
	return 2*sin(x)-x+0.4;
}

float pf(float x)
{
	return 2*cos(x)-1;
}
int _tmain(int argc, _TCHAR* argv[])
{   float xn,x=x0;
	int n=0;
	FILE *file;
	file=fopen("out.csv","w");
	//Метод простых итераций
	printf("ЊҐв®¤ Їа®бвле ЁвҐа жЁ©\n"); //"Метод простых итераций" в cp866
	fprintf(file,"Метод простых итераций\n");
	printf("-----------------------------------------\n");
	printf("|n\t|Xn\t|Xn+1\t|Xn+1-Xn|F(Xn+1)|\n");
	fprintf(file,"n;Xn;Xn+1;Xn+1-Xn;F(Xn+1);\n");
	printf("-----------------------------------------\n");
	do
	{
		xn=x;
		x=xn+c*f(xn);
		printf("|%d\t|%.4f|%.4f|%.4f\t|%.4f\t|\n",n++,xn,x,fabs(x-xn),fabs(f(x)));
		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;\n",n-1,xn,x,fabs(x-xn),fabs(f(x)));
		printf("-----------------------------------------\n");
	}
	while ((fabs(x-xn)>e)||(fabs(f(x))>delta));
	//Метод Ньютона
	x=x0;
	n=0;
	printf("ЊҐв®¤ Ќмов®­ \n"); //"Метод Ньютона" в cp866
	fprintf(file,"Метод Ньютона\n");
	printf("-----------------------------------------\n");
	printf("|n\t|Xn\t|Xn+1\t|Xn+1-Xn|F(Xn+1)|\n");
	fprintf(file,"n;Xn;Xn+1;Xn+1-Xn;F(Xn+1);\n");
	printf("-----------------------------------------\n");
	do
	{
		xn=x;
		x=xn-(f(xn)/pf(xn));
		printf("|%d\t|%.4f|%.4f|%.4f\t|%.4f\t|\n",n++,xn,x,fabs(x-xn),fabs(f(x)));
		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;\n",n-1,xn,x,fabs(x-xn),fabs(f(x)));
		printf("-----------------------------------------\n");
	}
	while ((fabs(x-xn)>e)||(fabs(f(x))>delta));
	//Модифицированный метод Ньютона
	x=x0;
	n=0;
	printf("Њ®¤ЁдЁжЁа®ў ­­л© ¬Ґв®¤ Ќмов®­ \n");//"Модифицированный метод Ньютона" в cp866
	fprintf(file,"Модифицированный метод Ньютона\n");
	printf("-----------------------------------------\n");
	printf("|n\t|Xn\t|Xn+1\t|Xn+1-Xn|F(Xn+1)|\n");
	fprintf(file,"n;Xn;Xn+1;Xn+1-Xn;F(Xn+1);\n");
	printf("-----------------------------------------\n");
	do
	{
		xn=x;
		x=xn-(f(xn)/pf(x0));
		printf("|%d\t|%.4f|%.4f|%.4f\t|%.4f\t|\n",n++,xn,x,fabs(x-xn),fabs(f(x)));
		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;\n",n-1,xn,x,fabs(x-xn),fabs(f(x)));
		printf("-----------------------------------------\n");
	}
	while ((fabs(x-xn)>e)||(fabs(f(x))>delta));
	getch();
	return 0;
}
//---------------------------------------------------------------------------
