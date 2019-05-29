#include"directory.h" 

void input(Node **startPtr)//傳入bin檔 
{
	FILE* fp;
	Node *Ptr = NULL;
	List lis[1];
	fp = fopen("./Directory.bin", "r+b");
	if(fp != NULL)/*判斷檔案室否讀取成功*/ 
	{
		fread(lis, sizeof(List), 1, fp);//讀取第一行檔案 
		while(!feof(fp))//feof 判斷是否為檔案最後一行 
		{
			printf("%d %s %s %s\n",lis->ID,lis->name,lis->phone,lis->Email);
			fread(lis, sizeof(List), 1, fp);//讀取第一行之後的檔案 
		}
	} 
	else 
	{
		printf("File open error!\n");
	}
	fclose(fp);
}
