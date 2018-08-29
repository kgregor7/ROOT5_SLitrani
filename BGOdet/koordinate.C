#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

int main()

{

FILE *f1 = fopen("/home/gkosir/BGO/DEGAS-BC-SiPM-Bottom-SIPM-Positions.txt","rt");
FILE *f2 = fopen("/home/gkosir/BGO/coords.dat","wt");
int i=0;
int sipm[32];
double x1[32],y1[32];
while (i<32){
	
	fscanf(f1, "%d	%lf	%lf	\n", &sipm[i], &x1[i], &y1[i]);
	
	printf("%d	%f	%f\n", sipm[i], x1[i], y1[i]);
++i;
}



double x2,y2;


for(int j=0; j<32; ++j){
	x2=y1[j]*0.1 - 4.907477288;
	y2=-x1[j]*0.1;
	printf("%d	%f	%f\n", sipm[j], x2, y2);
	fprintf(f2, "%d	%f	%f\n", sipm[j], x2, y2);


}

















return 0;
}
