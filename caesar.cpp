/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab Cipher

Added a solve function.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include "caesar.h"
#include "decrypt.h"

char shiftChar(char c, int rshift)
{
	char shifted;
	if(isupper(c))
	{
		shifted=char(int(c+rshift-65)%26+65);
	} else {
		shifted=char(int(c+rshift-97)%26+97);
	}
	return shifted;
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
	std::string message;
	char letter;
	int check;
	for(int i=0;i<plaintext.length();i++)
	{
		letter=plaintext[i];
		check=(int)letter;
		if((check>=65 && check<=90) ||(check>=97 && check<=122))
		{  
			message=message+shiftChar(letter,rshift);
		} else {
			message=message+letter;
		}
	}
	return message;
}

std::string solve(std::string encrypted_string)
{
	std::string line=encrypted_string;
	std::string rotate;
	std::vector<double> freq;
	std::vector<double> standard{0.0816,0.0149,0.0278,0.0425,0.1270,0.0222,
	0.0201,0.0609,0.0696,0.0015,0.0077,0.0402,0.0240,0.0674,0.0750,0.0192,
	0.0009,0.0598,0.06327,0.0905,0.0275,0.0097,0.0236,0.0015,0.0197,0.0007};
	//Frequency from mathcenter.oxford.emory.edu/site/math125/englishLetterFreqs/
	int shift;
	double closest=1;
	double current;
	for(int i=0;i<26;i++)
	{
		rotate=encryptCaesar(line, i);
		for(int j=0;j<26;j++)
		{
			freq.push_back(freqChar(rotate,char(97+j)));
		}
		for(int k=0;k<26;k++)
		{
			current=sqrt(pow(k-k,2)+pow(freq.at(k)-standard.at(k),2));
			if(current<closest)
			{
				closest=current;
				shift=i;
			}
		}
		
	}
	return decryptCaesar(encrypted_string,shift);

}

double freqChar(std::string line, char letter)
{
	double count=0;
	for(int i=0;i<line.length();i++)
	{
		if(line[i]==letter || tolower(line[i])==letter)
		{
			count++;
		}
	}
	if(count==0)
	{
		return 0;
	} else {
		return count/line.length();
	}
}
