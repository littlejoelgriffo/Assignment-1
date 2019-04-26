#include<stdio.h>
#include<unistd.h>

char lower2upper(char Jon);
char sub_boi(char Jon);
char rotor_boi(char Jon, int key);
char kingrotor_boi(char *msg);

int main (){
    char msg[]="Yeot";
    int ls=sizeof(msg)-1;
    int i; // sets 
    //printf("%d", ls);
    /* Convert any lower case  letters to upper case  */
    /****/for(int i=0; i<ls; i++) {
        msg[i]=lower2upper(msg[i]);
    /****/}
    /* Converted any lower case letters to upper case */
    
    // PUT IN MENU HERE
    int choice;
    while (choice != 666) {
    printf("\nEnter 1 for substitution or 2 for rotation, 666 to exit \n");
    scanf("%d", &choice);
    //Put menu here
    
    switch (choice) {
        case 1:                         //Case for if substitution is chosen
        for (int i=0; i<ls; i++) {
        printf("%c", sub_boi(msg[i])); 
        }
        break;
        case 2:;                        //Case for if rotation is chosen
        int key;
        printf("Enter a number between 1 and 25 for the rotation key: ");
        scanf("%d", &key);
        printf("\n");
        for (i=0; i<ls; i++) {
            printf("%c", rotor_boi(msg[i], key)); 
        }
        break;
    }
}
printf("\n->Thanks for using this program brought to you by the Gabeage Bin :D");
return 0;

}

char lower2upper(char Jon) {
if(Jon<=122 && Jon>=92) {
  Jon = Jon-32; } 
  return Jon;
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
        if (Jon >= 'A' && Jon <= 'Z') {
                Jon = Jon + key;
          if (Jon > 'Z')
             Jon = Jon - 26; /*This is to rotate any letters that 'fall of the end' of the alphabet
         back to the beginning. I have not included a statement for if the key makes the letter <
         A as the assignment specifies key <26 & >0 */
        }
        else  //
        Jon=Jon;

        return Jon;
        
      }    

    
