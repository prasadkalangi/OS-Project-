#include<stdio.h>
#include<pthread.h>
#include<time.h>
void *fun()
{
char a;
char b[62]={'1','2','3','4','5','7','8','9','0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
a=b[rand()%62];
printf("Random character is %c",a);	
}
main()
{
int size=0,size_l=0,i=0,m;
clock_t r,t;
double exetime;
while(1)
{
printf("\nEnter 1 to create process and 2 to exit:");
scanf("%d",&m);
if(m==2)
{
break;
}
else
{
pthread_t p[10],lower[10],higher[10];
pthread_create(&p[i],NULL,fun,NULL);
t=clock();
pthread_join(p[i],NULL);
r=clock()-t;
exetime=(double)r/CLOCKS_PER_SEC;//to get in seconds
printf("\nThe time taken by the process is=%f",exetime);
if(exetime<1)
{
printf("\nEntered to the higher priority");
higher[size]=p[i];
size++;
}
else
{
printf("\nEntered to the low priority");
lower[size_l]=p[i];
size_l++;
}
i++;
}
}
}
