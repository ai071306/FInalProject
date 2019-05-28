#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list{
    int ID;
    char name[30];
    char phone[30];
    char Email[50];
};
typedef struct list List;

struct node{
	List directory;
    struct node *nextPtr;
};
typedef struct node Node; 

int isEmpty(Node *startPtr);

void printList(Node **startPtr);

void insert(Node **startPtr);

void del(Node **startPtr);

void search(Node **startPtr);

void modify(Node **startPtr);

void clear(Node **startPtr);

void output(Node **startPtr);

void input(Node **startPtr);

int main()
{
    Node *startPtr = NULL;
    int choice;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete \n");
        printf("3.Print\n");
        printf("4.Search\n");
        printf("5.Modify\n");
        printf("6.Clear All\n");
        printf("7.Input bin\n");
        printf("8.Output bin\n");
        scanf("%d", &choice);
        system("CLS");
        switch(choice)
        {
            case 1:
                insert(&startPtr);
                break;
            case 2:
                del(&startPtr);
                break;
            case 3:
                printList(&startPtr);
                break;
            case 4:
            	search(&startPtr);
            	break;
            case 5:
            	modify(&startPtr);
            	break;
            case 6:
                clear(&startPtr);
                break;
            case 7:
                input(&startPtr);
                break;
            case 8:
            	output(&startPtr);
            	break;
        }
    }
}

int isEmpty(Node *startPtr)
{
    if(startPtr == NULL)
    {
        return 1;
    }
    return 0;
}

void printList(Node **startPtr)
{
    Node *Ptr;
    Ptr = *startPtr;
    if(isEmpty(Ptr))
    {
        printf("There is no data!\n");
    }
    else
	{
        while(!isEmpty(Ptr))
        {
            printf("ID : %d\n", Ptr->directory.ID);
            printf("Name : %s\n", Ptr->directory.name);
            printf("Phone : %s\n", Ptr->directory.phone);
            printf("Email : %s\n\n", Ptr->directory.Email);
            Ptr = Ptr->nextPtr;
        }
    }
}

void insert(Node **startPtr)
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

void del(Node **startPtr)
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

void search(Node **startPtr)
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

void modify(Node **startPtr)
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

void clear(Node **startPtr)
{
    *startPtr = NULL;
}

void output(Node **startPtr)
{
	FILE* fp;
	fp = fopen("./Directory.bin", "w+b");
	Node *Ptr;
    Ptr = *startPtr;
	if(fp != NULL) 
	{	
		while(!isEmpty(Ptr))
    	{
    		fwrite(Ptr, sizeof(List), 1, fp);
			Ptr = Ptr->nextPtr;
    	}
	} 
	else 
	{
	  	printf("File open error!\n");
	}
	fclose(fp);
}

void input(Node **startPtr)
{
	FILE* fp;
	Node *Ptr = NULL;
	List lis[1];
	fp = fopen("./Directory.bin", "r+b");
	if(fp != NULL) 
	{
		fread(lis, sizeof(List), 1, fp);
		while(!feof(fp))
		{
			printf("%d %s %s %s\n",lis->ID,lis->name,lis->phone,lis->Email);
			fread(lis, sizeof(List), 1, fp);
		}
	} 
	else 
	{
		printf("File open error!\n");
	}
	fclose(fp);
}
