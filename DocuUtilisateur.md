
### 3. **Documentation Utilisateur**

Cette documentation explique comment démarrer l'application et utiliser ses fonctionnalités. Voici un exemple :

```markdown
# Documentation Utilisateur - Tic-Tac-Toe

## Lancement du jeu

1. Clonez le dépôt sur votre machine.
2. Installez la bibliothèque `ncurses` si elle n'est pas encore installée.
3. Compilez le code avec `gcc -o tictactoe tictactoe.c -lncurses`.
4. Lancez le jeu avec `./tictactoe`.

## Commandes du jeu

- **Déplacement du curseur** : Utilisez les touches fléchées pour déplacer le curseur sur le tableau.
- **Placer un symbole** : Appuyez sur la barre d'espace pour placer votre symbole (X ou O) à l'emplacement sélectionné.
- **Quitter le jeu** : Appuyez sur la touche `q` pour quitter à tout moment.
- **Rejouer une partie précédente** : Depuis le menu, sélectionnez l'option "Replay", puis choisissez une partie à rejouer.
- **Réinitialiser les scores** : Sélectionnez "Reset" pour réinitialiser les scores et l'historique des jeux.

## Modes de jeu

- **Joueur vs Joueur** : Deux joueurs humains jouent alternativement.
- **Joueur vs IA** : Un joueur humain joue contre l'IA.
- **IA vs IA** : Deux IA s'affrontent.

## Suivi des scores

Le jeu enregistre le nombre de victoires pour X, O et les matchs nuls. Les scores sont affichés en haut du menu principal.
