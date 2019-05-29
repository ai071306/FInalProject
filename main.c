#include "directory.h"

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
        printf("7.Output bin\n");
        printf("8.Input bin\n");
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
                output(&startPtr);
                break;
            case 8:
            	input(&startPtr);
            	break;
        }
    }
}
