/* CS261- linkedList.c: Linked List Implementation.
* Name: Max Grubb
 * Date: 10/25/2015
 * Solution description: implements Linked List Functions*/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {

	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink); 
	lst->firstLink->next = lst->lastLink; 
	lst->lastLink->prev = lst->firstLink; 
	lst->size = 0;
	
  /* FIXME: you must write this */
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{

	struct DLink *temp = malloc(sizeof(struct DLink));
	temp->value = v;

	if((lst->firstLink->next == lst->lastLink) && (lst->lastLink->prev == lst->firstLink))
	{
		temp->prev = lst->firstLink;
		temp->next = lst->lastLink;
		lst->lastLink->prev = temp; 
		lst->firstLink->next = temp; 
		lst->size = lst->size + 1;
	}		



	else{
		   
	 	if(l == lst->firstLink->next)
		{
		
			l->prev = temp; 
			temp->next = l; 
			temp->prev = lst->firstLink; 
			lst->firstLink->next = temp; 
			lst->size = lst->size + 1;
		}

		else if (l == lst->lastLink)
		{
				
			l->prev->next = temp;  	
			temp->next = lst->lastLink; 
			temp->prev = lst->lastLink->prev; 
			lst->lastLink->prev = temp; 
			lst->size = lst->size + 1;
					

		}

	}

	/* FIXME: you must write this */

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
	_addLinkBefore(lst, lst->firstLink->next, e); 

	/* FIXME: you must write this */
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	_addLinkBefore(lst, lst->lastLink, e); 

	/* FIXME: you must write this */
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {


	
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	return lst->lastLink->prev->value;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	
	if(isEmptyList(lst)){
		printf("The list is empty\n");
	}
	else{	 

		if(l == lst->firstLink->next)
		{
			l = l->next; 
			l->prev = lst->firstLink;; 
			lst->firstLink->next =	l;  		
			lst->size = lst->size - 1; 
		 }		
		else if(l == lst->lastLink->prev)
		{
			l = l->prev; 
			l->next = lst->lastLink;
			lst->lastLink->prev = l;
			lst->size = lst->size - 1; 
		}
   			
	}
	
	/* FIXME: you must write this */
	
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {

   	_removeLink(lst, lst->firstLink->next);


/* FIXME: you must write this */

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
   	_removeLink(lst, lst->lastLink->prev);
	/* FIXME: you must write this */
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	
	if(lst->size == 0)
	{
		return 1; 
	}
	else
	{
		return 0;
	}
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{

	struct DLink *temp = malloc(sizeof(struct DLink));
	if(isEmptyList(lst))
	{
	printf("The list is empty.\n");
	}
	else{	

	for(temp = lst->firstLink->next; temp != lst->lastLink; temp = temp->next)
	{

		printf("%i\n", temp->value); 

				
  	}

/*		while(p < n)
		{

			printf("%i\n", frontList(lst));
			addBackList(lst, frontList(lst)); 	
			removeFrontList(lst);
			p++; 
		}*/

	/* FIXME: you must write this */

	}

}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	addFrontList(lst, v); 

	/* FIXME: you must write this */

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {


	

	struct DLink *temp = malloc(sizeof(struct DLink));
	 

	for(temp = lst->firstLink->next; temp != lst->lastLink; temp = temp->next)
	{

		if(temp->value == e)
			return 1; 
				
  	}
	return 0;
}
/*


	int n = lst->size; 
	int p; 

		for(p = 0; p < n; p++)
			
		
							
 
 				if(frontList(lst) == e)
				{
					return 1; 	 	
				}
				else{
				addBackList(lst, frontList(lst)); 	
				removeFrontList(lst);
				} 
*/			
	


/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {

	struct DLink *temp = malloc(sizeof(struct DLink));
	 

	for(temp = lst->firstLink->next; temp != lst->lastLink; temp = temp->next)
	{

			if(temp->value == e)
			{
				temp->prev->next = temp->next; 
				temp->next->prev = temp->prev; 
			}
	}


}

