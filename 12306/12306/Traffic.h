//
//  Traffic.h
//  12306
//
//  Created by GOD on 2018/6/26.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef Traffic_h
#define Traffic_h
//城市信息节点
typedef struct {
    char name[30];//城市名称
    int num;//城市序号
}City;
//城市信息表
typedef struct {
    City c[10];//保存城市信息
    bool b[10];//b[i]的城市是否被删除，true表示城市存在可用，false不可用
    int size;//城市信息表中保存的城市数目
}CityList;
typedef struct {
    //发车时间，到达时间，列车或飞机的名称
    char starttime[10],endtime[10],wayName[10];
    double moneycost;//金钱花费
    int timecost;//时间花费
    bool b;//该趟车次是否可用，true表示可以使用，false表示不能使用
}Time;
//车次节点
typedef struct {
    //起点城市序号，终点城市序号
    int startPlaceNum,endPlaceNum;
    Time t[10];//保存起点为startPlaceNum，终点为endPlaceNum的所有车次信息
    int trafficNum;//列车或飞机的趟数
    struct Information *next;//指向下一个节点
    bool b;//仅在求最优路径的时候使用
}Information;

//时刻表
typedef struct {
    Information *i[10];//i[t]存储着以城市c[t]为起点的，到各个城市的车次信息
    bool b[10];//b[i]存放i城市是否删除
}TimeList;

//辅助空间栈
typedef struct{
    int num[10];
    int top;
    bool b;
}Stack;
//读取存储城市信息的文件，将信息封装为城市信息表返回
CityList readFileToCityList(char *filePath){
    CityList cl;
    cl.size=0;
    int i=0;
    char data[50];
    FILE *fp=fopen(filePath,"r");//打开文件读取流
    //一直读到文件结束
    while(!feof(fp))
    {
        char *num;
        fscanf(fp,"%s",&data);//读取一个字符串到data数组中去
        num=data;
        if(i%2==0){
            if(num[0]-'0'<0) break;
            cl.c[i/2].num=num[0]-'0';
            cl.size++;
        }else
            memcpy(cl.c[i/2].name, num, strlen(num)+1);//将num指向的内容赋给所在位置为cl.c[i/2]的name数组（即把读取出来的城市名称保存在内存中）
        cl.b[i/2]=true;
        i++;
    }
    fclose(fp);
    return cl;
}

//判断时刻表中某行是否为空
bool timeListPointLineIsNull(int pointLine,TimeList *tl){
    if(tl->i[pointLine]==NULL)
        return true;
    else
        return false;
}

//判断时刻表中某行是否有起点为start 终点为end的记录，若有返回该记录在该行的序号，无则返回-1
int timeListHaveRecord(int pointLine,int end,TimeList *tl){
    Information *i=tl->i[pointLine];
    int j=0;
    while(i!=NULL){
        if(i->endPlaceNum==end) return j;
        i=i->next;
        j++;
    }
    return -1;
}
//根据出发时间和到站时间求出旅程花费的时间
int getJourneyTime(char *starttime,char *endtime){
    int starthour=(*starttime-'0')*10+*(starttime+1)-'0';
    int startminute=(*(starttime+3)-'0')*10+*(starttime+4)-'0';
    int endhour=(*endtime-'0')*10+*(endtime+1)-'0';
    int endminute=(*(endtime+3)-'0')*10+*(endtime+4)-'0';
    int result=0;
    if(endhour<starthour||(endhour==starthour&&startminute>endminute))
        result=endhour*60+endminute+(23-starthour)*60+60-startminute;
    else
        result=(endhour-starthour)*60+endminute-startminute;
    return result;
}

//时刻表初始化
void timeListInit(TimeList *t){
    int i=0;
    for(;i<10;i++)
        t->i[i]=NULL;
}

