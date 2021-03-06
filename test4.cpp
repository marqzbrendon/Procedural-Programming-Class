/***********************************************************************
* Program:
*    Test 4, Count Letters & Digits          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program is supposed to count the letters, digits, symbols and spaces
*    in an input text.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      I was not able to make the program work. I had trouble working with
*      pointers.
*******************************************************************************/

#include <iostream>
#include <cctype>
using namespace std;

// prototypes
char *promptText(char text[]);
void count(char* text);
void display(int letters, int digits, int symbols, int spaces);

/**********************************************************************
 * main
 *
 * It is the driver of the program
 ***********************************************************************/
int main(int argc, char ** argv)
{
   /*/ array to hold the text
   char text[256];

   // if there is input in the command line
   if (argc > 1)
   {
      for (char *p = text; *p; p++)
      {
         text[*p] = *argv[*p];
      }
   }

   // if there is no input in the command line
   else
   {
      promptText(text);
   }

   // call the function to count the characters
   count(text);
      
   return 0;
   }*/

   char *input;
   char text[256];
   //  char *pText;

   //pText = text;

   switch (argc)
   {
      case 1:

          input = promptText(text);
          
      default:

         input = argv[1];
         
   }

   count(input);
      
}

/**********************************************************************
 * promptText
 *
 * Prompts the user for a text.
 ***********************************************************************/
char *promptText(char text[])
{
   cout << "Please enter some text: ";
   cin.getline(text, 256);

   return text;
}

/**********************************************************************
 * count
 *
 * Counts the characters in the text.
 ***********************************************************************/
void count(char *text)
{
   // variables
   int letters = 0;
   int digits = 0;
   int symbols = 0;
   int spaces = 0;

   // traversing the array and counting characters
   for (char *p = text; *p; p++)
   {
      if (isalpha(*p))

         letters++;

      else if (isdigit(*p))

         digits++;

      else if (ispunct(*p))

         symbols++;

      else if (*p == ' ')

         spaces++;
   }

   // call display function
   display(letters, digits, symbols, spaces);
}

/**********************************************************************
 * display
 *
 * Shows the results to the user.
 ***********************************************************************/
void display(int letters, int digits, int symbols, int spaces)
{
   // printing results to the screen
   cout << "\tLetters: "  << letters << endl
        << "\tDigits:  "  << digits  << endl
        << "\tSymbols: "  << symbols << endl
        << "\tSpaces:  "  << spaces  << endl;

}
