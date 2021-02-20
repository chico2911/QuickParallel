#include<stdio.h>
#include<omp.h>
#include<math.h>
#include <stdlib.h>
#define ARRAY_MAX_SIZE 500000

void serial_quicksort(int *array, int lo, int hi){
	int i=lo,j=hi,h;
   	int x=array[(lo+hi)/2];
    //partition
    do  {
        while(array[i]<x) i++;
        while(array[j]>x) j--;
        if(i<=j){
        h=array[i]; array[i]=array[j]; array[j]=h;
        i++; j--;
        }
    }while(i<=j);
    //recursion
    if(lo<j) serial_quicksort(array,lo,j);
    if(i<hi) serial_quicksort(array,i,hi);
}

void quicksort(int * array, int lo, int hi){
	int pivotElement;
    //Se o array for menor que 10000, o custo de atribuir threads não compensa, logo executará em modo sequencial
	if((hi - lo + 1) < 10000) {
		serial_quicksort(array, lo, hi);
	} 
    else {
		int i=lo,j=hi,h;
   		int x=array[(lo+hi)/2];
		do{
       		while(array[i]<x) i++;
        	while(array[j]>x) j--;
        	if(i<=j){
        		h=array[i]; array[i]=array[j]; array[j]=h;
        		i++; j--;
        	}
    	}while(i<=j);
		#pragma omp task 
		{
			quicksort(array,lo,j);
		}
		#pragma omp task 
		{
			quicksort(array,i,hi);
		}
		#pragma omp taskwait
	}
}

void readFile(FILE *fp,int *array, int arraySize){
    for( int i = 0; i < arraySize-1; i++ ){
        fscanf (fp, "%d", &array[i]);
    }
}

int main(int argc, char* argv[])
{
    //Open the file where the array is at
    FILE *fp = fopen(argv[1],"r");
    int arraySize = atoi(argv[2]);
	int arr[ARRAY_MAX_SIZE];
    //Read the values from file do array arr
    readFile(fp,arr,arraySize);
    double start_time, run_time;
    // See Beginning time
    start_time = omp_get_wtime();
    //Make QuickSort
    #pragma omp parallel
	#pragma omp single
	{
	quicksort(arr, 0, arraySize-1);
	}
    //Beginning time - Final time
    run_time = omp_get_wtime() - start_time;
	printf("Run time was %lf seconds\n ",run_time);
	return 0; 
} 