#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
 
// function prototypes
void setup_board();
void display_board();
void set_coordsto();
void set_coordsfrom();
void move_validation_and_updation();
int king_state();

// global variables
char piece_moved;
char board[10][10];
char choice;
char move[5];
short x, y, a, b;
int i;

int main()
{ 
  char pR;
  int j,asc1,asc2,s=10;

  //here first of all we setup the board, by giving proper values to the matrix
  setup_board();

  //here we show the rules of the game and ask if the players are ready or not,in order to start the game
   printf("\n\n-------------------------------START-------------------------------\n\n\n");
   printf("RULES:\n\n 1) Any one player need to type Y if they are ready to start the game.\n 2) On the board the notation for each piece are as follow-\n    P=pawn\n    R=rook\n    N=knight\n    B=bishop\n    Q=queen\n    K=king");
   printf("\n 3) Players will be shown the updated board after every move, and they will have to answer from which place you want to lift the piece, and after that where you want to place it.");
   printf("\n 4) Here the capital letters are to be considered as white side and the small letters as black");
   printf("\n 5) The game will end when the king of any one side is killed and the winner will be displayed");
   printf("\n 6) The white(capitals) will have the first move.\n\n\n");
   printf("ARE YOU READY PLAYERS!!!!!!!\n");
   
   //here if the players are ready they type Y which we scan and then start the game
   scanf("%c",&pR);
   
   if(pR != 'Y')//if Y is not typed, the code will get terminated, and can be re started. 
   {
     printf("\n\nRELAX FOR SOME TIME AND COME BACK!! ");
     return 0;
   }
  
  printf("\n\nThen let the game begin!!!!!!!!!!!!!!!!!!!!!!\n\n");
  
  //here we call the function which will print the whole board , in its starting state.
  display_board();
  
  //now we start the real chess code
  for(i=0;i<1000;i++)//as the game progresses , we don't know how long it might take, so i gave a large value of 1000 which will be sufficient, that means this part of code will be executed after every move the players make 
  {
  
  
    printf("\nEnter Move From: ");
    scanf("%s", move); //this will take the input in form of position about which piece you want to move, for ex-b2
    set_coordsfrom();//this calls the function which will assign the address of the b2 in the matrix board[10][10], in the form of board[a][b] 
    piece_moved = board[a][b];//we store the value of the piece that player wants to move in piece_moved, in order to furthur update it
 


    printf("Enter Move To: ");
    scanf("%s", move); // this will take the input in form of position about where you want to move the piece, for ex-b4
    set_coordsto();//this calls the function which will assign the address of the b4 in the matrix board[10][10], in the form of board[x][y] 
  




   asc1=board[a][b];
   asc2=board[x][y];

   if(i%2 == 0)
   {  
     if(64<asc1 && asc1<91)
     {
 

      if(64<asc2 && asc2<91)
      {
        printf("\n\nYOU CANT KILL YOUR OWN PIECES\n\n");
        i--;
      }
      else
      {
          move_validation_and_updation();
      }
     }

    else
    {
      printf("\n\nCAPITALS ARE WHITE, YOU CAN ONLY MOVE YOUR PIECES!!!\nTRY AGAIN!!!\n\n");
      i--;
    }

   }
   
    

  else if(i%2 == 1)
    {
      if(96<asc1 && asc1<123)
      {
         if(96<asc2 && asc2<123)
        {
          printf("\n\nYOU CANT KILL YOUR OWN PIECES\n\n");
          i--;
        }
        else
        {
            move_validation_and_updation();
        }
      }        
      else
      {
       printf("\n\nSMALL ARE BLACK,YOU CAN ONLY MOVE YOUR PIECES!!!\nTRY AGAIN!!!\n\n");
       i--;
      }

       
    }








    printf("\n");

    //this will now print the updated borad, after the move is made by the player.
    display_board();

    //this function checks wether the kings of white and black, are alive or not, if any one of them is dead, the game will end and winner will be declared.
    s=king_state();
    
    //in the above function, if any one king is dead, return is given as 0, which we use here to end the game.
    if(s==0)
    {
      return 0;
    }
  }

  return 0;
}
 
