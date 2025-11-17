#include "globals.h"

// side represents the side to move; xside is the opposite side
int side, xside;
// ply represents the number of half-moves made in the current search
int ply;

// hply represents the number of half-moves made in the entire game
int hply;

//
int nodes;

int board[64];

int color[64]; // represents color of pieces on squares

int kingloc[2]; // represents the location of the kings for both sides

int history[64][64]; // history table used in sorting moves

// ?
int square_score[2][64][64];

// store the position in the endgame for each square
int king_endgame[2][64];

// store total material value of pawns for both sides
int pawn_mat[2];

// store total material value of pieces for both sides
int piece_mat[2][64];

// // store value of passed pawns for both sides
int passed _pawn[2][64];

int qrb_moves[64][9];
int knight_moves[64][9];
int king_moves[64][9];

// below three arrays are used to handle move lists
move move_list[MOVE_STACK];
int first_move[MAX_PLY];
game game_list[GAME_STACK];

// following characters are used to represent pieces on the board
char piece_char[6] = {'P', 'N', 'B', 'R', 'Q', 'K'};

// value of pieces in centipawns
int piece_value[6] = {100, 300, 300, 500, 900, 10000};

int init_color[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1};

int init_piece[64] = {
    3, 1, 2, 4, 5, 2, 1, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 1, 2, 4, 5, 2, 1, 3};

const int col[64] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7};

const int row[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7};

// Flip array to convert square from one side to another
// e.g., a1(0) to a8(56), b1(1) to b8(57), etc.
int Flip[64] = {
    56, 57, 58, 59, 60, 61, 62, 63,
    48, 49, 50, 51, 52, 53, 54, 55,
    40, 41, 42, 43, 44, 45, 46, 47,
    32, 33, 34, 35, 36, 37, 38, 39,
    24, 25, 26, 27, 28, 29, 30, 31,
    16, 17, 18, 19, 20, 21, 22, 23,
    8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7};

int pawn_score[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 4, -12, -12, 4, 2, 0,
    0, 2, 4, 4, 4, 4, 2, 0,
    0, 2, 4, 8, 8, 4, 2, 0,
    0, 2, 4, 8, 8, 4, 2, 0,
    4, 8, 10, 16, 16, 10, 8, 4,
    100, 100, 100, 100, 100, 100, 100, 100,
    0, 0, 0, 0, 0, 0, 0, 0};
