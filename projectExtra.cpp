/***********************************************************************
* Program:
*    Project Extra, Sudoku          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This is a Sudoku game! There is a hidden feature to solve the 85% board.
*    Type '!' and press the enter key and the board will be
*    solved and displayed!
*    This program will validate the sudoku board once it is read from the
*    file to make sure it is a valid board.
*    Also, the read-only characters are displayed in green and the program
*    accepts input independent of order (col or row),
*    and capitalization.
*    
*
*    Estimated:  4.0 hrs   
*    Actual:     4.0 hrs
*      Dealing with conversion of data-types and figuring out the
*      displayBoard loop were hard.
************************************************************************/

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
using namespace std;


bool readFile(int game[][9], bool displayGreen[][9]);
void getFile(char filename[]);
void displayBoard(int game[][9], bool displayGreen[][9]);
void displayOptions();
void interact(int game[][9], bool displayGreen[][9]);
void updateValue(int game[][9], char &col, int &row, int &value);
void getCoordinates(char &c, int &r);
int getValue(char &c, int &r);
void saveAndQuit(int game[][9], bool displayGreen[][9]);
void getFileToWrite(char fileWrite[]);
void writeFile(int game[][9], char fileWrite[], bool displayGreen[][9]);
void possibleValues(int game[][9], bool possValues[], char &col, int &row);
void displayPossValues(int row, char col, bool possValues[]);
bool isValidSquare(int game[][9], char &col, int &row, bool allow[][9]);
void solver(int game[][9]);

/**********************************************************************
 * main
 *
 * The boss of them all! Tells the program where to go.
 ***********************************************************************/
int main()
{
   // array for the game
   int game[9][9];

   // boolean array for read-only digits
   bool displayGreen[9][9];

   // set displayGreen to false
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; i < 8; i++)
      {
         displayGreen[i][j] = false;
      }
   }

   // get filename and fin data to array
   if (readFile(game, displayGreen))
   {

      // options and the board are displayed
      // once the program is initialized
      displayOptions();
      displayBoard(game, displayGreen);

      // interact will be looped until player quits the game
      interact(game, displayGreen);

      return 0;
   }

   else
   
   return 0;
}


/**********************************************************************
 * validateBoard
 *
 * This function will make sure the file used is valid for
 * a sudoku game.
 ***********************************************************************/

bool validateBoard(int game[][9])
{
   // validate board
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         
         if (game[row][col] > 0)
         {
            int value;
            int countRow = 0;
            int countCol = 0;
            int countSqr = 0;
            value = game[row][col];


            // validate column
            for (int iRow = 0; iRow < 8; iRow++)
            {               
               if (value == game[iRow][col])
               {      
                  countRow++;
                 
                  if (countRow > 1)
                  {
                     char c = col + 65;
                  
                     cout << "ERROR: Duplicate value '" << value
                          << "' in inside square represented by '"
                          << c << row + 1 << "'\n";
                  
                     return false;
                  }
               }
            }
         

            // validate row
            for (int iCol = 0; iCol < 8; iCol++)
            {
                           
               if (value == game[row][iCol])
               {
                  countCol++;
                  
                  if (countCol > 1)
                  {
                     char c = col + 65;
                     
                     cout << "ERROR: Duplicate value '" << value
                          << "' in inside square represented by '"
                          << c << row + 1 << "'\n";
                     
                     return false;
                  }
               }
            }


            // validate square
            for (int iRow = (row) / 3 * 3; iRow < ((row) / 3 * 3) + 3; iRow++)
            {
               for (int iCol = (col) / 3 * 3; iCol < ((col) / 3 * 3) + 3; iCol++)
               {
                               
                  if (value == game[iRow][iCol])
                  {
                     countSqr++;
                     
                     if (countSqr > 1)
                     {
                        char c = col + 65;
                        
                        cout << "ERROR: Duplicate value '" << value
                             << "' in inside square represented by '"
                             << c << row + 1 << "'\n";
                        
                        return false;
                     }
                  }
               }
            }
         }
      }
   }
   
   return true;            
   }
   

/**********************************************************************
 * readFile
 *
 * Calls the getFile function, and gets the name of the file. Then, it
 * reads the file and write the values into an array.
 ***********************************************************************/
bool readFile(int game[][9], bool displayGreen[][9])
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
      return false;
   }

  
   // fin the values into the array
   for (int iRow = 0; iRow < 9; iRow++)
   {
      for (int iCol = 0; iCol < 9; iCol++)
      {
               
         fin >> game[iRow][iCol];

         // set displayGreen to true
         if (game[iRow][iCol] > 0)
         {
            displayGreen[iRow][iCol] = true;
         }

         // convert negative numbers (user input) to positive
         else if (game[iRow][iCol] < 0)
         {
            game[iRow][iCol] = abs(game[iRow][iCol]);
         }         
      }
   }
   
   if (!validateBoard(game))
   {
      return false;
   }
   
   // close fstream
   fin.close();

   return true;
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
      /* << "   !  Solver\n"*/
        << endl;
}

/**********************************************************************
 * displayBoard
 *
 * Displays the sudoku board to the user.
 ***********************************************************************/