void setup_board()
{
  
  //here we setup the board, by giving values to the elements of matrix board[10][10].
  for(x=0;x<8;x++)
  {
    for(y=0;y<9;y++)
    {
      board[x][y] = '-';
    }
  }
  // upper pieces
  board[0][1] = 'r';
  board[0][2] = 'n';
  board[0][3] = 'b';
  board[0][4] = 'q';
  board[0][5] = 'k';
  board[0][6] = 'b';
  board[0][7] = 'n';
  board[0][8] = 'r';
 
  board[1][1] = 'p';
  board[1][2] = 'p';
  board[1][3] = 'p';
  board[1][4] = 'p';
  board[1][5] = 'p';
  board[1][6] = 'p';
  board[1][7] = 'p';
  board[1][8] = 'p';
 
  // lower piece 
  board[6][1] = 'P';
  board[6][2] = 'P';
  board[6][3] = 'P';
  board[6][4] = 'P';
  board[6][5] = 'P';
  board[6][6] = 'P';
  board[6][7] = 'P';
  board[6][8] = 'P';
 
  board[7][1] = 'R';
  board[7][2] = 'N';
  board[7][3] = 'B';
  board[7][4] = 'Q';
  board[7][5] = 'K';
  board[7][6] = 'B';
  board[7][7] = 'N';
  board[7][8] = 'R';
 
  // notation help
  board[9][0] = '+';
  board[7][0] = '1';
  board[6][0] = '2';
  board[5][0] = '3';
  board[4][0] = '4';
  board[3][0] = '5';
  board[2][0] = '6';
  board[1][0] = '7';
  board[0][0] = '8';
   
  board[9][1] = 'A';
  board[9][2] = 'B';
  board[9][3] = 'C';
  board[9][4] = 'D';
  board[9][5] = 'E';
  board[9][6] = 'F';
  board[9][7] = 'G';
  board[9][8] = 'H';
  
}
 
 //this part will print the board every time it is called, with updated position of pieces.
void display_board()
{
  for(x=0;x<10;x++)
  {
    for(y=0;y<10;y++)
    {
      printf(" %c ", board[x][y]);
    }
    printf("\n");
  }
   printf("\n");
}
 
 //this function gives the value of
void set_coordsto()
{
  // get y value from character
  if(strchr(move,'a'))
    y = 1;
  else if(strchr(move,'b'))
    y = 2;
  else if(strchr(move,'c'))
    y = 3;
  else if(strchr(move,'d'))
    y = 4;
  else if(strchr(move,'e'))
    y = 5;
  else if(strchr(move,'f'))
    y = 6;
  else if(strchr(move,'g'))
    y = 7;
  else if(strchr(move,'h'))
    y = 8;
  // get x value from character
   if(strchr(move,'8'))
    x = 0;
  else if(strchr(move,'7'))
    x = 1;
  else if(strchr(move,'6'))
    x = 2;
  else if(strchr(move,'5'))
    x = 3;
  else if(strchr(move,'4'))
   x = 4;
  else if(strchr(move,'3'))
   x = 5;
  else if(strchr(move,'2'))
   x = 6;
  else  if(strchr(move,'1'))
   x = 7;
   }

void set_coordsfrom()
{
  // get b value from character
  if(strchr(move,'a'))
    b = 1;
  else if(strchr(move,'b'))
    b = 2;
  else if(strchr(move,'c'))
    b = 3;
  else if(strchr(move,'d'))
    b = 4;
  else if(strchr(move,'e'))
    b = 5;
  else if(strchr(move,'f'))
    b = 6;
  else if(strchr(move,'g'))
    b = 7;
  else if(strchr(move,'h'))
    b = 8;
  // get a value from character
   if(strchr(move,'8'))
    a = 0;
  else if(strchr(move,'7'))
    a = 1;
  else if(strchr(move,'6'))
    a = 2;
  else if(strchr(move,'5'))
    a = 3;
  else if(strchr(move,'4'))
    a = 4;
  else if(strchr(move,'3'))
    a = 5;
  else if(strchr(move,'2'))
    a = 6;
  else  if(strchr(move,'1'))
    a = 7;
   }



 //now we have co-ordinates, of from where we have to move the piece from and where to place it, but that is not enough, bcoz as per the rules of chess not all piece can move anywhere in the board
  //so the next part of the code , uses the co-ordinates [a],[b],[x],[y]. in order to determine if the move is valid or not.
  //if it is not valid, it will show a message saying so, and if it is valid that it will update the piece's position, to the new one and make the old position blank.
  //all of this is done in the function
