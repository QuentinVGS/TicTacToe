# Documentation de Conception - Tic-Tac-Toe

## Structure du projet

Le projet est structuré de la manière suivante :

- `tictactoe.c` : Fichier principal contenant l'implémentation du jeu.
- `README.md` : Documentation du projet.
- `Makefile` (si applicable) : Fichier de compilation pour faciliter la création du projet.

  
## Explication des principales fonctions

 **Affichage du tableau** : La fonction `draw_board()` gère l'affichage du tableau de jeu en utilisant la bibliothèque `ncurses`.
 
 **Gestion des mouvements des joueurs** : Les fonctions `player_move()` et `ai_move()` permettent de gérer les coups du joueur et de l'IA, respectivement.
 
 **Vérification du gagnant** : La fonction `check_winner()` vérifie si un joueur a gagné ou si la partie se termine par un match nul.
 
 **Historique des parties** : Les jeux joués sont sauvegardés dans le tableau `game_history[]`, et la fonction `replay_game()` permet de rejouer une partie passée.
 
 **`draw_board()`** : Cette fonction est responsable de l'affichage du tableau de jeu. Elle utilise la bibliothèque `ncurses` pour afficher un tableau de 3x3 avec les symboles 'X' et 'O'. Elle met également en surbrillance la case sélectionnée par le joueur.
 
 **`player_move()`** : Cette fonction permet au joueur de faire un mouvement en déplaçant le curseur et en sélectionnant une case vide sur le tableau.
 
 **`ai_move()`** : Cette fonction génère un mouvement aléatoire pour l'IA, en plaçant son symbole sur une case vide.
 
 **`check_winner()`** : Cette fonction vérifie si un joueur a gagné la partie en inspectant les lignes, les colonnes et les diagonales du tableau. Elle renvoie 'X' ou 'O' si un joueur a gagné, 'D' pour un match nul, ou 0 si la partie continue.
 
 **`save_game_to_history()`** : Cette fonction enregistre l'état actuel du jeu et le gagnant dans l'historique des parties pour permettre un replay ultérieur.
 
 **`replay_game()`** : Permet de rejouer une partie enregistrée dans l'historique. Les coups sont rejoués avec une petite pause entre chaque.

## Compilation et exécution

1. Compilez le code avec la commande suivante :
   ```bash
   gcc -o tictactoe tictactoe.c -lncurses
