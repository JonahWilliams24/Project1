/* This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself*/
// Use terminal input via "./a.out"


//Make a length constraint 



#include <stdio.h>
#include <stdlib.h>



//char EncryptRWithKey(char[200]); //This is the prototype of the function that will rotationally encrpyt a message 
//char DecryptRWithKey(char[n]); //Prototpye for decrypting a rotated message when key is known
//char DecryptW/okey(char[n]); // prototype for decrpyting without key (this will be difficult to code)

int main() {
    int operator; //this is the integer of the key from 0-2 and determines what the program does
    int Ekey=0; //Ekey is for the encytption key, default is 0 (no rotation)
    //int Dkey=0; //Dkey is fot the decryption key, default is 0 (no rotation)
    //int n = 200; // n is length of the string (the message)
    //all these int variables can be written on the same line, I chose not to so I could explain their use
    //Also it is easy to use '//' to take out an int when its not being used i.e. in debugging of specific areas
    char message[200];
    //int key2;
    printf("Welcome to the cipher Code Program!\n"); //This prints the title card
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
    printf("Operator: ");
    scanf("%d", &operator); //This scans the input from the user
    
        if (operator==0 || operator==1 || operator==2 || operator==3 || operator==4 || operator==5) 
        // "||" means OR therefore this tests to see if the key is properly inputted in the range desired
            printf("Operator selected: %d\n", operator); // this prints the key selected by the user
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
                    printf("Key selected: %d\n", Ekey);
                    //message = EncryptWithKey(message);
                    printf("Encrypted message is: %s\n", message);
                    exit(0);
                }

            break;
            /*case 1:
                if (operator == 2 || operator == 3)
                {
                    printf("Enter code to be deciphered: \n");
                    scanf(" %[^\n]s", message);
                }            
        switch(operator) {
            case 2:
            printf("Enter cipher Code Key (1-25):\n");
            scanf("%d", &key2);
            //printf("Decrypted message is: \n", message);
            break;
            case 3:
            printf("Wow make my job hard why don't you?\n");
            break; */
        }
        
        
    
    return 0;
}


/*char EncryptWithKey(char[200]) {
    char ch;
    int i;
    for (i=0; message[i] !='\n'; ++i){
      ch = message[i];
      if(ch >= 'a' && ch <= 'z'){
          ch = ch + key2; 
          if(ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
            }    
            message[i]=ch;

      }
      else if (ch >= 'A' && ch <='Z'){
          ch=ch+key2;
          if (ch > 'Z'){
              ch=ch-'Z'+'A'-1;
          }
          message[i] = ch; 
      }
    }
    return ch;
}

void stringfunction(char *);


void stringfunction(char *array){
    array[3] = 'A';
       
}


x = functinon(y)*/