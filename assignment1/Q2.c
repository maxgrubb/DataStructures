/* CS261- Assignment 1 - Q.2*/
/* Name: Max Grubb 
 * Date: 10/10/2015
 * Solution description: math is performed on pointers to ints and int 
 */
 
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
** Function: foo() 
** Description: performs math on pointers and int  
** Parameters: int and pointers to int
** Pre-Conditions: Properly initialized int and pointers 
** Post-Conditions: new values are correct 
*********************************************************************/ 
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2; 
		 
    /*Set b to half its original value*/
    *b /= 2.0;
    
	/*Assign a+b to c*/
    c = *a + *b;
    
	/*Return c*/
	return c;
}

/*********************************************************************
** Function: print() 
** Description: prints values   
** Parameters: ints 
** Pre-Conditions: Properly initialized int and pointers 
** Post-Conditions: new values are printed 
*********************************************************************/ 
void print(int x, int y, int z)
{
	printf("x: %hd\n", x);
	printf("y: %hd\n", y); 
	printf("z: %hd\n", z);
}


int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
	int y = 6;
	int z = 7; 	
	int out; // will be assigned return value of foo(int*, int*, int)

    /*Print the values of x, y and z*/
    printf("The original values of x, y and z are: \n"); 
	print(x, y, z); 

    /*Call foo() appropriately, passing x,y,z as parameters*/
    out = foo(&x, &y, z); 
    
	/*Print the value returned by foo*/
   	printf("The value of c is: %hd\n", out); 
   
	/*Print the values of x, y and z again*/
 	printf("The new values of x, y and z are: \n"); 
	print(x, y, z); 

//	end();

    /*Is the return value different than the value of z?  Why?*/
	//No because the math completed on the pointers ultimately gives the same result. However, If we changed the math, the result would change.
    return 0;
}
    
    
