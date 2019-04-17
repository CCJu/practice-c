//
//  main.c
//  test
//
//  Created by GOD on 2018/6/29.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include "basic operation.h"
#include "cummuting.h"

int main(){
    FILE *fp;
    G.vexnum=0;
    paths.i=0;
    fp=fopen("G:\\ ˝æ›Ω·ππøŒ≥Ã…Ëº∆°™°™XXXXX\\transportation.txt","rb");
    CreateGraph(&G,fp);  //¥¥Ω®Õº
    Initialize();  // ‘À––≤Ÿ◊˜
}
