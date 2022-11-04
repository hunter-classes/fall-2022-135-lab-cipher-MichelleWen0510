#include <iostream>
#include "caesar.h"

int main()
{
	std::string text="Once upon a time there was a dear little girl who was loved by every one who looked at her, but most of all by her grandmother, and there was nothing that she would not have given to the child. Once she gave her a little cap of red velvet, which suited her so well that she would never wear anything else. So she was always called Little Red Riding Hood.";
	std::cout << "Caesar Encrypt: " << std::endl;
	std::string encrypt=encryptCaesar(text,5);
	std::cout << encrypt << std::endl;

	std::cout << "Caesar Decrypt: " << std::endl;
	std::string decrypt=solve(encrypt);

}
