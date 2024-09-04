# Chiffre de Vigenère
Un chiffre de Vigenère universel qui prend en compte TOUT les caractères Unicode et les chiffre selon le principe de Vigenère.

## Installation

```zsh
gcc -o Vigenère Vigenère.c
```
## Usage
Lors de l'ouverture de l'exécutable ce message s'affiche :
```bash
Voulez-vous Chiffrer (1) ou Déchiffrer (2) ?
```
Quelques exemples de chiffrement (haut) et de déchiffrement (bas) :
```bash
1
Entrez le message : 
A æ💀‹ࢢญጩ ឦᮗᰜ∑⨕𐁍
Entrez la clé : 
Github
 Ś📨₮率ࣩ๶᎝ ᠛᯹ᱣ≺⪉𐂵
```
```bash
2
Entrez le message : 
 Ś📨₮率ࣩ๶᎝ ᠛᯹ᱣ≺⪉𐂵
Entrez la clé : 
Github
A æ💀‹ࢢญጩ ឦᮗᰜ∑⨕𐁍
```
Remarque : Ce chiffre ne peut pas être brisé si la taille de la clé est égale à la taille du message. Plus une clé est longue plus elle diminue la fréquence d'apparition de répétition de chaines de caractères dans le texte chiffré , donc sa probabilité d'être brisé. 

Contact à la fin du code source.


