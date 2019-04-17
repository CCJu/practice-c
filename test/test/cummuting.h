//
//  cummuting.h
//  test
//
//  Created by GOD on 2018/6/29.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef cummuting_h
#define cummuting_h
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

void OptimalArrive(int op){//≤È—Ø,op=1 ±,∞¥ ±º‰◊Ó…Ÿµƒ‘≠‘Ú;op=0,∞¥∑—”√◊Ó…Ÿµƒ‘≠‘Ú
    char command;
    cityname a,b;
    int v,te,i;
    Mark visited;
    pa.length=0;
    P.i=0;
    printf("\n******************************\n");
    printf("\t    0:∑…ª˙\n");
    printf("\t    1:ª≥µ\n");
    printf("******************************\n");
    printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
    for(;;){
        command=getchar();
        fflush(stdin);
        if(command!='0'&&command!='1')
            printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ£∫\n");
        else break;
    }
    for(;;){
        printf("«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™)\n");
        scanf("%s%s",a,b);
        fflush(stdin);
        v=LocateVex(&G,a);
        te=LocateVex(&G,b);
        if(v==te||v<0||te<0)
            printf("≥« –√˚≥∆”–ŒÛ!");
        else break;
    }
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    SearchAllPath(&G,&P,pa,visited,v,te,command-'0');
    printf("À˘”–µƒ¬∑œﬂ\n");
    PrintPath(&G,&P);
    Quickestsearch(&G,&paths,&P,command-'0',op);
    if(op)
        printf("¬˙◊„◊ÓøÏµΩ¥Ôµƒ¬∑æ∂\n");
    else
        printf("¬˙◊„◊Ó °«ÆµΩ¥Ôµƒ¬∑æ∂\n");
    printfast(&paths,op);
}

/**************************∞¥÷–◊™¥Œ ˝◊Ó…Ÿµƒ‘≠‘Ú≤È—Ø*************************/
void LeastTransfer(){
    char command,command1;
    cityname a,b;
    int v,te,i;
    Mark visited;
    pa.length=0;
    P.i=0;
    printf("\n******************************\n");
    printf("\t    0:∑…ª˙\n");
    printf("\t    1:ª≥µ\n");
    printf("******************************\n");
    printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
    for(;;){
        command=getchar();
        fflush(stdin);
        if(command!='0'&&command!='1')
            printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ.\n");
        else break;
    }
    for(;;){
        printf("«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™):\n");
        scanf("%s%s",a,b);
        fflush(stdin);
        v=LocateVex(&G,a);
        te=LocateVex(&G,b);
        if(v==te||v<0||te<0) printf(" ‰»Î≥« –√˚≥∆ªÚ∏Ò Ω”–ŒÛ!");
        else break;
    }
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    SearchAllPath(&G,&P,pa,visited,v,te,command-'0');
    printf("–ﬁ’˝«∞µƒÀ˘”–¬∑œﬂ:\n");
    PrintPath(&G,&P);
    SortandDelete(&P);
    printf("–ﬁ’˝∫Ûµƒµ√µΩµƒ÷–◊™¥Œ ˝◊Ó…Ÿµƒ¬∑œﬂ:\n");
    PrintPath(&G,&P);
    for(;;){
        printf("\n*************************************************\n");
        printf("\t 0:‘⁄÷–◊™¥Œ ˝◊Ó…Ÿµƒ«Èøˆœ¬£¨∞¥◊Ó °«Æ‘≠‘Ú\n");
        printf("\t 1:‘⁄÷–◊™¥Œ ˝◊Ó…Ÿµƒ«Èøˆœ¬£¨∞¥øÏ‘≠‘Ú\n");
        printf("\t 2£∫Ω· ¯\n");
        printf("*************************************************\n");
        printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
        for(;;){
            command1=getchar();
            fflush(stdin);
            if(command1!='0'&&command1!='1'&&command1!='2')
                printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ.\n");
            else break;
        }
        if(command1=='2') return;
        Quickestsearch(&G,&paths,&P,command-'0',command1-'0');
        printfast(&paths,command1-'0');
    }
}

