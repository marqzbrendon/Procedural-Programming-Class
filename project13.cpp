/***********************************************************************
* Program:
*    Project 13, Sudoku          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This is a Sudoku game!
*
*    Estimated:  4.0 hrs   
*    Actual:     3.0 hrs
*      The second part of the project was easier than the first one.
*      The only thing that I had problems with was with Modularization
*      as I made changes in my code from the last project.
************************************************************************/

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

// prototypes
void readFile(int game[][9]);
void getFile(char filename[]);
void displayBoard(int game[][9]);
void displayOptions();
void interact(int game[][9]);
void updateValue(int game[][9], char &col, int &row, int &value);
void getCoordinates(char &c, int &r);
int getValue(char &c, int &r);
void saveAndQuit(int game[][9]);
void getFileToWrite(char fileWrite[]);
void writeFile(int game[][9], char fileWrite[]);
void possibleValues(int game[][9], bool possValues[], char &col, int &row);
void displayPossValues(int row, char col, bool possValues[]);
bool isValidSquare(int game[][9], char &col, int &row);

/**********************************************************************
 * main
 *
 * The boss of them all! Tells the program where to go.
 ***********************************************************************/
int main()
{
   // array for the game
   int game[9][9];

   // get filename and fin data to array
   readFile(game);

   // options and the board are displayed
   // once the program is initialized
   displayOptions();
   displayBoard(game);

   // interact will be looped until player quits the game
   interact(game);
   
   return 0;
}

/**********************************************************************
 * readFile
 *
 * Calls the getFile function, and gets the name of the file. Then, it
 * reads the file and write the values into an array.
 ***********************************************************************/
void readFile(int game[][9])
{
   // get filename
   char filename[256];
   getFile(filename);

   // open ifstream
   ifstream fin(filename);

   // handle errors reading the file
   if (fin.fail())
   {
      cout << "Error reading the file.\n";
      return;
   }
   
   // fin the values into the array
   for (int iRow = 0; iRow < 9; iRow++)
   {
      for (int iCol = 0; iCol < 9; iCol++)
      {
         fin >> game[iRow][iCol];
      }
   }

   // close fstream
   fin.close();
}
   
/**********************************************************************
 * getFile
 *
 * Gets the name of the file.
 ***********************************************************************/
void getFile(char filename[])
{
   // get filename and store in the array filename[]
   cout << "Where is your board located? ";
   cin >> filename;
}

/**********************************************************************
 * displayOptions
 *
 * The name says it all! Tells the user the options available.
 ***********************************************************************/
void displayOptions()
{
   // display options
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << endl;
}

/**********************************************************************
 * displayBoard
 *
 * Displays the sudoku board to the user.
 ***********************************************************************/
void displayBoard(int game[][9])
{
   // variables to count rows and columns for the array
   int colNumber = 0;
   int rowNumber = 0;

   // variable to count the row number to be displayed
   int countRow = 1;

   // fields A through I
   cout << "   A B C D E F G H I\n";


      // loop to go through the array displaying
      // the numbers and adding proper spaces
      // and special characters
   for (int iRow = 0; iRow < 11; iRow++)
   {
      if (iRow == 3 ||
          iRow == 7)

         cout << "   -----+-----+-----";

      else
      {            
         cout << countRow++ << "  ";
         
         for (int iCol = 0; iCol < 17; iCol++)
         {
            if (iCol == 5 ||
                iCol == 11)

               cout << '|';

            else if (iCol % 2 != 0)

               cout << " ";

            else
            {
               if (game[rowNumber][colNumber] == 0)
               {
                  cout << " ";
               }
               
               else
               {
                  cout << game[rowNumber][colNumber];
               }   

               colNumber++;
               rowNumber;
            }
                     
         } 
      }

      cout << endl;
   }

   cout << endl;
}

/**********************************************************************
 * interact
 *
 * Will handle the user input and call the proper functions for the
 * option selected.
 ***********************************************************************/
void interact(int game[][9])
{
   // variables
   char option;
   bool possValues[10];
   char col;
   int row;
   int value;

   // do-while for user to interact with the game.
   // loop ends when user hits q
   do
   {
      cout << "> ";
      cin >> option;
      option = toupper(option);

      // switch to determine the action
      switch (option)
      {
         // display the board
         case 'D':

            displayBoard(game);
            break;

         // show possible values for a specific square
         case 'S':

            getCoordinates(col, row);
            possibleValues(game, possValues, col, row);
            displayPossValues(row, col, possValues);
            cout << endl;
            break;

         // edit a square
         case 'E':

            getCoordinates(col, row);
            if (isValidSquare(game, col, row))
            {
               value = getValue(col, row);
               updateValue(game, col, row, value);
               cout << endl;
               break;
            }
            cout << endl;
            break;

         // display the options
         case '?':

            displayOptions();
            cout << endl;
            break;

         // save and quit the game   
         case 'Q':
         
            saveAndQuit(game);
            break;         
      }
   }
   while (option != 'Q');
}

