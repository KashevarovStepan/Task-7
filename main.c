#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void del(int*p,int n)
{
    int i,j,count=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]==p[j])
            {
                if(p[j]!=0)count++;
                p[j]=0;
            }
        }
    }
    for(i=0,j=0;i<n;i++)
    {
        if(p[i]!=0)
        {
            p[j]=p[i];
            j++;
        }
    }
    for(i=n-count;i<n;i++)p[i]=0;
}

void Task3()
{
    printf("Задание 3\n");
    int i,n,*p;
    printf("Введите количество элементов массива\n");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Введите элемент массива\n");
        scanf("%d",&p[i]);
    }
    printf("Начальный массив: ");
    for(i=0;i<n;i++)printf("%d ",p[i]);
    del(p,n);
    printf("\nИзмененный массив: ");
    for(i=0;i<n;i++)printf("%d ",p[i]);
    free(p);
}

int binarySearch(int *p,int n,int value,int left,int right)
{
    if(left>right)return -1;
    int mid=left+(right-left)/2;
    if(p[mid]==value)return mid;
    else
    {
        if(p[mid]>value)return binarySearch(p,n,value,left,mid-1);
        else return binarySearch(p,n,value,mid+1,right);
    }
}

void Task5()
{
    printf("Задание 5\n");
    printf("Введите массив с возрастающими элементами(a1<a2<a3...)\n");
    int i,n,*p,key,value;
    printf("Введите количество элементов массива\n");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Введите элемент массива\n");
        scanf("%d",&p[i]);
    }
    printf("Введите искомый элемент\n");
    scanf("%d",&value);
    printf("\nНачальный массив: ");
    for(i=0;i<n;i++)printf("%d ",p[i]);
    printf("\n");
    key=binarySearch(p,n,value,0,n-1);
    if(key==-1)printf("Такого элемента нет\n");
    else printf("Индекс элемента со значением %d равен %d\n",value,key);
}

int* unite(int *p1,int *p2,int m,int n)
{
    int i,j1=0,j2=0,*p;
    p=(int*)malloc((m+n)*sizeof(int));
    for(i=0;i<m+n;i++)
    {
        if(j1<m&&j2<n)
        {
            if(p1[j1]<=p2[j2])
            {
                p[i]=p1[j1];
                j1++;
            }
            else
            {
                p[i]=p2[j2];
                j2++;
            }
        }
        else
        {
            if(j1<m)
            {
                p[i]=p1[j1];
                j1++;
            }
            else//j2<n
            {
                p[i]=p2[j2];
                j2++;
            }
        }
    }
    return p;
}

void Task6()
{
    printf("Задание 6\n");
    printf("Введите два массива с неубывающими элементами(a1<=a2<=a3...)\n");
    int i,m,n,*p1,*p2,*p;
    printf("Введите количество элементов массива 1\n");
    scanf("%d",&m);
    p1=(int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
        printf("Введите элемент массива\n");
        scanf("%d",&p1[i]);
    }
    printf("Введите количество элементов массива 2\n");
    scanf("%d",&n);
    p2=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Введите элемент массива\n");
        scanf("%d",&p2[i]);
    }
    p=unite(p1,p2,m,n);
    printf("Массив 1: ");
    for(i=0;i<m;i++)printf("%d ",p1[i]);
    printf("\nМассив 2: ");
    for(i=0;i<n;i++)printf("%d ",p2[i]);
    printf("\nНовый массив: ");
    for(i=0;i<m+n;i++)printf("%d ",p[i]);
    free(p1);
    free(p2);
    free(p);
}

int main()
{
    SetConsoleOutputCP(1251);
    printf("Task 7\n");
    int task;
    do
    {
        printf("Введите номер задания(0-выход,3,5,6)\n");
        scanf("%d",&task);
        switch(task)
        {
        case 0:
            break;
        case 3:
            Task3();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        default:
            printf("Данное задание не выполнено");
            break;
        }
        printf("\n");
    }while(task!=0);
    return 0;
}
