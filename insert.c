#include"directory.h" 

void insert(Node **startPtr)//·s¼W 
{
    Node *newnode, *Ptr, *prePtr;

    newnode = (Node*)malloc(sizeof(Node));

    printf("Enter ID : ");
    scanf("%d", &newnode->directory.ID);

    printf("Enter Name : ");
    scanf("%s", newnode->directory.name);

    printf("Enter Phone : ");
    scanf("%s", newnode->directory.phone);

    printf("Enter E-mail : ");
    scanf("%s", newnode->directory.Email);
    newnode->nextPtr = NULL;

    if(isEmpty(*startPtr))
    {
        *startPtr = newnode;
    }
	else
	{
        prePtr = NULL;
        Ptr = *startPtr;
        while(Ptr != NULL)
        {
            if(Ptr->directory.ID >= newnode->directory.ID)
            {
                break;
            }
			else
			{
                prePtr = Ptr;
                Ptr = Ptr->nextPtr;
            }
        }
        if(prePtr == NULL)
        {
            newnode->nextPtr = Ptr;
            *startPtr = newnode;
        }
		else if(prePtr != NULL && Ptr != NULL)
		{
            newnode->nextPtr = Ptr;
            prePtr->nextPtr = newnode;
        }
		else
		{
            prePtr->nextPtr = newnode;
        }
    }
}
