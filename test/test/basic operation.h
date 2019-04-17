//
//  basic operation.h
//  test
//
//  Created by GOD on 2018/6/29.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef basic_operation_h
#define basic_operation_h
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define MAX_VERTEX_NUM 30
#define MAX_TURN_NUM  30
#define MAX_WAYS 20
#define MAX_PATHS 100
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;

typedef char ti[6];// ±º‰

typedef struct turn{
    ti departure;//∑¢≥µ ±º‰
    ti terminal;//µΩ¥Ô ±º‰
    int interval;//¬√≥ÃÀ˘–Ë ±º‰
    double  fee;//∑—”√
}turn;//“ªÃÀΩªÕ®π§æﬂµƒ»´≤ø–≈œ¢

typedef char cityname[15];

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    turn *t;//∂ØÃ¨∑÷≈‰µƒ“ªŒ¨ ˝◊È£¨¥Û–°Œ™25£¨µ⁄“ª∏ˆŒª÷√≤ª”√
    int i;//≥µ¥Œ◊‹ ˝
}ArcNode; //ª°Ω⁄µ„

typedef struct VNode{
    cityname city;
    ArcNode *firstarc[2];//÷∏’Î ˝◊È£¨µ⁄“ª∏ˆ÷∏œÚ∑…ª˙–≈œ¢£¨µ⁄∂˛∏ˆ÷∏œÚª≥µ–≈œ¢
}VNode,AdjList[MAX_VERTEX_NUM];//∂•µ„Ω⁄µ„

typedef struct ALGraph{
    AdjList vertices;
    int vexnum;//∂•µ„ ˝
}ALGraph;

typedef struct  temp{
    cityname de;
    cityname te;
    turn t;
    char tr[6];//¥Ê∑≈ΩªÕ®π§æﬂ
}temp;//temp «∂¡»° ˝æ› π”√µƒ

typedef struct {
    int path[MAX_VERTEX_NUM];   // ”√¿¥¥Ê¥¢¬∑œﬂ
    int length;//¬∑œﬂµƒΩ⁄µ„ ˝
}Path;

typedef int Mark[MAX_VERTEX_NUM]; //±Íº«

typedef struct Paths{
    Path paths[MAX_WAYS];
    int   i;//“—”–¬∑œﬂ ˝
}Paths;//¬∑œﬂ ˝◊È

typedef struct {
    temp arcs[MAX_VERTEX_NUM];
    int i;//¬∑æ∂∞¸∫¨µƒ µº Ω⁄µ„ ˝
    int sum;//¬∑æ∂◊‹π≤ª®∑—µƒ ±º‰
}Travel;//¬∑æ∂

typedef struct {
    Travel tra[MAX_PATHS];
    int i;//“—”–¬∑æ∂ ˝
}TRAVELS;//¥Ê∑≈Õ¨µ»◊Ó…Ÿ ±º‰µƒ¬∑æ∂

ALGraph G;//»´æ÷±‰¡ø
Path pa;//¬∑œﬂ
Paths P;//¬∑œﬂ ˝◊È
TRAVELS paths;//¬∑æ∂ ˝◊È


/************º∆À„ ±º‰µƒº‰∏Ù,aŒ™≥ˆ∑¢ ±º‰£¨bŒ™µΩ¥Ô ±º‰***************/
int interval(ti a,ti b){
    int i;
    int diff;
    time_t _t1;
    time_t _t2;
    struct tm t1={0};
    struct tm t2={0};
    i=strcmp(a,b)>0?1:0;
    t1.tm_year =100;
    t1.tm_mday=1;
    t1.tm_hour=10*(a[0]-'0')+(a[1]-'0');
    t1.tm_min=10*(a[3]-'0')+(a[4]-'0');
    t2.tm_year=100;
    t2.tm_mday=1+i;
    t2.tm_hour=10*(b[0]-'0')+(b[1]-'0');
    t2.tm_min=10*(b[3]-'0')+(b[4]-'0');
    _t1= mktime( &t1 );
    _t2= mktime( &t2 );
    diff= (_t2-_t1)/ 60;
    return diff;
}

