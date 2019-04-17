//
//  Menu.h
//  12306
//
//  Created by GOD on 2018/7/2.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef Menu_h
#define Menu_h
void showMenu(){
    //读取文件建立时刻表
    TimeList train,plane;
    CityList c;
    initByReadFile(&c, &train, &plane);
    int i,j;
    int x=1;
    while (x=1) {
        printf("\t\t********************************\n");
        printf("\t\t*     欢迎使用全国交通查询系统      *\n");
        printf("\t\t********************************\n");
        
        
        printf("现有城市:\n");
        showCity(&c);
        printf("\n\n");
        printf("可选择功能:\n\t\t 1:编辑城市交通图\n\t\t 2:修改火车时刻表\n\t\t 3:修改飞机时刻表\n\t\t 4:选择最佳路径");
        printf("\n请选择：");
        scanf("%d",&i);
        while (i!=1&&i!=2&&i!=3&&i!=4) {
            printf("输入有误，请重新输入：\n");
            scanf("%d",&i);
        }//避免按错而导致的错误
        switch (i) {
            case 1:{//编辑城市交通图
                
                printf("现有城市：\n");
                showCity(&c);
                printf("\n\n");
                printf("可选择功能：\n\t\t1:添加 2:删除\n");
                printf("请选择：");
                scanf("%d",&j);
                while (j!=1&&j!=2) {
                    printf("输入有误，请重新选择：\n");
                    scanf("%d",&j);
                }//避免按错而导致的错误
                printf("\n");
                if (j==1) {
                    printf("请输入增加的城市名称:\n");
                    char n[30];
                    scanf("%s",n);
                    addCityInCityList(packageToCity(n), &c, &train, &plane);
                    showCity(&c);
                    printf("增加成功\n");
                }
                if (j==2) {
                    printf("请输入删除的城市名称:\n");
                    char n[30];
                    scanf("%s",n);
                    deleteCityInCityList(packageToCity(n), &train, &c);
                    deleteCityInCityList(packageToCity(n), &plane, &c);
                    printf("删除成功\n");
                }
            }break;
            case 2:{
                //修改火车时间表
                printf("现有火车时刻表：\n");
                printf("\t\t起点 终点 车次 费用 出发时间 到达时间");
                showAllWay(&train);
                printf("\n\n");
                printf("可更改功能：\n\t\t1.添加\t 2.删除\n");
                printf("请选择：");
                scanf("%d",&j);
                while (j!=1&&j!=2) {
                    printf("输入有误，请重新选择：\n");
                    scanf("%d",&j);
                }//避免按错而导致的错误
                printf("\n");
                if (j==1) {
                    int start,end;
                    char wayName[10],starttime[10],endtime[10];
                    double cost;
                    printf("现有城市：\n");
                    showCity(&c);
                    printf("\n");
                    printf("请输入出发城市编号：");
                    scanf("%d",&start);
                    printf("请输入目的城市编号：");
                    scanf("%d",&end);
                    printf("请输入增加车次名称：");
                    scanf("%s",wayName);
                    printf("请输入价格：");
                    scanf("%lf",&cost);
                    printf("请输入出发时间：");
                    scanf("%s",starttime);
                    printf("请输入到达时间：");
                    scanf("%s",endtime);
                    //调用增加火车信息函数
                    addInformationInTimeList(packageToInformation(start, end, wayName, cost, starttime, endtime), &train);
                    //输出最新的列车时刻表
                    showAllWay(&train);
                }else if (j==2){
                    int start,end;
                    char wayName[10],starttime[10],endtime[10];
                    double cost;
                    printf("现有城市：\n");
                    showCity(&c);
                    printf("\n");
                    printf("请输入出发城市编号：");
                    scanf("%d",&start);
                    printf("请输入目的城市编号：");
                    scanf("%d",&end);
                    printf("请输入增加车次名称：");
                    scanf("%s",wayName);
                    printf("请输入价格：");
                    scanf("%lf",&cost);
                    printf("请输入出发时间：");
                    scanf("%s",starttime);
                    printf("请输入到达时间：");
                    scanf("%s",endtime);
                    //调用删除火车信息的函数
                    deleteInformation(packageToInformation(start, end, wayName, cost, starttime, endtime), &train);
                    //输出最新的列车时刻表
                    showAllWay(&train);
                }
            }break;
            case 3:{
                //修改飞机航班时刻表
                printf("现有飞机航班表：\n");
                printf("\t\t    起点 终点 车次 费用 出发时间 到达时间\n");
                showAllWay(&plane);
                printf("\n\n");
                printf("可更改功能:\n\t\t1.添加\t 2.删除\n");
                printf("请选择：");
                scanf("%d",&j);
                while (j!=1&&j!=2) {
                    printf("输入有误，请重新选择：\n");
                    scanf("%d",&j);
                }//避免按错而导致的错误
                printf("\n");
                if (j==1) {
                    int start,end;
                    char wayName[10],starttime[10],endtime[10];
                    double cost;
                    printf("现有城市：\n");
                    showCity(&c);
                    printf("\n");
                    printf("请输入出发城市编号：");
                    scanf("%d",&start);
                    printf("请输入目的城市编号：");
                    scanf("%d",&end);
                    printf("请输入增加车次名称：");
                    scanf("%s",wayName);
                    printf("请输入价格：");
                    scanf("%lf",&cost);
                    printf("请输入出发时间：");
                    scanf("%s",starttime);
                    printf("请输入到达时间：");
                    scanf("%s",endtime);
                    //调用增加飞机信息函数
                    addInformationInTimeList(packageToInformation(start, end, wayName, cost, starttime, endtime), &plane);
                    //输出最新的飞机航班表
                    showAllWay(&plane);
                }else if (j==2){
                    int start,end;
                    char wayName[10],starttime[10],endtime[10];
                    double cost;
                    printf("现有城市：\n");
                    showCity(&c);
                    printf("\n");
                    printf("请输入出发城市编号：");
                    scanf("%d",&start);
                    printf("请输入目的城市编号：");
                    scanf("%d",&end);
                    printf("请输入增加车次名称：");
                    scanf("%s",wayName);
                    printf("请输入价格：");
                    scanf("%lf",&cost);
                    printf("请输入出发时间：");
                    scanf("%s",starttime);
                    printf("请输入到达时间：");
                    scanf("%s",endtime);
                    //调用删除飞机信息的函数
                    deleteInformation(packageToInformation(start, end, wayName, cost, starttime, endtime), &plane);
                    //输出最新的飞机航班表
                    showAllWay(&plane);
                }break;
            case 4:{
                int k,start,end,isTransfer;
                printf("可选择交通工具：\n\t\t1.火车\t2.飞机\n");
                printf("请选择：");
                scanf("%d",&j);
                while(j!=1&&j!=2){
                    printf("输入有误，请重新输入:\n");
                    scanf("%d",&j);
                }
                printf("请选择最佳选择方案：\n\t\t1.时间最少 2.花费最少\n");
                printf("请选择：");
                scanf("%d",&k);
                while(k!=1&&k!=2){
                    printf("输入有误，请重新输入：");
                    scanf("%d",&k);
                }
                printf("现有城市：\n");
                showCity(&c);
                printf("请输入出发地编号：");
                scanf("%d",&start);
                printf("请输入目的地编号：");
                scanf("%d",&end);
                printf("是否换乘：\n\t\t1.换乘 2.都行\n");
                scanf("%d",&isTransfer);
                //调用函数求得最优路径
                findBestWay(start, end, k==1?false:true, isTransfer==1?true:false, i==1?&train:&plane);
            }
            }break;
        }
        printf("返回主菜单请输入任意数字返回主菜单！\n");
        printf("请输入：\n");
        scanf("%d",&x);
    }
}
#endif /* Menu_h */
