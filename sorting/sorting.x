struct arrays {
	char xarray<41>;
};


program SORTING_PROG {

	/*VERSION 1: BUBBLE SORT*/
	version SORTING_VERS1 {
		char bubblesort(arrays)=1;
	}=1;
	
	/*VERSION 2: MERGE SORT*/
	version SORTING_VERS2 {
		char mergesort(arrays)=1;
	}=2;

}=0x23451111;


