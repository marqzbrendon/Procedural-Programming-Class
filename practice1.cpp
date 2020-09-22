/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
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
#include <fstream>
using namespace std;
char * prompt(char *text);
void display(char text[]);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int argc, char ** argv)
{
   char text[256];
   char * input;
   
   switch (argc)
   {
     case 1:

        input = prompt(text);
        break;
      
     case 2:
        
        input = argv[1];
        break;

     default:

        cout << "Error.\n";
        break;
   }

   display(input);
}

char * prompt(char *text)
{
   cout << "Please enter the file name: ";
   cin >> text;   
   
   return text;
}
  
void display(char text[])
{
   int count = 0;
   char data[1024];

   ifstream fin(text);
   if (fin.fail())
   {
      cout << "Error reading the file.\n";
      return;
   }

   for (int i = 0; data[i]; i++)
   {
      if (data[i] == '\n')

         count++;
   }
   
   if (count == 0)

      cout << text << " has " << count << " line.\n";

   else if (count > 1)

      cout << text << " has " << count << " lines.\n";

   else

      cout << "There are no digits.\n";
}











