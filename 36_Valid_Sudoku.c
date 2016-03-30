/**
    * File Name: 36_Valid_Sudoku.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/30/16
*/

/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * The A partially filled sudoku which is valid.
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#define SIZE 10

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int check[SIZE];
	int i, j;
	bool rval = true;

	// Row check
	for (i = 0; i < boardColSize; i++) {
		memset(check, 0, sizeof(check));
		for (j = 0; j < boardRowSize; j++) {
			if (board[i][j] == '.') {
				continue;
			}
			if (check[board[i][j] - '0']) {
				return false;
			}
			check[board[i][j] - '0'] = 1;
		}
	}

	// Col check
	for (i = 0; i < boardRowSize; i++) {
		memset(check, 0, sizeof(check));
		for (j = 0; j < boardColSize; j++) {
			if (board[j][i] == '.') {
				continue;
			}
			if (check[board[j][i] - '0']) {
				return false;
			}
			check[board[j][i] - '0'] = 1;
		}
	}

	// 3x3 check
	for (i = 0; i < boardColSize; i += 3) {
		for (j = 0; j < boardRowSize; j += 3) {
			memset(check, 0, sizeof(check));
			for (int m = 0; m < 3; m++) {
				for (int n = 0; n < 3; n++) {
					if (board[i + m][j + n] == '.') {
						continue;
					}
					if (check[board[i + m][j + n] - '0']) {
						return false;
					}
					check[board[i + m][j + n] - '0'] = 1;
				}
			}
		}
	}

	return true;
}
