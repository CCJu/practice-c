//
//  main.c
//  SeqList
//
//  Created by GOD on 2018/4/18.
//  Copyright © 2018年 GOD. All rights reserved.
//
#define MaxSize 10
typedef int DataType;
#include "SeqList.h"
#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    Seq p;
    int i;
    for(i=0;i<10;i++){
        p.d[i]=i;
    }
    p.size=10;
    Move(&p);
    show(p);
    return 0;
}
