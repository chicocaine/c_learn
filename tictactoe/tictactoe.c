#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void PrintBoard(char board[9]);
int CheckBoard(char board[9]);
void ComputerMove(char board[9], char playChar);
void PlayerMove(char board[9], char playChar);

int main()
{
  int gameTurn = 0;  
  int gameOver = 0;
  char playChar = 'X';
  char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

  char firstMove;

  printf("TIC TAC TOE GAME!\n");
  printf("Who will go first? [c: computer || p: player]\n");
  if (scanf("%c", &firstMove) != 1) {
    printf("Error reading input.\n");
    return 1;
  }
 
  switch (tolower(firstMove))
  {
    case('c'):
      gameTurn = 1;
      break;
    case('p'):
      gameTurn = 0;
      break;
    default:
      printf("Invalid choice.");
  }

  while(!gameOver) 
  {
    PrintBoard(board);
    if (gameTurn == 1) 
    {
      ComputerMove(board, playChar);
    }
    else if (gameTurn == 0)
    {
      PlayerMove(board, playChar);
    }
    
    int checkBoard = CheckBoard(board);
    if (checkBoard > 0)
    {
      if (checkBoard == 2)
      {
        printf("Tie!\n");
        gameOver = 1;
        break;
      }
      if (gameTurn == 1)
      {
        printf("Computer Wins!\n");
        gameOver = 1;
        break;
      }
      printf("Player Wins!\n");
      gameOver = 1;
      break;
    }
    playChar = playChar == 'X' ? 'O' : 'X';
    gameTurn = !gameTurn;
  }
  
  return 0;
}

void PrintBoard(char board[9])
{
  printf(" %c | %c | %c \n", board[0], board[1], board[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[3], board[4], board[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int CheckBoard(char board[9]) 
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == ' ') 
    {
      break;
    }
    else if (i == 8)
    {
      return 2;
    }
  }

  if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
      (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')) return 1;

  for (int i = 0; i < 3; i++ )
  {
    if ((board[3*i] == board[3*i + 1] && board[3*i + 1] == board[3*i + 2] && board[3*i] != ' ') ||
        (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i] && board[0 + i] != ' ')     
    ) return 1;
  }

  return 0;
}

void ComputerMove(char board[9], char playChar)
{
  srand(time(0));

  printf("Computer plays:\n");

  int boardEmpty = 1;
  int moveLocation;
  int possibleMoveLocations[9];
  int claimedTiles[9];
  int pClaimedTiles[9];

  if (boardEmpty)
  {
    for (int i = 0; i < 9; i++)
    {
      if (board[i] != ' ')
      {
        boardEmpty = !boardEmpty;
        break;
      }
    }
  }

  if (boardEmpty)
  {
    moveLocation = rand() % 9;
    board[moveLocation] = playChar;
    return;
  }

  // look for own pieces
  for (int i = 0; i < 9; i++)
  {
    if (board[i] == playChar )
    {

    }
  }
  // look for opponents pieces



}

void PlayerMove(char board[9], char playChar)
{
  int moveLocation;
  printf("Where to place move? [1, ... 9]\n");
  if (scanf("%d", &moveLocation) != 1) {
    printf("Error reading input.\n");
    return;
  }
  board[moveLocation-1] = playChar;
}