/**********************************************************************
 * updateValue
 *
 * Changes the value of the square specified by the user.
 ***********************************************************************/
void updateValue(int game[][9], char &col, int &row, int &value)
{
   // variables
   bool possValues[10];

   
   // display error when square is filled
   if (game[col - 65][row - 1] > 0)
   {
      cout << "ERROR: Square '" << col << row << "' is filled\n";

      return;
   }

   // gets the allowed values for the square
   possibleValues(game, possValues, col, row);

   for (int i = 1; i < 10; i++)
   {
      // if input value is allowed, update
      if (possValues[i] && i == value)
      {
         game[row - 1][col - 65] = value;

         return;
      }
   }

   // if values is not allowed, display error message
   cout << "ERROR: Value '"
        << value
        << "' in square '"
        << col
        << row
        << "' is invalid\n";         
}

/**********************************************************************
 * getCoordinates
 *
 * Get the coordinates for the square to be updated.
 ***********************************************************************/
void getCoordinates(char &c, int &r)
{
   // display message and cin to variable
   cout << "What are the coordinates of the square: ";
   cin >> c >> r;

   // if lowercase, pass to uppercase
   c = toupper(c);
}

/**********************************************************************
 * getValue
 *
 * Gets the value to be added to the sudoku board.
 ***********************************************************************/
int getValue(char &c, int &r)
{
   // new value variable
   int v;

   // display message and get new value
   cout << "What is the value at '" << c << r << "': ";
   cin >> v;
   
   return v;
}
   
/**********************************************************************
 * saveAndQuit
 *
 * Saves and quit the game, no big deal.
 ***********************************************************************/
void saveAndQuit(int game[][9])
{
   // new file name array
   char writeTo[256];

   // get the name of the file
   getFileToWrite(writeTo);

   // write the new file with the sudoku numbers
   writeFile(game, writeTo);
}

/**********************************************************************
 * getFileToWrite
 *
 * Gets the filename of the new file to be written.
 ***********************************************************************/
void getFileToWrite(char fileWrite[])
{
   // get the name of the new file
   cout << "What file would you like to write your board to: ";
   cin >> fileWrite;
}

/**********************************************************************
 * writeFile
 *
 * Actually writes the new value with changes made by the user in the
 * sudoku board.
 ***********************************************************************/
void writeFile(int game[][9], char fileWrite[])
{
   // open fstream
   ofstream fout(fileWrite);

   // loop to write to the new file
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         fout << game[i][j];

         // add spaces between numbers
         if (j <= 7)

            fout << " ";

         // add new line at the end of the last number
         else if (j == 8)

            fout << endl;
      }
   }

   // close fstream
   fout.close();

   // display success message
   cout << "Board written successfully\n";
}


/**********************************************************************
 * possibleValues
 *
 * Determines what are the possible values for a specific square.
 ***********************************************************************/
void possibleValues(int game[][9], bool possValues[], char &col, int &row)
{

   // for loop to set all values to true in the boolean array
   for (int i = 1; i < 10; i++)
   {
      possValues[i] = true;
   }

   // for loop to check possible values in the row
   for (int iCol = 0; iCol < 9; iCol++)
   {
      possValues[game[row - 1][iCol]] = false;
   }

   // for loop to check possible values in the column
   for (int iRow = 0; iRow < 9; iRow++)
   {
      possValues[game[iRow][col - 65]] = false;
   }

   // for loop to check possible values in a square
   for (int iRow = (row - 1) / 3 * 3;
        iRow < ((row - 1) / 3 * 3) + 3;
        iRow++)
   {
      for (int iCol = (col - 65) / 3 * 3;
           iCol < ((col - 65) / 3 * 3) + 3;
           iCol++)
      {
         possValues[game[iRow][iCol]] = false;
      }
   }
}

/**********************************************************************
 * displayPossValues
 *
 * Display the possible values of a square to the user.
 ***********************************************************************/
void displayPossValues(int row, char col, bool possValues[])
{
   int count = 0;
   int count2 = 0;

   // count how many possible values exist for the square
   for (int i = 1; i < 10; i++)
   {
      if (possValues[i] == true)
         
         count++;
   }

   // display message  
   cout << "The possible values for '" << col << row << "' are: ";


   // display possible values
   for (int i = 1; i < 10; i++)
   {
      if (possValues[i] == true)
      {
         cout << i;
         count2++;
      
         // display commas properly
         if (count > 0)
         {
            if (count2 < count)
               
               cout << ", ";
         }
      }
   }

   cout << endl;
}

/**********************************************************************
 * isValidSquare
 *
 * Determines if a square to be updated has already a value.
 ***********************************************************************/
bool isValidSquare(int game[][9], char &col, int &row)
{
   // display error when square is filled
   if (game[row - 1][col - 65] > 0)
   {
      cout << "ERROR: Square '" << col << row << "' is filled\n";

      return false;
   }

   else

      return true;
}
