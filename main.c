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
    
    //FILE *input;
    //input = fopen("input.txt", "r");
    
    int operator; //this is the integer of the key from 0-2 and determines what the program does
    int Ekey=0;
    int Dkey=0; //Dkey is fot the decryption key, default is 0 (no rotation)
    int n = 200;// n is length of the string (the message)
    //all these int variables can be written on the same line, I chose not to so I could explain their use
    //Also it is easy to use '//' to take out an int when its not being used i.e. in debugging of specific areas
    int x=0; // x will be used in the substitution cipher
    char message[n]; 
    char sub[55];
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("\nWelcome to the Cipher Code Program!\n"); //This prints the title card
    printf("Select the required function by typing the relating operator into 'input' on the first line:\n\n"); 
    //this prompts the user to type the operator required so they can choose the function they want
    printf("To encrypt a message using a rotational cipher, with a desired key, type '0' into the 'input' file.\n"); 
    //option 1 is for the user to input a message and a key for encryption with the rotational cipher
    printf("To decrypt a message with a rotational cipher with a known key, type '1' into the 'input' file.\n");
    //option 2 is to decrypt a message when the user knows the key of a rotation cipher message 
    printf("To encrypt a message using a desired substitution, type '2' into the 'input' file.\n");
    //option 3 is for the user to encrpt using a substitution where they can choose which letters are changed to what
    printf("To decrypt a message with a substitution cipher knowing the substitution used, type '3' into the 'input' file.\n");
    //this is where the program will attempt to decipher the message of a rotational cipher without knowing the key
    printf("To decrpyt a message with a substition cipher knowing the substitution used, type '4' into the 'input' file.\n");
    //This will decrypt a message using the users substitution index
    printf("To decrypt a substitution cipher without knowing the substition type '5' into the input file.\n");
    //This is the hardest one to do with 26! possible combinations. BRUTE FORCE WILL NOT WORK!!!
    //printf("Operator: \n");
    scanf("%d", &operator); //This scans the input from the user
    
        if (operator==0 || operator==1 || operator==2 || operator==3 || operator==4 || operator==5) 
        // "||" means OR therefore this tests to see if the key is properly inputted in the range desired
            printf("Operator selected: %d\n", operator); // this prints the key selected by the user
        else {
            printf("ERROR INVALID OPERATOR\n"); // Any other input prints the error message...
            exit(0); // ...and exits the program
        }
       
        switch(operator) {
            case 0:
                scanf(" %[^\n]s", message); // scans the message written until a new line
                printf("Message is: ");
                printf("%s", message); // this prints the message itself
                //this also works to check for any issue in scanning the message by the user (manually)
                printf("Enter desired cipher key ranging from 1-25 (Inclusive):");
                scanf("%d", &Ekey);
                if (Ekey <1 || Ekey >25) // this ensures the user has inputted a key from 1-25
                {
                    printf("\nINVALID KEY");   
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
                            if(message[i] >90) //this makes the letters rotate around instead of continuing
                                message[i]=message[i] - 26; // by minusing 26 if the ascii value exceeds 90
                        }
                    }
                    printf("Encrypted message is: ");
                    printf("%s", message);
                    exit(0);
                } 
            break;
            case 1:
                scanf(" %[^\n]s", message); // scans the message written until a new line
                printf("\nEncrypted message is: ");
                printf("%s", message); // this prints the message itself
                //this also works to check for any issue in scanning the message by the user (manually)
                printf("Enter cipher key ranging from 1-25 (Inclusive):");
                scanf("%d", &Dkey);
                if (Dkey < 1 || Dkey > 25) // this ensures the user has inputted a key from 1-25
                {
                    printf("\nINVALID KEY\n");   
                    exit(0); //if the user inputs outside of 1-25 the program exits
                }
                else 
                {
                    printf("\nKey selected: %d\n", Dkey);
                    for (int i=0; i<200 && message[i] != '\0'; i++)
                    {
                        if (message[i] <=122 && message[i] >=97){
                            message[i] = message[i] - 32;
                        }
                        if (message[i] <=90 && message[i] >= 65){
                            message[i] = message[i] - Dkey;
                            if(message[i] < 65)
                               message[i]= message[i] + 26; 
                        }
                    }
   
                    printf("Message is: %s", message);
                    exit(0);
                }

                break;
            case 2:
                printf("\nEnter message to be encrypted onto line 2 of 'input'.\n");
                printf("Enter substitution key in alphabetical order with no spaces onto line 3 of 'input'.");
                scanf(" %[^\n]s", message);
                scanf("%s", sub);
                if(sub[26] != '\0'){
                    printf("\nERROR\n-Substitution requires 26 unique letters in alphabetical order of substitution desired.");
                    exit(0);
                }
                printf("\nSubstitution in alphabetical order is: ");
                for(int i=0; sub[i] != '\0'; ++i){
                    if(sub[i] <=122 && sub[i] >= 97){
                        sub[i] = sub[i] - 32;
                    }
                }
                printf("%s\n", sub);
                printf("Original message is:\n%s", message);
                printf("Encrypted message is: \n");
                for(int i=0; message[i] != '\0' && i <= 200; ++i ){
                    if (message[i] <=122 && message[i] >=97){
                            message[i] = message[i] - 32;
                    }
                    
                    switch(message[i]){
                    case 65:
                    message[i]=sub[0];
                    printf("%c", message[i]);
                    break;
                    case 66:
                    message[i]=sub[1];
                    printf("%c", message[i]);
                    break;
                    case 67:
                    message[i]=sub[2];
                    printf("%c", message[i]);
                    break;
                    case 68:
                    message[i]=sub[3];
                    printf("%c", message[i]);
                    break;
                    case 69:
                    message[i]=sub[4];
                    printf("%c", message[i]);
                    break;                    
                    case 70:
                    message[i]=sub[5];
                    printf("%c", message[i]);
                    break;
                    case 71:
                    message[i]=sub[6];
                    printf("%c", message[i]);
                    break;                    
                    case 72:
                    message[i]=sub[7];
                    printf("%c", message[i]);
                    break;                    
                    case 73:
                    message[i]=sub[8];
                    printf("%c", message[i]);
                    break;                    
                    case 74:
                    message[i]=sub[9];
                    printf("%c", message[i]);
                    break;                    
                    case 75:
                    message[i]=sub[10];
                    printf("%c", message[i]);
                    break;                    
                    case 76:
                    message[i]=sub[11];
                    printf("%c", message[i]);
                    break;                    
                    case 77:
                    message[i]=sub[12];
                    printf("%c", message[i]);
                    break;                    
                    case 78:
                    message[i]=sub[13];
                    printf("%c", message[i]);
                    break;                    
                    case 79:
                    message[i]=sub[14];
                    printf("%c", message[i]);
                    break;                    
                    case 80:
                    message[i]=sub[15];
                    printf("%c", message[i]);
                    break;                    
                    case 81:
                    message[i]=sub[16];
                    printf("%c", message[i]);
                    break;
                    case 82:
                    message[i]=sub[17];
                    printf("%c", message[i]);
                    break;
                    case 83:
                    message[i]=sub[18];
                    printf("%c", message[i]);
                    break;
                    case 84:
                    message[i]=sub[19];
                    printf("%c", message[i]);
                    break;
                    case 85:
                    message[i]=sub[20];
                    printf("%c", message[i]);
                    break;
                    case 86:
                    message[i]=sub[21];
                    printf("%c", message[i]);
                    break;
                    case 87:
                    message[i]=sub[22];
                    printf("%c", message[i]);
                    break;                 
                    case 88:
                    message[i]=sub[23];
                    printf("%c", message[i]);
                    break;
                    case 89:
                    message[i]=sub[24];
                    printf("%c", message[i]);
                    break;
                    case 90:
                    message[i]=sub[25];
                    printf("%c", message[i]);
                    break;
                    default:
                    printf("%c", message[i]);                    
                    }
            }             
            exit(0);
            case 3:
                printf("\nEnter message to be decrypted onto line 2 of 'input'.\n");
                printf("Enter substitution key in alphabetical order with no spaces onto line 3 of 'input'.");
                scanf(" %[^\n]s", message);
                scanf("%s", sub);
                if(sub[26] != '\0'){
                    printf("\nERROR TOO MANY CHARACTERS\nSubstitution requires 26 unique letters in order of substitution desired");
                    exit(0);
                }
                printf("\nSubstitution in alphabetical order is: ");
                for(int i=0; sub[i] != '\0'; ++i){
                    if(sub[i] <=122 && sub[i] >= 97){
                        sub[i] = sub[i] - 32;
                    }
                }
                printf("%s\n", sub);
                printf("Original message is:\n%s", message);
                printf("Decrypted message is: \n");
                for(int i = 0; message[i] != '\0' && i <= 200; ++i ){
                    if (message[i] <=122 && message[i] >=97){
                            message[i] = message[i] - 32;
                    }
                    
                    switch(message[i]){
                    case 65:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;  
                    case 66:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 67:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 68:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 69:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 70:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 71:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 72:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 73:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 74:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 75:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 76:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 77:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 78:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 79:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 80:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 81:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 82:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 83:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;case 84:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 85:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 86:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 87:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 88:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 89:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    case 90:
                    for(x=0; x<= 26; x++){
                        if(sub[x] == message[i])
                            printf("%c", alphabet[x]);
                    }
                    break;
                    default:
                    printf("%c", message[i]);                    
                    }

            }             
                
            exit(0);
            case 4:
            exit(0);
            case(5):
            exit(0);
        }
    


        
    
    return 0;
}


char EncryptRWithKey(char message[]) {
    //message[1] = 'A';
    //printf("%s", message);
    return 0;
}







