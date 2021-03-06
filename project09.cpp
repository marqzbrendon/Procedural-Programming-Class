/***********************************************************************
* Program:
*    Project 09, Mad Lib Program          (e.g. Assignment 10, Hello World)
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
*    Actual:     4.0 hrs
*      The askQuestions() function was difficult to figure it out
*      based only on the Pseudocode.
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
   
      return -1;
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

   // cout thank you message
   cout << "Thank you for playing." << endl;
   
   return numWords;
}



/**********************************************************************
 * main
 * 
 * The driver to the program, that's all folks.
 ***********************************************************************/
int main()
{

   // declaring the array to hold the filename
   char filename[256];

   // calling function getFileName passing the filename array
   getFileName(filename);

   // declaring the two dimensional array for the story
   char story[256][32];

   // calling readFile function, passing the filename
   // and the array to hold the story.
   // the number of words in the story will be returned
   int numWords = readFile(filename, story);
   
   return 0;
}