//读取存储车次信息的文件，将信息封装为火车，飞机时刻表返回
TimeList readFileToTimeList(char *filePath){
    TimeList t;
    timeListInit(&t);
    int i=0;
    char buf[100];  /*缓冲区*/
    FILE *fp;            /*文件指针*/
    fp = fopen(filePath,"r");
    while(fgets(buf,100,fp) != NULL)/*整行读文件直到文件结束*/
    {
        strlen(buf);
        //按空格截取字符串
        char delims[] = " ";
        char *result = NULL;
        result = strtok( buf, delims );
        char *c[6];
        int j=0;
        while( result != NULL ) {
            c[j]=&(*result);
            j++;
            result = strtok( NULL, delims);
        }
        int startNum=c[0][0]-'0';
        //时刻表中第startNum行为空
        if(timeListPointLineIsNull(startNum, &t)){
            //为第startNum行添加新的信息
            Information *infor=(Information *)malloc(sizeof(Information));
            infor->trafficNum=0;
            infor->startPlaceNum=startNum;
            infor->endPlaceNum=c[1][0]-'0';
            strcpy(infor->t[infor->trafficNum].wayName,c[2]);
            infor->t[infor->trafficNum].moneycost=strtod (c[3], NULL);
            strcpy(infor->t[infor->trafficNum].starttime,c[4]);
            strcpy(infor->t[infor->trafficNum].endtime,c[5]);
            infor->t[infor->trafficNum].timecost=getJourneyTime(c[4],c[5]);
            infor->t[infor->trafficNum].b=true;
            infor->next=NULL;
            infor->trafficNum++;
            t.i[startNum]=infor;
        }else{//时刻表中第startNum行不为空
            int endNum=c[1][0]-'0';
            int result=timeListHaveRecord(startNum, endNum, &t);
            //无起点为startNum 终点为endNum的记录
            if(result==-1){
                Information *infor=(Information *)malloc(sizeof(Information));
                infor->trafficNum=0;
                infor->startPlaceNum=startNum;
                infor->endPlaceNum=c[1][0]-'0';
                strcpy(infor->t[infor->trafficNum].wayName,c[2]);
                infor->t[infor->trafficNum].moneycost=strtod (c[3], NULL);
                strcpy(infor->t[infor->trafficNum].starttime,c[4]);
                strcpy(infor->t[infor->trafficNum].endtime,c[5]);
                infor->t[infor->trafficNum].timecost=getJourneyTime(c[4],c[5]);
                infor->t[infor->trafficNum].b=true;
                infor->next=NULL;
                Information *tt=t.i[startNum];
                infor->trafficNum++;
                while(tt->next!=NULL)
                    tt=tt->next;
                tt->next=infor;
            }else{
                int j=0;
                Information *info=t.i[startNum];
                while(j!=result){
                    info=info->next;
                    j++;
                }
                strcpy(info->t[info->trafficNum].wayName, c[2]);
                info->t[info->trafficNum].moneycost=strtod (c[3], NULL);
                strcpy(info->t[info->trafficNum].starttime,c[4]);
                strcpy(info->t[info->trafficNum].endtime,c[5]);
                info->t[info->trafficNum].timecost=getJourneyTime(c[4],c[5]);
                info->t[info->trafficNum].b=true;
                info->trafficNum++;
            }
        }
        i++;
    }
    fclose(fp);
    return t;
}

//通过读取文件来初始化城市信息表和列车，飞机时刻表
void initByReadFile(CityList *c,TimeList *train,TimeList *plane){
    *c=readFileToCityList("/Users/mac1/Downloads/station.txt");
    *train=readFileToTimeList("/Users/mac1/Downloads/railwaylist.txt");
    *plane=readFileToTimeList("/Users/mac1/Downloads/airplanelist.txt");
}

//更新时刻表中的城市数目
void updateCityNum(TimeList *t,int num){
    t->b[num]=true;
}

//添加新的城市信息
void addCityInCityList(City c,CityList *cl,TimeList *t1,TimeList *t2){
    //增加新城市在城市信息表中
    strcpy(cl->c[cl->size].name,c.name);
    cl->c[cl->size].num=cl->size;
    cl->b[cl->size]=true;
    cl->size++;
    //更新火车时刻表
    updateCityNum(t1,cl->size-1);
    //更新飞机时刻表
    updateCityNum(t2,cl->size-1);
}

