#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#define MAX_CHARACTER 1423          // ֏ est le dernier caractère (Arménien)
#define MAX_MESSAGE_LENGTH 15000  


void repeatKey(wchar_t *key, wchar_t *message, wchar_t *repeatedKey) {
    int messageLen = wcslen(message);
    int keyLen = wcslen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; i++, j++) {
        if (j == keyLen) {
            j = 0;
        }
        repeatedKey[i] = key[j];
    }
    repeatedKey[messageLen] = L'\0';  
}


int main () {
 
   setlocale(LC_ALL, "") ;
   wchar_t Tableau_Alphabet[MAX_CHARACTER][MAX_CHARACTER], Message[MAX_MESSAGE_LENGTH], Key[MAX_MESSAGE_LENGTH], repeatedKey[MAX_MESSAGE_LENGTH], MessageChiffre[MAX_MESSAGE_LENGTH] ;
   int Choice ;
    

   printf("Voulez-vous Chiffrer (1) ou Déchiffrer (2) ?\n") ;
   scanf("%d", &Choice) ;
   getchar();

   // définition du Tableau de Vigenere
   for (int i = 0 ; i < MAX_CHARACTER ; i++) {          
      for (int j = 0 ; j < MAX_CHARACTER ; j++) {
         int index = (j + i) % MAX_CHARACTER ;
         wchar_t wcc = index + 32  ;          
         Tableau_Alphabet[i][j] = wcc ;
      }
   }

   if (Choice == 1) {

   // récupération du message 
   printf("Entrez le message à chiffrer : \n") ;
   fgetws(Message, sizeof(Message) / sizeof(wchar_t), stdin) ;
   size_t messageLen = wcslen(Message);

      if (Message[messageLen - 1] == L'\n') {
         Message[messageLen - 1] = L'\0';
      }
   
   // récupération de la clé
   printf("Entrez la clé de chiffrement : \n") ;
   fgetws(Key, sizeof(Key) / sizeof(wchar_t), stdin) ;
   size_t keyLen = wcslen(Key) ;
 
      // enlève la séquence d'échapement de retour à la ligne
      if (Key[keyLen - 1] == L'\n') {
         Key[keyLen - 1] = L'\0' ;
      }

      // répétition de la clé en fonction du message, sortie : repeatedKey
      repeatKey(Key, Message, repeatedKey) ;

   
   // chiffrement 
   for (int i = 0 ; i < MAX_MESSAGE_LENGTH && Message[i] != '\0' ; i++) {
      for (int j = 0 ; j < MAX_CHARACTER ; j++) {
         if (Message[i] == Tableau_Alphabet[0][j]) {
            for (int l = 0 ; l < MAX_CHARACTER ; l++) {
               if (repeatedKey[i] == Tableau_Alphabet[l][0]) {
                  MessageChiffre[i] = Tableau_Alphabet[l][j] ; break ;
               }
            }
         }
      }
   }

   // nettoyage de la clé de chiffrement
   for (int i = 0 ; i < MAX_MESSAGE_LENGTH ; i++) {
      Key[i] = 0 ; repeatedKey[i] = 0 ;
   }

   wprintf(L"%ls", MessageChiffre) ;

   } 

   if (Choice == 2) {

   // récupération du message 
   printf("Entrez le message à déchiffrer : \n") ;
   fgetws(Message, sizeof(Message) / sizeof(wchar_t), stdin) ;
   size_t messageLen = wcslen(Message);

      if (Message[messageLen - 1] == L'\n') {
         Message[messageLen - 1] = L'\0';
      }
   
   // récupération de la clé
   printf("Entrez la clé de chiffrement : \n") ;
   fgetws(Key, sizeof(Key) / sizeof(wchar_t), stdin) ;
   size_t keyLen = wcslen(Key) ;
 
      // enlève la séquence d'échapement de retour à la ligne
      if (Key[keyLen - 1] == L'\n') {
         Key[keyLen - 1] = L'\0' ;
      }

      // répétition de la clé en fonction du message, sortie : repeatedKey
      repeatKey(Key, Message, repeatedKey) ;

   
   // déchiffrement 
   for (int i = 0 ; i < (sizeof(Key) / sizeof(wchar_t)) && repeatedKey[i] != '\0'; i++) {
      for (int j = 0 ; j < MAX_CHARACTER ; j++) {
         if (repeatedKey[i] == Tableau_Alphabet[j][0]) {
            for (int l = 0 ; l < MAX_CHARACTER ; l++) {
               if (Message[i] == Tableau_Alphabet[j][l]) {
                  MessageChiffre[i] = Tableau_Alphabet[0][l] ; break ;
               }
            }
         }
      }
   }
   MessageOrigine[messageLen] = L'\0' ;
   // nettoyage de la clé de chiffrement
   for (int i = 0 ; i < MAX_MESSAGE_LENGTH ; i++) {
      Key[i] = 0 ; repeatedKey[i] = 0 ;
   }

   wprintf(L"%ls", MessageChiffre) ;

   } 

return 0 ;
}


// Contact : 
// ¦²¶­¸Ç¥¾¼­¹¼¼³²µµ}¯´Á
// Clé : Violet
// Coller avec les caracères de contrôle
