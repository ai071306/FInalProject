#include"directory.h" 

void output(Node **startPtr)//輸出bin檔
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
