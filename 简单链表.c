#include <stdio.h>
#define LEN sizeof(struct student)
struct student
{
	int num;
	float score;
	struct student *next;
};
int main()
{ 
    struct stduent a[3],*head,*p;
    a[0].num=10101; a[0].score=89.5;
    a[1].num=10103; a[1].score=90;
    a[2].num=10107; a[2].score=85;
    head=&a[0];
    a[0].next=&a[1];
    a[1].next=&a[2];
    a[2].next=NULL;
    do
    {
    	printf("%d %f\n",head->num,head->score);
    	head=head->next;
    }while(head!=NULL);
    return 0;
}