void move_validation_and_updation()
{
 int k,temp=0;
 switch(piece_moved)
 {
  //case for pawns, for both white and black side
  case 'p': 
  {
      if((x-a)==1 && board[x][y]=='-')
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';
      }

      else if((a==1) && (x-a)==2 && board[x][y]=='-')
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';
      }
      
      else if((board[x][y] != '-') && (x-a)==1 && abs(b-y)==1)
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';
      }
      
      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;

  }


  case 'P': 
  {
      if((a-x)==1 && board[x][y]=='-')
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';
      }

      else if((a==6) && (a-x)==2 && board[x][y]=='-')
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';
      }
      
      else if((board[x][y] != '-') && (a-x)==1 && abs(b-y)==1)
      {
        board[x][y] = piece_moved;
        board[a][b] = '-';  

      }
      
      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;

  }

  //cases for rook 
  case 'r':
  {
      if((a-x)==0 || (b-y)==0)
      {
        
        
        if( (a-x) == 0 )//all of this is to ensure that rook does not jump over any other piece in its way
        {
          for(k=1;k<abs(b-y);k++)
          {
             if(b>y && board[a][b-k] != '-')
            {
              temp=5;
            }
            else if(b<y && board[a][b+k] != '-')
            {
              temp=5;
       
            }
          }
        }
        

        if( (b-y) == 0 )
        {
          for(k=1;k<abs(a-x);k++)
          {
             if(a>x && board[a-k][b] != '-')
            {
              temp=5;
            }
            else if(a<x && board[a+k][b] != '-')
            {
              temp=5;
       
            }
          }
        }

         if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            temp=0;
            i--;
          }

      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
  }


  case 'R':
  {
      if((a-x)==0 || (b-y)==0)
      {
        if( (a-x) == 0 )
        {
          for(k=1;k<abs(b-y);k++)
          {
             if(b>y && board[a][b-k] != '-')
            {
              temp=5;
            }
            else if(b<y && board[a][b+k] != '-')
            {
              temp=5;
       
            }
          }
        }
        

        if( (b-y) == 0 )
        {
          for(k=1;k<abs(a-x);k++)
          {
             if(a>x && board[a-k][b] != '-')
            {
              temp=5;
            }
            else if(a<x && board[a+k][b] != '-')
            {
              temp=5;
       
            }
          }
        }

         if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            temp=0;
            i--;
          }
      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
  }

  //cases for knight
  case 'n':
  {
      if((abs(a-x)==2 && abs(b-y)==1) || (abs(a-x)==1 && abs(b-y)==2))
      {
        board[x][y] = piece_moved;
          board[a][b] = '-';
      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
  }


  case 'N':
  {
      if((abs(a-x)==2 && abs(b-y)==1) || (abs(a-x)==1 && abs(b-y)==2))
      {
        board[x][y] = piece_moved;
          board[a][b] = '-';
      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
  }

  //cases for bishop
  case 'b':
  {
      if((abs(a-x)==abs(b-y)) && (a-x) != 0)
      {  
        
        for(k=1;k<abs(a-x);k++)//this part is done to ensure that the bishop cant jump the pieces in between its path
          { 
            if(a>x && b<y && board[a-k][b+k] != '-')
            {
              temp=5;
            }
            else if(a<x  && b>y && board[a+k][b-k] != '-')
            {
              temp=5;
       
            }
            else if(a<x  && b<y && board[a+k][b+k] != '-')
            {
              temp=5;
       
            }
            else if(a>x  && b>y && board[a-k][b-k] != '-')
            {
              temp=5;
       
            }
          }
          if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }

      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;

  }


 case 'B':
  {
      if((abs(a-x)==abs(b-y)) && (a-x) != 0)
      {
        for(k=1;k<abs(a-x);k++)//this part is done to ensure that the bishop cant jump the pieces in between its path
          { 
            if(a>x && b<y && board[a-k][b+k] != '-')
            {
              temp=5;
            }
            else if(a<x  && b>y && board[a+k][b-k] != '-')
            {
              temp=5;
       
            }
            else if(a<x  && b<y && board[a+k][b+k] != '-')
            {
              temp=5;
       
            }
            else if(a>x  && b>y && board[a-k][b-k] != '-')
            {
              temp=5;
       
            }
          }
          if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }

      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;

  }


 //case for queen
 case 'q':
 {
    if((abs(a-x)==abs(b-y)) && (a-x) != 0)
      
      {
        for(k=1;k<abs(a-x);k++)//this part is done to ensure that the bishop cant jump the pieces in between its path
          { 
            if(a>x && b<y && board[a-k][b+k] != '-')
            {
              temp=5;
            }
            else if(a<x  && b>y && board[a+k][b-k] != '-')
            {
              temp=5;
            }
            else if(a<x  && b<y && board[a+k][b+k] != '-')
            {
              temp=5;
       
            }
            else if(a>x  && b>y && board[a-k][b-k] != '-')
            {
              temp=5;
            }
      
            
          }
          if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }

      }

    else if((a-x)==0 || (b-y)==0)
      {
        if( (a-x) == 0 )
        {
          for(k=1;k<abs(b-y);k++)
          {
             if(b>y && board[a][b-k] != '-')
            {
              temp=5;
            }
            else if(b<y && board[a][b+k] != '-')
            {
              temp=5;
       
            }
          }
        }
        

        if( (b-y) == 0 )
        {
          for(k=1;k<abs(a-x);k++)
          {
             if(a>x && board[a-k][b] != '-')
            {
              temp=5;
            }
            else if(a<x && board[a+k][b] != '-')
            {
              temp=5;
       
            }
          }
        }

         if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }
      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
 }


 case 'Q':
 {
    if((abs(a-x)==abs(b-y)) && (a-x) != 0)
      {
        for(k=1;k<abs(a-x);k++)//this part is done to ensure that the queen cant jump the pieces in between its path
          { 
           if(a>x && b<y && board[a-k][b+k] != '-')
            {
              temp=5;
            }
            else if(a<x  && b>y && board[a+k][b-k] != '-')
            {
              temp=5;
       
            }
            else if(a<x  && b<y && board[a+k][b+k] != '-')
            {
              temp=5;
       
            }
            else if(a>x  && b>y && board[a-k][b-k] != '-')
            {
              temp=5;
       
            }
          }
          if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }

      }

    else if((a-x)==0 || (b-y)==0)
      {
        if( (a-x) == 0 )
        {
          for(k=1;k<abs(b-y);k++)
          {
             if(b>y && board[a][b-k] != '-')
            {
              temp=5;
            }
            else if(b<y && board[a][b+k] != '-')
            {
              temp=5;
       
            }
          }
        }
        

        if( (b-y) == 0 )
        {
          for(k=1;k<abs(a-x);k++)
          {
             if(a>x && board[a-k][b] != '-')
            {
              temp=5;
            }
            else if(a<x && board[a+k][b] != '-')
            {
              temp=5;
       
            }
          }
        }

         if(temp==0)
          {
          board[x][y] = piece_moved;
          board[a][b] = '-';
          }
          else
          {
            printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
            i--;
            temp=0;
          }
      }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;
 }

//cases for king
 case 'k':
 {
    if(abs(a-x)<=1 && abs(b-y)<=1)
    {
        board[x][y] = piece_moved;
          board[a][b] = '-';
    }

      else
      {
        printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
        i--;
      }

      break;

 }


 case 'K':
  {
      if(abs(a-x)<=1 && abs(b-y)<=1)
      {
          board[x][y] = piece_moved;
            board[a][b] = '-';
      }

        else
        {
          printf("\n\nINVALID MOVE, TRY AGAIN!!\n");
          i--;
        }

        break;
      
  }


 }
}



int king_state()
{
  int i,j,temp1=0,temp2=0;
  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      if(board[i][j]=='k')
      {
        temp1=5;
      }

      if(board[i][j]=='K')
      {
        temp2=5;
      }
    }
  }
 
  if(temp1==0)
  {
    printf("\n\nWHITE(CAPITAL) HAS WON THE GAME, YAHOOOOO");
     return 0;
  }

   if(temp2==0)
  {
    printf("\n\nBLACK(SMALL) HAS WON THE GAME, YAHOOOOO");
     return 0;
  }
 
  temp1=0;
  temp2=0;
  return 10;
}