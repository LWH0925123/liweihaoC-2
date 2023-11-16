#include<stdio.h>
#include<stdlib.h>

int Count;
struct Clerk
{
    char Name[100];
    int Number;
    struct Clerk *Next;
};

struct Clerk *Create()
{
    struct Clerk *Head=NULL;
    struct Clerk *End,*New;
    Count=0;
    End=New=(struct Clerk*)malloc(sizeof(struct Clerk));
    printf("输入第一个名称与序号\n");
    scanf("%s",&New->Name);
    scanf("%d",&New->Number);
    while(New->Number!=0)
    {
        Count++;
        if(Count==1)
        {
            New->Next=Head;
            End=New;
            Head=New;
        }
        else
        {
            New->Next=NULL;
            End->Next=New;
            End=New;
        }
        New=(struct Clerk*)malloc(sizeof(struct Clerk));
        scanf("%s",&New->Name);
        scanf("%d",&New->Number);
    }
    free(New);
    return Head;
}

struct Clerk *Insert(struct Clerk *Head)
{
    struct Clerk *New;
    New=(struct Clerk*)malloc(sizeof(struct Clerk));
    scanf("%S",&New->Name);
    scanf("%d",&New->Number);
    New->Next=Head;
    Head=New;
    Count++;
    return Head;
}

void Delete(struct Clerk *Head,int Index)
{
    int i;
    struct Clerk *Temp;
    struct Clerk *Pre;
    Temp=Head;
    Pre=Temp;
    for(i=1;i<Index;i++)
    {
        Pre=Temp;
        Temp=Temp->Next;
    }
    Pre->Next=Temp->Next;
    free(Temp);
    Count--;
}

void print(struct Clerk *Head)
{
    struct Clerk *Temp;
    int Index=1;
    Temp=Head;
    while(Temp!=NULL)
    {
        printf("%d ",Index);
        printf("%s ",Temp->Name);
        printf("%d\n",Temp->Number);
        Temp=Temp->Next;
        Index++;
    }
}
