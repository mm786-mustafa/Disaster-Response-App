//admin
#include<iostream>
#include<iomanip>
//#include"User.h"

using namespace std;



string encryptPassword(const string &password, int shift) 
{
    string encryptedPassword = password;

    for (size_t i = 0; i < encryptedPassword.length(); ++i) 
	{
	    char &ch = encryptedPassword[i];
	    if (isalpha(ch)) {
	        char base = isupper(ch) ? 'A' : 'a';
	        ch = (ch - base + shift) % 26 + base;
	    }
	}


    return encryptedPassword;
}

// Function to verify a user-entered password against the stored encrypted password
bool verifyPassword(const string &storedPassword, const string &enteredPassword, int shift) 
{
    return encryptPassword(enteredPassword, shift) == storedPassword;
}








