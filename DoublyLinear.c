#include<stdio.h>
#include<stdlib.h>

struct node
{

        int data;
        struct node * next;
        struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE);

void InsertFirst(PPNODE Head, int iNo)
{
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(*Head == NULL)
        {
                *Head = newn;
        }
        else
        {
                (*Head) -> prev = newn;
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
        newn -> prev = NULL;

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
                newn -> prev = temp;
        }

}

void InsertAtPos(PPNODE Head, int iNo, int iPos)
{
        PNODE newn = NULL;
        PNODE temp = NULL;
        int iSize = 0, iCnt =0;

        iSize = Count(*Head);

        if((iPos < 1) || (iPos > (iSize + 1)))
        {
                printf("Invalid position\n");
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
                newn -> prev = NULL;

                temp = *Head;

                for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
                {
                        temp = temp -> next;
                }

                newn -> prev = temp;
                newn -> next = temp -> next;
                temp -> next -> prev = newn;
                temp -> next = newn;
        }
}

void DeleteFirst(PPNODE Head)
{
        if(*Head == NULL)
        {
                printf("LL is empty\n");
                return;
        }

        if((*Head) -> next == NULL)
        {
                free(*Head);
                *Head = NULL;
        }
        else
        {
                *Head = (*Head) -> next;
                free((*Head) -> prev);
                (*Head) -> prev = NULL;
        }
}

void DeleteLast(PPNODE Head)
{
        PNODE temp = NULL;

        if(*Head == NULL)
        {
                printf("LL is empty\n");
                return;
        }

        if((*Head) -> next == NULL)
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
        PNODE newn = NULL;
        PNODE temp = NULL;
        int iSize = 0, iCnt =0;

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
                temp = *Head;

                for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
                {
                        temp = temp -> next;
                }

                temp -> next = temp -> next -> next;
                free(temp -> next -> prev);
                temp -> next -> prev = temp;
        }
}

void Display(PNODE Head)
{
        printf("Elements from LL are : \n");
        printf("NULL <-> ");
        while(Head != NULL)
        {
                printf("|%d| <-> ",Head -> data);
                Head = Head -> next;
        }

        printf("NULL\n");
}

int Count(PNODE Head)
{
        int iCnt = 0;
        while(Head != NULL)
        {
                iCnt++;
                Head = Head -> next;
        }

        return iCnt;
}

int main()
{
        PNODE First = NULL;
        int iRet = 0;

        InsertFirst(&First,100);
        InsertFirst(&First,90);
        InsertFirst(&First,80);

        Display(First);

        iRet = Count(First);
        printf("Number of elements are : %d\n",iRet);

        InsertLast(&First,110);
        InsertLast(&First,120);
        InsertLast(&First,130);

        Display(First);

        iRet = Count(First);
        printf("Number of elements are : %d\n",iRet);

        DeleteFirst(&First);
        DeleteLast(&First);

        Display(First);

        iRet = Count(First);
        printf("Number of elements are : %d\n",iRet);

        InsertAtPos(&First,105,3);
        InsertAtPos(&First,115,5);

        Display(First);

        iRet = Count(First);
        printf("Number of elements are : %d\n",iRet);

        DeleteAtPos(&First,3);
        DeleteAtPos(&First,5);
//      DeleteAtPos(&First,6);

        Display(First);

        iRet = Count(First);
        printf("Number of elements are : %d\n",iRet);

        return 0;
}