/************≤È—ØST≥µ¥Œ ˝◊È÷– «∑Ò“—”–≥µ¥Œt,µ±≥µ¥Œ ˝◊È÷–”–∏√≥µ¥Œ ±,∑µªÿÀ¸µƒ±Í∫≈,∑Ò‘Ú∑µªÿ0******************/
int Search_turn(turn *ST,int length,turn *t){
    int i;
    double a;
    ST[0]=t[0];
    for(i=length;;i--){
        a=ST[0].fee-ST[i].fee;
        if(strcmp(ST[0].departure,ST[i].departure)==0&&strcmp(ST[0].terminal,ST[i].terminal)==0&&fabs(a)<=1e-2)
            break;
    }
    return i;
}

/*********************************************************/
void HeapAdjust(turn *H,int s,int m){
    int j;
    H[0]=H[s];
    for(j=2*s;j<=m;j=2*s){
        if(j<m&&strcmp(H[j+1].departure,H[j].departure)>0) j++;
        if(strcmp(H[0].departure,H[j].departure)>0) break;
        H[s]=H[j];
        s=j;
    }
    H[s]=H[0];
}

/******************∂‘√ø∏ˆ≥µ¥Œ ˝◊ÈΩ¯––≈≈–Ú***************************/
void HeapSort(turn *H,int length){
    int i;
    turn t;
    for(i=length/2;i>0;i--)
        HeapAdjust(H,i,length);
    for(i=length;i>1;i--){
        t=H[1];
        H[1]=H[i];
        H[i]=t;
        HeapAdjust(H,1,i-1);
    }
}

/************∂®Œªcity‘⁄∂•µ„ºØ÷–µƒŒª÷√£¨»Áπ˚≤ª‘⁄∂•µ„ºØ÷–£¨∑µªÿ-1*****************/
int LocateVex(ALGraph *G,cityname city){
    int i;
    for(i=0;i<=G->vexnum-1;i++)
        if(!strcmp(G->vertices[i].city,city))
        {return i;
            break;
        }
    return -1;
}

/***********************≤È—Ø∂•µ„ºØvŒª÷√µƒΩ⁄µ„µƒ≥« –√˚≥∆********************/
char* GetVex(ALGraph *G,int v)
{
    if(v>=G->vexnum||v<0)
        exit(0);
    return G->vertices[v].city;
}

/*********************Ω´∂•µ„ºØ÷–“‘vŒ™√˚≥∆µƒ≥« –∏ƒ√˚Œ™value*********************/
int PutVex(ALGraph *G,cityname v,cityname value)
{
    int i,j;
    i=LocateVex(G,v);
    j=LocateVex(G,value);
    if(j>-1) return 0;
    if(i > -1) // v «Gµƒ∂•µ„
    {
        strcpy(G->vertices[i].city,value);
        return 1;
    }
    return 0;
}

/************************≤È—ØvΩ⁄µ„µƒ∑…ª˙¡¥±ÌªÚ’ﬂ¡–≥µ¡¥±Ì÷–µƒµ⁄“ªÃıª°*********************/
int FirstAdjVex(ALGraph *G,cityname v,int trans)
/*
 trans=0,¥˙±Ì∑…ª˙£ªtrans=1£¨¥˙±Ì¡–≥µ°£
 œ¬Õ¨*/
{
    ArcNode *p;
    int v1;
    v1 = LocateVex(G,v); // v1Œ™∂•µ„v‘⁄ÕºG÷–µƒ–Ú∫≈
    p = G->vertices[v1].firstarc[trans];
    if(p)
        return p->adjvex;
    else
        return -1;
}

