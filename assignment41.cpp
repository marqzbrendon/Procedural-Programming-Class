/***********************************************************************
* Program:
*    Assignment 41, Allocating memory          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will allocate a memory, prompt for an array size, then it
*    will prompt for a text, display the text, and delete the
*    allocated memory.
*
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      Use pointers!.
************************************************************************/

#include <iostream>
using namespace std;


int promptSpace()
{  
   cout << "Number of characters: ";
   int number;
   cin >> number;
      
   return number;
}

void promptText(char * pText, int num)
{
   cout << "Enter Text: ";
   cin.ignore();
   cin.getline(pText, num + 1);
}


void display(char * pText, int num)
{
   cout << "Text: ";
      
   for (int i = 0; pText[i]; i++)
   {
      cout << pText[i];
   }

   cout << endl;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int numberChar = promptSpace();

   char * pText = NULL;

   pText = new(nothrow) char[numberChar +1];
   if (!pText)
   {
      cout << "Allocation failure!\n";

      return -1;
   }

   promptText(pText, numberChar);
   
   display(pText, numberChar);

   delete [] pText;

   pText = NULL;
   
   return 0;
}
