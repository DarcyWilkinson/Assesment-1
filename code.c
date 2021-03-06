/* this program is to convert text as string into encoded text using a 
 * rotation cipher with user input into the stdin, selecting between 
 * encryption and decryptionusing a switch case to form a simple menu  
 * and function definitions tooptimise code readibility.............. */

#include<stdio.h>
#include<ctype.h>

/* both the encryption and decryption functions take an integer
 * that the user has input at the start to mark how many "shifts"
 * occur and also places in a string of text to encrypr/decrypt
 * return value is void as the function prints the rotated text*/

void encrypt(char code[], int key);
void decrypt(char code[], int key);

int main()
{
    char code[100];
    int key;
    
    printf("enter code in CAPS ONLY: ");
    gets(code); // reads from stdin and puts it in a string terminating at the newline character (\n)
    
    printf("\n enter rotation key: \n"); // new line at the start to seperate from previous input
    scanf("%d", &key); 
    
    int decider;
    printf("enter 1 for encrypt 2 for decrypt \n"); // simple menu to choose whether to encrypt or decrypt text
    scanf ("%d", &decider); // reads the number input by user
        switch (decider) 
        {
            case 1:  
                encrypt(code, key);
            break; 
           
            case 2: 
                decrypt(code, key);
            break;
            
            default: printf("error"); //if its anything apart from 1 or 2
        }

         return 0;
}

void encrypt(char code[], int key)
{
    int point = 0;
    
    
    for(point = 0; code[point] != '\0'; ++point) //starting at the first char in the string and exiting at a null
    {    
        code[point] = 65 + (code[point]-65+key)%26; // takes an individual point and add on the key and use modulus to get integer
        //Begins at A and adds onto it to get the correct letter
    }
    
    printf("encrypted text: %s\n", code);
}

void decrypt(char code[], int key)
{
    int point = 0;
        
    for(point = 0; code[point] != '\0'; ++point) //starting at the first char in the string and exiting at a null
    {    
        code[point] = 65 + (code[point]-65-key)%26; // takes an individual point and takes away the key and use modulus to get integer
        //Begins at A and goes backwards onto it to get the correct letter
    }
    
    printf("decrypted text: %s\n", code); // prints after the whole string has been changed
}