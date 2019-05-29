#include"directory.h" 

void del(Node **startPtr)//§R°£ 
{
    Node *prePtr, *Ptr;
    int ID;
    printf("Enter the ID :");
    scanf("%d", &ID);

    if(isEmpty(*startPtr))
    {
        printf("There is no data!\n");
    }
	else
	{
        Ptr = *startPtr;
        prePtr = NULL;
        while(Ptr != NULL)
		{
            if(Ptr->directory.ID == ID)
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
            *startPtr = Ptr->nextPtr;
            free(Ptr);
        }
		else if(prePtr != NULL && Ptr->nextPtr != NULL)
		{
            prePtr->nextPtr = Ptr->nextPtr;
            free(Ptr);
        }
		else if(Ptr->nextPtr == NULL)
		{
            prePtr->nextPtr = NULL;
            free(Ptr);
        }
        else
        {
            printf("%d is not in the data!\n", ID);
        }
    }
}