/****************************◊Ó”≈¬∑œﬂ≤È—Ø******************************/
void Consult(){
    char command;
    int i;
    for(;;){
        printf("Õº÷–ƒø«∞“—”–µƒ≥« –»Áœ¬:");
        for(i=0;i<G.vexnum;i++){
            if(i%5==0) putchar('\n');
            printf("%15s",G.vertices[i].city);
        }
        printf("\n*********************************\n");
        printf("*\t1:◊ÓøÏµΩ¥Ô              *\n");
        printf("*\t2:◊Ó °«ÆµΩ¥Ô            *\n");
        printf("*\t3:÷–◊™¥Œ ˝◊Ó…Ÿ          *\n");
        printf("*\t4:Ω· ¯≤È—Ø              *\n");
        printf("*********************************\n");
        printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
        for(;;){
            command=getchar();
            fflush(stdin);
            if(command!='1'&&command!='2'&&command!='3'&&command!='4')
                printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ£∫\n");
            else break;
        }//end for
        switch(command){
            case '1':OptimalArrive(1);break;
            case '2':OptimalArrive(0);break;
            case '3':LeastTransfer();break;
            case '4':printf("Ω· ¯≤È—Ø!\n");
                return;
        }//end switch
    }//end for
}

/**********************************************************/
void Compiletimetable(int trans){//±‡º≠ ±øÃ±Ì£¨µ±trans=0 ±£¨±‡º≠∑…ª˙ ±øÃ±Ì
    cityname a,b;//µ±trans=1 ±£¨±‡º≠¡–≥µ ±øÃ±Ì
    int  de,te,i,j;
    temp arc;
    char command;
    for(;;){
        printf("Õº÷–ƒø«∞“—”–µƒ≥« –»Áœ¬:");
        for(i=0;i<G.vexnum;i++){
            if(i%5==0) putchar('\n');
            printf("%15s",G.vertices[i].city);
        }
        printf("\n\nœ÷‘⁄–ﬁ∏ƒ%s timetable£∫\n",trans>0?"train":"plane");
        printf("\n\t************************************************");
        printf("\n\t*    ^_^ ª∂”≠¿¥µΩ  »´π˙ΩªÕ®◊…—Øƒ£ƒ‚œµÕ≥ ^_^    *");
        printf("\n\t*     2013º∂Õ¯¬Áπ§≥Ã(4)∞‡“∂æµˆŒ/3113006586     *");
        printf("\n\t************************************************\n");
        printf("\t*\t 0:≤È—Ø¡Ω∏ˆ≥« –º‰µƒ∞‡¥Œ                *\n");
        printf("\t*\t 1:…æ≥˝¡Ω∏ˆ≥« –º‰À˘”–µƒ∞‡¥Œ            *\n");
        printf("\t*\t 2:…æ≥˝¡Ω∏ˆ≥« –º‰“ªÃÀ∞‡¥Œ              *\n");
        printf("\t*\t 3:‘ˆº”¡Ω∏ˆ≥« –º‰“ªÃÀ∞‡¥Œ              *\n");
        printf("\t*\t 4:Ω· ¯≤È—Ø                            *\n");
        printf("\t************************************************\n");
        printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
        for(;;){
            command=getchar();
            fflush(stdin);
            if(command!='0'&&command!='1'&&command!='2'&&command!='3'&&command!='4')
                printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ:\n");
            else break;
        }//end for
        switch(command){
            case '0':for(;;){
                printf("\n«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™)\n");
                scanf("%s%s",a,b);
                fflush(stdin);
                de=LocateVex(&G,a);
                te=LocateVex(&G,b);
                if(de==te||de<0||te<0)
                    printf("≥« –√˚≥∆ªÚ∏Ò Ω”–ŒÛ!");
                else break;
            }
                Display(&G,a,b,trans);
                break;
            case '1': for(;;){
                printf("«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™)\n");
                scanf("%s%s",arc.de,arc.te);
                fflush(stdin);
                de=LocateVex(&G,arc.de);
                te=LocateVex(&G,arc.te);
                if(de==te||de<0||te<0) printf("≥« –√˚≥∆ªÚ∏Ò Ω”–ŒÛ!");
                else break;
            }
                printf("≤Ÿ◊˜«∞\n");
                if(Display(&G,arc.de,arc.te,trans)==0){
                    printf("Œﬁ∑®≤Ÿ◊˜!\n");
                    break;
                }
                strcmp(arc.tr,trans==0?"plane":"train");
                DeleteArcALL(&G,&arc);
                printf("≤Ÿ◊˜∫Û£∫\n");
                Display(&G,arc.de,arc.te,trans);
                break;
            case '2':for(;;){
                printf("«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™)\n");
                scanf("%s%s",arc.de,arc.te);
                fflush(stdin);
                de=LocateVex(&G,arc.de);
                te=LocateVex(&G,arc.te);
                if(de==te||de<0||te<0) printf("≥« –√˚≥∆ªÚ∏Ò Ω”–ŒÛ!");
                else break;
            }
                printf("≤Ÿ◊˜«∞\n");
                if(Display(&G,arc.de,arc.te,trans)==0){
                    printf("Œﬁ∑®≤Ÿ◊˜!\n");
                    break;
                }
                printf("«Î“¿¥Œ ‰»Î“™…æ≥˝µƒ“ªÃÀ∞‡¥Œ–≈œ¢(∑¢≥µ ±º‰,µΩ¥Ô ±º‰£¨∑—”√),√ø∏ˆ–≈œ¢”√ø’∏Ò∑÷ø™\n");
                scanf("%s%s%lf",arc.t.departure,arc.t.terminal,&arc.t.fee);
                fflush(stdin);
                strcpy(arc.tr,trans==0?"plane":"train");
                DeleteArcONE(&G,&arc);
                printf("≤Ÿ◊˜∫Û\n");
                Display(&G,arc.de,arc.te,trans);
                break;
            case '3':printf("\n«Î“¿¥Œ ‰»Î∆µ„£¨÷’µ„(¡Ω∏ˆµÿµ„º‰“‘ø’∏Ò∏Ùø™)\n");
                scanf("%s%s",arc.de,arc.te);
                fflush(stdin);
                i=LocateVex(&G,arc.de); // ª°Œ≤ªÚ±ﬂµƒ–Ú∫≈
                j=LocateVex(&G,arc.te);// ª°Õ∑ªÚ±ﬂµƒ–Ú∫≈
                if(i<0) InsertVex(&G,arc.de);
                if(j<0) InsertVex(&G,arc.te);
                printf("≤Ÿ◊˜«∞\n");
                Display(&G,arc.de,arc.te,trans);
                printf("«Î“¿¥Œ ‰»Î“ªÃÀ“™≤Â»Îµƒ∞‡¥Œ–≈œ¢(∑¢≥µ ±º‰,µΩ¥Ô ±º‰£¨∑—”√),√ø∏ˆ–≈œ¢”√ø’∏Ò∑÷ø™\n");
                scanf("%s%s%lf",arc.t.departure,arc.t.terminal,&arc.t.fee);
                fflush(stdin);
                strcpy(arc.tr,trans==0?"plane":"train");
                InsertArc(&G,&arc);
                Display(&G,arc.de,arc.te,trans);
                break;
            case '4':printf("Ω· ¯–ﬁ∏ƒ!\n");
                return;
        }//end switch
    }//end for
}