void displayBoard(int game[][9], bool displayGreen[][9])
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
               
               else if (displayGreen[rowNumber][colNumber])
               {
                  cout << "\E[22;32m" << game[rowNumber][colNumber] << "\E[0m";
               }

               // user input is storage as a negative number,
               // a minus symbol is necessary to display it properly
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
void interact(int game[][9], bool displayGreen[][9])
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
         case 'D':

            displayBoard(game, displayGreen);
            break;

         case 'S':

            getCoordinates(col, row);
            possibleValues(game, possValues, col, row);
            displayPossValues(row, col, possValues);
            cout << endl;
            break;

         case 'E':

            getCoordinates(col, row);
            if (isValidSquare(game, col, row, displayGreen))
            {
               value = getValue(col, row);
               updateValue(game, col, row, value);
               cout << endl;
               break;
            }
            cout << endl;
            break;

         case '?':

            displayOptions();
            cout << endl;
            break;

         case '!':

            solver(game);
            displayBoard(game, displayGreen);
            cout << endl;
            break;
            

         case 'Q':
         
            saveAndQuit(game, displayGreen);
            break;

         default:

            cout << "ERROR: Invalid command\n";
            cout << endl;
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
   // variable
   char coords[3];

   do
   {
      // display message and cin to variable
      cout << "What are the coordinates of the square: ";
      cin >> coords;
      
      //   robust error checking
      if (isalpha(coords[0]) && isdigit(coords[1]))
      {
         c = toupper(coords[0]);
         
         r = coords[1] - '0';
      }
      
      else if (isdigit(coords[0]) && isalpha(coords[1]))
      {
         r = coords[0] - '0';
         
         c = toupper(coords[1]);
      }
      
      else
         
         cout << "ERROR: Square '" << coords[0] << coords[1] << "' is invalid\n";
   }
   while (isalpha(coords[0]) && isalpha(coords[1]) ||
          isdigit(coords[0]) && isdigit(coords[1]));
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
void saveAndQuit(int game[][9], bool displayGreen[][9])
{
   // new file name array
   char writeTo[256];

   // get the name of the file
   getFileToWrite(writeTo);

   // write the new file with the sudoku numbers
   writeFile(game, writeTo, displayGreen);
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
void writeFile(int game[][9], char fileWrite[], bool displayGreen[][9])
{
   // open fstream
   ofstream fout(fileWrite);

   // loop to write to the new file
   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         // if number has to display in green
         // save as positive
         if (displayGreen[i][j])
         {
            fout << game[i][j];

            if (j <= 7)
                  
               fout << " ";

            else if (j == 8)

               fout << endl;
         }

         // if number does not have to display in gree
         // save it as negative
         else   
         {
            fout << -game[i][j];

            if (j <= 7)

               fout << " ";

            else if (j == 8)

               fout << endl;
         }
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
   for (int iRow = (row - 1) / 3 * 3; iRow < ((row - 1) / 3 * 3) + 3; iRow++)
   {
      for (int iCol = (col - 65) / 3 * 3; iCol < ((col - 65) / 3 * 3) + 3; iCol++)
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
   // variables
   int count = 0;
   int count2 = 0;

   for (int i = 1; i < 10; i++)
   {
      if (possValues[i] == true)

      // counts the number of possible values
      count++;
   }

   // display message
   if (count > 1)
      
      cout << "The possible values for '" << col << row << "' are: ";

   else

      cout << "The possible value for '" << col << row << "' is: ";

   
   for (int i = 1; i < 10; i++)
   {
      if (possValues[i])
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
bool isValidSquare(int game[][9], char &col, int &row, bool allow[][9])
{
   // allow edition if square is a read-write
   if (!allow[row - 1][col - 65])
   {
      return true;
   }
      
   // if space is filled out, display error
   else
   {
      cout << "ERROR: Square '" << col << row << "' is read-only\n";
      return false;
   }
}


/**********************************************************************
 * isSolved
 *
 * Loop through the board until it is completely solved.
 ***********************************************************************/
bool isSolved(int game[][9])
{
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         // return false when there is a 0
         if (game[row][col] == 0)
        
            return false;
      }
   }

   // return true when all 0 are gone
   return true;
}


/**********************************************************************
 * solver
 *
 * Magically solves the board.
 ***********************************************************************/
void solver(int game[][9])
{
   // variables
   bool possValues[10];
   int value;

   do
   {
      // loop through multi-dimensional array
      for (int row = 1; row < 10; row++)
      {
         for (char col = 'A'; col < 'J'; col++)
         {
            // request possible values of blank spaces only
            if (game[row - 1][col - 65] == 0)
            {
               possibleValues(game, possValues, col, row);

               int counter = 0;
               
               for (int i = 1; i < 10; i++)
               {
                  // couts the number of possible values
                  if (possValues[i])
                  {
                     counter++;
                     
                     value = i;
                  }
               }

               // if there is only one possible value, edit square
               if (counter == 1)
               {
                  updateValue(game, col, row, value);
               }
            }
         }
      }
   }

   // loop until board is solved
   while (!isSolved(game));
}
