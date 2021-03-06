// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
<<<<<<< HEAD
	const int MaxSize = 100000;
=======
    //apparently I had an old version, so updated this from 25k to 100k
    const int MaxSize = 1000000;
	//const int MaxSize = 25000;
>>>>>>> 926a660616bea0eb60a938ff292ad61aa76ed33c
	int i, j, temp;


	// Part one: processing a statically allocated array


    //start time for initializing static array
    clock_t s_total_begin = clock();
	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

    //start time for sorting static array
    clock_t s_begin = clock();
    /*
	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}

    */
    //end time for sorting static array
    clock_t s_end = clock();
    clock_t s_total_end = clock();
    printf("Static: Sorting Time used: %lf%s\n", 
            (double)(s_end - s_begin) / CLOCKS_PER_SEC, ", Seconds");

	// Part two: processing a dynamically allocated array

    //start time for initializing dynamic array
    clock_t d_total_begin = clock();
    int * dynamicArray;
    int * dynamicStart;
<<<<<<< HEAD
=======
    int * dynamicEnd;
>>>>>>> 926a660616bea0eb60a938ff292ad61aa76ed33c
    dynamicArray = (int*) malloc(MaxSize * sizeof(int));
    dynamicStart = dynamicArray;

    dynamicStart = dynamicArray;
    if(dynamicArray == NULL) {
        //ran out of memory
        exit(1);
    }

    //intialize the dynamic array
	for (i=0; i<MaxSize; i++){		// initialize the array with a
        *(dynamicArray++) = MaxSize - i; // descending sequence of values
        //dynamicArray+=i;
    }
    dynamicEnd = dynamicArray;
    printf(">>> After dynamic creation\n");

    //start time for sorting dynamic array
    clock_t d_begin = clock();
    //bubble sort the dynamic array
    //dynamicArray = dynamicArray + i;
    //

    printf("start =%d\n", *(dynamicStart));
    printf("end =%d\n", *(dynamicArray));
    printf("%d\n", *(dynamicArray));
    printf("-1 %d\n", *(dynamicArray-1));
    for(i=0; i < MaxSize-1; i++) {
        while(dynamicArray > dynamicStart) {
            //printf("[%d, %d]\n", *(dynamicArray -1), *(dynamicArray));
            if(*(dynamicArray -1)  > *(dynamicArray) ) {
                temp = *(dynamicArray -1);
                *(dynamicArray -1) = *(dynamicArray);
                *(dynamicArray) = temp;
            }
            dynamicArray--;
        }
        printf("pre %d\n", *(dynamicArray));
        printf("pre start %d\n", *(dynamicArray));
        dynamicStart = dynamicArray +1;
        dynamicArray = dynamicEnd;
        printf("post %d\n", *(dynamicArray));
        printf("post start %d\n", *(dynamicArray));
        printf("post end %d\n", *(dynamicEnd));
    }
    printf("new %d\n", *(dynamicArray));
    printf("new +1 %d\n", *(dynamicArray+1));
    /*
    for(i=0; i < MaxSize-1; i++) {
        //for(dynamicArray=MaxSize-1;dynamicArray>i; dynamicArray--) {
        if(*(dynamicArray -1) > *(dynamicArray) ) {
            temp = *(dynamicArray -1);
            *(dynamicArray -1) = *(dynamicArray);
            *(dynamicArray) = temp;
        }
        //}
        
         Previous version of dynamic bubble sort -> it was slow! 
        for(j=MaxSize-1; j>i; j--) {
            if(*(dynamicArray+(j-1)) > *(dynamicArray+j)) {
                temp = *(dynamicArray+(j-1));
                *(dynamicArray+(j-1)) = *(dynamicArray+j);
                *(dynamicArray+j) = temp;
            }
        }
        }
        */
    //end time for sorting dynamic array
    clock_t d_end = clock();
    clock_t d_total_end = clock();

    int index = 0;
    while(index < 100) {
        //printf("%d = %d\n", index, *(dynamicArray++));
    }

    //remember to free the dynamic array
    free(dynamicArray);


	// Display the amount of time used for each part above
    printf("Static: Sorting Time used: %lf%s\n", 
            (double)(s_end - s_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Dynamic: Sorting Time used: %lf%s\n", 
            (double)(d_end - d_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Static: Total Time used: %lf%s\n", 
            (double)(s_total_end - s_total_begin) / CLOCKS_PER_SEC, ", Seconds");
    printf("Dynamic: Total Time used: %lf%s\n", 
            (double)(d_total_end - d_total_begin) / CLOCKS_PER_SEC, ", Seconds");

	return 0;
}
