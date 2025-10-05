#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

// Function Prototypes
void InsertFirst(PPNODE Head, int iNo);
void InsertLast(PPNODE Head, int iNo);
void InsertAtPos(PPNODE Head, int iPos, int iNo);
void DeleteFirst(PPNODE Head);
void DeleteLast(PPNODE Head);
void DeleteAtPos(PPNODE Head, int iPos);
void Display(PNODE Head);
int Count(PNODE Head);

// Insert at first
void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

// Insert at last
void InsertLast(PPNODE Head, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *Head;

    newn->data = iNo;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

// Count nodes
int Count(PNODE Head)
{
    int iCnt = 0;
    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

// Display list
void Display(PNODE Head)
{
    printf("Elements of Linked List are:\n");
    while (Head != NULL)
    {
        printf("| %d | -> ", Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

// Insert at position
void InsertAtPos(PPNODE Head, int iPos, int iNo)
{
    int iSize = Count(*Head);
    PNODE newn = NULL;
    PNODE temp = *Head;
    int iCnt = 0;

    if ((iPos < 1) || (iPos > (iSize + 1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(Head, iNo);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(Head, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

// Delete first node
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        return;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

// Delete last node
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Delete node at position
void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = Count(*Head);
    PNODE temp = *Head;
    PNODE target = NULL;
    int iCnt = 0;

    if ((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if (iPos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

// Main Function
int main()
{
    PNODE First = NULL;
    int choice = 0, position = 0, element = 0;

    while(1)
    {
        printf("\n=== Singly Linked List Operations ===\n");
        printf("1. Insert at First Position\n");
        printf("2. Insert at Last Position\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                InsertFirst(&First, element);
                printf("Element inserted successfully!\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                InsertLast(&First, element);
                printf("Element inserted successfully!\n");
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                InsertAtPos(&First, position, element);
                break;

            case 4:
                DeleteFirst(&First);
                printf("First node deleted successfully!\n");
                break;

            case 5:
                DeleteLast(&First);
                printf("Last node deleted successfully!\n");
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                DeleteAtPos(&First, position);
                break;

            case 7:
                Display(First);
                break;

            case 8:
                printf("Number of nodes: %d\n", Count(First));
                break;

            case 9:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
