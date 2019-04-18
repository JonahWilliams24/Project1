/* This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself*/
// Use terminal input via "./a.out"


//Make a length constraint 


#include <stdio.h>
#include <stdlib.h>


char EncryptRWithKey(char message[200]); //This is the prototype of the function that will rotationally encrpyt a message
//char DecryptRWithKey(char[n]); //Prototpye for decrypting a rotated message when key is known
//char DecryptW/okey(char[n]); // prototype for decrpyting without key (this will be difficult to code)


int main() {
    int operator; //this is the integer of the key from 0-2 and determines what the program does
    int Ekey=0;
    int Dkey=0; //Dkey is fot the decryption key, default is 0 (no rotation)
    int n = 200; // n is length of the string (the message)
    //all these int variables can be written on the same line, I chose not to so I could explain their use
    //Also it is easy to use '//' to take out an int when its not being used i.e. in debugging of specific areas
    int i; // i will be the index key for the strings so that the letters can be altered
    char message[n]; 
    printf("\nWelcome to the cipher Code Program!\n"); //This prints the title card
    printf("Select the required function by inputting the relating operator into the terminal:\n\n"); 
    //this prompts the user to type the operator required so they can choose the function they want
    printf("To encrypt a message using a rotational cipher, with a desired key, input '0' into the terminal.\n"); 
    //option 1 is for the user to input a message and a key for encryption with the rotational cipher
    printf("To decrypt a message with a rotational cipher with a known key, input '1' into the terminal.\n");
    //option 2 is to decrypt a message when the user knows the key of a rotation cipher message 
    printf("To encrypt a message using a desired substitution, input '2' into the terminal.\n");
    //option 3 is for the user to encrpt using a substitution where they can choose which letters are changed to what
    printf("To decrypt a message with a rotational cipher without knowing a key input '3' into the terminal.\n");
    //this is where the program will attempt to decipher the message of a rotational cipher without knowing the key
    printf("To decrpyt a message with a substition cipher knowing the substitution used input '4' into the terminal.\n");
    //This will decrypt a message using the users substitution index
    printf("To decrypt a substitution cipher without knowing the substition input '5' into the terminal.\n");
    //This is the hardest one to do with 26! possible combinations. BRUTE FORCE WILL NOT WORK!!!
    //printf("Operator: ");
    scanf("%d", &operator); //This scans the input from the user
    
        if (operator==0 || operator==1 || operator==2 || operator==3 || operator==4 || operator==5) 
        // "||" means OR therefore this tests to see if the key is properly inputted in the range desired
            printf("\nOperator selected: %d\n", operator); // this prints the key selected by the user
        else {
            printf("\nERROR INVALID OPERATOR\n"); // Any other input prints the error message...
            exit(0); // ...and exits the program
        }
        if (operator == 0 || operator == 1) // this is for using the rotation cipher function
        { 
            printf("Enter message: "); // the message is the one that needs to be encrypted or decyrpted 
            scanf(" %[^\n]s", message); // scans the message written until a new line
            printf("\nMessage is: %s\n", message); // this prints the message itself
            //this also works to check for any issue in scanning the message by the user (manually)
         }
        switch(operator) {
            case 0:
                printf("Enter desired cipher key ranging from 1-25 (Inclusive):");
                scanf("%d", &Ekey);
                if (Ekey <1 || Ekey >25) // this ensures the user has inputted a key from 1-25
                {
                    printf("INVALID KEY\n");   
                    exit(0); //if the user inputs outside of 1-25 the program exits
                }
                else 
                {
                    printf("\nKey selected: %d\n", Ekey);
                    for (int i=0; i<200 && message[i] != '\0'; i++)
                    {
                        if (message[i] <=122 && message[i] >=97){
                            message[i] = message[i] - 32;
                        }
                        if (message[i] <=90 && message[i] >= 65){
                            message[i] = message[i] + Ekey;
                        }
                    }
   
                    printf("%s", message);
                    exit(0);
                } 
            break;
            case 1:
                printf("Enter rotational Key: ");
                scanf("%d", &Dkey);
                if (Dkey <1 || Dkey >25) // this ensures the user has inputted a key from 1-25
                    {
                        printf("/nINVALID KEY\n");   
                        exit(0); //if the user inputs outside of 1-25 the program exits
                    }
                    else 
                    {
                    printf("Key selected: %d\n", Dkey);
                    //decryptfunction
                    printf("Deciphered Message is: %s", message);
                    }

                break;
            case 2:
            exit(0);
        }

        
    
    return 0;
}


char EncryptRWithKey(char message[]) {
    //message[1] = 'A';
    //printf("%s", message);
    return 0;
}







