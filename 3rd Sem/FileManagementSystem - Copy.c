/************************* File Management System *********************************/
/* Problem Statement

The system should follow the working principle of ‘ls’ command in Linux Operating system. It
should be able to show the files, folders under the current directory. The user should be able to
add file, folders under specific folder. If the folder under which the user want to add the files do
not exist, it should be created first and then the files/folders should be added. Use tree data
structure to implement the system. Please note that this files or folders mentioned above need not
to be created physically. Storing the names would be sufficient.

*/
/*************************************************************************************/

/*Solution*/

/* @Project by Pratik Goel */

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
void commands();								//displays all commands
void folder(dir *, char [], char []);			//creates new file/folder in the current directory 
void display(dir *, int);						//displays all the files and folders recursively
void ls(dir *);									//displays the contents of current directory
bool alreadyExists(dir *, char [], char []);	//checks if a given file/folder already exists in the current directory
void showCurrentDirectory(dir *);				//shows the name of thecurrent directory
void changeCurrentDirectory(dir *, char []);	//changes the working directory
void setRoot();									//sets current directory to the root folder
dir *root = NULL;		//the root directory
dir *currentDirectory;	//the current directory
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
	char command[10];
	char filename[100];
	printf("File Management Service\n");
	printf("enter \"help all\" for help\n");
	scanf("%s%s",command,filename);
	while(1)
	{
		if(strcmp(command, "mkdir") == 0)
			folder(currentDirectory, filename, "folder");
		else if(strcmp(command, "file") == 0)
			folder(currentDirectory, filename, "file");
		else if(strcmp(command, "tree") == 0)
		{
			printf("\n");
			display(root, 0);
			printf("\n");
		}
		else if(strcmp(command, "ls") == 0)
		{
			printf("\n");
			display(currentDirectory,0);
			printf("\n");
		}
		else if(strcmp(command, "sd") == 0)
			showCurrentDirectory(currentDirectory);
		else if(strcmp(command, "cd") == 0)
			changeCurrentDirectory(currentDirectory, filename);
		else if(strcmp(command, "help") == 0)
			commands();
		else if(strcmp(command, "exit") == 0)
			exit(0);
		else
			printf("Invalid command.\n");
		scanf("%s%s",command,filename);
	}
	return 0;
}
void commands()
{
	printf("mkdir <foldername> : making a new folder\n");
	printf("file <filename> : create a new file\n");
	printf("tree al : display all the files and folders in the root directory\n");
	printf("ls -al : display all the files and folders in the current directory\n");
	printf("sd view: show current directory\n");
	printf("cd <foldername> : change current directory\n");
	printf("cd root : go to root directory\n");
	printf("help all: get the list of commands\n");
	printf("exit 0: to exit the console\n");
	printf("Commands are specific to this program and not to be confused with DOS/Linux terminal commands\n");
	printf("fol:represents a folder\n");
	printf("fil:represents a file\n\n");
}
void folder(dir *temp, char filename[30], char filetype[10])
{
	//check for duplicate filename
	if(alreadyExists(temp, filename, filetype))
	{
		printf("A %s with this name already exists.\n", filetype);
		return;
	}
	int i = 0;
	//loop to enter the first link which is set to NULL
	for(i=0; i<100; i++)
		if(temp->link[i] == NULL)
			break;
	dir *nf;	//new file/folder
	nf = (dir*) malloc(sizeof(dir));
	temp->link[i] = nf;	//link the new folder to ith position of temp's link
	strcpy(nf->filetype, filetype);	//copy the filetype to nf
	strcpy(nf->filename, filename);	//copy the filename to nf
	//set new file/folders links to NULL
	for(i=0; i<100; i++)
		nf->link[i] = NULL;
	printf("%s has been successfully created under %s\n", nf->filename, temp->filename);
}
void ls(dir *temp)
{
	int i;	//loop variable
	for(i=0; i<100 && temp->link[i] != NULL; i++)
		printf("%s\t", temp->link[i]->filename);
	printf("\n");
}
void display(dir *temp, int level)
{
    if(temp == NULL)
        return;
	int i;	//loop variable
	//call all the subdirectories/files recursively
	for(i=0; i<100 && temp->link[i] != NULL; i++)
	{
		//display(temp->link[i], level+1);	//increment level to print more dashes
		//print 'fol:' for folders
		if(strcmp(temp->filetype, "folder") == 0)
			printf("fol: ");
		//print 'fil:' for files
		else if(strcmp(temp->filetype, "file") == 0)
			printf("fil: ");
		printf("%s\n", temp->filename);
	}
}
bool alreadyExists(dir *temp, char name[30], char type[6])
{
	int i;
	for(i=0; i<100 && temp->link[i] != NULL; i++)
		if(strcmp(temp->link[i]->filetype, type) == 0)
			if(strcmp(temp->link[i]->filename, name) == 0)
				return true;
	return false;
}
void showCurrentDirectory(dir *cur)
{
    printf("The current directory is: %s\n", cur->filename);
}
void changeCurrentDirectory(dir *temp, char foldername[30])
{
	//to set current directory to "root"
	if(strcmp(foldername, "root") == 0)
	{
		setRoot();
		showCurrentDirectory(currentDirectory);
		return;
	}
	int i; //loop variable
	bool found = false;
	for(i=0; i<100 && temp->link[i] != NULL; i++)
	{
		if(strcmp(temp->link[i]->filetype, "folder") == 0)
			if(strcmp(temp->link[i]->filename, foldername) == 0)
			{
				found = true;
				currentDirectory = temp->link[i];
				break;
			}
	}
	//if directory does not exist, create one and set current directory to it
	if(found == false)
	{
		printf("Directory not found. Creating new directory.\n");
		folder(currentDirectory, foldername, "folder");
		changeCurrentDirectory(currentDirectory, foldername);
		return;
	}
	showCurrentDirectory(currentDirectory);
}
void setRoot()
{
	currentDirectory = root;
}