//删除时刻表中和城市c相关的记录，并不是直接删除此条记录，而是将该记录的标志位设置为false，来表示删除
void deleteInformationInTimeList(TimeList *t,City c){
    t->b[c.num]=false;
    int i=0;
    for(;i<10;i++)
        if(t->b[i]!=false){
            Information *ii=t->i[i];
            while(ii!=NULL){
                int j=0;
                for(;j<ii->trafficNum;j++)
                    if(ii->endPlaceNum==c.num)
                        ii->t[j].b=false;
                ii=ii->next;
            }
            
        }
    
}
//删除城市信息
void deleteCityInCityList(City c,TimeList *t,CityList *cc){
    //在城市信息表中删除城市c
    int i=0;
    for(;i<10;i++)
        if(strcmp(cc->c[i].name,c.name)==0) break;
    cc->b[i]=false;
    //在火车时刻表中删除和城市c相关的记录
    deleteInformationInTimeList(t, c);
    //在飞机时刻表中删除和城市c相关的记录
    deleteInformationInTimeList(t, c);
}

//将输入的信息封装为Information结构体
Information packageToInformation(int start,int end,char *name,double cost,char *starttime,char *endtime){
    Information i;
    i.startPlaceNum=start;
    i.endPlaceNum=end;
    strcpy(i.t[0].starttime,starttime);
    strcpy(i.t[0].endtime,endtime);
    i.t[0].moneycost=cost;
    strcpy(i.t[0].wayName,name);
    i.t[0].timecost=getJourneyTime(starttime, endtime);
    return i;
}

//将输入的信息封装为City结构体
City packageToCity(char *name){
    City c;
    strcpy(c.name,name);
    return c;
}


//增加时刻表的记录
void addInformationInTimeList(Information i,TimeList *t){
    int startCity=i.startPlaceNum,endCity=i.endPlaceNum;
    //当新增记录的起点，终点大于范围时，或者起点终点不存在的情况下直接返回主调并且给出提示信息
    if(startCity>=10||t->b[startCity]==false||endCity>=10||t->b[endCity]==false){ printf("增加失败");return;}
    else {
        Information *ii=t->i[startCity];
        if(t->b[startCity]==false) t->b[startCity]=true;
        bool b=false;//标志找未找到与新增记录起点终点相同的数据
        while(ii->next!=NULL){
            if(ii->endPlaceNum==endCity){b=true;break;}
            ii=ii->next;
        }
        if(ii->endPlaceNum==endCity) b=true;
        if(b==false){
            //在时刻表第i.startPlaceNum行插入新的记录
            Information *infor=(Information *)malloc(sizeof(Information));
            infor->trafficNum=0;
            infor->startPlaceNum=i.startPlaceNum;
            infor->endPlaceNum=i.endPlaceNum;
            strcpy(infor->t[infor->trafficNum].wayName,i.t[0].wayName);
            infor->t[infor->trafficNum].moneycost=i.t[0].moneycost;
            strcpy(infor->t[infor->trafficNum].starttime,i.t[0].starttime);
            strcpy(infor->t[infor->trafficNum].endtime,i.t[0].endtime);
            infor->t[infor->trafficNum].timecost=i.t[0].timecost;
            infor->t[infor->trafficNum].b=true;
            infor->next=NULL;
            infor->trafficNum++;
            ii->next=infor;
        }else{
            //比较其他的信息是否相同
            int j=0;
            bool b=false;
            for(;j<ii->trafficNum;j++){
                if(strcmp(ii->t[j].starttime,i.t[0].starttime)==0&&strcmp(ii->t[j].endtime, i.t[0].endtime)==0){
                    b=true;
                    break;
                }
            }
            if(b) ii->t[j].b=true;
            else{
                //将新纪录写入
                ii->t[ii->trafficNum].b=true;
                strcpy(ii->t[ii->trafficNum].starttime,i.t[0].starttime);
                strcpy(ii->t[ii->trafficNum].endtime,i.t[0].endtime);
                strcpy(ii->t[ii->trafficNum].wayName,i.t[0].wayName);
                ii->t[ii->trafficNum].timecost=i.t[0].timecost;
                ii->t[ii->trafficNum].moneycost=i.t[0].moneycost;
                ii->trafficNum++;
            }
        }
    }
}

