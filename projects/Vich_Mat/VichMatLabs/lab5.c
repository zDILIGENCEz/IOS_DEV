//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <math.h>
//---------------------------------------------------------------------------
#define x0 1
#define y0 1
#define z0 1
#define e 0.001
//---------------------------------------------------------------------------
float fx(float x,float y, float z)
{
	return (11+2*y+5*z)/11;
}
float fy(float x,float y, float z)
{
	return (7-5*x+z)/7;
}
float fz(float x,float y, float z)
{
	return (5+x+y)/5;
}
int _tmain(int argc, _TCHAR* argv[])
{
	float xk,x=x0,yk,y=y0,zk,z=z0;
	int k=0;
	FILE *file;
	file=fopen("out.csv","w");
	printf("Ìועמה ןנמסעûץ טעונאצטי\n");
	fprintf(file,"Ìועמה ןנמסעûץ טעונאצטי\n");
	printf("---------------------------------------------------------\n");
	printf("|k|Xk\t|Xk+1\t|Xk+1-Xk|Yk|Yk+1|Yk+1-Yk|Zk\t|Zk+1\t|Zk+1-Zk|\n");
	fprintf(file,"k;Xk;Xk+1;Xk+1-Xk;Yk;Yk+1;Yk+1-Yk;Zk;Zk+1;Zk+1-Zk;\n");
	printf("---------------------------------------------------------\n");
	do
	{
		xk=x;
		yk=y;
		zk=z;
		x=fx(xk,yk,zk);
		y=fy(xk,yk,zk);
		z=fz(xk,yk,zk);
		printf("|%d %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n",k++,xk,x,fabs(x-xk),yk,y,fabs(y-yk),zk,z,fabs(z-zk));
		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;\n",k-1,xk,x,fabs(x-xk),yk,y,fabs(y-yk),zk,z,fabs(z-zk));
		printf("---------------------------------------------------------\n");
	}
	while ((fabs(x-xk)>e)||(fabs(y-yk)>e)||(fabs(z-zk)>e));
	k=0;
	x=x0; y=y0; z=z0;
	printf("Ìועמה Çויהוכÿ\n");
	fprintf(file,"Ìועמה Çויהוכÿ\n");
	printf("---------------------------------------------------------\n");
	printf("|k|Xk\t|Xk+1\t|Xk+1-Xk|Yk|Yk+1|Yk+1-Yk|Zk\t|Zk+1\t|Zk+1-Zk|\n");
	fprintf(file,"k;Xk;Xk+1;Xk+1-Xk;Yk;Yk+1;Yk+1-Yk;Zk;Zk+1;Zk+1-Zk;\n");
	printf("---------------------------------------------------------\n");
	do
	{
		xk=x;
		yk=y;
		zk=z;
		x=fx(xk,yk,zk);
		y=fy(x,yk,zk);
		z=fz(x,y,zk);
		printf("|%d %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n",k++,xk,x,fabs(x-xk),yk,y,fabs(y-yk),zk,z,fabs(z-zk));
		fprintf(file,"%d;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f;\n",k-1,xk,x,fabs(x-xk),yk,y,fabs(y-yk),zk,z,fabs(z-zk));
		printf("---------------------------------------------------------\n");
	}
	while ((fabs(x-xk)>e)||(fabs(y-yk)>e)||(fabs(z-zk)>e));
	getch();
	return 0;
}
//---------------------------------------------------------------------------
