/*Name:Max Grubb
 * Assignment 5
 * Authored by CS professors and edited by Max Grubb
 * 11/23/2015
 * main.c to do list main file
 * ***********************************************/ 


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"

void openFile(DynArr *arr ){
	char file[20];
 	FILE *fp; 		
	printf("Please enter your filename: \n");
	scanf("%s", file);  	
	while(getchar() != '\n'); 	
	fp = fopen(file, "r");
	loadList(arr, fp);
	printf("The list has been loaded successfully!\n");
	fclose(fp); 	
}


void outFile(DynArr *arr ){
	char file[20];
 	FILE *ft; 		
	printf("Please enter your filename: \n");
	scanf("%s", file);  	
	while(getchar() != '\n'); 	
	ft = fopen(file, "w");
	saveList(arr, ft);

	if(ft == NULL) {
		printf("Cannot open the file\n"); 
	}	
	else
		printf("The list has been saved successfully!\n");
	
}


void removeList(DynArr *arr){

	if(sizeDynArr(arr) == 0)
		printf("The list is empty"); 
	else
		removeMinHeap(arr, compare);

}

void addToList(DynArr *arr){

	char task[20];
	int prio;
 	printf("Please enter your task: \n");
	scanf("%s", task);  	
	while(getchar() != '\n'); 	

 	printf("Please enter your task's priority: \n");
	scanf("%i", &prio);  	
	while(getchar() != '\n'); 	
	
	addHeap(arr, createTask(prio, task), compare);


}

void getFront(DynArr *arr){
	
	struct Task* temp;
	if(sizeDynArr(arr) > 0){
	temp = getMinHeap(arr);
	printf("Your first task is: %s\n\n", temp->description);	
	free(temp);	
	}
	else 
		printf("The list is empty\n"); 

}

void printTheList(DynArr *arr){

 	printList(arr);
	
}

int main (int argc, const char * argv[])
{
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);
 

	printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */

	switch(cmd){
		case 'l': openFile(mainList);		
			printf("%i\n", sizeDynArr(mainList));
			break; 
		case 's': outFile(mainList); 
			break;
		case 'a':addToList(mainList); 
				break;
		case 'g': getFront(mainList);
	 		break;
		case 'r':removeList(mainList);
 			break;
		case 'p':printTheList(mainList);  
			break;
			
 
	}

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