//删除时刻表的记录
void deleteInformation(Information i,TimeList *t){
    int startCity=i.startPlaceNum,endCity=i.endPlaceNum;
    if(t->b[startCity]==false) return;
    else{
        Information *ii=t->i[startCity];
        while(ii!=NULL){
            if(ii->endPlaceNum==endCity){
                int j=0;
                for(;j<ii->trafficNum;j++){
                    if(strcmp(ii->t[j].starttime,i.t[0].starttime)==0&&strcmp(ii->t[j].endtime, i.t[0].endtime)==0&&strcmp(ii->t[j].wayName,i.t[0].wayName)==0){
                        ii->t[j].b=false;
                        return;
                    }
                }
                printf("删除失败\n");
                return ;
            }
            ii=ii->next;
        }
    }
}

//在时刻表中根据起点，终点找出最低的价格或者最快的时间，返回具体的数值
double bestWeight(int start,int end,TimeList *t,bool costFirst){
    double result=0;
    Information *ii=t->i[start];
    while(ii!=NULL){
        if(ii->endPlaceNum==end){
            if(costFirst){
                int j=0;
                result=ii->t[0].moneycost;
                for(;j<ii->trafficNum;j++){
                    if(ii->t[j].moneycost<result)
                        result=ii->t[j].moneycost;
                }
                break;
            }else{
                int j=0;
                result=ii->t[0].timecost;
                for(;j<ii->trafficNum;j++){
                    if(ii->t[j].timecost<result)
                        result=ii->t[j].timecost;
                }
                break;
            }
        }else
            ii=ii->next;
    }
    return result;
}

//在时刻表中根据起点，终点找出最低的价格或者最快的时间，返回最优车次的车次名
void getBestWeightName(int start,int end,TimeList *t,bool costFirst){
    int min=0;
    Information *ii=t->i[start];
    while(ii!=NULL){
        if(ii->endPlaceNum==end){
            if(costFirst){
                int j=0;
                for(;j<ii->trafficNum;j++){
                    if(ii->t[j].moneycost<ii->t[min].moneycost)
                        min=j;
                }
                printf(" %s ",ii->t[min].wayName);
                break;
            }else{
                int j=0;
                for(;j<ii->trafficNum;j++){
                    if(ii->t[j].timecost<ii->t[min].timecost)
                        min=j;
                }
                printf(" %s ",ii->t[min].wayName);
                break;
            }
        }else
            ii=ii->next;
    }
}

//比较路径s1,s2哪个更便宜或更快，放回true时s1比s2更好，反之亦然
bool whichCheaper(Stack *s1,Stack *s2,TimeList *t,double *cost,bool costFirst){
    if(costFirst){
        double s1cost = 0.0;
        double s2cost = 0.0;
        int i=1;
        for(;i<s1->top;i++)
            s1cost+=bestWeight(s1->num[i-1], s1->num[i], t,true);
        for(i=1;i<s2->top;i++)
            s2cost+=bestWeight(s2->num[i-1], s2->num[i], t,true);
        if(s1cost<s2cost){
            *cost=s1cost;
            for(i=0;i<s1->top;i++)
                s2->num[i]=s1->num[i];
            s2->top=s1->top;
            return true;
        }
        else{
            *cost=s2cost;
            return false;
        }
    }else{
        double s1cost = 0.0;
        double s2cost = 0.0;
        int i=1;
        for(;i<s1->top;i++)
            s1cost+=bestWeight(s1->num[i-1], s1->num[i], t,false);
        for(i=1;i<s2->top;i++)
            s2cost+=bestWeight(s2->num[i-1], s2->num[i], t,false);
        if(s1cost<s2cost){
            *cost=s1cost;
            for(i=0;i<s1->top;i++)
                s2->num[i]=s1->num[i];
            s2->top=s1->top;
            return true;
        }
        else{
            *cost=s2cost;
            return false;
        }
    }
}

