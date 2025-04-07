
### 2. **Documentation de Conception**

Cette documentation explique la structure du code, les principales fonctions et comment compiler/exécuter le projet. Voici un exemple de ce que tu pourrais inclure :

```markdown
# Documentation de Conception - Tic-Tac-Toe

## Structure du projet

Le projet est structuré de la manière suivante :

- `tictactoe.c` : Fichier principal contenant l'implémentation du jeu.
- `README.md` : Documentation du projet.
- `Makefile` (si applicable) : Fichier de compilation pour faciliter le build du projet.

### Fonctionnalités principales :
1. **Affichage du tableau** : La fonction `draw_board()` gère l'affichage du tableau de jeu en utilisant `ncurses`.
2. **Gestion des mouvements des joueurs** : Les fonctions `player_move()` et `ai_move()` permettent de gérer les coups du joueur et de l'IA, respectivement.
3. **Vérification du gagnant** : La fonction `check_winner()` vérifie si un joueur a gagné ou si la partie est un match nul.
4. **Historique des parties** : Les jeux joués sont sauvegardés dans `game_history[]`, et la fonction `replay_game()` permet de rejouer une partie passée.

### Compilation et exécution :
1. Compile le code avec la commande suivante :
   ```bash
   gcc -o tictactoe tictactoe.c -lncurses
