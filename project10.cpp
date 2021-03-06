/***********************************************************************
* Program:
*    Project 10, Mad Lib Program          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program is the first part of the MadLib project. It will
*    prompt the user for a filename, then it will pass the filename
*    as an array. Finally, it will read the file and prompt for
*    words to replace in the story, also passing as array.
*
*    Estimated:  3.0 hrs   
*    Actual:     8.0 hrs
*      handlePunct() took me at least 3 hours to figure it out.
************************************************************************/

// libraries
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;


/**********************************************************************
 * getFileName
 *
 * This function will prompt the user for a filename and return it to main. 
 ***********************************************************************/
void getFileName(char filename[])
{
   // prompting the user for a filename, passing the name as array to main
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(filename, 256);   
}


/**********************************************************************
 * askQuestions
 * 
 * This function will search and replace the questions that were passed in
 * the array by readFile().
 ***********************************************************************/
void askQuestions(char question[])
{
   // if statement to determine if a question has to be prompted

   // questions always begin with colon followed by an alphabetic character
   if (question[0] == ':' && isalpha(question[1]))
   {
      // use tab, then cout first letter as uppercase
      cout << '\t' << (char)toupper(question[1]);

      // cout the rest of the letters as lowercase,
      // replacing underscores with spaces
      for (int i = 2; question[i]; i++)
      {
         if (question[i] == '_')
         
            cout << " ";
   
         else
            
            cout << (char)tolower(question[i]);
      }

      // cout colon and cin the answer
      cout << ": ";
      cin.getline(question, 32);

   }  
}


/**********************************************************************
 * readFile
 * 
 * This will read the file informed by the user in getFileName, insert
 * the file characters into an array, and pass it to askQuestions. 
 ***********************************************************************/
int readFile(char filename[], char story[][32])
{
   // declaring ifstream variable
   // and treating possible file reading errors
   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "Error reading the file." << endl;
   
      return 0;
   }

   // numWords will count the amount of words in the story
   int numWords = 0;

   // while loop to read the story from the file and
   // prompt askQuestions and check if there
   // is a question to be asked
   while (fin >> story[numWords] && !fin.eof())
   {
      askQuestions(story[numWords]);

      numWords = numWords + 1; // counting the amount of words
   }

   // closing fin
   fin.close();
   
   return numWords;
}


/**********************************************************************
 * handlePunct
 *
 * This will deal with special characters in the madlib program.
 ***********************************************************************/
void handlePunct(char current, char next, char prev, bool endOf)
{
   // handling new lines
   if (current == '!')
   {
      cout << "\n";
   }

   // handling commas and periods
   else if (current == '.' && next == '!' ||
            current == ',' && next == '!')
   {
      //    cerr << 2;
      cout << current;
   }
   
   else if (current == '.')
   {
      
      if (endOf || next == '>')
      {
         cout << current;
      }
      else
      {
         cout << current << " ";
      }
   }
   
   else if (current == ',')
   {
      cout << current << " ";
   }

   // handling quotation marks
   else if (current == '<' && prev != '!')
   {
      cout << " \"";
   }
   
   else if (current == '>' && (next != '!' && next != '<'))
   {
      cout << "\" ";
   }
   
   else if (current == '<' ||
            current == '>')
   {
      cout << "\"";
   }
}


/**********************************************************************
 * display
 *
 * This will call handlePunct() to deal with punctuation, and display
 * the final story to the user.
 ***********************************************************************/
void display(char story[][32], int numWords)
{
   // cout new line
   cout << "\n";

   // for loop to handle proper punctuation and spaces
   for (int i = 0; i < numWords; i++)
   {
      if (story[i][0] == ':')
      {
         handlePunct(story[i][1], story[i + 1][1],
                     story[i - 1][1], i == numWords - 1);
      }
      else if (story[i + 1][0] != ':' && i != numWords - 1)
      {
         cout << story[i] << " ";
      }
      else
      {
         cout << story[i];
      }
      
   }

   // cout at the end of the story
   cout << "\n";
}

/**********************************************************************
 * playAgain
 *
 * Will prompt the user to play again after the story is displayed..
 ***********************************************************************/
bool playAgain()
{
   cout << "Do you want to play again (y/n)? ";
   char answer;
   cin >> answer;
   cin.ignore();
   if (answer == 'y')

      return true;

   else if (answer == 'n')

      return false;
}      

/**********************************************************************
 * main
 * 
 * The driver to the program, that's all folks.
 ***********************************************************************/
int main()
{
   // variables
   char filename[256];
   char story[256][32];
   int numWords;
   
   do
   {
      // calling function getFileName passing the filename array
      getFileName(filename);

      // calling readFile function, passing the filename
      // and the array to hold the story.
      // the number of words in the story will be returned
      numWords = readFile(filename, story);

      // call display function
      display(story, numWords);

   } while (playAgain());

   // thanks!
   cout << "Thank you for playing.\n";

   return 0;
}
