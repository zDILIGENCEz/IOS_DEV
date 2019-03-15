//---------------------------------------------------------------------------
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <conio.h>
//---------------------------------------------------------------------------
#define A 1 //начало
#define B 3 //конец отрезка
#define N 8 //разбиение
#define NPOINT 3 //кол-во исходных точек: не трогать!
//---------------------------------------------------------------------------

float f(float x)
{
	return (7*sqrt(pow(x,2)+1))/pow(x,4);
}
float L2(float x, float a[], float xi[])
{
	return a[0]*(x-xi[1])*(x-xi[2])+a[1]*(x-xi[0])*(x-xi[2])+a[2]*(x-xi[0])*(x-xi[1]);
}
float N1(float x, float xi[], float t)
{
	return f(xi[0])+t*(f(xi[1])-f(xi[0]))+((t*(t-1))/2)*((f(xi[2])-f(xi[1]))-(f(xi[1])-f(xi[0])));
}
float N2 (float x, float xi[], float t)
{
	return f(xi[2])+t*(f(xi[2])-f(xi[1]))+((t*(t+1))/2)*((f(xi[2])-f(xi[1]))-(f(xi[1])-f(xi[0])));
}
float P(float x, float a[])
{
	return a[2]*x*x+a[1]*x+a[0];
}
int _tmain(int argc, _TCHAR* argv[])
{
	float x[NPOINT],xisum=0,xi2sum=0,xi3sum=0,xi4sum=0,yisum=0,xiyisum=0,xi2yisum=0;
	float a[NPOINT],aP[NPOINT],op,L,i,fx,lxp,shag,h,t;
	int k,j;
	shag=((float)(B-A)/N);
	h=(B-A)/(NPOINT-1);
	for (i=A,k=0; k<NPOINT; i+=h,k++) x[k]=i;
	a[0]=f(x[0])/((x[0]-x[1])*(x[0]-x[2]));
	a[1]=f(x[1])/((x[1]-x[0])*(x[1]-x[2]));
	a[2]=f(x[2])/((x[2]-x[0])*(x[2]-x[1]));
	for (k=0; k<NPOINT; k++) {
		xisum+=x[k];
		xi2sum+=pow(x[k],2);
		xi3sum+=pow(x[k],3);
		xi4sum+=pow(x[k],4);
		yisum+=f(x[k]);
		xiyisum+=x[k]*f(x[k]);
		xi2yisum+=pow(x[k],2)*f(x[k]);
	}
	op=3*xi4sum*xi2sum+2*xisum*xi2sum*xi3sum-pow(xi2sum,3)-xi4sum*pow(xisum,2)-3*pow(xi3sum,2);
	aP[0]=(yisum*xi2sum*xi4sum+xisum*xi3sum*xi2yisum+xiyisum*xi3sum*xi2sum-pow(xi2sum,2)*xi2yisum-xi4sum*xisum*xiyisum-pow(xi3sum,2)*yisum)/op;
	aP[1]=(3*xiyisum*xi4sum+yisum*xi3sum*xi2sum+xisum*xi2yisum*xi2sum-pow(xi2sum,2)*xiyisum-xi4sum*xisum*yisum-3*xi3sum*xi2yisum)/op;
	aP[2]=(3*xi2sum*xi2yisum+xisum*xiyisum*xi2sum+xisum*yisum*xi3sum-pow(xi2sum,2)*yisum-xi2yisum*pow(xisum,2)-3*xi3sum*xiyisum)/op;
	k=0;
	puts("-------------------------------------------------------------------------");
	printf("|N |xi\t\t|f(x)\t|L2(x)\t||f(x)-L2(x)|\t|N1(x)\t|t\t||f(x)-N1(x)||\n");
	puts("-------------------------------------------------------------------------");
	for (i = A;i<B+shag; i+=shag) {
		t=(i-x[0])/h;
		printf("|%2.d|%.3f\t|%.3f\t|%.3f\t\t|%.3f\t|%.3f\t|%.3f\t|%.3f\t|\n",k++,i,f(i),L2(i,a,x),fabs(f(i)-L2(i,a,x)),N1(i,x,t),t,fabs(f(i)-N1(i,x,t)));
		puts("-------------------------------------------------------------------------");
	}
	k=0;
	puts("-------------------------------------------------------------------------");
	printf("|N  |xi\t\t|f(x)\t|N2(x)\t|t'\t||f(x)-N2(x)|\t|P(x)\t||f(x)-P(x)||\n");
	puts("-------------------------------------------------------------------------");
	for (i = A; i <B+shag; i+=shag) {
		t=(i-x[2])/h;
		printf("|%2.d|%.3f\t|%.3f\t|%.3f\t|%.3f\t|%.3f\t\t|%.3f\t|%.3f|\n",k++,i,f(i),N2(i,x,t),t,fabs(f(i)-N2(i,x,t)),P(i,aP),fabs(f(i)-P(i,aP)));
		puts("-------------------------------------------------------------------------");
	}
	getch();
	return 0;
}
//---------------------------------------------------------------------------