/**************************≤È—ØvΩ⁄µ„µƒ∑…ª˙¡¥±ÌªÚ’ﬂ¡–≥µ¡¥±Ì÷–µƒœ‡∂‘”⁄ª°<v,w>µƒœ¬“ªª°µƒª°Õ∑*********************/
int NextAdjVex(ALGraph *G,cityname v,cityname w,int trans)
{
    ArcNode *p;
    int v1,w1;
    v1 = LocateVex(G,v); // v1Œ™∂•µ„v‘⁄ÕºG÷–µƒ–Ú∫≈
    w1 = LocateVex(G,w); // w1Œ™∂•µ„w‘⁄ÕºG÷–µƒ–Ú∫≈
    p = G->vertices[v1].firstarc[trans];
    while(p&&p->adjvex != w1) // ÷∏’Îp≤ªø’«“À˘÷∏±ÌΩ·µ„≤ª «w
        p = p->nextarc;
    if(!p||!p->nextarc) // √ª’“µΩwªÚw «◊Ó∫Û“ª∏ˆ¡⁄Ω”µ„
        return -1;
    else
        return p->nextarc->adjvex;
}

/**********************‘⁄∂•µ„ºØ÷–≤Â»Î≥« –v*********************/
void InsertVex(ALGraph *G,cityname v)
{
    strcpy(G->vertices[G->vexnum].city,v); // ππ‘Ï–¬∂•µ„œÚ¡ø
    G->vertices[G->vexnum].firstarc[0]=NULL;
    G->vertices[G->vexnum].firstarc[1]=NULL;
    G->vexnum++; // ÕºGµƒ∂•µ„ ˝º”1
}

/************************‘⁄Õº÷–…æ≥˝≥« –vº∞∆‰œ‡πÿµƒª°*********************/
int DeleteVex(ALGraph *G,cityname v)
{
    int i,j,k;
    ArcNode *p,*q;
    
    j=LocateVex(G,v);    // j «∂•µ„vµƒ–Ú∫≈
    if(j < 0 )            // v≤ª «ÕºGµƒ∂•µ„
        return 0;
    for(k=0;k<2;k++){
        p = (*G).vertices[j].firstarc[k];    // …æ≥˝“‘vŒ™≥ˆ∂»µƒª°ªÚ±ﬂ
        while( p ){
            q = p;
            p = p->nextarc;
            free(q);
        }
    }
    for(i = j+1; i < (*G).vexnum; i++)    // ∂•µ„v∫Û√Êµƒ∂•µ„«∞“∆
        (*G).vertices[i-1] = (*G).vertices[i];
    (*G).vexnum--;
    // …æ≥˝“‘vŒ™»Î∂»µƒª°ªÚ±ﬂ«“±ÿ“™ ±–ﬁ∏ƒ±ÌΩ·µ„µƒ∂•µ„Œª÷√÷µ
    for(k=0;k<2;k++)
        for(i = 0; i < (*G).vexnum; i++)
        {
            p = (*G).vertices[i].firstarc[k]; // ÷∏œÚµ⁄1Ãıª°ªÚ±ﬂ
            while(p) // ”–ª°
            {
                if(p->adjvex == j)        //  «“‘vŒ™»Î∂»µƒ±ﬂ°£
                {
                    if(p == (*G).vertices[i].firstarc[k]) {// ¥˝…æΩ·µ„ «µ⁄1∏ˆΩ·µ„
                        (*G).vertices[i].firstarc[k] = p->nextarc;
                        free(p);
                        p = (*G).vertices[i].firstarc[k];
                    }
                    else{
                        q->nextarc = p->nextarc;
                        free(p);
                        p = q->nextarc;
                    }
                }
                else
                {
                    if(p->adjvex > j)
                        p->adjvex--; // –ﬁ∏ƒ±ÌΩ·µ„µƒ∂•µ„Œª÷√÷µ(–Ú∫≈)
                    q = p;
                    p = p->nextarc;
                }
            }
        }
    return 1;
}

