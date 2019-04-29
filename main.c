/* This program was created by Gabe Halpin c3302926. It works with a hardcoded message and can encrypt/decrypt
via substitution or rotation with a key given and for a rotation ciphered text, decrypt it without the key given to the program.
To change the message, see the second line of the int main. To change the substitution key, see the switch case in the
respective encrypt and decrypt functions. The key for rotation will be prompted for the user to scan in each time. */

#include<stdio.h>
#include<unistd.h> //This is to allow the sizeof command to work.
char lower2upper(char Jon); //Converts any present lower case letters in the message to upper case
char sub_boi(char Jon); //Substitutes given letters in the alphabet for others to create encrypted text.
char sub_boi_d(char Jon); //Substitutes given letters in the alphabet for others to decrypt text.
char rotor_boi(char Jon, int key); //Rotates letters by a certain number on the alphabet (key) to encrypt text.
char rotor_boi_d(char Jon, int key); //Rotates letters by a certain number on the alphabet (key) to decrypt text.
char kingrotor_boi(char *msg, int ls, int debug); //Decrypts a rotation cipher encrypted message by making assumptions on english words included.
int main()
{
    int debug = 0;              //This is to switch on and off some extra printfs that in the case of things going wrong may make the problem clearer to see. Change to =1 to enable.
    char msg[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"; 
    //^This is the message passed on the respective functions. Change to whatever you would like to encrypt/decrypt.
    int ls = sizeof(msg) - 1; //This is to find the length of the string holding the message. I have found the sizeof function gets a value that is one too high so the -1 fixes that.
    //^ ls is very important for dictating when to end loops used throughout this program.
    int i;   // used for incrementing place in arrays. 
    if (debug==1) 
        printf("%d", ls); //This will print the value of ls in the case that loops are not going for the correct amount of iterations.
    
    for (int i = 0; i < ls; i++) {    //Increments the place in the array so one by one all letters are passed into the function.
        msg[i] = lower2upper(msg[i]); //calls the lowercase to uppercase converter function and stores the values to overwrite the given message.

    }
    

    //This is the menu:
    int choice; //Used to hold the value of what the user enters into the menu.
    while (choice != 666) {  //Loops the menu so the user can test multiple functions in one run. Exits when the user enters 666.
        printf
            ("\n->Enter 1 for Rotation Encryption given key\n2 for Rotation Decryption given key\n3 for Substitution Encryption (key given)\n4 for Subsitution Decryption (key given)\n5 for Rotation Decryption without key\n->Enter 666 to exit \n");
        scanf("%d", &choice); //scans in the value the user enters which then dictates which switch case is activated.

        switch (choice) {
        case 1:;               //Case for if rotation encryption is chosen
            int key = 0;
            printf
                ("Enter a number between 1 and 25 for the rotation key: ");
            scanf("%d", &key);
            printf("\n");
            for (i = 0; i < ls; i++) {
                printf("%c", rotor_boi(msg[i], key));
            }
            break;
        case 2:;               //Case for if rotation decryption is chosen
            key = 0;
            printf
                ("Enter a number between 1 and 25 for the rotation key: ");
            scanf("%d", &key);
            printf("\n");
            for (i = 0; i < ls; i++) {
                printf("%c", rotor_boi_d(msg[i], key));
            }
            break;
        case 3:                //Case for if substitution encryption is chosen
            for (int i = 0; i < ls; i++) {
                printf("%c", sub_boi(msg[i]));
            } break;
        case 4:                //Case for if substitution decryption is chosen
            for (int i = 0; i < ls; i++) {
                printf("%c", sub_boi_d(msg[i]));
            } break;
        case 5:
            kingrotor_boi(msg, ls, debug);
            break;
        }
    }
    printf
        ("\n->Thanks for using this program brought to you by the Gabeage Bin :D");
    return 0;
}
char lower2upper(char Jon)
{
    if (Jon <= 122 && Jon >= 92) {
        Jon = Jon - 32;
    }
    return Jon;
}
char sub_boi(char Jon)
{
    switch (Jon) {
        case 'A': Jon = 'Z';break; //I know this is an exception to my indenting style, however it makes my file 100+ lines less which is a lot..
        case 'B': Jon = 'Y';break; //.. easier to read and navigate. Please don't make me down for this.
        case 'C': Jon = 'X';break;
        case 'D': Jon = 'W';break;
        case 'E': Jon = 'V';break;
        case 'F': Jon = 'U';break;
        case 'G': Jon = 'T';break;
        case 'H': Jon = 'S';break;
        case 'I': Jon = 'R';break;
        case 'J': Jon = 'Q';break;
        case 'K': Jon = 'P';break;
        case 'L': Jon = 'O';break;
        case 'M': Jon = 'N';break;
        case 'N': Jon = 'M';break;
        case 'O': Jon = 'L';break;
        case 'P': Jon = 'K';break;
        case 'Q': Jon = 'J';break;
        case 'R': Jon = 'I';break;
        case 'S': Jon = 'H';break;
        case 'T': Jon = 'G';break;
        case 'U': Jon = 'F';break;
        case 'V': Jon = 'E';break;
        case 'W': Jon = 'D';break;
        case 'X': Jon = 'C';break;
        case 'Y': Jon = 'B';break;
        case 'Z': Jon = 'A';break;
    }
    return Jon;
}
char rotor_boi(char Jon, int key)
{
    if (Jon >= 'A' && Jon <= 'Z') {
        Jon = Jon + key;
        if (Jon > 'Z')
            Jon = Jon - 26;     /*This is to rotate any letters that 'fall of the end' of the alphabet
                                   back to the beginning. I have not included a statement for if the key makes the letter <
                                   A as the assignment specifies key <26 & >0 */
    }

    else                        //
        Jon = Jon;
    return Jon;
}
char kingrotor_boi(char *msg, int ls, int debug)
{
    printf("Here is the input encrypted message: %s\n", msg);
    char decryptmsg[ls];
    char alpha_m8[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ehtayz[] =
        { 'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'H', 'L', 'D',
        'C'
    };
    int alpha_count[25];
    char mostcommon;
    int c = 0, i = 0, prevalence = 0, key, passornahh = 0, u = 0;
    for (i = 0; i <= 25; i++) {
        for (u = 0; u <= ls; u++) {
            if (msg[u] == alpha_m8[i]) {
                prevalence++;
            }
        }
        alpha_count[c] = prevalence;
        c++;
        if (debug == 1)
            printf("\n%c", alpha_m8[c]);
        if (debug == 1)
            printf("%d", alpha_count[c]);
    }
    int largest = alpha_count[0];
    for (i = 0; i <= 25; i++) {
        if (alpha_count[i] >= largest && alpha_count[i] != 32) {
            largest = alpha_count[i];
            mostcommon = 65 + i;
        }
    }
    if (debug == 1)
        printf("Here is the most common letter (coded): %c", mostcommon);
    for (int m = 0; m <= 12; m++) {
        key = ehtayz[m] - mostcommon;
        if (key < 0) {
            key = key + 26;
        }
        if (debug == 1)
            printf("\nThe key # being tested is:%d\n", key);

//Rotor code:
        for (i = 0; i < ls; i++) {
            decryptmsg[i] = rotor_boi(msg[i], key);
            if (debug == 1)
                printf("%c", decryptmsg[i]);
        }
        if (debug == 1)
            printf("\n");       //Simply makes different rotation cipher code easier to read.
        if (debug == 1)
            printf("the key shift to be tested is: %s", decryptmsg);
        for (int i = 0; i < ls; i++) {
            if (decryptmsg[i] == 32) {
                i++;
                if (decryptmsg[i] == 'A') {
                    i++;
                    if (decryptmsg[i] == 32) {
                        if (debug == 1)
                            printf("\nA has been found.");
                        passornahh = passornahh + 50;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < ls; i++) {
            if (decryptmsg[i] == 32) {
                i++;
                if (decryptmsg[i] == 'T') {
                    i++;
                    if (decryptmsg[i] == 'H') {
                        i++;
                        if (decryptmsg[i] == 'E') {
                            i++;
                        }
                        if (decryptmsg[i] == 32) {
                            if (debug == 1)
                                printf("\nTHE has been found.");
                            passornahh = passornahh + 50;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < ls; i++) {
            if (decryptmsg[i] == 32) {
                i++;
                if (decryptmsg[i] == 'T') {
                    i++;
                    if (decryptmsg[i] == 'O') {
                        i++;
                        if (decryptmsg[i] == 32) {
                            if (debug == 1)
                                printf("\n TO has been found.");
                            passornahh = passornahh + 50;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < ls; i++) {
            if (decryptmsg[i] == 32) {
                i++;
                if (decryptmsg[i] == 'O') {
                    i++;
                    if (decryptmsg[i] == 'F') {
                        i++;
                        if (decryptmsg[i] == 32) {
                            if (debug == 1)
                                printf("\n OF has been found.");
                            passornahh = passornahh + 50;
                            break;
                        }
                    }
                }
            }
        }
        if (passornahh >= 100) {
            printf("\nThe message decrypted is: \n");
            for (i = 0; i < ls; i++) {
                printf("%c", decryptmsg[i]);
            }
            m = 666;            //This is to exit the for loop depending on the variable m, as the other ehtayz letters do not need to be tested once the correct key is found.
        }
    }
    return 0;
}
char rotor_boi_d(char Jon, int key)
{
    if (Jon >= 'A' && Jon <= 'Z') {
        Jon = Jon - key;
        if (Jon < 'A')
            Jon = Jon + 26;     /*This is to rotate any letters that 'fall of the end' of the alphabet
                                   back into the A to Z range. I have not included a statement for if the key makes the letter >
                                   A as the assignment specifies 0<key<26 */
    }

    else                        //
        Jon = Jon;
    return Jon;
}
char sub_boi_d(char Jon)
{
    switch (Jon) {
        case 'A': Jon = 'Z';break; //I know this is an exception to my indenting style, however it makes my file 100+ lines less which is a lot..
        case 'B': Jon = 'Y';break; //.. easier to read and navigate. Please don't make me down for this.
        case 'C': Jon = 'X';break;
        case 'D': Jon = 'W';break;
        case 'E': Jon = 'V';break;
        case 'F': Jon = 'U';break;
        case 'G': Jon = 'T';break;
        case 'H': Jon = 'S';break;
        case 'I': Jon = 'R';break;
        case 'J': Jon = 'Q';break;
        case 'K': Jon = 'P';break;
        case 'L': Jon = 'O';break;
        case 'M': Jon = 'N';break;
        case 'N': Jon = 'M';break;
        case 'O': Jon = 'L';break;
        case 'P': Jon = 'K';break;
        case 'Q': Jon = 'J';break;
        case 'R': Jon = 'I';break;
        case 'S': Jon = 'H';break;
        case 'T': Jon = 'G';break;
        case 'U': Jon = 'F';break;
        case 'V': Jon = 'E';break;
        case 'W': Jon = 'D';break;
        case 'X': Jon = 'C';break;
        case 'Y': Jon = 'B';break;
        case 'Z': Jon = 'A';break;
    }
    return Jon;
}
