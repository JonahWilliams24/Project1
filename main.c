/* This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself*/
// Use terminal input via "./a.out"


//Make a length constraint 



#include <stdio.h>
#include <stdlib.h>



char EncryptWithKey(char[200]); //This is the prototype of the function that will encrypt a message with a desired key
//char DecryptWithKey(char[n]); //Prototpye for decrypting message when key is known
//char DecryptW/okey(char[n]); // prototype for decrpyting without key (this will be difficult to code)

int main() {
    int operator; //this is the integer of the key from 0-2 and determines what the program does
    int key, n=200; // key is the rotation of the cipher code, n is length of the string
    char message[n];
    //int KEY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int key2;
    printf("Welcome to the cipher Code Program!\n"); //This prints the title card
    printf("Select the required function by inputting the relating operator into the terminal.\n\n"); 
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
    printf("To decrypt a substitution cipher without knowing the substition input '5' into the terminal");
    //This is the hardest one to do with 26! possible combinations. BRUTE FORCE WILL NOT WORK!!!
    scanf("%d", &operator); //This scans the input from the user
    
        if (operator==0 || operator==1 || operator==2 || operator==3 || operator==4 || operator==5) 
        // "||" means OR therefore this tests to see if the key is properly inputted in the range desired
            printf("Operator selected: %d\n", operator); // this prints the key selected so the user knows
        else {
            printf("\nERROR INVALID OPERATOR\n"); // Any other input prints the error message
            exit(0); // and exits the program
        }
        if (operator == 0 || operator == 1) { // this is for encrypting messages 
            printf("Enter message into terminal.\n"); 
            // the message is the one that needs to be encrypted or decyrpted 
            scanf(" %[^\n]s", message); // scans the message from line 2 of input file 
            printf("Message is: %s\n", message); // this prints the message itself
         }
        switch(operator) {
            case 0:
            printf("Enter desired cipher key ranging from 1-25:\n");
            scanf("%d", &key);
            //key=key;
                //if (key!=KEY){
                    //printf("INVALID KEY");   // Edit this to stop from being broken
                    //exit(0);
                //}
            printf("Key selected: %d\n", key);
            message = EncryptWithKey(message);
            printf("Encrypted message is: %s" encryptedmessage);
            break;
            case 1:
            srand(time(NULL)); //this uses the time to generate a random number 
                randomkey = rand() % 26 + 1; // %26 gives the remainder of the 
                printf("Random key is: %d\n", randomkey);
                printf("Encrypted message is: \n"); // INPUT ENCRYPTED MESSAGE HERE
                //exit(0);
            }
        if (operator == 2 || operator == 3){
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
            break;
        }
        
        
    
    return 0;
}


char EncryptWithKey(char[200]) {
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


x = functinon(y)
