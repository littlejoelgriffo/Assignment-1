


#include <stdio.h> 
int main () { 
    char test; 
    printf("Enter a letter for testing: "); 
    scanf("%c", &test); 
    //test to see if this commit on this fine sunday works
    printf("\nNow this is your letter +1: %c", test+1); 
    //printf("\n %c", 'A'+1); \\little quotes '' correspond to chars, "" to strings 
     
    char message [4], cm;
    int i, key;  
     
    /*printf("\nEnter a message (4 letters) to encrypt: "); 
    gets(message); //does this set the letters to values in the array? How do we know that they are 1-26? why does gets not work for me but does with other similar code? 
     
    printf("\nEnter key: "); 
    scanf("%d", &key); */ 
    
    return 0; 
     
}
