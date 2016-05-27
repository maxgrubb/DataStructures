/* hashMap.c
 * Max Grubb 
 * 11/29/2015
 * hash table implementation file */
  

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)

{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/		
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/

void _setTableSize(struct hashMap * ht, int newTableSize)
{
	assert(newTableSize > 0); 
	assert(ht != 0); 
	ht->table = malloc(sizeof(hashLink) * newTableSize); 
	assert( ht != 0); 
	ht->tableSize = ht->tableSize;

/*write this*/			
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  

	float lf; 
	lf = tableLoad(ht); 
	 
	int index; 
	index = stringHash1(k) %  (ht->count + 1); 		

	  
	hashLink *temp = malloc(sizeof(hashLink));
	hashLink *newLink = malloc(sizeof(hashLink));  
	if(containsKey(ht, k) == 1){
				
		temp = ht->table[index]; 
		 	
		while(temp != 0){			
			if(k == temp->key)
			{
				temp->value = temp->value + 1; 
				ht->count++;	
			}
					
			temp=temp->next;
					
		}		
}	
	else{
		newLink->key = k;
		newLink->value = v;
		newLink->next = NULL;  
		temp = ht->table[index]; 

		//ht->table[index] = newLink;  
	//	ht->count++; 

		if(ht->table[index] == 0){
		//	newLink->next = NULL; 
			ht->table[index] = newLink;  
			ht->count++; 
		}
		else{
			
		while(temp != 0){			
			
			if(temp->next == 0){ 
					temp->next = newLink; 			
					ht->count++; 
				} 
			temp = temp->next;
			}
			
				
				
		}

	}
	
	if(lf >= LOAD_FACTOR_THRESHOLD){
		_setTableSize(ht, ht->tableSize*2);  
	} 
	free(temp); 
	/*write this*/	
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	int i = 0; 	
	long retNum = 0;  
	retNum = (ValueType)retNum; 
	hashLink *temp = malloc(sizeof(hashLink));
//	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
//		while(temp != 0){			
//			if(k == temp->key){
				retNum = temp->value; 
				return (ValueType*)retNum;
//				}
//			temp=temp->next;			
//		}		
//	}
	
//	retNum = (ValueType)retNum; 
/*
	int index; 
	index = stringHash1(k) %  (ht->count + 1); 		

	  
	if(index < 0) index += ht->count; 


	hashLink *temp = malloc(sizeof(hashLink));
	temp = ht->table[index]; 
		while(temp != NULL){			
			if(k == temp->key)
			{
				retNum = temp->value; 
				return (ValueType*)retNum;
			//	return temp->value; 		
			}
			else{
			temp=temp->next;
			}
		}*/			
//	return 0;
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey(struct hashMap * ht, KeyType k)
{  
	int index; 
	index = stringHash1(k) %  (ht->count + 1); 		

	hashLink *temp = malloc(sizeof(hashLink));
	temp = ht->table[index]; 
		while(temp != 0){			
			if(k == temp->key)
			{
				return 1; 
			}
			else{
			temp=temp->next;
			}
		}
	
	
	return 0; 
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	int index; 
	if(ht->count == 0)
	{	index = stringHash1(k);}
	else	
	{	index = stringHash1(k) % ht->count; }		


	  
//	if(index < 0) index += ht->count; 
//	printf("Index is: %ld\n", index); 
//	hashLink *temp = malloc(sizeof(hashLink));
//	temp = ht->table[index];  
	
//		free(ht->table[index]); 
		ht->table[index] = ht->table[index]->next;  		
	//	ht->table[index] = NULL; 
		ht->count--;
	

	/*write this*/	
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	int counts = 0;
	counts = ht->count; 
	return counts; 
	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	int buckets = ht->tableSize;  

	return buckets;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	int index;
	int empty = 0;  
	 
	for (index = 0; index < ht->tableSize; index++){
		if(ht->table[index] == NULL)
			empty++;  	
	
	} 
	
	return empty;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	float load = ht->count/ht->tableSize;  
	return load;
}

void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}


