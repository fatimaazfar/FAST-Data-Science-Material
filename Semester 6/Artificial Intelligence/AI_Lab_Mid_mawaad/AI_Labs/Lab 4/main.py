import pygame
import copy
import math
import random

# Define the colors we will use in RGB format
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)

# This sets the WIDTH and HEIGHT of each grid location
WIDTH = 100
HEIGHT = 100

# This sets the margin between each cell
MARGIN = 5

# Set up the Pygame window
WINDOW_SIZE = [300, 300]
screen = pygame.display.set_mode(WINDOW_SIZE)

# Set the caption of the window
pygame.display.set_caption("Tic Tac Toe")

# Define constants for the players
X = "X"
O = "O"
D = "D"
EMPTY = None

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]

def draw_board(board):
    """
    This function draws the board on the screen.
    """
    # Clear the screen
    screen.fill(WHITE)
    # Draw the grid lines
    for row in range(3):
        for column in range(3):
            pygame.draw.rect(screen, BLACK, [(MARGIN + WIDTH) * column + MARGIN,
                                             (MARGIN + HEIGHT) * row + MARGIN,
                                             WIDTH,
                                             HEIGHT])
            if board[row][column] == X:
                # Draw an X
                pygame.draw.line(screen, RED, [(MARGIN + WIDTH) * column + MARGIN + 25,
                                              (MARGIN + HEIGHT) * row + MARGIN + 25],
                                 [(MARGIN + WIDTH) * (column + 1) - MARGIN - 25,
                                  (MARGIN + HEIGHT) * (row + 1) - MARGIN - 25], 10)
                pygame.draw.line(screen, RED, [(MARGIN + WIDTH) * (column + 1) - MARGIN - 25,
                                              (MARGIN + HEIGHT) * row + MARGIN + 25],
                                 [(MARGIN + WIDTH) * column + MARGIN + 25,
                                  (MARGIN + HEIGHT) * (row + 1) - MARGIN - 25], 10)
            elif board[row][column] == O:
                # Draw an O
                pygame.draw.circle(screen, RED, [(MARGIN + WIDTH) * column + MARGIN + WIDTH // 2,
                                                 (MARGIN + HEIGHT) * row + MARGIN + HEIGHT // 2], WIDTH // 2 - MARGIN, 10)
    # Update the screen
    pygame.display.update()

def player(board):
    """
    Returns player who has the next turn on a board.
    """
    count = 0
    for i in board:
        for j in i:
            if j:
                count += 1
    if count % 2 != 0:
        return O
    return X

def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    res = set()
    board_len = len(board)
    for i in range(board_len):
        for j in range(board_len):
            if board[i][j] == EMPTY:
                res.add((i, j))
    return res

def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board):
        raise Exception("Invalid action")
    new_board = copy.deepcopy(board)
    new_board[action[0]][action[1]] = player(board)
    return new_board

def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] is not None:
            return board[i][0]
        if board[0][i] == board[1][i] == board[2][i] and board[0][i] is not None:
            return board[0][i]
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] is not None:
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] is not None:
        return board[0][2]
    return None

def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) is not None:
        return True
    for i in board:
        for j in i:
            if j is None:
                return False
    return True

def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    return 0

def alpha_beta_pruning(board):
    """
    Returns the optimal action for the current player on the board using the alpha-beta pruning algorithm.
    """
    curr_player = player(board)

    if curr_player == X:
        v = float('-inf')
        for action in actions(board):
            result_board = result(board, action)
            alpha_beta_value = alpha_beta(result_board, float('-inf'), float('inf'), O)
            if alpha_beta_value > v:
                v = alpha_beta_value
                optimal_action = action

    elif curr_player == O:
        v = float('inf')
        for action in actions(board):
            result_board = result(board, action)
            alpha_beta_value = alpha_beta(result_board, float('-inf'), float('inf'), X)
            if alpha_beta_value < v:
                v = alpha_beta_value
                optimal_action = action

    return optimal_action

def alpha_beta(board, alpha, beta, maximizing_player):
    """
    Returns the minimax value of the board using alpha-beta pruning.
    """
    if terminal(board):
        return utility(board)

    if maximizing_player == X:
        v = float('-inf')
        for action in actions(board):
            result_board = result(board, action)
            v = max(v, alpha_beta(result_board, alpha, beta, O))
            alpha = max(alpha, v)
            if beta <= alpha:
                break
        return v

    elif maximizing_player == O:
        v = float('inf')
        for action in actions(board):
            result_board = result(board, action)
            v = min(v, alpha_beta(result_board, alpha, beta, X))
            beta = min(beta, v)
            if beta <= alpha:
                break
        return v
    
def main():
    """
    This function runs the game.
    """
    # Initialize the game
    pygame.init()
    # Set the HEIGHT and WIDTH of the screen
    WINDOW_SIZE = [320, 320]
    screen = pygame.display.set_mode(WINDOW_SIZE)
    # Set title of screen
    pygame.display.set_caption("Tic Tac Toe")
    # Loop until the user clicks the close button.
    done = False
    # Used to manage how fast the screen updates
    clock = pygame.time.Clock()
    # Initialize the board
    board = initial_state()
    # Draw the grid
    draw_board(board)
    # -------- Main Program Loop -----------
    while not done:
        # --- Main event loop
        for event in pygame.event.get():  # User did something
            if event.type == pygame.QUIT:  # If user clicked close
                done = True  # Flag that we are done so we exit this loop
            elif event.type == pygame.MOUSEBUTTONDOWN:
                # User clicks the mouse. Get the position
                pos = pygame.mouse.get_pos()
                # Change the x/y screen coordinates to grid coordinates
                column = pos[0] // (WIDTH + MARGIN)
                row = pos[1] // (HEIGHT + MARGIN)
                # Set that location to one
                if board[row][column] == EMPTY:
                    board[row][column] = player(board)
                    draw_board(board)
                    if not terminal(board):
                        board = result(board, alpha_beta_pruning(board))
                        draw_board(board)
                    if terminal(board):
                        # Display the winner
                        if winner(board) == "X":
                            print("X wins!")
                        elif winner(board) == "O":
                            print("O wins!")

                        else:
                            print("Tie!")
                        # Wait 2 seconds
                        pygame.time.wait(2000)
                        done = True
        # --- Limit to 60 frames per second
        clock.tick(60)
    # Close the window and quit.
    pygame.quit()

if __name__ == "__main__":
    main()

