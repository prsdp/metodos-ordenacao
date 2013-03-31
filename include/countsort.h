#ifndef _COUNT_SORT_H
#define _COUNT_SORT_H

void count_sort(int arraya[], int TAM, int max){
             
	int arrayb[TAM];
	int arrayc[max+1];
	int i;
	
	for(i=0;i<=max;i++){
		arrayc[i]=0;
	}
	for(i=0;i<TAM;i++){
		arrayc[arraya[i]]=arrayc[arraya[i]]+1;
	}
	for(i=1;i<=max;i++){
		arrayc[i]=arrayc[i]+arrayc[i-1];
	}
	for(i=(TAM-1);i>=0;i--){
		arrayb[arrayc[arraya[i]]-1]=arraya[i];
		arrayc[arraya[i]]=arrayc[arraya[i]]-1;
	}
	
}
#endif