/**********************************************/
void CompileCityInformation(){//±‡º≠≥« ––≈œ¢
    char command;
    cityname a,b;
    int i;
    for(;;){
        printf("Õº÷–ƒø«∞“—”–µƒ≥« –»Áœ¬:");
        for(i=0;i<G.vexnum;i++){
            if(i%5==0) putchar('\n');
            printf("%15s",G.vertices[i].city);
        }
        printf("\n******************************\n");
        printf("\t1:…æ≥˝≥« –\n");
        printf("\t2:ÃÌº”≥« –\n");
        printf("\t3:–ﬁ∏ƒ≥« –√˚≥∆\n");
        printf("\t4:Ω· ¯≤Ÿ◊˜\n");
        printf("******************************\n");
        printf("\n«Îƒ„ ‰»Î”––ß≤È—Ø–Ú∫≈£∫");
        for(;;){
            command=getchar();
            fflush(stdin);
            if(command!='1'&&command!='2'&&command!='3'&&command!='4')
                printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ£∫\n");
            else break;
        }//end for
        switch(command){
            case '1':for(;;){
                printf("«Î ‰»Î“™…æ≥˝µƒ≥« –√˚≥∆\n");
                scanf("%s",a);
                fflush(stdin);
                if(LocateVex(&G,a)>=0) break;
                else printf("Õº÷–√ª”–∏√≥« –!");
            }
                DeleteVex(&G,a);
                printf("…æ≥˝≥…π¶!\n");
                break;
            case '2':for(;;){
                printf("«Î ‰»Î“™ÃÌº”µƒ≥« –√˚≥∆\n");
                scanf("%s",a);
                fflush(stdin);
                if(LocateVex(&G,a)<0) break;
                else printf("Õº÷–“—”–∏√≥« –!");
            }
                InsertVex(&G,a);
                printf("ÃÌº”≥…π¶");
                break;
            case '3':for(;;){
                printf("«Î ‰»Î“™±ª–ﬁ∏ƒµƒæ…≥« –√˚≥∆\n");
                scanf("%s",a);
                fflush(stdin);
                if(LocateVex(&G,a)>=0) break;
                else printf("Õº÷–√ª”–∏√≥« –!");
            }
                for(;;){
                    printf("«Î ‰»Î–ﬁ∏ƒ∫Ûµƒ–¬≥« –√˚≥∆\n");
                    scanf("%s",b);
                    fflush(stdin);
                    if(LocateVex(&G,b)<0) break;
                    else printf("Õº÷–“—”–∏√≥« –!");
                }
                PutVex(&G,a,b);
                printf("–ﬁ∏ƒ√˚≥∆≥…π¶!\n");
                break;
            case '4':printf("Ω· ¯–ﬁ∏ƒ!\n");
                return;
        }//end switch
    }//end for
}

