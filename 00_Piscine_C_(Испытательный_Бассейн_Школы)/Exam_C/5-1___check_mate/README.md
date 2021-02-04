# check_mate

## Conceptual Overview
### The Problem
We are asked to write a program that takes arguments of strings representing rows of an arbitrarily sized square chessboard containing one king and arbitrary opposing pieces. If the king is in check, the program prints "Success", otherwise it prints "Fail".

<details>
	<summary>Full Subject</summary>

```
	Assignment name  : check_mate 
	Expected files   : *.c, *.h
	Allowed functions: write, malloc, free
	--------------------------------------------------------------------------------

	Write a program that takes rows of a chessboard as its argument and checks if
	the King is in a check position.

	Chess is played on a chessboard, a square 8 by 8 board with 
	distinct pieces on it: King, Queen, Bishop, Knight, Rook and Pawns.
	For this exercise, you will only play with Pawns, Bishops, Rooks and Queen...
	and obviously a King.

	Each piece has a unique pattern of capture. All patterns of capture are
	detailed in the examples.txt file.

	A piece can capture only the first enemy piece it finds in its capture
	pattern.

	The board will have a variable size but will remain a square. There will
	only be one King and all other pieces are against it.
	All other characters except those used for pieces are considered empty squares.

	The King is considered as in a check position when an enemy piece can
	capture it.
	When this is the case, you will print "Success" on the standard output
	followed by a newline, otherwise you will print "Fail" followed by a newline.

	If there are no arguments, the program will print only a newline.

	Examples:

	$> ./check_mate '..' '.K' | cat -e
	Fail$
	$> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
	Success$
	$> ./check_mate 'R...' 'iheK' '....' 'jeiR' | cat -e
	Success$
	$> ./check_mate | cat -e
	$
	$>
```
</details>

<details>
	<summary>Capture Patterns</summary>

```
	Pion / Pawn (P):

		. . . . . . .
		. . . . . . .
		. . X . X . .
		. . . P . . .
		. . . . . . .
		. . . . . . .
		. . . . . . .

	Fou / Bishop (B):

		X . . . . . X
		. X . . . X .
		. . X . X . .
		. . . B . . .
		. . X . X . .
		. X . . . X .
		X . . . . . X

	Tour / Rook (R):

		. . . X . . .
		. . . X . . .
		. . . X . . .
		X X X R X X X
		. . . X . . .
		. . . X . . .
		. . . X . . .

	Dame / Queen (Q)

		X . . X . . X
		. X . X . X .
		. . X X X . .
		X X X Q X X X
		. . X X X . .
		. X . X . X .
		X . . X . . X 
```
</details>

### References
* [Subject File (English)](subject.en.txt)
* [Capture Patterns](examples.txt)
* [check_mate_iterative.c (iterative, longer but simpler coding concepts)](check_mate.c)
* [check_mate.c (recursive, shorter but more advanced)](check_mate.c)

### Approach
* Find the location of the king.
* Starting from the king's location, check in every direction for pieces that can capture the king, stopping upon reaching a piece that cannot capture the king or upon reaching the edge of the board.
	* Check directly upward, downward, leftward, and rightward for queens (Q) and rooks (R).
	* Check diagonally up & left, up & right, down & left, and down & right for queens (Q) and bishops (B). Check in the single space down & left and the single space down & left of the king for pawns.
* If a piece that can capture the king is found, print "Success\n" and exit, otherwise print "Fail\n" and exit.

### Code
```C
#include <unistd.h>

typedef struct s_pos
{
	int row;
	int col;
}				t_pos;

t_pos	find_king(int board_size, char **board)
{
	int row = 0;
	int col;
	while (row < board_size)
	{
		col = 0;
		while (col < board_size)
		{
			if (board[row][col] == 'K')
				return ((t_pos){row, col}); // Returns struct t_pos with values of row, col
			++col;
		}
		++row;
	}
	return ((t_pos){-2, -2});
}

int		check_capture(t_pos pos, t_pos direction, int b_size, char **board)
{
	pos.row += direction.row;
	pos.col += direction.col;
	if (pos.row < 0 || pos.row >= b_size || pos.col < 0 || pos.col >= b_size)
		return (0);

	if (board[pos.row][pos.col] == 'Q')
		return (1);
	else if (board[pos.row][pos.col] == 'R')
		return (direction.row == 0 || direction.col == 0); // Returns 1 if true, 0 if false
	else if (board[pos.row][pos.col] == 'B')
		return (direction.row != 0 && direction.col != 0); // Returns 1 if true, 0 if false
	else if (board[pos.row][pos.col] == 'P')
		return (direction.row == 1 && direction.col != 0
				&& board[pos.row - 1][pos.col - direction.col] == 'K'); // Returns 1 if true, 0 if false

	return (check_capture(pos, direction, b_size, board));
}

int		check_mate(int board_size, char **board)
{
	t_pos king_pos = find_king(board_size, board);

	return (
		check_capture(king_pos, (t_pos){-1, -1}, board_size, board)
		|| check_capture(king_pos, (t_pos){-1, 0}, board_size, board)
		|| check_capture(king_pos, (t_pos){-1, 1}, board_size, board)
		|| check_capture(king_pos, (t_pos){0, -1}, board_size, board)
		|| check_capture(king_pos, (t_pos){0, 1}, board_size, board)
		|| check_capture(king_pos, (t_pos){1, -1}, board_size, board)
		|| check_capture(king_pos, (t_pos){1, 0}, board_size, board)
		|| check_capture(king_pos, (t_pos){1, 1}, board_size, board)
		); // Returns 1 if logical test is true, 0 if false
}

int		main(int ac, char **av)
{
	if (ac < 2)
		write(1, "\n", 1);
	else if (check_mate(ac - 1, &av[1]))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	return (0);
}
```

### Test Cases
`./check_mate 'K....' '.....' '..P..' '.....' '....Q'`

##### Moulinette's Tests
```
./check_mate

./check_mate '...B.' '.B...' '$%^&*' '...K.' '.....'
Success
./check_mate  "...B." ".T..." "....." "...K." "....."
Fail
./check_mate "K"
Fail
./check_mate "BPKP" "PRP." ".Q.." "..P."
Fail
./check_mate "B....." "......" "......" "......" "......" ".....K"
Success
./check_mate "K....." "......" "......" "......" "......" ".....B"
Success
./check_mate '........' '........' '.P....P.' '...B.B..' '....Q...' '..R..R..' '......K.' '...R....'
Fail
```