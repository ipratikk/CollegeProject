#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Directory
{
	char filename[100];
	char filetype[30];
	struct Directory *link[100];
}dir;
dir *root=NULL,currentDirectory=NULL;
int main()
{
	int i;
	dir *newfolder;
	newfolder=(dir*)malloc(sizeof(dir));
	strcpy(newfolder->filename,"root");
	strcpy(newfolder->filetype,"folder");
	for(i=0;i<100;i++)
		newfolder->link[i]=NULL;
	root=newfolder;
	currentDirectory = root;
	char input[110];
	char command[5];
	char filename[100];
	printf("File Management Service\n");
	printf("enter \"help\" for help\n");
	scanf("%[^\n]%*c",input);
	extract(input,command,filename);
	while(1)
	{
		if(strcmp(command,"mkdir")==0)
			create(currentDirectory,filename,"folder");
		if(strcmp(command,"file")==0)
			create(currentDirectory,filename,"file");
		if(strcmp(command,"tree")==0)
			display(root);
		
	}
}
void commands()
{
	printf("mkdir <foldername> : making a new folder\n");
	printf("file <filename> : create a new file\n");
	printf("tree : display all the files and folders in the root directory\n");
	printf("ls : display all the files and folders in the current directory\n");
	printf("sd : show current directory\n");
	pritnf("cd <foldername> : change current directory\n");
	printf("cd root : go to root directory\n");
	printf("help : get the list of commands\n");
	printf("exit : to exit the console\n");
}
	
