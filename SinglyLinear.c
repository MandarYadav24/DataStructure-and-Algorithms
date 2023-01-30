// Singly Linear Linked List.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int CountNode(PNODE);

void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn -> data = iNo;
    newn -> next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn -> data = iNo;
    newn -> next = NULL;
    
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos(PPNODE Head, int iPos, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iSize = 0, iCnt = 0;
    
    iSize = CountNode(*Head);
    
    if((iPos < 1) || (iPos > (iSize + 1)))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(Head,iNo);
    }
    else if(iPos == (iSize + 1))
    {
        InsertLast(Head,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
    
        newn -> data = iNo;
        newn -> next = NULL;
        
        temp = *Head;
        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
    
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = NULL;
    
    if(*Head == NULL)
    {
        printf("No node present\n");
        return;
    }
    else
    {
        temp = *Head;
        *Head = (*Head) -> next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = NULL;
    
    if(*Head == NULL)
    {
        printf("No node present\n");
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        temp = *Head;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    PNODE tempdelete = NULL;
    PNODE temp = NULL;
    int iSize = 0, iCnt = 0;
    
    iSize = CountNode(*Head);
    
    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Position\n");
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
        temp = *Head;
        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        
        tempdelete = temp -> next;
        temp -> next = temp -> next -> next;
        free(tempdelete);
        
    }
}

void Display(PNODE Head)
{
    printf("Elements from LL are : \n");
    while(Head != NULL)
    {
        printf("|%d|->",Head -> data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

int CountNode(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}

int main() {
    PNODE First = NULL;
    int iRet = 0;
    
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
   
    InsertLast(&First,111); 
    InsertLast(&First,121);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
    
    InsertAtPos(&First,2,61);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
    
    DeleteFirst(&First);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
    
    DeleteLast(&First);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
    
    DeleteAtPos(&First,1);
    Display(First);
    
    iRet = CountNode(First);
    printf("Number of elements are : %d\n",iRet);
    
    return 0;
}
