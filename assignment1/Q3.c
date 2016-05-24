/* CS261- Assignment 1 - Q.3*/
/* Name: Max Grubb 
 * Date: 10/10/2015
 * Solution description:Sorts array of ints 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include <math.h>


/*********************************************************************
** Function: sort() 
** Description: sorts array of numbrs  
** Parameters: int and pointers to int array
** Pre-Conditions: Properly initialized int and pointers 
** Post-Conditions: array is properly sorted   
*********************************************************************/ 

void sort(int* number, int n){
     /*Sort the given array number , of length n*/  

	int	q;
	int r; 
	int p; 

		for(r = n-1; r > 0; r--){
		for(q = 0; q < r; q++) {

			if(number[q] >  number[q+1]){
				p = number[q+1];   
				number[q+1] = number[q];   
				number[q] = p; 		

			}
		}
		}

}

int main(){
    /*Declare an integer n and assign it a value of 20.*/

	int n = 20; 
	int s;
   
	 /*Allocate memory for an array of n integers using malloc.*/
    
	int *grubbPoint = malloc(n * sizeof(*grubbPoint)); 

    /*Fill this array with random numbers, using rand().*/

	for(s = 0; s < n; s++){

		grubbPoint[s] = rand() % 1000;

	}
    
    /*Print the contents of the array.*/

	for(s = 0; s < n; s++){

		printf("%i\n", grubbPoint[s]);

	}

	/*Pass this array along with n to the sort() function of part a.*/
    
	sort(grubbPoint, n); 

    /*Print the contents of the array.*/    

		printf("Sorted:\n");
		for(s = 0; s < n; s++){

		printf("%i\n", grubbPoint[s]);

	}
    
	return 0; 

}
