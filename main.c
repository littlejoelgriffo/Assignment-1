
#include <stdio.h> 
int main () { 
    char test; 
    printf("Enter a letter for testing: "); 
    scanf("%c", &test); 
    test=(test+1) %26;
    printf("\nNow this is your letter +1: %c", test); 
    /*printf("\n %c", 'A'+1); \\little quotes '' correspond to chars, "" to strings 
     
    char message[4], cm;
    int i, key;  
    cm=i=key;
     
    printf("\nEnter a message (4 letters) to encrypt: "); 
    gets(message); //oes this set the letters to values in the array? How do we know that they are 1-26? why does gets not work for me but does with other similar code? 
     
    printf("\nEnter key: "); 
    scanf("%d", &key); */ 
    
    return 0; 
     
}