/**********************************************************/
void Initialize(){//≥ı ºªØ≤Ÿ◊˜ΩÁ√Ê
    char command;
    for(;;){
        printf("\n\t************************************************");
        printf("\n\t*    ^_^ ª∂”≠¿¥µΩ  »´π˙ΩªÕ®◊…—Øƒ£ƒ‚œµÕ≥ ^_^    *");
        printf("\n\t*     2013º∂Õ¯¬Áπ§≥Ã(4)∞‡“∂æµˆŒ/3113006586     *");
        printf("\n\t************************************************\n");
        printf("\t*\t        1:≥« ––≈œ¢±‡º≠                 *\n");
        printf("\t*\t        2:¡–≥µ ±øÃ±Ì±‡º≠               *\n");
        printf("\t*\t        3:∑…ª˙∫Ω∞‡±Ì±‡º≠               *\n");
        printf("\t*\t        4:◊…—Ø∑˛ŒÒ                     *\n");
        printf("\t*\t        5:ÕÀ≥ˆ                         *\n");
        printf("\t************************************************\n");
        printf("\n«Îƒ„ ‰»Î≤È—Ø–≈œ¢–Ú∫≈£∫");
        for(;;){
            command=getchar();
            fflush(stdin);
            if(command!='1'&&command!='2'&&command!='3'&&command!='4'&&command!='5')
                printf("«Î÷ÿ–¬ ‰»Î”––ß≤Ÿ◊˜—°œÓ:\n");
            else break;
        }//end for
        switch(command){
            case '1':CompileCityInformation();break;
            case '2':Compiletimetable(1);break;
            case '3':Compiletimetable(0);break;
            case '4':Consult();break;
            case '5':printf("Ω· ¯!\n");
                exit(0);
        }
        
    }//end for
}


#endif /* cummuting_h */
