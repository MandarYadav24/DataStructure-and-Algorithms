#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int Count(PNODE Head);

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
        newn -> next = newn;
        newn -> prev = newn;
    }
    else
    {
        PNODE temp = *Head;

        while(temp -> next != *Head)
        {
            temp = temp -> next;
        }
        newn -> next = *Head;
        (*Head) -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*Head == NULL)
    {
        (*Head) = newn;
        newn -> next = newn;
        newn -> prev = newn;
    }
    else
    {
        PNODE temp = (*Head);
        while(temp -> next != (*Head))
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
        newn -> next = (*Head);
        (*Head) -> prev = newn;
    }
}

void InsertAtPos(PPNODE Head, int iPos, int No)
{
    int iSize = 0;
    int i = 0;
    iSize = Count(*Head);
    if((iPos < 1) || (iPos > iSize + 1))
    {
        printf("Invalid position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(Head,No);
    }
    else
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        if(newn == NULL)
        {
            printf("Unable to allocate memory\n");
            return;
        }
        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;
        PNODE temp = (*Head);

        for(i = 1; i < (iPos - 1); i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next -> prev = newn;
        temp -> next = newn;

    }
}

void DeleteFirst(PPNODE Head)
{
    if (*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == *Head) // single node
    {
        free(*Head);
        *Head = NULL;
    }
    else // more than one node
    {
        PNODE temp = *Head;
        while(temp -> next != *Head)
        {
            temp = temp -> next;
        }
        temp -> next = (*Head) -> next;
        (*Head) -> next -> prev = temp;
        free(*Head);
        *Head = temp -> next;
    }
}

void DeleteLast(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) -> next == (*Head))
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        PNODE temp = (*Head);
        while(temp -> next != (*Head))
        {
            temp = temp -> next;
        }
        temp -> prev -> next = (*Head);
        (*Head) -> prev = temp -> prev;
        free(temp); 
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = 0;
    int i = 0;
    iSize = Count(*Head);
    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE temp = *Head;
        int i = 0;
        for(i = 1; i < (iPos - 1); i++)
        {
            temp = temp -> next;
        }
        PNODE target = temp -> next;
        temp -> next = target -> next;
        target -> next -> prev = temp;
        free(target);
    }
}

void Display(PNODE Head)
{
    if(Head == NULL)
    {
        return;
    }

    PNODE temp = Head;
    do
    {
        printf("|%d|<=>",temp -> data);
        temp = temp -> next;
    }
    while(temp != Head);
    printf("\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    if(Head == NULL)
    {
        return 0;
    }
    PNODE temp = Head;
    do
    {
        iCnt++;
        temp = temp -> next;
    }
    while(temp != Head);
    return iCnt;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,101);
    InsertFirst(&First,51);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&First,151);
    InsertLast(&First,201);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&First,3,75);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&First,1,25);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&First,7,250);
    Display(First); 
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&First,3);
    Display(First);
    iRet = Count(First);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are : %d\n",iRet);

    return 0;
}
