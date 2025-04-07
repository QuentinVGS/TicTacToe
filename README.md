# Jeu Tic-Tac-Toe en Terminal avec ncurses

## Description

Ce projet implémente le jeu **Tic-Tac-Toe** avec une interface terminal grâce à la bibliothèque `ncurses`. Le jeu permet de jouer en mode **Joueur vs Joueur**, **Joueur vs IA** et **IA vs IA**. Il inclut un système de scores, un historique des parties et la possibilité de rejouer des parties précédentes.

## Fonctionnalités

- **Joueur vs Joueur (PvP)**
- **Joueur vs IA (PvAI)**
- **IA vs IA (AIvAI)**
- **Suivi des scores** : Victoires, nuls, défaites.
- **Historique des parties** : Sauvegarde et relecture des parties.
- **Réinitialisation** : Réinitialise les scores et l'historique.

## Installation et Compilation

1. Clonez le projet :
   ```bash
   git clone https://github.com/votreutilisateur/tic-tac-toe.git
   cd tic-tac-toe
Installez ncurses (si nécessaire) :

Debian/Ubuntu : sudo apt-get install libncurses5-dev

macOS (Homebrew) : brew install ncurses

Compilez avec make :

bash
Copier
Modifier
make
Lancez le jeu :

bash
Copier
Modifier
./tic-tac-toe
Utilisation
Touches directionnelles : Déplacez le curseur sur le plateau.

Espace : Placez votre symbole.

Touche q : Quittez le jeu.

Menu : Choisissez le mode de jeu, rejouez une partie ou quittez.

Réinitialisation
La réinitialisation efface les scores et l'historique des parties. Elle est disponible dans le menu principal après chaque partie.

Auteurs
[Votre Nom] : Développeur principal
