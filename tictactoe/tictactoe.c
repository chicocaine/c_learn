#include <stdio.h>
#include <string.h>
#include <ctype.h>

void PrintBoard(char board[3][3]);
void CheckBoard(char board[3][3]);
void ComputerMove();
void PlayerMove();

int main()
{
  int gameTurn = 0;  
  int gameOver = 0;
  char board[3][3];

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
    gameTurn = !gameTurn;
    CheckBoard(board);
  }
  

  return 0;
}

void PrintBoard(char board[3][3])
{
  printf("%c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|----|---");
  printf("%c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|----|---");
  printf("%c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void CheckBoard(char board[3][3]) 
{

}

void ComputerMove()
{

}

void PlayerMove()
{

}