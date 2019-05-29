#include"directory.h" 

void modify(Node **startPtr)//н╫зя 
{
	Node *Ptr;
	Ptr = *startPtr;
    int m;
    char *name, *phone ,*Email;
    name = (char *)malloc(sizeof(char)*30);
    phone = (char *)malloc(sizeof(char)*30);
    Email = (char *)malloc(sizeof(char)*50);
	printf("1.modify the Name\n");
	printf("2.modify the Phone\n");
	printf("3.modify the Email\n");
	scanf("%d", &m);
	
	if(m == 1)
	{
		printf("1.Enter the Name :");
		scanf("%s",name);
		if(isEmpty(*startPtr))
        {
            printf("There is no data!\n");
        }
        else
        {
        	while(Ptr != NULL)
            {
            	if(!strcmp(Ptr->directory.name,name))
            	{
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
            		printf("Enter the New Name :");
					scanf("%s",name);
					strcpy(Ptr->directory.name,name);
					printf("After Modify:\n");
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
                    return;
           		}
           		else
           		{
           		    Ptr=Ptr->nextPtr;
				}
            }
            if(Ptr == NULL)
            {
                printf("Name: %s is not int the data!\n", name);
            }
		}

	}
	if(m == 2)
	{
		printf("1.Enter the Phone :");
		scanf("%s",phone);
		if(isEmpty(*startPtr))
        {
            printf("There is no data!\n");
        }
        else
        {
        	while(Ptr != NULL)
            {
            	if(!strcmp(Ptr->directory.phone,phone))
            	{
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
            		printf("Enter the New Phone :");
					scanf("%s",phone);
					strcpy(Ptr->directory.phone,phone);
                    printf("After Modify:\n");
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
					return;
           		}
           		else
           		{
           		    Ptr=Ptr->nextPtr;
				}
            }
            if(Ptr == NULL)
            {
                printf("Phone: %s is not int the data!\n", phone);
            }
		}
	}
	if(m == 3)
	{
		printf("1.Enter the Email :");
		scanf("%s",Email);
		if(isEmpty(*startPtr))
        {
            printf("There is no data!\n");
        }
        else
        {
        	while(Ptr != NULL)
            {
            	if(!strcmp(Ptr->directory.Email,Email))
            	{
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
            		printf("Enter the New Email :");
					scanf("%s",Email);
					strcpy(Ptr->directory.Email,Email);
                    printf("After Modify:\n");
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
					return;
           		}
           		else
           		{
           		    Ptr=Ptr->nextPtr;
				}
            }
            if(Ptr == NULL)
            {
                printf("Email: %s is not int the data!\n", Email);
            }
		}
	}
}
