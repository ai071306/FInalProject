#include"directory.h" 

void input(Node **startPtr)//�ǤJbin�� 
{
	FILE* fp;
	Node *Ptr = NULL;
	List lis[1];
	fp = fopen("./Directory.bin", "r+b");
	if(fp != NULL)/*�P�_�ɮ׫ǧ_Ū�����\*/ 
	{
		fread(lis, sizeof(List), 1, fp);//Ū���Ĥ@���ɮ� 
		while(!feof(fp))//feof �P�_�O�_���ɮ׳̫�@�� 
		{
			printf("%d %s %s %s\n",lis->ID,lis->name,lis->phone,lis->Email);
			fread(lis, sizeof(List), 1, fp);//Ū���Ĥ@�椧�᪺�ɮ� 
		}
	} 
	else 
	{
		printf("File open error!\n");
	}
	fclose(fp);
}
