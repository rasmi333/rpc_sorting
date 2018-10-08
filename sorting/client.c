#include <stdio.h>
#include <rpc/rpc.h>
#include "sorting.h"
#include <math.h>
#include <stdio.h>
#include <rpc/rpc.h>
#include <time.h>
#include <stdlib.h>

/*Version 1: Bubble sort*/
char sorting_prog_1(char *host,int len, char values[], CLIENT *clnt)
{
	char *result_1 = malloc(len * sizeof(char));
	
	arrays bubblesort_1_arg;

	bubblesort_1_arg.xarray.xarray_val=values;
	bubblesort_1_arg.xarray.xarray_len=len; 
			
	result_1 = bubblesort_1(&bubblesort_1_arg, clnt);
	if (result_1==(char *) NULL) {
		printf("error");
     		clnt_perror (clnt, "call failed");
	} 
 	else {
		printf("The bubble-sorted array: ");
		printf("%s \n", result_1);
	}	
}

/*Version 2: Merge Sort*/
char sorting_prog_2(char *host,int len, char values[], CLIENT *clnt)
{
	char *result_2 = malloc(len * sizeof(char));
	arrays mergesort_2_arg;

	mergesort_2_arg.xarray.xarray_val=values;
	mergesort_2_arg.xarray.xarray_len=len; 

	result_2 = mergesort_2(&mergesort_2_arg, clnt);
	if (result_2==(char *) NULL) {
		printf("error");
     		clnt_perror (clnt, "call failed");
	}
	else { 
		printf("The merge-sorted array is: "); 
		printf("%s \n", result_2); 
	}
		
}

int main (int argc, char *argv[])
{
	CLIENT*clnt;
	char *host;
    	srand(time(0)); 

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	clnt = clnt_create(host, SORTING_PROG, SORTING_VERS1, "udp");
	if (clnt == NULL) {
	clnt_pcreateerror (host);	
	exit(1);
																																																																																																																																																										}
	
	/*Generate 3 random different arrays and write them into input file*/
	FILE *fptr;
	fptr = fopen("inputfile.txt", "w");
	int i;
	for (i = 0; i < 15; i++)  //Array 1 with 15 numbers
	{ 
        	int num = (rand()%94) + 33; 
        	fprintf(fptr, "%d,", num);	       
	}
	fprintf(fptr, "\n");

	for (i=0; i<20; i++)  //Array 2 with 20 numbers
	{
		int num = (rand()%94) + 33; 
        	fprintf(fptr, "%d,", num); 
	}
	fprintf(fptr, "\n");
	
	for (i=0; i<25; i++)  //Array 3 with 25 numbers
	{
		int num = (rand()%94) + 33; 
        	fprintf(fptr, "%d,", num); 
	}
	fprintf(fptr, "\n");
	fclose(fptr);

	 	//read
	fptr = fopen("inputfile.txt", "r");
	if (fptr != NULL)
	{
		char arr[150]; 
		int line =0;
		while(fgets(arr, sizeof(arr), fptr)) {
			line++;
			/*Array 1*/
			if(line ==1) {
				printf("Array 1\n");	
				int i=0;
				char *array[15];
				char *p = strtok(arr, ",");
				char random_char[15];
				int random_num[15];
				while (p!=NULL) {
					array[i++] = p;
					p = strtok(NULL, ",");
				}
				printf("The ASCII array: ");
				for (i=0; i<15; i++) {
					printf("%s ", array[i]);
					int num = atoi(array[i]);
					random_num[i] = num;
					char c = num;
					random_char[i] = c;
				}
				printf("\n");
				printf("The unsorted array: ");	
				for (i=0; i<15; i++) {
					printf("%c ", random_char[i]);
				}
				printf("\n");
				sorting_prog_1(host, 15, random_char, clnt);
				sorting_prog_2(host, 15, random_char, clnt);
				printf("\n");
			}
			/*Array 2*/
			if(line ==2) {
				printf("Array 2\n");
				int i=0;
				char *array[20];
				char *p = strtok(arr, ",");
				char random_char[20];
				int random_num[20];
				while (p!=NULL) {
					array[i++] = p;
					p = strtok(NULL, ",");
				}
				printf("The ASCII array: ");
				for (i=0; i<20; i++) {
					printf("%s ", array[i]);
					int num = atoi(array[i]);
					random_num[i] = num;
					char c = num;
					random_char[i] = c;
				}
				printf("\n");
				printf("The unsorted array: ");	
				for (i=0; i<20; i++) {
					printf("%c ", random_char[i]);
				}
				printf("\n");
				sorting_prog_1(host, 20, random_char, clnt);
				sorting_prog_2(host, 20, random_char, clnt);
				printf("\n");
			}
			/*Array 3*/
			if(line ==3) {
				printf("Array 3\n");
				int i=0;
				char *array[25];
				char *p = strtok(arr, ",");
				char random_char[25];
				int random_num[25];
				while (p!=NULL) {
					array[i++] = p;
					p = strtok(NULL, ",");
				}
				printf("The ASCII array: ");
				for (i=0; i<25; i++) {
					printf("%s ", array[i]);
					int num = atoi(array[i]);
					random_num[i] = num;
					char c = num;
					random_char[i] = c;
				}
				printf("\n");
				printf("The unsorted array: ");	
				for (i=0; i<25; i++) {
					printf("%c ", random_char[i]);
				}
				printf("\n");
				sorting_prog_1(host, 25, random_char, clnt);
				sorting_prog_2(host, 25, random_char, clnt);
				printf("\n");
			}
		}
		fclose(fptr);
	} 
	else {
		printf("File does not exits");
		exit(1);
	}

	clnt_destroy (clnt);
	exit (0);
}
