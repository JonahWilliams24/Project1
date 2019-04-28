 /*This program is designed so the user can either input a message they want to be encrypted 
or enter an encrypted message they wish to be decrypted. The program requires an input from
the user to encrypt or decrypt and the message itself. The program can only encrypt or decrypt
a rotational cipher message or a substitution message.*/

// Use terminal input via "./a.out" or custom run command

//The hardest area of code to understand the function of is the decrpytion of the substitution cipher, as the process is confusing to grasp...
//... let alone the code used. The hardest part to code was to find a single letter word in 'message'.

//For deciphering rotational without key find a single letter word and assume it is 'A', use that to find 'key' and decipher it...
//... If its not 'A' adjust for if it was 'I'

//This program is also very difficult to break as there are a lot of parts that check for any errors in the input from the user

#include <stdio.h>
#include <stdlib.h>

//#define int n=1024;

void RCipher(int key, char []);

int main() {
        
    int operator; //this is the integer of the key from 0-2 and determines what the program does
    int key=0; //key is the encryption and decryption key where the default is 0 (no rotation)
    int n = 1024; // n is length of the string (the message), changing the value of n here will alter how long the strings can be
    int x=0;// x will be used in the substitution cipher
    int S=0; //S is used during the decryption to test if a condition was met in a 'for' loop outside the loop 
    int test=200; //This is for the user to try another key in the rotational decipher 
    int count=0; //This is used to make sure that 'sub' meets the right value 
    //all these int variables can be written on the same line, I chose not to so I could explain their use
    //Also it is easy to use '//' to take out a single int when its not being used i.e. in debugging of specific areas 
    char message[n]; //This is the array of the string which the user inputs to be altered
    char sub[27]; //this is the substitution array, where the user inputs the substition desired for encryption or decryption
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //This is the alphabet and is used to decipher substitution messages
    
    //These printf statements provide the user with a menu so they can decide what they want to do
    
    printf("\nWelcome to the Cipher Code Program!\n"); //This prints the title card
    printf("-Please use 'INPUT READER' run command after entering anything new into 'input'");
    printf("\nSelect the required function by typing the relating operator into 'input' on the first line:\n\n"); 
    //this prompts the user to type the operator required so they can choose the function they want
    printf("To encrypt a message using a rotational cipher, with a desired key, type '0' into the 'input' file.\n"); 
    //option 1 is for the user to input a message and a key for encryption with the rotational cipher
    printf("To decrypt a message with a rotational cipher with a known key, type '1' into the 'input' file.\n");
    //option 2 is to decrypt a message when the user knows the key of a rotation cipher message 
    printf("To encrypt a message using a desired substitution, type '2' into the 'input' file.\n");
    //option 3 is for the user to encrpt using a substitution where they can choose which letters are changed to what
    printf("To decrypt a message with a substitution cipher knowing the substitution used, type '3' into the 'input' file.\n");
    //option 4 is where the user decrypts a substitution cipher where the substitution is known
    printf("To decrpyt a message with a rotation cipher without the key, type '4' into the 'input' file.\n");
    //This will decrypt a message using given a key (hopefully)
    printf("To decrypt a message without knowing the substition, type '5' into the input file.\n");
    //This is the hardest one to do with 26! possible combinations. BRUTE FORCE WILL NOT WORK!!!
    //This is in the menu however the program is currently unable to decipher a message without a substitution
    //printf("Operator: \n");
    scanf("%d", &operator); //This scans the input from the user
    
    if (operator==0 || operator==1 || operator==2 || operator==3 || operator==4 || operator==5) 
        // "||" means OR therefore this tests to see if the key is properly inputted in the range desired
        printf("Operator selected: %d\n", operator); // this prints the key selected by the user, useful to make sure the code works
    else {
        printf("**ERROR** \nINVALID OPERATOR\n"); // Any other input prints the error message...
        exit(0); // ...and exits the program
    }
       
    switch(operator) { //A switch statement takes the value of an int and will execute any code below the 'case' it fits
        case 0: //'case 0:'' means anything between this and 'break;' will be executed if the value of operator is '0'
            scanf(" %[^\n]s", message); // '%[^\n] scans the message written until a new line is found (the '\n')
            printf("Message is: %s", message); // this prints the message itself
            //this also works to check for any issue in scanning the message by the user (manually)
            printf("Enter desired cipher key ranging from 1-25 (Inclusive) onto line 2 of 'input':");
            //1-25 is range as '0' and '25' are no rotation
            scanf("%d", &key); //This reads the key typed into the input file
            if (key <1 || key >25){ // this ensures the user has inputted a key from 1-25
                    //since key is an int, if a floating point variable is inputted it will still read it as an int... 
                    //...and test if its within the range specified
                    printf("\nINVALID KEY"); //this just prints an error message for the user...
                    exit(0); //... and exits the program if the key is not between 1-25
            }
            else { //else is used here instead of else if as anything not in the range exits the program
                printf("\nKey selected: %d\n", key); //This simply prints the chosen key for the user
                RCipher(key, message); //This is the function which encrypts and decrypts messages
                //This function passes the value of 'key' and 'messsge' which the user inputted...
                //... the function is a void type and only prints the message from there directly not returning any values
                exit(0); //After running the function, the program exits
                } 
                //The encryption process only affects letters, first converting to capital letters if not already
                //... then rotating them according to the key
                //No 'break' statement is required as the program exits instead
            case 1: // 'case 1:' is for decryption of a rotational cipher
                //This works on the same principle as the encryption 
                scanf(" %[^\n]s", message); // scans the message written until a new line 
                //The [^\n] does the scanf function as normal except it reads till a new line is found as opposed to whitespace
                printf("Encrypted message is: %s", message); // this prints the message itself 
                //this also works to check for any issue in scanning the message by the user (manually)
                printf("Enter cipher key ranging from 1-25 (Inclusive) onto line 2 of 'input':"); //Prompt for the user
                scanf("%d", &key); //This reads the key from the user
                if (key < 1 || key > 25){ // this ensures the user has inputted a key from 1-25
                    printf("\nINVALID KEY\n"); //any value outside 1-25 prints this error message...  
                    exit(0); //...and the program exits
                }
                else {
                    printf("\nKey selected: %d\n", key); //This prints the value of the key for the user
                    key=key*-1;
                    RCipher(key, message); //This is the function which encrypts and decrypts messages
                    //This function passes the value of 'key' and 'messsge' which the user inputted...
                    //... the function is a void type and only prints the message from there directly not returning any values
                    //Only letters are altered in this decryption, first converted to capital letters then rotated
                    //All other characters are left unaffected
                    exit(0); //Upon the function being completed the program exits
                }
            case 2: //'case 2:' is for encrypion using a substitution cipher
                //Neither the encryption or decryption for substitution ciphers uses functions as they are both unique with minimal overlap
                printf("Enter message to be encrypted onto line 2 of 'input'.\n"); //This is a prompt for the user
                printf("Enter substitution key in alphabetical order with no spaces onto line 3 of 'input'."); //This is also a prompt
                scanf(" %[^\n]s", message); //This scans and stores the value of 'message' until a new line is read
                scanf("%s", sub); //This reads the substitution input from the reader until whitespace is found
                //That is why the prompt says 'with no spaces'
                if(sub[26] != '\0'){ //if the 26th character of 'sub' is not the null character then the program prints...
                    printf("\n**ERROR**\n-Substitution requires 26 unique letters in alphabetical order of substitution desired."); //... this error message...
                    exit(0); //... and exits the program
                }
                //else is not required here as the program would otherwise have exitted
                for(int i=0; sub[i] != '\0'; ++i){ //This creates a 'for' loop which reads each character until the null character
                    if(sub[i] <=122 && sub[i] >= 97) //Any lower case letters (With ascii values between 97 and 122) are converted to capitals...
                        sub[i] = sub[i] - 32; //... by taking away 32 from their value
                    count = count + sub[i]; //This adds each ascii value one by one to produce a sum
                }
                if(count != 2015){ //2015 is the sum of the ascii values of 'A' to 'Z', this 'if' statement checks to ensure that...
                    //... each letter has only been inputted once as any letter inputted more than once would produce a different value...
                    //... for 'count' and the program would exit
                    printf("\n**ERROR**\n-Substitution requires 26 unique letters in alphabetical order of substitution desired.");
                    exit(0);
                }
                printf("\nSubstitution in alphabetical order is: "); 
                printf("%s\n", sub); //This prints the substitution after converting to capitals
                printf("Original message is:\n%s", message); //this prints the original message//
                printf("Encrypted message is: \n"); //... followed by the encrypted message
                //notice there is no string printed in the above message as all characters are passed up individually
                for(int i=0; message[i] != '\0' && i <= n; ++i ){
                    //This 'for' loop counts until either the null character is read or n characters have been read
                    if (message[i] <=122 && message[i] >=97) //This converts letters in 'message' to uppercase
                        message[i] = message[i] - 32;

                    //This switch statement evaluates the value of each character in 'message'...
                    //... and depending on what letter it is, it is replaced with the corresponding letter in 'sub'
                    //This switch statement is long but it prints each character one at a time
                    switch(message[i]){
                    case 65: //for example if there is an 'A' in message (ascii value of 65) it is replaced with...
                    message[i]=sub[0]; //... the first letter in 'sub' (which is sub[0])
                    printf("%c", message[i]); //Then the character is printed by itself
                    break; // 'break' stops the switch case from continuing on
                    case 66:
                    message[i]=sub[1]; //This cycle continues onwards testing each character of 'message'
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
                    default: //'default' means what happens if none of the cases are met
                    //In this instance only capital letters should be affected therefore anything else is printed without alteration
                    printf("%c", message[i]);                    
                    }
            }             
            exit(0); //once the message is finished being printed the program exits
            case 3: // case 3 works similar to case 2 however it is a bit more complicated
                printf("Enter message to be decrypted onto line 2 of 'input'.\n"); //This is a prompt for the user
                printf("Enter substitution key in alphabetical order with no spaces onto line 3 of 'input'."); //This is another prompt for the user
                scanf(" %[^\n]s", message); //This scans the message until a new line is read
                scanf("%s", sub); //This reads the substitution until whitespace (This is why the prompt says 'no spaces')
                //anything after whitespace will not be read in 'sub' 
                if(sub[26] != '\0'){ //this 'if' statement ensures there are only 26 characters in 'sub'...
                    printf("\n**ERROR**\nSubstitution requires 26 unique letters in alphabetical order of substitution desired.");
                    exit(0); //... otherwise an error message is printed and the program exits
                }
                for(int i=0; sub[i] != '\0'; ++i){ //This creates a 'for' loop which reads each character until the null character
                    if(sub[i] <=122 && sub[i] >= 97) //Any lower case letters (With ascii values between 97 and 122) are converted to capitals...
                        sub[i] = sub[i] - 32; //... by taking away 32 from their value
                    count = count + sub[i]; //This adds each ascii value one by one to produce a sum
                }
                if(count != 2015){ //2015 is the sum of the ascii values of 'A' to 'Z', this 'if' statement checks to ensure that...
                    //... each letter has only been inputted once as any letter inputted more than once would produce a different value...
                    //... for 'count' and the program would exit
                    printf("\n**ERROR**\n-Substitution requires 26 unique letters in alphabetical order of substitution desired.");
                    exit(0);
                }
                printf("\nSubstitution in alphabetical order is: ");
                printf("%s\n", sub); //This prints the substitution in all caps
                printf("Original message is:\n%s", message); //This prints the encrypted message
                printf("Decrypted message is: \n"); //this is the first half of the message, like the encryption substitution...
                //... the decryption prints one character at a time
                for(int i = 0; message[i] != '\0' && i <= n; ++i ){ //This 'for' loop counts each character until n characters or the null character
                    if(message[i] <=122 && message[i] >=97){ //Any lowercase letters are first converted to capitals
                        message[i] = message[i] - 32;
                    }
                    
                    if(count != 2015){ //2015 is the sum of the ascii values of 'A' to 'Z', this 'if' statement checks to ensure that...
                    //... each letter has only been inputted once as any letter inputted more than once would produce a different value...
                    //... for 'count' and the program would exit
                    printf("\n**ERROR**\n-Substitution requires 26 unique letters in alphabetical order of substitution desired.");
                    exit(0);
                    }
                    //This switch case scans each character from 'message' and tests to see what its value is
                    //If its value is a letter it is replaced with the correpsonding letter in substitution
                    switch(message[i]){
                    case 65: //for example if there is an 'A' in 'message'...
                    for(x=0; x<= 26; x++){ //... this 'for' loop will match it to an 'A' in 'sub'...
                        if(sub[x] == message[i]) //... by counting through each letter in sub (to 26)...
                            printf("%c", alphabet[x]); //... and printing the letter from 'alphabet'
                    }
                    //'alphabet' is used to record all the letters that might be needed, and printing the letters anytime required
                    // Difficult process to explain essentially when a letter is read from 'message' it is tested to find where that letter is located...
                    //... in 'sub' and replaced with the letter in alphabet that corresponds to it
                    //'x' is used as a counter to find where the letters line up so they can be swapped
                    //When an 'A' is scanned in 'message' it is compared to 'sub' and the location in the array of 'sub' is compared...
                    //... to the location in 'alphabet' and replaced with the letter there i.e. if 'A' is the 6th letter in 'sub'...
                    //... it is replaced with the 6th letter in 'alphabet' (alphabet[5] which is 'E') and then printed
                    break; //This stops the switch statement from contiuing when an 'A' is read
                    case 66:
                    for(x=0; x<= 26; x++){ //the 'for' loop counts
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
                    default: //The default statement prints everything else that is not a capital letter, one character at a time
                    printf("%c", message[i]);                    
                    }

            }             
                
            exit(0);
            case 4: //case 4 is for decrypting a rotational message without being given a key
                //This is a very specific way to decrypt messages with a rotational cipher, only possible with one letter words being either 'A' or 'I'
                //Any other possibility such as no one letter words will not work with this program
                printf("Enter message to be deciphered: \n"); //This is a prompt for the user
                scanf(" %[^\n]s", message); //This scans the message until a new line character is read
                printf("Encrypted message is: %s", message); //This prints the string entered by the user
                for(int i=0; i<n && message[i] != '\0'; i++){ //this 'for' loop converts any lowercase letters to capital letters
                    if(message[i] <=122 && message[i] >=97){ //This converts any lowercase letters to uppercase
                        message[i] = message[i] - 32;
                    }
                    //This next part finds the first one letter word in the message...
                    //... by testing for a space, followed by a letter followed by another space
                    if(message[i] == 32 && S != 1000){ //This is a test condition to find any one letter words
                    //message[i] == 32 is for finding a space, the condition of S != 1000 makes it so the first one letter word found is used
                        x=i; //adding values to i to test the next letter in 'message' did not seem to work, however using 'message[x]'...
                        //... and changing the values of x worked for the desired purpose
                        while(x<(i+2)){ //This 'while' loop tests for the next two characters in 'message'...
                            x++; //... by incrementing x...
                            if(message[x] == 32){ //... and testing if there is another space two characters after the first one
                                //essentially this just searches for any one letter words, making it quite unreliable if there...
                                //... are no one letter words or there are any other single characters with spaces on either side
                                S=1000; //Setting S to equal 1000 ensures that it will only test for single letter words until one is found
                            }
                        }
                    }
                        
                    
                }
                if(S==1000){ //If a single letter is found...
                    printf("\nSingle letter word/s found.\n"); 
                    printf("Assume this is 'A':\n"); //... it is assumed to be 'A'
                    x--; //x is decremented here as its old value was the value after the one letter word and the character is what we need
                    key = message[x] - 65; //The key is then changed to the value of the distance from the value of the one letter word
                    printf("Key is: %d\n", key); //This prints the key to ensure no errors in calculating the key
                    //The positive value for key is printed first so the user knows the key used to rotate the text
                    key = key*-1; //The value for key is made negative as there is only one function for encryption and decryption...
                    //... where the value for 'key' is either added or subtracted
                    //This means that if the one letter word in 'message' is 'B' then key becomes 66-65 which is 1, meaning the original...
                    //... message was rotated using a key of 1, if the first one letter word was an 'A' in 'message'
                    RCipher(key, message); //This is the function which encrypts and decrypts messages
                    //This function passes the value of 'key' and 'messsge' which the user inputted...
                    //... the function is a void type and only prints the message from there directly not returning any values
                    /*for (int i=0; i<n && message[i] != '\0'; i++){
                        //this creates a 'for' loop which reads each character one by one
                        if (message[i] <=90 && message[i] >= 65){ //this 'if' statement checks if any character is a capital letter...
                            message[i] = message[i] - key; //... then rotates it according to the key
                            if(message[i] < 65) //if a character goes past '65'... 
                               message[i] = message[i] + 26; //... 26 is added to loop it back
                        }
                    }*/
                    //Only letters are altered in this decryption: first converted to capital letters then rotated
                    //All other characters are left unaffected
                    //printf("Deciphered message is: %s", message); //This prints the final message...
                    printf("\nIf this message is incorrect enter '1' onto line 3 of 'input'\n"); //This is for the user to determine whether or not...
                    //... the single letter word was 'A'
                    scanf("%d", &test);
                    if(test == 1){ //If the word was not 'A' then the same process as before occus however now it assumes the one letter word is 'I'
                        key = message[x] - 73; //'73' is the ascii value for 'I' and this determines the distance between the character and 'I'...
                        //... and then reassigning 'key' to this value
                        if(key <= 0){ //if key goes below '1' it needs to loop back to have a positive value for 'key'
                            key = key + 26; //This causes the rotation of key if 'message[x]' is smaller than '73' so there is no negative value for key
                        }
                        printf("Assume the single letter word is now 'I':\n"); //This is so the user knows what is happening
                        printf("Key is: %d \n", key); //This prints the new key
                        for (int i=0; i<n && message[i] != '\0'; i++){
                            //this creates a 'for' loop which reads each character one by one
                            if (message[i] <=90 && message[i] >= 65){ //this 'if' statement checks if any character is a capital letter...
                            message[i] = message[i] - key; //... then rotates it according to the key
                            if(message[i] < 65) //if a character goes past '65'... 
                               message[i] = message[i] + 26; //... 26 is added to loop it back
                            }
                        }
                        printf("Deciphered message is: %s", message); //This then prints the entire message altered
                    }
                    else exit(0); //If the user does not enter '1' onto line 3 of 'input' the program will exit
                }
                else {
                    printf("\nPROGRAM FAILED TO DECIPHER MESSAGE\n");
                    printf("-recommend testing keys 1-25 with operator 1");
                    //Ran out of time to come up with another way to decrypt without key, for rotational cipher there is only 25 keys so testing each key...
                    //... would not take that long with this program
                    exit(0); //The program will then sadly exit upon failing to decrpyt a message
                }
            exit(0);
            case(5):
                printf("ERROR\nI did not have time to even attempt this part :'(");
            exit(0);
        }
    return 0;
}

void RCipher(int key, char message[]){
    int n = 1024;
    for (int i=0; i<n && message[i] != '\0'; i++){
        //This creates a 'for' loop which tests each character one by one in 'message' until the null 0 character is read...
        //... or the program reads too many characters (Greater than the value for n)
        if (message[i] <=122 && message[i] >=97){ //This tests the ascii value of each character and if it is...
            //... between 97 and 122 it is a lowercase letter
            message[i] = message[i] - 32; // if it is a lowercase letter it is converted to a capital by taking away '32' from its value
        }
        if (message[i] <=90 && message[i] >= 65){ //between 65 and 90 are the capital letters
            //This 'if' statement will only affect capital letters leaving anything else unchanged (such as symbols)
            message[i] = message[i] + key;
            if(message[i] >90) //this makes the letters rotate around instead of continuing...
                message[i]=message[i] - 26; //... by minusing 26 if the ascii value exceeds 90
            else if(message[i] <65) //Since this function works to encrypt and decrypt it is important to ensure that any rotation is looped...
            //... if the rotation causes the message to go outside the range of capital letters
                message[i]=message[i] + 26; //Adding 26 makes it rotate if it goes below the range of capital letters
        }
    }
    printf("Message is: "); //once each character has been altered accordingly the program prints the new message
    printf("%s", message); //The message is printed here as a whole string rather than each character like it does with the substitution cipher
}