/**************************≤Â»Î“ªÃÀ≥µ¥Œ**************************/
Status InsertArc(ALGraph *G,temp *arc){
    int i,j;
    char choice;
    ArcNode *a,*p;
    i=LocateVex(G,arc->de); // ª°Œ≤ªÚ±ﬂµƒ–Ú∫≈
    j=LocateVex(G,arc->te); // ª°Õ∑ªÚ±ﬂµƒ–Ú∫≈  i==j?
    if(i<0||j<0) return FALSE;
    choice=strcmp(arc->tr,"plane")==0?0:1;
    for(p=G->vertices[i].firstarc[choice];p&&p->adjvex != j;p = p->nextarc) ;// ÷∏’Îp≤ªø’«“À˘÷∏±ÌΩ·µ„≤ª «j
    if(!p){
        a=(ArcNode *)malloc(sizeof(ArcNode));
        a->adjvex=j;
        a->t=(turn *)malloc(MAX_TURN_NUM*sizeof(turn));
        a->i=1;
        a->t[a->i]=arc->t;
        a->nextarc=G->vertices[i].firstarc[choice];
        G->vertices[i].firstarc[choice]=a; //interval∏≥÷µ
    }
    else {
        if(Search_turn(p->t,p->i,&(arc->t))==0){//pŒ™’Ê£¨±£÷§¡Ài>0
            p->t[++p->i]=arc->t;//∂—≈≈–Ú
            //interval∏≥÷µ
            if(p->i>1)
                HeapSort(p->t,p->i);
        }
    }
    return OK;
}

/********************∏˘æ›¥”txtŒƒº˛∂¡Ω¯µƒ–≈œ¢¥¥Ω®Õº******************************/
Status CreateGraph(ALGraph *G,FILE *fp)
{
    int i,j;
    temp *a=(temp *)malloc(sizeof(temp));
    for(;;){
        if(fscanf(fp,"%s%s%s%s%lf%s",a->de,a->te,a->t.departure,a->t.terminal,&a->t.fee,a->tr)>0){
            i=LocateVex(G,a->de); // ª°Œ≤ªÚ±ﬂµƒ–Ú∫≈
            j=LocateVex(G,a->te);// ª°Õ∑ªÚ±ﬂµƒ–Ú∫≈
            if(i<0) InsertVex(G,a->de);
            if(j<0) InsertVex(G,a->te);
            if(i==j&&i!=-1) ;
            else {
                a->t.interval=interval(a->t.departure,a->t.terminal);
                InsertArc(G,a);
            }
            free(a);
            a=(temp *)malloc(sizeof(temp));
        }
        else break;
    }
    fclose(fp);
    return OK;
}

/********************* ‰≥ˆ¡Ω≥« –º‰ª≥µªÚ∑…ª˙µƒÀ˘”–≥µ¥Œ*********************/
int Display(ALGraph *G,cityname de,cityname te,int trans){//trŒ™0÷∏¥˙∑…ª˙£¨trŒ™1÷∏¥˙ª≥µ
    int i,j;
    ArcNode *p;
    i=LocateVex(G,de);
    j=LocateVex(G,te);
    if(i<0||j<0||i==j){
        printf("ƒ„ ‰»Îµƒ≥« –”–ŒÛ!\n");
        return 0;
    }
    for(p=G->vertices[i].firstarc[trans];p&&p->adjvex!=j;p=p->nextarc) ;
    if(!p)  {printf("%-15s-->%15s√ª”–%s\n",de,te,trans>0?"train":"plane");return 0;}
    else{
        printf("%-15s-->%15s”–%d¥Œ%s:\n",de,te,p->i,trans>0?"train":"plane");
        for(i=1;i<=p->i;i++)
            printf("turn%d:%s-->%s %.1f\n",i,p->t[i].departure,p->t[i].terminal,p->t[i].fee);
    }//end else
    return 1;
}

/***************************** ‘⁄G÷–≤È’“≤¢…æ≥˝¡Ω≥« –»´≤øµƒ∞‡¥Œ£¨…æ≥˝≥…π¶∑µªÿ1£¨∑Ò‘Ú∑µªÿ0*********************/
int DeleteArcALL(ALGraph *G,temp *arc)
{
    int i,j;
    int choice;
    ArcNode *p,*q;
    i = LocateVex(G,arc->de ); // i «∂•µ„v(ª°Œ≤)µƒ–Ú∫≈
    j = LocateVex(G,arc->te ); // j «∂•µ„w(ª°Õ∑)µƒ–Ú∫≈
    if(i < 0 || j < 0 || i == j)  return 0;
    choice=strcmp(arc->tr,"plane")==0?0:1;
    p=G->vertices[i].firstarc[choice];
    while(p&&p->adjvex!=j) // p≤ªø’«“À˘÷∏÷Æª°≤ª «¥˝…æ≥˝ª°<v,w>
    { // p÷∏œÚœ¬“ªÃıª°
        q=p;
        p=p->nextarc;
    }
    if(p&&p->adjvex==j) // ’“µΩª°<v,w>
    {
        if(p==G->vertices[i].firstarc[choice]) // pÀ˘÷∏ «µ⁄1Ãıª°
            G->vertices[i].firstarc[choice]=p->nextarc; // ÷∏œÚœ¬“ªÃıª°
        else
            q->nextarc=p->nextarc; // ÷∏œÚœ¬“ªÃıª°
        free(p); //  Õ∑≈¥ÀΩ·µ„
        return 1;
    }
    return 0;
}

