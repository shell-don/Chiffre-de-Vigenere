# Chiffre de Vigenère
Un chiffre de Vigenère universel qui ne prend en compte que les alphabets occidentaux modernes (jusqu'au point de code 1423) ce qui comprend le Latin de base et étendu, l'alphabet phonétique international, le Grec, le Copte, le Cyrillique et l'Arménien mais aussi des caractères de commandes et des diacritiques. 

## Installation

```zsh
gcc -o Vigenère Vigenère.c
```
## Usage
Lors de l'ouverture de l'exécutable ce message s'affiche :
```bash
Voulez-vous Chiffrer (1) ou Déchiffrer (2) ?
```
Quelques exemples de chiffrement (haut) et de déchiffrement (bas), décalage de 2 (modifiable) :
```bash
1
Entrez le message à chiffrer : 
A§*£`<ñŽƱʬʄ˧ξϾζѨБԬփ     
Entrez la clé de chiffrement : 
GitHub
hð~Ëµ~Ęǆȅ˔˙̩ϥчЊҐѦծ֪
```
```bash
2
Entrez le message à déchiffrer : 
hð~Ëµ~Ęǆȅ˔˙̩ϥчЊҐѦծ֪
Entrez la clé de chiffrement : 
GitHub
A§*£`<ñŽƱʬʄ˧ξϾζѨБԬփ
```
Remarque : Ce chiffre ne peut pas être brisé si la taille de la clé est égale à la taille du message. Plus une clé est longue plus elle diminue la fréquence d'apparition de répétition dans le texte chiffré de caractères, donc sa probabilité d'être brisé. 

Contact à la fin du code source.


