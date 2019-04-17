//
//  main.c
//  12306
//
//  Created by GOD on 2018/6/25.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Traffic.h"
#include "Menu.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //showMenu();
    
    TimeList train,plane;
    CityList c;
    initByReadFile(&c, &train, &plane);
    //添加城市
    showCity(&c);
    addCityInCityList(packageToCity("老河口"), &c, &train, &plane);
    showCity(&c);

    //删除城市
    showCity(&c);
    deleteCityInCityList(packageToCity("老河口"), &train, &c);
    showCity(&c);

    //增加车次
    addInformationInTimeList(packageToInformation(6, 1, "D28", 125, "05:12", "13:31"), &train);
    showAllWay(&train);

    //删除车次
    deleteInformation(packageToInformation(6, 1, "D28", 125, "05:12", "13:31"), &train);
    showAllWay(&train);

    //起点0号城市，终点6号城市，换乘，花费金钱最小求最优路径，输出乘坐的车次
    findBestWay(0, 6, true, true, &train);

    return 0;
}