/**************************************************************************/
int DeleteArcONE(ALGraph *G,temp *arc){//‘⁄G÷–≤È’“≤¢…æ≥˝∏¯∂®µƒ≥µ¥Œ£¨…æ≥˝≥…π¶∑µªÿ1£¨∑Ò‘Ú∑µªÿ0
    int i,j,num,k;
    int choice;
    ArcNode *p,*q;
    i = LocateVex(G,arc->de ); // i «∂•µ„v(ª°Œ≤)µƒ–Ú∫≈
    j = LocateVex(G,arc->te ); // j «∂•µ„w(ª°Õ∑)µƒ–Ú∫≈
    if(i < 0 || j < 0 || i == j){
        //printf("À˘“™…æ≥˝µƒª°≤ª¥Ê‘⁄!\n");
        return 0;
    }
    choice=strcmp(arc->tr,"plane")==0?0:1;
    p=G->vertices[i].firstarc[choice]; // p÷∏œÚ∂•µ„vµƒµ⁄“ªÃı≥ˆª°
    while(p&&p->adjvex!=j) // p≤ªø’«“À˘÷∏÷Æª°≤ª «¥˝…æ≥˝ª°<v,w>
    { // p÷∏œÚœ¬“ªÃıª°
        q=p;
        p=p->nextarc;
    }
    if(p&&p->adjvex==j){
        num=Search_turn(p->t,p->i,&(arc->t));
        if(!num)  return 0;//√ª”–∏√≥µ¥Œ
        if(p==G->vertices[i].firstarc[choice]&&p->i==1) {
            G->vertices[i].firstarc[choice]=p->nextarc; // ÷∏œÚœ¬“ªÃıª°
            free(p);
        }
        else if(p->i==1){
            q->nextarc=p->nextarc; // ÷∏œÚœ¬“ªÃıª°
            free(p); //  Õ∑≈¥ÀΩ·µ„
        }
        else{
            for(k=num+1;k<=p->i;k++)
                p->t[k-1]=p->t[k];
            p->i--;
        }
        return 1;
        
    }
    return 0;
}

/***************************************************************/
void Savepath(Paths *P,Path *pa){//Ω´¬∑œﬂpa¥ÊΩ¯¬∑œﬂ ˝◊È¿Ô√Ê
    int j;
    for(j=0;j<pa->length;j++)
        P->paths[P->i].path[j]=pa->path[j];
    P->paths[P->i].length=pa->length;
    P->i++;
}

/****************************************************************/
void PrintPath(ALGraph *G,Paths *P){        // ¥Ú”°À˘”–¬∑œﬂ
    int i,j;
    for (i=0; i<P->i; i++){
        printf("¬∑œﬂ%d:\n",i);
        for(j=0;j<P->paths[i].length;j++){
            printf("%s\t", GetVex(G,P->paths[i].path[j]));
            if(j<P->paths[i].length-1) printf("--->");
        }
        putchar('\n');
    }
}

/**************************************************************/
void SearchAllPath(ALGraph *G,Paths *P,Path pa,Mark visited,int v,int te,int trans){//…Ó∂»À—À˜∏¯∂®¡Ωµ„º‰À˘”–µƒø…¥Ôµƒ¬∑œﬂ
    ArcNode *w;
    if(visited[v]) return ;
    pa.path[pa.length]=v;
    pa.length++;
    if(v==te)  Savepath(P,&pa);//’“µΩ¡À“ªÃıø…¥Ôµƒ¬∑œﬂ£¨≤¢±£¥ÊΩ¯¬∑œﬂ
    else {
        visited[v]=1;
        for(w=G->vertices[v].firstarc[trans];w;w=w->nextarc)
            if(!visited[w->adjvex])
                SearchAllPath(G,P,pa,visited,w->adjvex,te,trans);
        visited[v]=0;
    }
}

