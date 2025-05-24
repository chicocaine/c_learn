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
  scanf("%c", &firstMove);
 
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
    }
    else if (gameTurn == 0)
    {
      PlayerMove();
    }
    if (CheckBoard(board) == 1)
    {
      if (gameTurn == 1)
      {
        printf("Computer Wins!\n");
        break;
      }
      printf("Player Wins!\n");
      break;
    }
    gameTurn = !gameTurn;
  }
  
  return 0;
}

void PrintBoard(char board[9])
{
  printf("%c | %c | %c \n", board[0], board[1], board[2]);
  printf("---|----|---");
  printf("%c | %c | %c \n", board[3], board[4], board[5]);
  printf("---|----|---");
  printf("%c | %c | %c \n", board[6], board[7], board[8]);
}

int CheckBoard(char board[9]) 
{
  for (int i = 0; i < 3; i++ )
  {
    if (board[3*i] == board[3*i + 1] == board[3*i + 2] ||
        board[0 + i] == board[3 + i] == board[6 + i]      
    ) return 1;
  }
  if (board[0] == board[4] == board[8] || board[2] == board[4] == board [6]) return 1;
  return 0;
}

void ComputerMove()
{

}

void PlayerMove()
{

}