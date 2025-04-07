#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 3

char board[SIZE][SIZE];
int moves[SIZE * SIZE][2], move_count = 0;

// Scores
int x_wins = 0, o_wins = 0, draws = 0;

typedef struct {
    char board[SIZE][SIZE];
    char winner;
} GameHistory;

GameHistory game_history[100];
int game_history_count = 0;

void init_board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
    move_count = 0;
}

void draw_board(int cursor_x, int cursor_y) {
    clear();
    mvprintw(0, 0, " TIC-TAC-TOE ");
    mvprintw(1, 0, "==============");

    // Dessiner le cadre
    mvaddch(2, 0, ACS_ULCORNER);
    mvhline(2, 1, ACS_HLINE, SIZE * 4 + 1);
    mvaddch(2, SIZE * 4 + 2, ACS_URCORNER);

    for (int i = 0; i < SIZE; i++) {
        mvaddch(i * 2 + 3, 0, ACS_VLINE);
        for (int j = 0; j < SIZE; j++) {
            if (i == cursor_y && j == cursor_x) {
                attron(A_REVERSE);
                mvprintw(i * 2 + 3, j * 4 + 1, " %c ", board[i][j]);
                attroff(A_REVERSE);
            } else {
                mvprintw(i * 2 + 3, j * 4 + 1, " %c ", board[i][j]);
            }
            if (j < SIZE - 1) mvprintw(i * 2 + 3, j * 4 + 3, "|");
        }
        mvaddch(i * 2 + 3, SIZE * 4 + 2, ACS_VLINE);
        if (i < SIZE - 1) mvprintw(i * 2 + 4, 0, "---+---+---");
    }

    mvaddch(SIZE * 2 + 3, 0, ACS_LLCORNER);
    mvhline(SIZE * 2 + 3, 1, ACS_HLINE, SIZE * 4 + 1);
    mvaddch(SIZE * 2 + 3, SIZE * 4 + 2, ACS_LRCORNER);
    refresh();
}

int check_winner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];
    return move_count == SIZE * SIZE ? 'D' : 0;
}

void player_move(char symbol) {
    int cursor_x = 0, cursor_y = 0;
    int ch;
    while (1) {
        draw_board(cursor_x, cursor_y);
        ch = getch();
        if (ch == 'q') exit(0);
        else if (ch == KEY_UP && cursor_y > 0) cursor_y--;
        else if (ch == KEY_DOWN && cursor_y < SIZE - 1) cursor_y++;
        else if (ch == KEY_LEFT && cursor_x > 0) cursor_x--;
        else if (ch == KEY_RIGHT && cursor_x < SIZE - 1) cursor_x++;
        else if (ch == ' ' && board[cursor_y][cursor_x] == ' ') {
            board[cursor_y][cursor_x] = symbol;
            moves[move_count][0] = cursor_y;
            moves[move_count][1] = cursor_x;
            move_count++;
            break;
        }
    }
}

void ai_move(char symbol) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board[y][x] != ' ');

    board[y][x] = symbol;
    moves[move_count][0] = y;
    moves[move_count][1] = x;
    move_count++;
    draw_board(-1, -1);
    usleep(500000);
}

void save_game_to_history(char winner) {
    GameHistory game;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            game.board[i][j] = board[i][j];

    game.winner = winner;
    game_history[game_history_count++] = game;
}

void replay_game(int game_index) {
    init_board();
    GameHistory game = game_history[game_index];
    move_count = 0;

    // Rejouer les coups enregistrés dans l'historique
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (game.board[i / SIZE][i % SIZE] != ' ') {
            board[i / SIZE][i % SIZE] = game.board[i / SIZE][i % SIZE];
            draw_board(-1, -1); // Dessiner le tableau après chaque coup
            usleep(500000); // Pause pour voir l'animation
        }
    }

    char winner = check_winner();
    mvprintw(14, 0, "Replayed Winner: %c", winner);
    getch(); // Attendre une touche avant de revenir au menu
}

// Fonction pour réinitialiser les scores, l'historique et l'état du jeu
void reset_game() {
    x_wins = 0;
    o_wins = 0;
    draws = 0;
    game_history_count = 0;
    init_board();
}

void game_loop(int mode) {
    init_board();
    char turn = 'X';
    while (!check_winner()) {
        if (mode == 3 || (mode == 2 && turn == 'O')) ai_move(turn);
        else player_move(turn);
        turn = (turn == 'X') ? 'O' : 'X';
    }

    char winner = check_winner();
    if (winner == 'X') x_wins++;
    else if (winner == 'O') o_wins++;
    else draws++;

    save_game_to_history(winner); // Enregistrer la partie dans l'historique
    draw_board(-1, -1);
    mvprintw(14, 0, "Winner: %c", winner);
    getch();
}

void display_scores() {
    mvprintw(5, 0, "Scores:");
    mvprintw(6, 0, "X wins: %d", x_wins);
    mvprintw(7, 0, "O wins: %d", o_wins);
    mvprintw(8, 0, "Draws: %d", draws);
}

void menu() {
    int choice = 0;
    int ch;
    while (1) {
        clear();
        mvprintw(2, 0, " TIC-TAC-TOE MENU ");
        mvprintw(3, 0, "=================");
        display_scores();

        char *options[] = {"Player vs Player", "Player vs AI", "AI vs AI", "Replay", "Reset", "Quit"};
        for (int i = 0; i < 6; i++) {
            if (i == choice) {
                attron(A_REVERSE);
                mvprintw(10 + i, 0, "%s", options[i]);
                attroff(A_REVERSE);
            } else {
                mvprintw(10 + i, 0, "%s", options[i]);
            }
        }
        refresh();
        ch = getch();
        if (ch == KEY_UP && choice > 0) choice--;
        else if (ch == KEY_DOWN && choice < 5) choice++;
        else if (ch == '\n') {
            if (choice == 5) break; // Quitter le jeu
            else if (choice == 4) { // Option Reset
                reset_game(); // Réinitialiser le jeu
            } else if (choice == 3) { // Option Replay
                clear();
                mvprintw(5, 0, "Select game to replay:");
                for (int i = 0; i < game_history_count; i++) {
                    mvprintw(6 + i, 0, "Game %d: Winner %c", i + 1, game_history[i].winner);
                }
                refresh();
                int game_choice = getch() - '1';  // Convertir la touche en indice de jeu
                if (game_choice >= 0 && game_choice < game_history_count) {
                    replay_game(game_choice);
                }
            } else { // Lancer une nouvelle partie
                game_loop(choice + 1);
            }
        }
    }
}

int main() {
    srand(time(0));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    menu();
    endwin();
    return 0;
}
