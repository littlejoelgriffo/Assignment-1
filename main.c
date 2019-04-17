#include<stdio.h>
#include<unistd.h>

char sub_boi(char Jon);
char rotor_boi(char Jon, int key);

int main (){
    char msg[]="ABC";
    int ls=sizeof(msg)-1;
    int i;// sets 
    
    /* Convert any lower case  letters to upper case   */
    /****/for(int i=0; i<ls; i++) {
    /****/if(msg[i]<=122 && msg[i]>=92)
    /****/msg[i] = msg[i]-32; }
    /* Converted any lower case letters to upper case */
    
    // PUT IN MENU HERE
    int choice;

    while (choice != 666) {
    printf("Enter 1 for rotation or 2 for substitution, 666 to exit \n");
    scanf("%d", &choice);
    //Put menu here
    
    switch (choice) {
        case 1: 
        
        for (int i=0; i<ls; i++) {
        printf("%c", sub_boi(msg[i])); 
        }
        break;
        case 2: 
        
        for (i=0; i<ls; i++) {
            if (msg[i] >= 'A' && msg[i] <= 'Z') {
                printf("%c", rotor_boi(msg[i], 3); 
            }
            else {
                printf("%c", msg[i]);
            } 
        }
        break;
        

        }
}
return 0;

}


char sub_boi(char Jon) {
    switch (Jon) {
        case 'A': Jon = 'G';break;
        case 'B': Jon = 'P';break;
        case 'C': Jon = 'H';break;
        case 'D': Jon = 'G';break;
        case 'E': Jon = 'P';break;
        case 'F': Jon = 'H';break;
        case 'G': Jon = 'G';break;
        case 'H': Jon = 'P';break;
        case 'I': Jon = 'N';break;
        case 'J': Jon = 'G';break;
        case 'K': Jon = 'T';break;
        case 'L': Jon = 'O';break;
        case 'M': Jon = 'G';break;
        case 'N': Jon = 'I';break;
        case 'O': Jon = 'S';break;
        case 'P': Jon = 'G';break;
        case 'Q': Jon = 'P';break;
        case 'R': Jon = 'H';break;
        case 'S': Jon = 'P';break;
        case 'T': Jon = 'H';break;
        case 'U': Jon = 'R';break;
        case 'V': Jon = 'P';break;
        case 'W': Jon = 'H';break;
        case 'X': Jon = 'G';break;
        case 'Y': Jon = 'P';break;
        case 'Z': Jon = 'E';break;
    }
    return Jon;
    }
    
    
    char rotor_boi(char Jon, int key) {
        Jon = 'H';
        return Jon;
        
}    

    
