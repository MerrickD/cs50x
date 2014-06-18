/**
 * vigenere.c
 * 
 * Merrick A. Dennis
 * merrickd@verizon.net 
 * 
 * Implementation of the Vigenère cipher (http://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
 *
 */


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_cipher(string message, int k);

int main(int argc, string argv[]) {
	
	// clear the screen via stdlib.h
	system("clear");

	char* char_string = argv[1];

	// only accept a single command-line argument	
	if (argc == 1 || argc > 2) {
		printf("Single command-line argument only, please!\n");
		return 1;
	}

	// only accept alphabetical input for the cipher word
	for (int i = 0; char_string[i] != '\0'; i++) {
		bool is_alpha = isalpha(argv[1][i]);
		if (is_alpha == false) {
			printf("I only accept alphabetical input.\n");
			return 2;
		}
	}

	// get message to cipher from user
	printf("Message to cipher: ");
	string message = GetString();

	printf("===============================\n");
	printf("Message: %s\n", message);	
	printf("Cipher text: %s\n", argv[1]);
	printf("===============================\n");

	// print_cipher(message, atoi(argv[1]));
	
}

// print the encrypted message
void print_cipher(string message, int k) {	

	
}
