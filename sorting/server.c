#include <rpc/rpc.h>
#include "sorting.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Version 1: Bubble sort*/
char * bubblesort_1_svc(arrays *argp, struct svc_req *rqstp)
{
	char *result = malloc(argp->xarray.xarray_len *sizeof(char));
	int i, j;
	char temp;

	for (i=0; i < argp->xarray.xarray_len; i++) {
		for (j=0; j < argp->xarray.xarray_len-i-1; j++) {
			if ( *(argp->xarray.xarray_val+j) > *(argp->xarray.xarray_val+j+1)) {
				temp = *(argp->xarray.xarray_val+j);
				*(argp->xarray.xarray_val+j) = *(argp->xarray.xarray_val+j+1);
				*(argp->xarray.xarray_val+j+1) = temp;
			}		
		}
		result[i] = *(argp->xarray.xarray_val + j); 
	}
	 	
	printf("The sorted array is: %s\n", result);
	return result;
}

/*Version 2: Merge sort*/
char * mergesort_2_svc(arrays *argp, struct svc_req *rqstp)
{
	char *result = malloc(argp->xarray.xarray_len * sizeof(char));
	int middle = (int)(argp->xarray.xarray_len/2);
	int i, j, k;
	//Sort left array
	for (i=0; i<middle-1; i++) {
		for (j=i+1; j<middle; j++) {
			char temp;
			if ( *(argp->xarray.xarray_val+i) > *(argp->xarray.xarray_val+j) ) {
				temp = *(argp->xarray.xarray_val+i);
				*(argp->xarray.xarray_val+i) = *(argp->xarray.xarray_val+j);
				*(argp->xarray.xarray_val+j) = temp;
			}
		}
	}

	//sort right array
	for (i=middle+1; i<argp->xarray.xarray_len-1; i++) {
		for (j=i+1; j<argp->xarray.xarray_len; j++) {
			char temp;
			if (*(argp->xarray.xarray_val+i) > *(argp->xarray.xarray_val+j)) {
				temp = *(argp->xarray.xarray_val+i);
				*(argp->xarray.xarray_val+i) = *(argp->xarray.xarray_val+j);
				*(argp->xarray.xarray_val+j) = temp;
			}
		}
	}

	//Merge and sort whole array
	i = j = k = 0;
	for ( ; k < argp->xarray.xarray_len; ) {
		if ( *(argp->xarray.xarray_val+i) <= *(argp->xarray.xarray_val+middle+j) )
			result[k++] = *(argp->xarray.xarray_val+ i++);
		else
			result[k++] = *(argp->xarray.xarray_val+middle+ j++); 
		if (i == middle || j == middle) 
			break;
	}

	for ( ; i<middle; ) 
		result[k++] = *(argp->xarray.xarray_val+ i++);
	for ( ; j<middle; )
		result[k++] = *(argp->xarray.xarray_val+middle+ j++);
	printf("The sorted array is: %s\n", result);
	return result;
}





