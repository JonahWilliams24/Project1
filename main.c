/* This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself*/



#include <stdio.h>

int main() {
    int operator; //this is the integer of the key from 0-3 and determines what the program does
    int n=100, key=0;
    char message[n];
    int KEY[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    printf("Welcome to the Cypher Code Program!\n\n\n"); //This prints the title card
    printf("Select the required function by inputting the relating operator into the file 'input' on line 1.\n\n"); 
    //this is a seperate file in Eclipse Che where any input is required to be entered
    printf("To encrypt a message with a desired key put '0' on line 1 in the input file.\n"); 
    //option 1 is where the user knows the key they want
    printf("To encrypt a message without a desired key put '1' on line 1 in the input file.\n");
    //option 2 is where the program generates a random key 
    printf("To decrypt a message with a known key put '2' on line 1 in the input file.\n");
    //option 3 is to decrypt a message with a known key
    printf("To decrypt a message without knowing a key put '3' on line 1 in the input file.\n");
    scanf("%d", &operator); //This scans the first line from the input file
    
        if (operator==0 || operator==1 || operator==2 || operator==3) 
        // "||" means OR therefore this tests to see if the key is properly inputted
            printf("Operator selected: %d\n", operator); // this prints the key selected so the user knows
        else {
            printf("\nERROR INVALID OPERATOR\n"); // Any other input prints the error message
        }
    if (operator==0)   {
        printf("Enter message onto line 2 of the file 'input'.\n");
        scanf(" %[^\n]s", message);
        printf("Message is: %s\n", message);
        printf("Enter desired Key ranging from 0-25 onto line 3 in 'input' file. ");
        printf("This determines the rotation of the cypher code\n");
        scanf("%d", &key);
        if (key != KEY[26]){
            printf("ERROR INVALID KEY\n");
        }

        printf("Key selected is %d", key);
        
        
        
    }
    return 0;
}
