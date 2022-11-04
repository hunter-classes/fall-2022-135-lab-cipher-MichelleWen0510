/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab Cipher

Decrypt caesar.
*/
#include <iostream>
#include <string>
#include "decrypt.h"

char unshiftChar(char c, int rshift)
{
	char shifted;
	if(isupper(c))
	{
		shifted=char(int(c+(26-rshift)-65)%26+65);
	} else {
		shifted=char(int(c+(26-rshift)-97)%26+97);
	}
	return shifted;
}

std::string decryptCaesar(std::string ciphertext,int rshift)
{
	std::string message;
	char letter;
	int check;
	for(int i=0;i<ciphertext.length();i++)
	{
		letter=ciphertext[i];
		check=(int)letter;
		if((check>=65 && check<=90) ||(check>=97 && check<=122))
		{  
			message=message+unshiftChar(letter,rshift);
		} else {
			message=message+letter;
		}
	}
	return message;
}

