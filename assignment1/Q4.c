 /* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

/*********************************************************************
** Function: sort() 
** Description: sorts array of student structures  
** Parameters: int and pointers to structure array
** Pre-Conditions: Properly initialized int and pointers 
** Post-Conditions: array is properly sorted   
*********************************************************************/ 

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     

	int q;
	int r; 
	int o; 
	int p; 

		for(r = n-1; r > 0; r--){
		for(q = 0; q < r; q++) {

			if(students[q].score >  students[q+1].score)
			{
				p = students[q+1].score;   
				students[q+1].score = students[q].score;   
				students[q].score = p; 
		

				o = students[q+1].id;
				students[q+1].id = students[q].id;
				students[q].id = o;

			}
		}
	 
	}

}

int main(){
    /*Declare an integer n and assign it a value.*/

	int n = 10;
	int q; 
	int s;

    /*Allocate memory for n students using malloc.*/

	struct student *grubbStudent = malloc(n * sizeof(struct student));

    
    /*Generate random IDs and scores for the n students, using rand().*/

	for(q=0; q < n; q++)
	{
		grubbStudent[q].id = rand() % 1000;
			
			if(grubbStudent[q].id < 100)
			{
				grubbStudent[q].id = rand() % 1000; 
			}
			if(q>0){
				
				if((grubbStudent[q-1].id == grubbStudent[q].id) || (grubbStudent[q].id == 0))
				{
					grubbStudent[q].id = rand() % 1000; 
				}
			}

		grubbStudent[q].score = rand() % 101;
		
	

	}
    
    /*Print the contents of the array of n students.*/

	for(s = 0; s < n; s++){

		printf("Student ID: %i Score: %i\n", grubbStudent[s].id, grubbStudent[s].score);
		
	}

    /*Pass this array along with n to the sort() function*/

	 sort(grubbStudent, n); 
    
    /*Print the contents of the array of n students.*/
	
	for(s = 0; s < n; s++){

		printf("Sorted Student ID: %i Score: %i\n", grubbStudent[s].id, grubbStudent[s].score);
		
	}


	free(grubbStudent);
	printf("End\n"); 


    return 0;
}
