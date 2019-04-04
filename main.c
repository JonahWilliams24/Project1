/* This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself*/



#include <stdio.h>

int main() {
    int key; //this is the integer of the key from 0-3 and determines what the program does
    int n;
    char message[n];
    printf("Welcome to the Cypher Code Program!\n"); //This prints the title card
    printf("Select the required function by inputting the relating key into the file 'input' on line 1.\n"); 
    //this is a seperate file in Eclipse Che where any input is required to be entered
    printf("To encrypt a message with a desired key put '0' on line 1 in the input file.\n"); 
    //option 1 is where the user knows the key they want
    printf("To encrypt a message without a desired key put '1' on line 1 in the input file.\n");
    //option 2 is where the program generates a random key 
    printf("To decrypt a message with a known key put '2' on line 1 in the input file.\n");
    //option 3 is to decrypt a message with a known key
    printf("To decrypt a message without knowing a key put '3' on line 1 in the input file.\n");
    scanf("%d", &key); //This scans the first line from the input file
        if (key==0 || key==1 || key==2 || key==3) 
        // "||" means OR therefore this tests to see if the key is properly inputted
            printf("Key selected: %d\n", key); // this prints the key selected so the user knows
        else {
            printf("\nERROR INVALID KEY\n"); // Any other input prints the error message
        }
    if (key==0)   {
        printf("Enter message onto line 2 of the file 'input'\n");
        scanf("%s", message);
        
    }
    return 0;
}
