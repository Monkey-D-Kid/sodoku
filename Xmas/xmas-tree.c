#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rec_print_leaf(int height, int size)
{
	if (height == size){
		return;
	}
	else{
		if (height == 0){
			printf("/\\\n");
		} else {
			int width = height * 2;
			char* body = malloc(width * sizeof(char));
			char* left_buf = malloc(height * sizeof(char));
			int i;
			for (i = 0; i < width; i++){
				strcat(body," ");
				if ( (i % 2) == 1 ){
					printf("Enter\n");
					strcat(left_buf," ");
				}
			}
			strcat(left_buf,"/");
			printf("%s%s%s\n",left_buf, body, "\\");
		}
		rec_print_leaf(height + 1, size);
	}
}

void print_left(int height, int size, int leaf){
	int num = size - height;
	int i;
	char *left = malloc(num * sizeof(char));
	for (i = 0; i < num; i++){
		strcat(left," ");
	}
	if(leaf)
		strcat(left,"/");
	else
		strcat(left,"|");
	printf("%s",left);
}


void print_body(int height, int size){
	int width = height * 2, i;
        char* body = malloc(width * sizeof(char));
	char* last;
	if (height == (size - 1))
		last = strdup("_");
	else
		last = strdup(" ");

	for (i = 1; i <= width; i++){
		if(i == height || i == (height+1))
			strcat(body," ");
		else
			strcat(body,last);
	}
	printf("%s",body);
}

void rec_print_leaf_2(int height, int size){
	if (height == size){
		return;
	}else {
		print_left(height,size,1);
		print_body(height,size);
		printf("\\\n");
		rec_print_leaf_2(height+1, size);
	}
}

void print_root(int size){
	int height_of_root = size / 3;
	int i;
	for(i = 0; i < height_of_root; i++)
	{
		print_left(1,size,0);
		printf("  |\n");
	}
}
void main()
{
	int height;
	printf("How height is your xmas-tree :) \n");
	scanf("%d",&height);
	rec_print_leaf_2(0, height);	
	print_root(height);
}
