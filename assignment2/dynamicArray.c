 
/* CS261- dynamicArray.c: Dynamic Array implementation.
* Name: Max Grubb
 * Date: 10/16/2015
 * Solution description: implements Dynamic Array Functions*/
#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"
#include <stdio.h>

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/

DynArr* newDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/

void _dynArrSetCapacty(DynArr *v, int newCap)
{	
	assert(newCap > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * newCap);
	assert(v!= 0);
	v->size = v->size;
	v->capacity = newCap;	
}


/*
 Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array

*/

int sizeDynArr(DynArr *v)
{
	return v->size;
}

/*

 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/


void addDynArr(DynArr *v, TYPE val)
{
	
	assert(v->capacity > 0);
	assert(v != 0);
	if(v->size == v->capacity)
	{
		DynArr *w = newDynArr((v->capacity*2));
		
		int n; 
		for(n = 0; n < v->size; n++)
		{
			w->data[n] = v->data[n];
		}
		
		_dynArrSetCapacty(v, (v->capacity*2));
		for(n = 0; n < v->size; n++)
		{
			v->data[n] = w->data[n];
		}
		deleteDynArr(w); 				
		v->data[v->size] = val; 
		v->size = v->size + 1;
	}

	else{

		v->data[v->size] = val; 
		v->size = v->size + 1;
	}

}
	



/*
	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	assert(v->capacity > 0);
	assert(v!= 0);
	assert(pos < v->size);
	assert(pos >= 0);

	return v->data[pos]; 
}

/*
	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val

*/
void putDynArr(DynArr *v, int pos, TYPE val)
{

	assert(v->capacity > 0);
	assert(v!= 0);
	assert(pos < v->size);
	assert(pos >= 0);

	v->data[pos] = val;

}

/*
	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/


void swapDynArr(DynArr *v, int i, int  j)
{


	int p = v->data[i];
	int q = v->data[j]; 
	
	assert(v->capacity > 0);
	assert(v!= 0);
	assert(i >= 0);
	assert(j >= 0); 
	assert(i < v->size);
	assert(j < v->size);

   
	v->data[i] = q; 
	v->data[j] = p; 

}


/*

	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one

*/

void removeAtDynArr(DynArr *v, int idx)
{
	assert(v->capacity > 0);
	assert(v!= 0);
	assert(idx >= 0); 
	assert(idx < v->size);



	while(idx < v->size)
	{
		v->data[idx] = v->data[idx + 1]; 
		idx++; 	
	}

	 
	DynArr *w = newDynArr((v->capacity-1));
		
		int n; 
		for(n = 0; n < v->size; n++)
		{
			w->data[n] = v->data[n];
		}
		
		_dynArrSetCapacty(v, (v->capacity-1));
		for(n = 0; n < v->size; n++)
		{
			v->data[n] = w->data[n];
		}
		deleteDynArr(w); 				
		v->size = v->size - 1;

}

/*
void printDynArr(DynArr *v){
	
	int x;

	for(x = 0; x < v->size; x++)
	{
		printf("position return val: %i\n", getDynArr(v, x));
	} 

}
*/

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */


/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/

void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	assert(v->capacity > 0);
	assert(v != 0);
	if(v->size == v->capacity)
	{
		DynArr *w = newDynArr((v->capacity*2));
		
		int n; 
		for(n = 0; n < v->size; n++)
		{
			w->data[n] = v->data[n];
		}
		
		_dynArrSetCapacty(v, (v->capacity*2));
		for(n = 0; n < v->size; n++)
		{
			v->data[n] = w->data[n];
		}
		deleteDynArr(w); 				
		v->data[v->size] = val; 
		v->size = v->size + 1;
	}

	else{

		v->data[v->size] = val; 
		v->size = v->size + 1;
	}

}



/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/


TYPE topDynArr(DynArr *v)
{
	return v->data[v->size-1];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/


void popDynArr(DynArr *v)
{

	assert(v->capacity != 0);
	if(v->capacity > 1){
	DynArr *w = newDynArr((v->capacity-1));
		
		int n; 
		for(n = 0; n < v->size; n++)
		{
			w->data[n] = v->data[n];
		}
		
		_dynArrSetCapacty(v, (v->capacity-1));
		for(n = 0; n < v->size; n++)
		{
			v->data[n] = w->data[n];
		}
		deleteDynArr(w); 				
		v->size = v->size - 1;
	}	
	else 
	{
//		printf("Stack is empty\n"); 
		v->size = 0;   
	}
	/* FIXME: You will write this function */

}


/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/

int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */

	if(v->size == 0)
	{	return 1;} 
	else 
	{	return 0; }
	
	/* FIXME:  You will change this return value*/

//	return 1;
}

