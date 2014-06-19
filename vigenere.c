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

void print_cipher(string message, char *k[]);
int shift(int letter);

int main(int argc, char *argv[]) {
	
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

	print_cipher(message, argv);
	
}

// print the encrypted message
// c = (p_i + k_j) % 26
void print_cipher(string message, char *k[]) {

	int j = 0;

	for (int i = 0; i <= strlen(message); i++) {
		// Check if the current character needs to be encrypted
		if (isalpha(message[i])) {
			// Cipher uppercase letters
			if (isupper(message[i])) {
				printf("%c", (((message[i] - 65) + shift(k[1][j])) % 26) + 65);				
			}
			// Cipher lowercase letters
			else if (islower(message[i])) {						
				printf("%c", (((message[i] - 97) + shift(k[1][j])) % 26) + 97);				
			}
		}
		// If the character is not a letter, just print it.
		else {
			printf("%c", message[i]);
			continue;
		}
		// Don't increment past the length of the cipher word; -1 because of carriage return
		if (j == strlen(k[1]) - 1) {
			j = 0;
		} else {
			j++;
		}
	}
	printf("\n");
	
}

// get the shift value for the supplied letter of the key
int shift(int letter) {

	if (isupper(letter)) {
		int shift = letter - 65;
		return shift;
	} else if (islower(letter)) {
		int shift = letter - 97;
		return shift;
	}

	return 0;
}
