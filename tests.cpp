#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("Encrypt")
{
	CHECK(encryptCaesar("Way to Go!", 5)== "Bfd yt Lt!");
	CHECK(encryptCaesar("Hello, World!", 10)== "Rovvy, Gybvn!");
}

TEST_CASE("Decrypt")
{
	CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
	CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
}

