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

