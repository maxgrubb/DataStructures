/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*********************************************************************
** Function: sticky() 
** Description: modifies string to alternate upper and lower case   
** Parameters: pointer to char
** Pre-Conditions: Properly initialized char and pointer 
** Post-Conditions: char is properly reassigned   
*********************************************************************/ 
void sticky(char* word){
     /*Convert to sticky caps*/

	int n = 0;
	int o = strlen(word); 


		
			for(n = 0; n < o; n++){	

				 if(!(n%2)){
			
					if(word[n] >= 'a')
					{word[n] = toUpperCase(word[n]);}

				 }	

					else if(n%2){

						if (word[n] < 'a')
							{word[n] = toLowerCase(word[n]);}

					}

		 	}			

}	



	


		

int main(){
    /*Read word from the keyboard using scanf*/

	char str[50];
	

	printf("Enter a word: ");
	scanf("%s", str);
    
    /*Call sticky*/

	sticky(str); 
    
    /*Print the new word*/
	
		printf("%s\n", str); 
			
    
    return 0;
}
