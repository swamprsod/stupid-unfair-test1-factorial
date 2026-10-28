#include <stdio.h>

unsigned long long
fact(unsigned long long a){
	if(a<= 0){ return 1; }
	else{ return a*fact(a-1); }
}

unsigned long long
dumbfact(unsigned long long a){
	unsigned long long acc=1;
	for(int i=acc+1;i<=a;){ acc*=i++; }
	return acc;
}

int
main(){

printf("%llu\n",dumbfact(20ULL));
printf("%llu\n",fact(20ULL));
}



