#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print_cipher(string message, int k);

int main(int argc, string argv[]) {
	
	// clear the screen via stdlib.h
	// system("clear");

	// only accept a single command-line argument	
	if (argc == 1 || argc > 2) {
		printf("Single command-line argument only, please!\n");
		return 1;
	}	

	// get message to cipher from user
	// printf("Message to cipher: ");
	string message = GetString();

	// printf("===============================\n");
	// printf("Message: %s\n", message);	
	// printf("Cipher strength: %s\n", argv[1]);
	// printf("===============================\n");

	print_cipher(message, atoi(argv[1]));
	
}

/**
 * implementation of Caesar cipher
 * c = (p + k) % 26
 */
void print_cipher(string message, int k) {	

	for (int i = 0; i <= strlen(message); i++) {
		if (isalpha(message[i])) {
			// Cipher uppercase letters
			if (isupper(message[i])) {
				printf("%c", (((message[i] - 65) + k) % 26) + 65);
			}
			// Cipher lowercase letters
			else if (islower(message[i])) {
				printf("%c", (((message[i] - 97) + k) % 26) + 97);
			}
		}
		// If the character is not a letter, just print it.
		else {
			printf("%c", message[i]);
		}
	}
	printf("\n");
}
