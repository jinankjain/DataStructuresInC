#include<stdio.h>
#include<stdlib.h>
struct List
{
    int value;
    struct List *next;
};

struct List *head;
struct List *curr;

void insertAtEnd(int val);
void insertAfter(int val,int pos);
void deleteByPosition(int pos);
int listLength();
void printList();

void insertAtEnd(int val)
{
    struct List *temp = malloc(sizeof(struct List));
    if(head==NULL)
    {
        temp->value = val;
        temp->next = NULL;
        curr = temp;
        head = temp;
    }else
    {
        temp->value = val;
        temp->next = NULL;
        curr = temp;
    }
}


void insertAfter(int val,int pos)
{
    struct List *temp = malloc(sizeof(struct List));
    struct List *p = malloc(sizeof(struct List));
    p->value = val;
    temp = head;
    while(temp!=NULL && temp->value!=pos)
    {
        temp = temp->next;
    }
    if(temp==NULL && pos!=0)
    {
        printf("Invalid position such number does not exist in List\n");
    }else if(temp==NULL && pos==0)
    {
        p->next = NULL;
        head = p;
    }else
    {
        p->next = temp->next;
        temp->next = p;
    }
}

void deleteByPosition(int pos)
{
    if(pos>0)
    {
        struct List *temp = malloc(sizeof(struct List));
        temp = head;
        int cnt = 1;
        while(cnt<(pos-1) && temp!=NULL)
        {
            temp = temp->next;
            cnt++;
        }
        if(pos==1)
        {
            head = head->next;
        }
        else if(temp==NULL || temp->next==NULL)
        {
            printf("Position out of bounds\n");
        }else
        {
            temp->next = temp->next->next;
        }
    }else
    {
        printf("Enter a position greater than 0\n");
    }
}

int listLength()
{
    struct List *temp = malloc(sizeof(struct List));
    temp = head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp = temp->next;
        cnt++;
    }
    printf("%d\n",cnt);
    return cnt;
}

void printList()
{
    struct List *temp = head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\n", temp->value);
            temp = temp->next;
        }
    }
}



int main()
{
    //Mock Test Run
    insertAfter(10,NULL);
    insertAfter(20,10);
    insertAfter(10,10);
    listLength();
    deleteByPosition(0);
    printList();

    return 0;
}
