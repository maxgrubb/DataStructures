/* CS261- Assignment 1 - Q.1*/
/* Name: Max Grubb 
 * Date: 10/10/2015
 * Solution description: Program creates memory for ten structures, populates their values and returns max, min and average 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct student{
	int id;
	int score;
};


/*********************************************************************
** Function: allocate() 
** Description: allocates memory for 10 student structures  
** Parameters: none
** Pre-Conditions: Properly initialized student structure 
** Post-Conditions: memory properly allocated
*********************************************************************/ 

struct student* allocate(){
     /*Allocate memory for ten students*/

	int numStudents = 10; 

	struct student *grubbStudent = malloc(numStudents * sizeof(struct student)); 
	    
     /*return the pointer*/

	return grubbStudent;
}

/*********************************************************************
** Function: generate() 
** Description: populates structures with random id and test scores  
** Parameters: pointer to student structure 
** Pre-Conditions: Properly initialized student structure 
** Post-Conditions: values properly assigned
*********************************************************************/ 

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/


	int n; 
 

	for(n=0; n < 10; n++)
	{
		students[n].id = rand() % 1000;
			
			if(students[n].id < 100)
			{
				students[n].id = rand() % 1000; 
			}
			if(n>0){
				
				if((students[n-1].id == students[n].id) || (students[n].id == 0))
				{
					students[n].id = rand() % 1000; 
				}
			}

		students[n].score = rand() % 101;
		
	

	}

}


/*********************************************************************
** Function: output() 
** Description: prints values of structure    
** Parameters: pointer to student structure  
** Pre-Conditions: Properly initialized and assigned  student structure 
** Post-Conditions: values properly displayed 
*********************************************************************/ 

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int p; 
	int q;
	int r;
	
	for(p=0; p < 10; p++)
	{
		q = students[p].id;
		r = students[p].score;
		printf("Student %i score: %i\n", q, r); 
	}

		
}

/*********************************************************************
** Function: summary() 
** Description: prints min max and average scores     
** Parameters: pointer to student structure  
** Pre-Conditions: Properly initialized and assigned  student structure 
** Post-Conditions: values properly displayed 
*********************************************************************/ 

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	int n;
	int o;
	int p;
	int q;
	int r;
	int s;
	int t = 0; 

	for(n = 9; n > 0; n--){
		for(r = 0; r < n; r++) {

		if(students[r].score >  students[r+1].score)
		{
			p = students[r+1].score; // if n = 3 & n - 1 = 4, p = 4  
			students[r+1].score = students[r].score;  // both = 4 
			students[r].score = p; // n = 2
		

			o = students[r+1].id;
			students[r+1].id = students[r].id;
			students[r].id = o;

		}
	}
	 
}
		for(q = 0; q < 10; q++){

		printf("Sorted ID and Score: %i and %i\n", students[q].id, students[q].score); 

		}

		for(s = 0; s < 10; s++){ 

			t = t + students[s].score; 

		 }


		printf("\nThe minimum score is: %i for student # %i\n", students[0].score, students[0].id);
		printf("The maximum score is: %i for student # %i\n", students[9].score, students[9].id);
		printf("The average score is: %i\n", t/10);

	}
	

     

/*********************************************************************
** Function: deallocate() 
** Description: frees memory of the structures     
** Parameters: pointer to student structure  
** Pre-Conditions: Properly initialized and assigned  student structure 
** Post-Conditions:memory is freed  
*********************************************************************/ 

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if(stud != NULL){
	free(stud); 
	}
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/

	stud = allocate(); 
    
    /*call generate*/

	generate(stud); 
    
    /*call output*/

	output(stud); 
    
    /*call summary*/

	summary(stud);
    
    /*call deallocate*/

	deallocate(stud); 

    return 0;
}
