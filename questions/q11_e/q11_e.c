/*
In this exercise, you will create a simple program that simulates a login form. The program will receive a username and user ID from the command line, compare these with predefined credentials, and output a message indicating whether the login was successful.

Tasks
Define Credentials: Inside your program, define variables for a username and another variable for a user ID.
 Set their values to "JohnDoe" and "12345"

Receive Input: The program should accept two command-line arguments: the first for the username and the second for the user ID.

Compare Credentials: Use the strcmp function to compare the inputted credentials with the ones you defined. Check if both the username and user ID match.

Output a Message:

If the details are correct, print: "Hello to user _____ Id _____ you have successfully logged in", replacing the blanks with the appropriate username and user ID.
If the details are incorrect, print: "Incorrect login details".

*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Define predefined credentials
    char *username = "JohnDoe";
    char *user_id = "12345";

 

    // Compare input credentials with predefined ones
    if (strcmp(argv[1], username) == 0 && strcmp(argv[2], user_id) == 0)
    {
        printf("Hello to user %s Id %s you have successfully logged in", username, user_id);
    }
    else
    {
        printf("Incorrect login details\n");
    }
    return 0;
}