#include"directory.h" 

void search(Node **startPtr)//´M§ä 
{
	Node *Ptr ;
	Ptr = *startPtr;
    int m;
    char *name, *phone;
    name = (char *)malloc(sizeof(char));
    phone = (char *)malloc(sizeof(char));
    printf("1.Enter the Name\n");
    printf("2.Enter the Phone\n");  
    scanf("%d", &m);

    switch(m)
    {
	case 1:
		printf("1.Enter the Name :");
		scanf("%s",name);
		if(isEmpty(*startPtr))
        {
           printf("%s is not int the data!\n", name);
        }
        else
        {
        	while(Ptr != NULL)
            {
            	if(strcmp(Ptr->directory.name,name)==0)
            	{
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
            		break;
           		}
           		else
           		{
           		    Ptr=Ptr->nextPtr;
				}
            }
		}
		break;

	case 2:
		printf("1.Enter the Phone :");
		scanf("%s",phone);
		if(isEmpty(*startPtr))
        {
           printf("%s is not int the data!\n", phone);
        }
        else
        {
        	while(Ptr != NULL)
            {
            	if(strcmp(Ptr->directory.phone,phone)==0)
            	{
            		printf("ID : %d\n", Ptr->directory.ID);
            		printf("Name : %s\n", Ptr->directory.name);
            		printf("Phone : %s\n", Ptr->directory.phone);
            		printf("Email : %s\n\n", Ptr->directory.Email);
            		break;
           		}
           		else
           		{
           		    Ptr=Ptr->nextPtr;
				}
            }
		}
	}
}