/**************************************************************/
int Locatenextturn(ALGraph *G,ti T,int de,int te,int trans){//te  «…œ“ª≥µµƒµΩ¥Ô ±º‰£¨de «–¬“ª≥µ£¨∑µªÿ◊ÓΩ¸ ±º‰µƒŒª÷√
    int i;
    ArcNode *p=G->vertices[de].firstarc[trans];
    while(p->adjvex!=te) p=p->nextarc;
    for(i=1;i<=p->i;i++)
        if(strcmp(p->t[i].departure,T)>0)   return i;
    return 1;
}


/*************************************************************/
void Calculatetime(TRAVELS *paths){//º∆À„≥µ¥Œ¬∑æ∂ ˝◊È÷–√ø∏ˆ¬∑æ∂µƒÀ˘–Ëµƒ◊‹ ±º‰
    int i,j;
    for(i=0;i<paths->i;i++)
        for(j=0,paths->tra[i].sum=0;j<paths->tra[i].i;j++){
            paths->tra[i].sum+=paths->tra[i].arcs[j].t.interval;
            if(j!=paths->tra[i].i-1)
                paths->tra[i].sum+=interval(paths->tra[i].arcs[j].t.terminal,paths->tra[i].arcs[j+1].t.departure);
        }
}

/*****************************************************************/
void SortandDelete(Paths *P){//∞¥÷–◊™¥Œ ˝◊Ó…Ÿ¿¥≈≈≥µ¥Œ¬∑æ∂
    Path a;
    int i,j;
    for(i=0;i<P->i-1;i++)
        for(j=0;j<P->i-1-i;j++)
            if(P->paths[j].length>P->paths[j+1].length){
                a=P->paths[j];
                P->paths[j]=P->paths[j+1];
                P->paths[j+1]=a;
            }
    for(i=0;i<P->i-1;i++)
        if(P->paths[i].length<P->paths[i+1].length)
            break;
    if(i<=P->i-2)
        P->i=i+1;
    else ;
}


/*********************∞¥sum◊Ó–°¿¥≈≈–Ú≥µ¥Œ¬∑æ∂ ˝◊È£¨±£¡Ù◊Ó…Ÿsumµƒ≥µ¥Œ¬∑æ∂*********************/
void SortandAdjust(TRAVELS *paths){
    int i,j;
    Travel a;
    for(i=0;i<paths->i-1;i++)
        for(j=0;j<paths->i-1-i;j++)
            if(paths->tra[j].sum>paths->tra[j+1].sum){
                a=paths->tra[j];
                paths->tra[j]=paths->tra[j+1];
                paths->tra[j+1]=a;
            }
    for(i=0;i<paths->i-1;i++)
        if(paths->tra[i].sum<paths->tra[i+1].sum)
            break;
    if(i<=paths->i-2)
        paths->i=i+1;
    else ;
}

/**************************º∆À„≥µ¥Œ¬∑æ∂ ˝◊È÷–√ø∏ˆ¬∑æ∂µƒÀ˘–Ëµƒ◊‹ª®∑—***************************/
void Calculatefee(TRAVELS *paths){
    int i,j;
    for(i=0;i<paths->i;i++)
        for(j=0,paths->tra[i].sum=0;j<paths->tra[i].i;j++)
            paths->tra[i].sum+=paths->tra[i].arcs[j].t.fee;
}

