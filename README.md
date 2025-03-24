# Jeu de Tic-Tac-Toe (C)

Il s'agit d'un jeu simple de Tic-Tac-Toe implémenté en C utilisant la bibliothèque `ncurses`. Le jeu propose plusieurs modes, dont Joueur contre Joueur, Joueur contre IA et IA contre IA. Il inclut également un tableau des scores qui suit les victoires de 'X' et 'O', ainsi que les égalités.

## Fonctionnalités

- **Modes de jeu** :
  - **Joueur contre Joueur** : Deux joueurs humains jouent sur la même machine.
  - **Joueur contre IA** : Un joueur humain contre une IA.
  - **IA contre IA** : Deux IA jouent l'une contre l'autre.
  
- **Tableau des scores** :
  - Suivi du nombre de victoires de 'X', 'O' et des parties nulles.
  
- **Replay** : Permet de revoir une partie jouée.

## Prérequis

- Système UNIX (Linux, macOS, etc.)
- Bibliothèque `ncurses` installée sur ton système.

### Installation de ncurses

Sur **Ubuntu/Debian** :
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
