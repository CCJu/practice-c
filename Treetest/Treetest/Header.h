//
//  Header.h
//  Treetest
//
//  Created by GOD on 2018/5/23.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef Header_h
#define Header_h

void print(char *c){
    ind++;
    printf("%d",ind);
    if(*c!='#') print(++c);
    printf("%d",ind);
}


#endif /* Header_h */