//输出最优的路径s
void showBestWay(Stack s,TimeList *t){
    int i=1;
    for(;i<s.top;i++)
        getBestWeightName(s.num[i-1], s.num[i], t,true);
}
//根据给定的起点和终点，按照花费最少或者时间最少给出最优方案
void findBestWay(int startPlace,int endPlace,bool costFirst,bool isTransfer,TimeList *t){
    if(costFirst){
        //花费最少优先
        if(isTransfer){//换乘
            Information *information=t->i[startPlace];
            while (information!=NULL) {
                information->b=false;
                information=information->next;
            }
            double minCost=0;
            //初始化辅助空间
            Stack s,temporary;
            s.top=0;temporary.top=0;temporary.b=false;
            bool b[10];
            int jj=0,ttt=startPlace;
            for(;jj<10;jj++){
                b[jj]=false;
            }
            //将startPlace入栈
            s.num[s.top]=startPlace;
            s.top++;
            b[startPlace]=true;
            while (s.top!=0) {
                Information *ii=t->i[startPlace];
                //找第startPlace行，第一个未标记使用的节点
                if(ttt!=startPlace){
                    while(ii!=NULL){
                        if(b[ii->endPlaceNum]!=true)
                            break;
                        ii=ii->next;
                    }
                }else{
                    while(ii!=NULL){
                        if(b[ii->endPlaceNum]!=true&&ii->b!=true)
                            break;
                        ii=ii->next;
                    }
                    if(ii!=NULL) ii->b=true;
                }
                //若改行全部节点都被使用，回溯，栈顶元出栈
                if(ii==NULL){
                    s.top--;
                    startPlace=s.num[s.top-1];
                    continue;
                }else{
                    //第一个未标记使用的节点入栈
                    s.num[s.top]=ii->endPlaceNum;
                    s.top++;
                    b[ii->endPlaceNum]=true;
                    int tt=0;
                    for(;tt<10;tt++)
                        b[tt]=false;
                    for(tt=0;tt<s.top;tt++)
                        b[s.num[tt]]=true;
                    //该节点恰好为终点,将最便宜的路径存入temporary，更新minCost，向前回溯
                    if(ii->endPlaceNum==endPlace){
                        if(temporary.b==true)
                            whichCheaper(&s, &temporary, t, &minCost,true);
                        else{
                            int i=0;
                            for(;i<s.top;i++)
                                temporary.num[i]=s.num[i];
                            temporary.b=true;
                            temporary.top=s.top;
                            for(jj=1;jj<temporary.top;jj++)
                                minCost+=bestWeight(temporary.num[jj-1], temporary.num[jj], t,true);
                        }
                        s.top-=2;
                        startPlace=s.num[s.top-1];
                        continue;
                    }else{
                        //继续在endPlaceNum向下寻找未被使用的节点
                        startPlace=ii->endPlaceNum;
                        continue;
                    }
                }
            }
            showBestWay(temporary, t);
            printf("%.4lf",minCost);
        }else{//不换乘
            if(t->b[startPlace]!=false){
                bool b=false;//标识找未找到最优的路径
                Information *ii=t->i[startPlace];
                //筛选出startPlace-endPlace的所有路径
                while(ii!=NULL){
                    if(ii->endPlaceNum==endPlace)break;
                    ii=ii->next;
                }
                //从所有路径中选出花费最少的
                int j=0,min=0;
                for(;j<ii->trafficNum;j++)
                    if(ii->t[j].b==true)
                        if(ii->t[j].moneycost<=ii->t[min].moneycost){
                            min=j;
                            b=true;
                            break;
                        }
                if(b){
                    printf("%d %d ",ii->startPlaceNum,ii->endPlaceNum);
                    printf("%s %s %.4lf %s\n",ii->t[min].wayName,ii->t[min].starttime,ii->t[min].moneycost,ii->t[min].endtime);
                }
            }
        }
    }else{
        //时间最少优先
        if(isTransfer){//换乘
            Information *information=t->i[startPlace];
            while (information!=NULL) {
                information->b=false;
                information=information->next;
            }
            double minCost=0;
            //初始化辅助空间
            Stack s,temporary;
            s.top=0;temporary.top=0;temporary.b=false;
            bool b[10];
            int jj=0,ttt=startPlace;
            for(;jj<10;jj++){
                b[jj]=false;
            }
            //将startPlace入栈
            s.num[s.top]=startPlace;
            s.top++;
            b[startPlace]=true;
            while (s.top!=0) {
                Information *ii=t->i[startPlace];
                //找第startPlace行，第一个未标记使用的节点
                if(ttt!=startPlace){
                    while(ii!=NULL){
                        if(b[ii->endPlaceNum]!=true)
                            break;
                        ii=ii->next;
                    }
                }else{
                    while(ii!=NULL){
                        if(b[ii->endPlaceNum]!=true&&ii->b!=true)
                            break;
                        ii=ii->next;
                    }
                    if(ii!=NULL) ii->b=true;
                }
                //若改行全部节点都被使用，回溯，栈顶元出栈
                if(ii==NULL){
                    s.top--;
                    startPlace=s.num[s.top-1];
                    continue;
                }else{
                    //第一个未标记使用的节点入栈
                    s.num[s.top]=ii->endPlaceNum;
                    s.top++;
                    b[ii->endPlaceNum]=true;
                    int tt=0;
                    for(;tt<10;tt++)
                        b[tt]=false;
                    for(tt=0;tt<s.top;tt++)
                        b[s.num[tt]]=true;
                    //该节点恰好为终点,将最便宜的路径存入temporary，更新minCost，向前回溯
                    if(ii->endPlaceNum==endPlace){
                        if(temporary.b==true)
                            whichCheaper(&s, &temporary, t, &minCost,false);
                        else{
                            int i=0;
                            for(;i<s.top;i++)
                                temporary.num[i]=s.num[i];
                            temporary.b=true;
                            temporary.top=s.top;
                            for(jj=1;jj<temporary.top;jj++)
                                minCost+=bestWeight(temporary.num[jj-1], temporary.num[jj], t,false);
                        }
                        s.top-=2;
                        startPlace=s.num[s.top-1];
                        continue;
                    }else{
                        //继续在endPlaceNum向下寻找未被使用的节点
                        startPlace=ii->endPlaceNum;
                        continue;
                    }
                }
            }
            showBestWay(temporary, t);
            printf("%.4lf",minCost);
        }else{//不换乘
            if(t->b[startPlace]!=false){
                bool b=false;//标识找未找到最优的路径
                Information *ii=t->i[startPlace];
                //筛选出startPlace-endPlace的所有路径
                while(ii!=NULL){
                    if(ii->endPlaceNum==endPlace)break;
                    ii=ii->next;
                }
                //从所有路径中选出时间最少的
                int j=0,min=0;
                for(;j<ii->trafficNum;j++)
                    if(ii->t[j].b==true)
                        if(ii->t[j].timecost<=ii->t[min].timecost){
                            min=j;
                            b=true;
                            break;
                        }
                if(b){
                    printf("%d %d ",ii->startPlaceNum,ii->endPlaceNum);
                    printf("%s %s %.4lf %s\n",ii->t[min].wayName,ii->t[min].starttime,ii->t[min].moneycost,ii->t[min].endtime);
                }
            }
        }
    }
}


//显示时刻表中所有的车次
void showAllWay(TimeList *t){
    int i=0;
    for(;i<10;i++){
        if(t->b[i]!=false){
            Information *ii=t->i[i];
            while(ii!=NULL){
                int j=0;
                for(;j<ii->trafficNum;j++){
                    if(ii->t[j].b!=false){
                        printf("%d %d ",ii->startPlaceNum,ii->endPlaceNum);
                        printf("%s %s %.4lf %s \n",ii->t[j].wayName,ii->t[j].starttime,ii->t[j].moneycost,ii->t[j].endtime);
                    }
                }
                ii=ii->next;
            }
        }
    }
}

//显示所有的城市信息
void showCity(CityList *c){
    int size=c->size;
    int i=0;
    for(;i<size;i++)
        if(c->b[i]==true)
            printf("%d %s\n",c->c[i].num,c->c[i].name);
}
#endif /* Traffic_h */
