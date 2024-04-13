def is_valid(board, row, col, num):
    # Check if the number is already present in the current row
    for i in range(3):
        if board[row][i] == num and i != col:
            return False

    # Check if the number is already present in the current column
    for i in range(3):
        if board[i][col] == num and i != row:
            return False

    # Check if the number is already present in the current 3x3 subgrid
    return True

def solve_sudoku(board):
    empty_cell = find_empty_cell(board)
    if empty_cell is None:
        return True  # All cells filled, puzzle solved

    row, col = empty_cell
    for num in range(1, 4):  # Numbers from 1 to 3 (inclusive)
        if is_valid(board, row, col, num):
            board[row][col] = num
            if solve_sudoku(board):
                return True
            board[row][col] = 0  # Backtrack if solution not found
    return False

def find_empty_cell(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return (i, j)
    return None  # No empty cell found

def print_board(board):
    for row in board:
        print(row)

# Example Sudoku board (0 represents empty cells)
board = [
    [0, 0, 3],
    [0, 1, 0],
    [2, 0, 1]
]

print("Sudoku Board (Initial):")
print_board(board)
print("\nSolving Sudoku...\n")

if solve_sudoku(board):
    print("Sudoku Board (Solved):")
    print_board(board)
else:
    print("No solution exists.")
