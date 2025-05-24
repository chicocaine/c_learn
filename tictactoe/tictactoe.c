#include <stdio.h>
#include <string.h>
#include <ctype.h>

void PrintBoard(char board[9]);
int CheckBoard(char board[9]);
void ComputerMove();
void PlayerMove();

int main()
{
  int gameTurn = 0;  
  int gameOver = 0;
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
      ComputerMove();
      break;
    }
    else if (gameTurn == 0)
    {
      PlayerMove();
      break;
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
    else 
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

void ComputerMove()
{
  printf("Computer goes first.\n");
}

void PlayerMove()
{
  printf("Player goes first.\n");
}