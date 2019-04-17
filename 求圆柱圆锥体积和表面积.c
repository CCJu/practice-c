#include <stdio.h>
#include <math.h>
#define PI 3.14
int main()
{
	float r=3,h=4.3,l;
printf("圆柱体的表面积为%f\n",2*PI*r*(h+r));    
    printf("圆柱体的体积为%f\n",PI*r*r*h);
	l= r*r+h*h;
	printf("圆锥的表面积为%f\n",PI*r*(sqrt(l)+r));
	printf("圆锥的体积为%f\n",PI*r*r*h/3);
	return 0;
}
	