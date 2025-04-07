# Documentation Utilisateur - Tic-Tac-Toe

## Lancement du jeu

1. Clonez le dépôt sur votre machine.
2. Installez la bibliothèque `ncurses` si elle n'est pas encore installée.
```bash
sudo apt install libncurses5-dev libncursesw5-dev
```
4. Compilez le code avec `gcc -o tictactoe tictactoe.c -lncurses`.
5. Lancez le jeu avec `./tictactoe`.

## Commandes du jeu

- **Déplacement du curseur** : Utilisez les touches fléchées pour déplacer le curseur sur le tableau.
- **Placer un symbole** : Appuyez sur la barre d'espace pour placer votre symbole (X ou O) à l'emplacement sélectionné.
- **Quitter le jeu** : Appuyez sur la touche `q` pour quitter à tout moment.
- **Rejouer une partie précédente** : Depuis le menu, sélectionnez l'option "Replay", puis choisissez une partie à rejouer.
- **Réinitialiser les scores** : Sélectionnez "Reset" pour réinitialiser les scores et l'historique des jeux.

## Modes de jeu

Le jeu propose plusieurs modes de jeu :

1. **Player vs Player** : Deux joueurs s'affrontent en prenant chacun leur tour.
2. **Player vs AI** : Un joueur affronte l'IA qui joue de manière aléatoire.
3. **AI vs AI** : Deux IA s'affrontent entre elles. Vous pouvez observer leur partie.
