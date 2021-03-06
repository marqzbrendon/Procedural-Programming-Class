/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

const int SIZE = 256;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int countLetters(char *pText, char letter)
{   
   int count = 0;
   for (char *p = pText; *p; p++)
   {
      if (*p == letter)
         count++;
   }
   
   return count;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   cout << "Enter a letter: ";
   char letter;
   cin >> letter;
   
   cout << "Enter text: ";
   cin.ignore();
   char text[SIZE];
   cin.getline(text, SIZE);

   char *pText;

   int count = countLetters(text, letter);
   
   cout << "Number of \'" << letter << "\'s: " << count << endl;
   
   return 0;
}