/*
int main(){

	DynArr grubbRay; 
//	TYPE t = topDynArr(&grubbRay); 
	initDynArr(&grubbRay, 1); 

	printf("Size is %i\n", grubbRay.size); 
	pushDynArr(&grubbRay, 5);
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	pushDynArr(&grubbRay, 4);
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	pushDynArr(&grubbRay, 3);
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	pushDynArr(&grubbRay, 2);
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n\n", grubbRay.size); 

	if(containsDynArr(&grubbRay, 5))
	{
		printf("Array contains your value\n");
	}
	else
	{
		printf("Array does not contain your value\n");
	}

	popDynArr(&grubbRay); //top is two   
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	popDynArr(&grubbRay);  //top is three
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	popDynArr(&grubbRay);  //top is four
	printf("Top is %i\n", topDynArr(&grubbRay));   
	printf("Size is %i\n", grubbRay.size); 
	popDynArr(&grubbRay);  //top is five
	printf("Capacity is %i\n", grubbRay.capacity); 
	printf("Size is %i\n", grubbRay.size); 


	if(isEmptyDynArr(&grubbRay))
	{
		printf("Is Empty Funct!"); 
	}
	else
	{
		printf("Not Empty!"); 
	}
*/
//	printf("Top is %i\n", topDynArr(&grubbRay));   
/*
	int r, t, s; 	 

	initDynArr(&grubbRay, 2); 		
	s = grubbRay.capacity; 
	printf("capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("size is: %i\n", t);
	printf("\n\n\n"); 
 

	addDynArr(&grubbRay, 15);	
	s = grubbRay.capacity; 
	printf("Add 1 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 1 size is: %i\n", t);
	r = getDynArr(&grubbRay, 0);
	printf("position return val: %i\n", r);
 

	addDynArr(&grubbRay, 20);	
	s = grubbRay.capacity; 
	printf("Add 2 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 2 size is: %i\n", t);
	r = getDynArr(&grubbRay, 1);
	printf("position return val: %i\n", r);

	
	addDynArr(&grubbRay, 25);	
	s = grubbRay.capacity; 
	printf("Add 3 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 3 size is: %i\n", t);

	addDynArr(&grubbRay, 30);	
	s = grubbRay.capacity; 

	printf("Add 3 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 3 size is: %i\n", t);

	addDynArr(&grubbRay, 35);	
	s = grubbRay.capacity; 
	printf("Add 3 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 3 size is: %i\n", t);


	addDynArr(&grubbRay, 40);	
	s = grubbRay.capacity; 
	printf("Add 3 capacity = %i\n", s);
	t = sizeDynArr(&grubbRay); 
	printf("Add 3 size is: %i\n", t);


	printDynArr(&grubbRay); 


	printf("\n\ntesting section: \n\n");
	
		printf("Swap:\n"); 

			swapDynArr(&grubbRay, 2, 3); 

			printDynArr(&grubbRay); 

		printf("\nPut:\n"); 
	
			putDynArr(&grubbRay, 3, 77);

			printDynArr(&grubbRay); 
	
	
			t = sizeDynArr(&grubbRay); 
			printf("size is: %i\n", t);


		printf("\nInsert:\n"); 

			removeAtDynArr(&grubbRay, 0);

			printDynArr(&grubbRay); 


	if(containsDynArr(&grubbRay, 77))
	{
		printf("Array contains your value\n");
	}
	else
	{
		printf("Array does not contain your value\n");
	}

	removeDynArr(&grubbRay, 77); 
	printDynArr(&grubbRay); 
	removeDynArr(&grubbRay, 77); 
	printDynArr(&grubbRay); 
	removeDynArr(&grubbRay, 77); 
	printDynArr(&grubbRay); 
	return 0; 



}



*/



/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/

int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	int n; 
	for(n = 0; n < v->size; n++)
	{	
		if(v->data[n] == val)
		{	return 1; }

	}	
	/* FIXME:  You will change this return value */
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	
	assert(v->capacity > 0);
	assert(v!= 0);
//	assert(idx >= 0); 
//	assert(idx < v->size);

	int x; 
	int y;
	for(x = 0; x < v->size; x++)
	{	
		
		if(v->data[x] == val)
		{	
			y = x; 		
			while(y < v->size)
			{
				v->data[y] = v->data[y + 1]; 
				y++; 	
			}
		
	 
	DynArr *w = newDynArr((v->capacity-1));
		
		int n; 
		for(n = 0; n < v->size; n++)
		{
			w->data[n] = v->data[n];
		}
		
		_dynArrSetCapacty(v, (v->capacity-1));
		for(n = 0; n < v->size; n++)
		{
			v->data[n] = w->data[n];
		}
		deleteDynArr(w); 				
		v->size = v->size - 1;
	}
	}
	

/* FIXME: You will write this function */
}






