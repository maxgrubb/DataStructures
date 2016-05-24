/* CS261- Assignment 1 - Q. 0*/
/* Name: Max Grubb
 * Date: 10/10/2015
 * Solution description: Program shows attributes pointer to int 
 */
 
#include <stdio.h>
#include <stdlib.h>



/*********************************************************************
** Function: fooA() 
** Description: Returns address and value of pointer 
** Parameters: reference to pointer to int
** Pre-Conditions: Properly initialized int and pointer 
** Post-Conditions: attributes properly displayed
*********************************************************************/ 

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     
     /*Print the address pointed to by iptr*/
     
     /*Print the address of iptr itself*/
	printf("The address of x is: %p\n", iptr);
	printf("The value of x pointed to by iptr is: %hd\n", *iptr);
	printf("The address of iptr is: %p\n", &iptr);

}

int main(){

 
	
    
    /*declare an integer x*/

		int x = 1;
//		int *ptr = &x;
//		printf("The address of x is: %p\n", ptr);
    
    /*print the address of x*/
	printf("The address of x is: %p\n", &x);

    /*Call fooA() with the address of x*/
	fooA(&x); 
    
    /*print the value of x*/
	
	printf("The value of x is: %hd\n", x);
    
    return 0;
}
