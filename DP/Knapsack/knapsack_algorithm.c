#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void knapsack();
struct knapsack
{
    int value,weight,b;
    float ratio;
};
void knapsack()
{
    int p,i,c,a,j;
    printf("Enter the no. of items you have.\n");
    scanf("%d",&a);
    struct knapsack k[a],temp[a];
    for(i=0;i<a;i++)
    {
        k[i].b=i+1;
        printf("Enter the weight of the item %d.\n",i+1);
        scanf("%d",&k[i].weight);
        printf("Enter the value of the item %d.\n",i+1);
        scanf("%d",&k[i].value);
        k[i].ratio=k[i].value/k[i].weight;
        printf("%.2f\n",k[i].ratio);
    }

    printf("Enter the weight of the knapsack required.\n");
    scanf("%d",&c);
    printf("Sorting the ratios.....\n");
    for(j=0;j<a;j++)
    {
        for(i=0;i<a-1;i++)
        {
            if(k[i+1].ratio>k[i].ratio)
            {
                temp[i].b=k[i].b;
                temp[i].value=k[i].value;
                temp[i].weight=k[i].weight;
                temp[i].ratio=k[i].ratio;
                k[i].b=k[i+1].b;
                k[i].value=k[i+1].value;
                k[i].weight=k[i+1].weight;
                k[i].ratio=k[i+1].ratio;
                k[i+1].b=temp[i].b;
                k[i+1].value=temp[i].value;
                k[i+1].weight=temp[i].weight;
                k[i+1].ratio=temp[i].ratio;


            }
        }
    }
    for(i=0;i<a;i++)
    {
        printf("%d\t%d\t%d\t%f\n",k[i].b,k[i].value,k[i].weight,k[i].ratio);

    }
    printf("Sorted\n");
    printf("Executing knapsack......\n");
    p=0;
    for(i=0;i<a;i++)
    {
        if(c>=k[i].weight)
        {
            printf("Present value: %d\n",c);
            c=c-k[i].weight;
            p=p+k[i].value;
            printf("Updated value: %d\n",c);
        }
        else if(c<k[i].weight)
        {
            printf("Present value: %d\n",c);
            p=p+((c*k[i].value)/k[i].weight);
            c=0;
            printf("Updated value: %d\n",c);


        }
    }
    printf("So the value of maximum profit is %d.\n",p);
}
void main()
{
    clock_t t1,t2;
    double t3;
    printf("Welcome....\n");
    knapsack();
}