/*****************************—∞’“À˘”–≥µ¥Œ¬∑æ∂***********************************/
void SearchAllTurn(ALGraph *G,TRAVELS *paths,Travel current,Path p,int de,int te,int first,int trans,int criteria){
    int j;
    ArcNode *po;
    po=G->vertices[p.path[de]].firstarc[trans];
    while(po->adjvex!=p.path[te]) po=po->nextarc;
    for(;first<=po->i;first++,current.i--){
        if(te==p.length-1){//µΩ ±µΩ¥Ô¡À÷’µ„
            strcpy(current.arcs[ current.i].de,GetVex(G,p.path[de]));
            strcpy(current.arcs[ current.i].te,GetVex(G,p.path[te]));
            current.arcs[ current.i].t=po->t[first];
            strcpy(current.arcs[ current.i].tr,trans==0?"plane":"train");
            current.i++;
            paths->tra[paths->i]=current;//Ω´≥µ¥Œ¬∑æ∂–¥Ω¯≥µ¥Œ¬∑æ∂ ˝◊È
            (paths->i)++;
            if(paths->i>=MAX_PATHS){
                if(criteria)  Calculatetime(paths);
                else          Calculatefee(paths);
                SortandAdjust(paths);
            }
            continue;
        }
        strcpy(current.arcs[ current.i].de,GetVex(G,p.path[de]));
        strcpy(current.arcs[ current.i].te,GetVex(G,p.path[te]));
        current.arcs[ current.i].t=po->t[first];
        strcpy(current.arcs[ current.i].tr,trans==0?"plane":"train");
        current.i++;
        j=Locatenextturn(G,po->t[first].terminal,p.path[te],p.path[te+1],trans);
        SearchAllTurn(G,paths,current,p,te,te+1,j,trans,criteria);
    }
}

/*****************************º∆À„≥µ¥Œ¬∑æ∂µƒ ±º‰∫Õ∑—”√**********************************/
void quick(ALGraph *G,TRAVELS *paths,Path p,int trans,int criteria){
    Travel current;
    current.i=0;
    current.sum=0;
    SearchAllTurn(G,paths,current,p,0,1,1,trans,criteria);
    if(criteria)  Calculatetime(paths);
    else          Calculatefee(paths);
    SortandAdjust(paths);
}

/************************∞¥’’±Í◊º∏˘æ›¬∑œﬂ ˝◊È÷–µÿ√ø“ª∏ˆ¬∑œﬂ…Ó∂»À—À˜À˘”–µƒ≥µ¥Œ¬∑æ∂*********************/
int Quickestsearch(ALGraph *G,TRAVELS *paths,Paths *P,int trans,int criteria){//criteria=1 ±£¨∞¥ ±º‰◊Ó…Ÿµƒ‘≠‘Ú
    int i;//criteria=0 ±£¨∞¥∑—”√◊Ó…Ÿµƒ‘≠‘Ú
    paths->i=0;
    for(i=0;i<P->i;i++)
        quick(G,paths,P->paths[i],trans,criteria);
    //fastest(paths);
    return 1;
}

/******************∞¥’’±Í◊º(ª®∑—£¨ ±º‰)¥Ú”°≥µ¥Œ¬∑œﬂ ˝◊È÷–µƒÀ˘”–µƒ¬∑œﬂ**********************/
void printfast(TRAVELS *paths,int criteria){
    int i,j;
    double hour;
    for(i=0;i<paths->i;i++){
        printf("path%d:\n",i+1);
        for(j=0;j<paths->tra[i].i;j++){
            printf("%15s-->%-15s ",paths->tra[i].arcs[j].de,paths->tra[i].arcs[j].te);
            printf("%s-->%s ",paths->tra[i].arcs[j].t.departure,paths->tra[i].arcs[j].t.terminal);
            printf("%5d minute     %.1f  RMB\n",paths->tra[i].arcs[j].t.interval,paths->tra[i].arcs[j].t.fee);
        }
        
        if(criteria) {
            printf("◊‹ ±º‰:%.3f hour(s)\n\n", hour=paths->tra[i].sum/60.0);
            Calculatefee(paths);
            printf("◊‹∑—”√:%d RMB\n\n", paths->tra[i].sum);
            Calculatetime(paths);
        }
        else{
            printf("◊‹∑—”√:%d RMB\n\n", paths->tra[i].sum);
            Calculatetime(paths);
            printf("◊‹ ±º‰:%.3f hour(s)\n\n", hour=paths->tra[i].sum/60.0);
            Calculatefee(paths);
        }
    }
}


#endif /* basic_operation_h */
