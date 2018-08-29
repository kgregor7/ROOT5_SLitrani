#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <ostream> 
#include <iostream>
#include <fstream>
int main() {


FILE *g1 = fopen("datafile-14-41_22-08-2018.dat","rt");



int sims=0;
char ch, line[1024];
while (EOF != (ch=getc(g1))){
	//if('#' == ch) sims= sims-1;
        if ('\n' == ch) ++sims;
	}
fclose(g1);
int nsims=sims;
std::cout << nsims << std::endl;



int ndetektorji[nsims];
int seen[nsims];
int num[nsims];
double eff[nsims], avg;
int najbolseen[33]={0};
double najboleff[33]={0};
int najbolNdet[33]={0};

std::ofstream datafile1;
datafile1.open ("datafile_best-14-41_22-08-2018.dat");

FILE *g2= fopen("datafile-14-41_22-08-2018.dat","rt");

int i=0;
while (fgets(line, sizeof line, g2)) {
	
	sscanf(line, "%d	%d	%d	%lf	%lf",&num[i], &seen[i], &ndetektorji[i], &avg, &eff[i] );
	printf("%d	%d	%d	%f	%f\n", num[i], seen[i],ndetektorji[i],  avg, eff[i] );
	i++;
	}




for(int z=1; z<=32;++z) {
	for(int s=0; s<=nsims; ++s) {	
		if(ndetektorji[s]==z) {
			
			if(eff[s] > najboleff[z]) {
				najbolNdet[z]=num[s];
				najbolseen[z]=seen[s];
				najboleff[z]= eff[s];
					}		
				}	

		}

	std::cout << z << "\t"  << najbolNdet[z] << "\t" << najboleff[z] << "\t" <<najbolseen[z]<< std::endl;
	datafile1 << z << "\t"  << najbolNdet[z]<< "\t" << najboleff[z] <<"\t"<< najbolseen[z]<< std::endl;
	}

datafile2.open ("datafile_7det_all_stats.dat");
datafile2 << "#vrstica\t" << "st.detektorjev\t"<< "ucinkovitost\t"<< "ucinkovitost/st.detektorjev"<< std::endl;
for(int a=0; a<=nsims; ++a) {	
	datafile2 << a << "\t"  << ndetektorji[a]<< "\t" << eff[a] <<"\t"<< eff[a] / (double) ndetektorji[a] << std::endl;
	std::cout << a << "\t"  << ndetektorji[a]<< "\t" << eff[a] <<"\t"<< eff[a] / (double) ndetektorji[a] << std::endl;

	}





return 0;
}
