#include <stdio.h>
#include <stdlib.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>


void repeatKey(wchar_t *key, wchar_t *message, wchar_t *repeatedKey) {
    size_t messageLen = wcslen(message);
    size_t keyLen = wcslen(key);
    size_t i, j;

    for (i = 0, j = 0; i < messageLen; i++, j++) {
        if (j == keyLen) {
            j = 0;
        }
        repeatedKey[i] = key[j];
    }
    repeatedKey[messageLen] = L'\0';  
}


int main(void) {
    
    setlocale(LC_ALL, "");

	// 1024 est la taille maximale du message (modifiable)
    	size_t buffer_size = 1024 ;  	
	char Choice[3] ; 

	printf("Voulez-vous chiffrer (1) ou déchiffrer (2) ?\n") ;
	fgets(Choice, 3, stdin) ;

	if (*(&Choice[0]) != '1' && *(&Choice[0]) != '2') {
        	printf("Choix invalide.\n");
        	return 1 ; 
    	}
	
    	
   	wchar_t* buffer = (wchar_t*)calloc(buffer_size, sizeof(wchar_t)) ;
	if (buffer == NULL) {
        	fwprintf(stderr, L"Erreur d'allocation de mémoire pour le tampon\n") ;
        	return 1 ;
    	}

    	fwprintf(stdout, L"Entrez le message : \n") ;
    	if (fgetws(buffer, buffer_size, stdin) == NULL) {
        	fwprintf(stderr, L"Erreur de lecture de l'entrée\n") ;
        	free(buffer) ;
        	return 1 ;
    	}

    	size_t size_message = wcslen(buffer) ;
    	if (size_message > 0 && buffer[size_message - 1] == L'\n') {
        	buffer[size_message - 1] = L'\0' ;
        	size_message-- ;
    	}

    	wchar_t* message = (wchar_t*)calloc(size_message + 1, sizeof(wchar_t)) ;
    	if (message == NULL) {
        	fwprintf(stderr, L"Erreur d'allocation de mémoire pour le message\n") ;
        	free(buffer) ;
        	return 1 ;
    	}
    	wcscpy(message, buffer) ;

    	wchar_t* cipher_message = (wchar_t*)calloc(size_message + 1, sizeof(wchar_t)) ;
    	if (cipher_message == NULL) {
        	fwprintf(stderr, L"Erreur d'allocation de mémoire pour le message chiffré\n") ;
        	free(message) ;
        	free(buffer) ;
        	return 1 ;
    	}

    	wchar_t* cle = (wchar_t*)calloc(size_message + 1, sizeof(wchar_t)) ;
    	if (cle == NULL) {
        	fwprintf(stderr, L"Erreur d'allocation de mémoire pour la clé\n") ;
        	free(cipher_message) ;
        	free(message) ;
        	free(buffer) ;
        	return 1 ;
    	}

    	fwprintf(stdout, L"Entrez la clé : \n") ;
    	if (fgetws(buffer, buffer_size, stdin) == NULL) {
        	fwprintf(stderr, L"Erreur de lecture de l'entrée pour la clé\n") ;
        	free(cle) ;
        	free(cipher_message) ;
        	free(message) ; 
        	free(buffer) ;
        	return 1 ;
    	}

    	size_t size_key = wcslen(buffer) ;
    	if (size_key > 0 && buffer[size_key - 1] == L'\n') {
        	buffer[size_key - 1] = L'\0' ;
        	size_key-- ;
    	}

    	repeatKey(buffer, message, cle) ;
       
    	free(buffer) ; 

	if (*(&Choice[0]) == '1') {

    // Chiffrement
	for (size_t i = 0 ; i < size_message ; i++) {
    		int message_val = (int)message[i] ;
   	 	int key_val = (int)cle[i] ;
		if (message[i] == L' ') {
     			cipher_message[i] = L' ' ; 
		} else {
    			cipher_message[i] = (wchar_t)((message_val + key_val) % 0x10FFFF) ;
		}

	}

    	cipher_message[size_message] = L'\0' ; 

    	fwprintf(stdout, L"%ls", cipher_message) ;

    	// Libération de la mémoire
    	free(cle) ;
    	free(cipher_message) ;
    	free(message) ;

    	return 0 ;
	}

	if (*(&Choice[0]) == '2') {

	    // Déhiffrement du message
    	for (size_t i = 0 ; i < size_message ; i++) {
    		int message_val = (int)message[i] ;
   	 	    int key_val = (int)cle[i] ;
		    if (message[i] == L' ') {
    			cipher_message[i] = L' ' ; 
		    } else {
			    cipher_message[i] = (wchar_t)((message_val - key_val) % 0x10FFFF) ;
		}
	}
    cipher_message[size_message] = L'\0' ; 

    	// Affichage du message déchiffré
    	fwprintf(stdout, L"%ls", cipher_message) ;

    	// Libération de la mémoire
    	free(cle) ;
    	free(cipher_message) ;
    	free(message) ;

    	return 0 ;
	}

	return 1 ;

}
