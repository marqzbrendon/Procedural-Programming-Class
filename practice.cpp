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

void getFileName(char filename[])
{
   cout << "Enter a filename: ";
   cin >> filename;
}

int readFile(char filedata[])
{
   char filename[256];
   getFileName(filename);

   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "Error reading the file.\n";

      return 0;
   }

   int count = 0;

   for (int i = 0; !fin.eof(); i++)
   {
      fin.get(filedata[i]);

      count++;
   }

   fin.close();

   return count;
}


void display(char filedata[], int count)
{
   for (count; count >= 0; count--)
   {
      cout << filedata[count];
   }

   cout << endl;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char filedata[256];

   int count = readFile(filedata);
      
   display(filedata, count);
      
   return 0;
}
