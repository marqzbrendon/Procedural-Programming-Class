/***********************************************************************
 * Program:
 *    Assignment 40, Multi- Dimensional Arrays
 *    Brother Christensen, CS124
 * Author:
 *    Brendon Marques
 * Summary:
 *    This program will use multi-dimensional arrays to display a tic-tac-toe game.
 *
 *    Estimated:  0.5 hrs
 *    Actual:     1.0 hrs
 *      Everything, really!
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define column 3
#define rows 3
void getFileName(char filename[]);
void readfile(char filename[], char game[][column]);
void display(char game[][column]);
void saveFileName(char filename[]);
void saveGame(char filename, char game[][column]);


/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void getFileName(char filename[])
{
   cout << "Enter source filename: ";
   cin >> filename;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void readFile(char filename[], char game[][column])
{
   ifstream fin(filename);

   if (fin.fail())
   {
      cout << "Error";
   }

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         fin >> game[i][j];
      }
   }

   fin.close();

}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 **********************************************************************/
void saveFileName(char filename[])
{
   cout << "Enter destination filename: ";
   cin >> filename;
   cout << "File written" << endl;

}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 **********************************************************************/
void saveGame(char filename[], char game[][column])
{
   ofstream fout(filename);

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         fout << game[i][j];
         if ( j < column - 1)
         {
            fout << " ";
         }
      }

      if (i < rows - 1)
      {
         fout << endl;
      }
   }

   fout.close();

}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
  ***********************************************************************/
void display(char game[][column])
{
   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < column; j++)
      {
         cout << " "
              << (game[i][j] == '.' ? ' ': game[i][j])
              << " ";
         if (j < column - 1)
         {
            cout << "|";
         }

      }
      cout << endl;
      if (i < rows - 1)
      {
         cout << "---+---+---" << endl;
      }
   }

}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char filename[256];
   char game[rows][column];

   getFileName(filename);
   readFile(filename, game);
   display(game);
   saveFileName(filename);
   saveGame(filename, game);

   return 0;
}
