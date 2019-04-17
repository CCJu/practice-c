//
//  Sort.h
//  Arraysort
//
//  Created by GOD on 2018/6/13.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef Sort_h
#define Sort_h
typedef struct {
    int data;
    struct Node *next;
}Node;
typedef struct {
    Node *a[10];
}List;
void init(int **array){
    int i=0;
    for(;i<100000;i++)
        *((*array)+i)=rand()%100000;
}
void show(int *array){
    int i=0;
    for(;i<100000;i++)
        printf("%d\n",array[i]);
}
//查找
bool find(int *array,int n){
    return true;
}
//直接插入排序
void directInsertionSort(int *array){
    double starttime=clock();
    int i=1;
    for(;i<100000;i++){
        int j=i-1,t=array[i];
        while(j>=0){
            if(t<array[j])
                array[j+1]=array[j];
            else
                break;
            j--;
        }
        array[j+1]=t;
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//希尔排序
void hillSort(int *array){
    double starttime=clock();
    int numOfD=6;
    for(;numOfD>0;numOfD/=2){
        int i=numOfD-1;
        for(;i>=0;i--){
            int j=i+numOfD;
            for(;j<100000;j+=numOfD){
                int k=i,t=array[i+numOfD];
                while(k>=0){
                    if(t<array[k])
                        array[k+numOfD]=array[k];
                    else
                        break;
                    k-=numOfD;
                }
                array[k+numOfD]=t;
            }
        }
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//直接选择排序
void directSelectionSort(int *array){
    double starttime=clock();
    int i=0,j,t,min;
    for(;i<100000;i++){
        min=i;
        j=i;
        for(;j<100000;j++)
            if(array[j]<array[min]) min=j;
        if(i!=min){
            t=array[i];
            array[i]=array[min];
            array[min]=t;
        }
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
void toMaximumHeap(int *array,int begin,int end){
    if(end-begin==1)return;
    int i=end;
    for(;i>=begin;i--){
        if(i-1>=begin){
            if((i-begin-1)/2==(i-begin-2)/2){
                if(array[i]>array[i-1]){
                    if(array[i]>array[(i-begin-1)/2+begin]){
                        int t=array[i];
                        array[i]=array[(i-begin-1)/2+begin];
                        array[(i-begin-1)/2+begin]=t;
                        i=end+1;
                        continue;
                    }
                }else{
                    if(array[i-1]>array[(i-begin-2)/2+begin]){
                        int t=array[i-1];
                        array[i-1]=array[(i-begin-2)/2+begin];
                        array[(i-begin-2)/2+begin]=t;
                        i=end+1;
                        continue;
                    }
                }
            }else{
                if(array[i]>array[(i-begin-1)/2+begin]){
                    int t=array[i];
                    array[i]=array[(i-begin-1)/2+begin];
                    array[(i-begin-1)/2+begin]=t;
                    i=end+1;
                    continue;
                }
            }
        }
    }
}
//堆排序
void heapSort(int *array){
    double starttime=clock();
    int i=0;
    for(;i<100000;i++){
        toMaximumHeap(array, i, 99999);
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//冒泡排序
void bubbleSort(int *array){
    double starttime=clock();
    int i=0;
    for(;i<99999;i++){
        int j=0;
        bool flag=false;
        for(;j<99999;j++){
            if(array[j]>array[j+1]){
                int t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
                flag=true;
            }
        }
        if(!flag) break;
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//快速排序
void quicklySort(int *array,int start,int end){
    int i=start,j=end;
    int num=array[i];
    if(i>=j) return;
    while(i<j){
        while(i<j){
            if(array[j]<num) break;
            j--;
        }
        while(i<j){
            if(array[i]>num) break;
            i++;
        }
        int t=array[i];
        array[i]=array[j];
        array[j]=t;
    }
    int t=array[start];
    array[start]=array[i];
    array[i]=t;
    quicklySort(array,start,i-1);
    quicklySort(array,i+1, end);
}
void quickSort(int **array,int start,int end){
    int i=start,j=end;
    int num=(*array)[i];
    if(i>=j) return;
    while(i<j){
        while(i<j){
            if((*array)[j]<num) break;
            j--;
        }
        while(i<j){
            if((*array)[i]>num) break;
            i++;
        }
        int t=(*array)[i];
        (*array)[i]=(*array)[j];
        (*array)[j]=t;
    }
    int t=(*array)[start];
    (*array)[start]=(*array)[i];
    (*array)[i]=t;
    quickSort(array,start,i-1);
    quickSort(array,i+1, end);
}
//二路归并排序,不使用辅助空间
void binaryMergeSort(int *array){
    double starttime=clock();
    int i=2;
    for(;i<100000;i*=2){
        bool ii=true;
        if(100000%i!=0)
            ii=false;
        int j=1;
        for(;j<=(ii?100000/i:100000/i+1);j++){
            quickSort(&array, (j-1)*i, (j-1)*i+i-1<100000?(j-1)*i+i-1:99999);
        }
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//二路归并排序,使用辅助空间
void binaryMergeSort1(int *array){
    double starttime=clock();
    int i=1;
    for(;i<100000;i*=2){
        int length=2*i<100000?2*i:100000;
        int t[length];
        bool ii=true;
        if(100000%length!=0)
            ii=false;
        int j=1;
        for(;j<=(ii?100000/length:100000/length+1);j++){
            int start1=(j-1)*i,end1=(j-1)*i+i-1<100000?(j-1)*length+length-1:99999;
            int start2=j*i,end2=j*i+i-1<100000?(j-1)*length+length-1:99999;
            int k=0;
            for(;start1<=end1&&start2<=end2;k++){
                if(array[start1]<array[start2]){
                    t[k]=array[start1];
                    start1++;
                }else{
                    t[k]=array[start2];
                    start2++;
                }
            }
            while(start1<=end1){
                t[k]=array[start1];
                k++;
                start1++;
            }
            while(start2<=end2){
                t[k]=array[start2];
                k++;
                start2++;
            }
            start1=(j-1)*i;
            k=0;
            for(;start1<=(j-1)*i+length-1;start1++,k++)
                array[start1]=t[k];
        }
        
    }
    double endtime=clock();
    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
}
//void insert(List *list,int location,int num){
//    Node *n=list->a[location];
//    while(n!=NULL){
//        if(n->next==NULL) break;
//        n=(Node *)n->next;
//    }
//    Node *t;
//    t=malloc(sizeof(Node));
//    t->data=num;
//    t->next=NULL;
//    n->next=t;
//}
//void arrayUpdate(int **array,List l){
//    int i=0,j=0;
//    for(i=0;i<10;i++){
//        Node *n=l.a[i];
//        while (n!=NULL) {
//            (*array)[j]=n->data;
//            n=(Node *)n->next;
//            j++;
//        }
//    }
//}
//void listInit(List *l){
//    int i=0;
//    List ll;
//    for(;i<10;i++)
//        ll.a[i]=NULL;
//    l=&ll;
//}
////基数排序
//void radixSort(int *array){
//    double starttime=clock();
//    int i=1;
//    for(;i<6;i++) {
//        int j=0;
//        List l;
//        listInit(&l);
//        for(;j<100000;j++){
//            int num=array[j];
//            num/=pow(10, i-1);
//            int t=num-num/10*10;
//            insert(&l, t, array[j]);
//        }
//        arrayUpdate(&array, l);
//    }
//    double endtime=clock();
//    printf("directInsertionSort: %lf ms\n",(endtime-starttime)/CLOCKS_PER_SEC);
//}

#endif /* Sort_h */
