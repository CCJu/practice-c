//
//  main.c
//  Arraysort
//
//  Created by GOD on 2018/6/13.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "Sort.h"
int main(int argc, const char * argv[]) {
    // insert code here...
//    int num[6]={64,5,7,89,6,24};
//    int *array=num;
    int num[100000];
    int *array=num;
    init(&array);
    //directInsertionSort(array);
    //hillSort(array);
    //directSelectionSort(array);
    
    //heapSort(array);
    
    //bubbleSort(array);
    quicklySort(array, 0, 99999);
    
    //binaryMergeSort1(array);
    //radixSort(array);
    //show(array);
    return 0;
}
