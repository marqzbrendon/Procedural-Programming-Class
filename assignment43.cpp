/***********************************************************************
* Program:
*    Assignment 43, Command Line          (e.g. Assignment 10, Hello World)
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
*    Estimated:  0.5 hrs   
*    Actual:     0.75 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void convert(int argc, char ** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   
   float feet;

   float conversion = 0.3048;
   
   for (int i = 1; i < argc; i++)
   {
      feet = atof(argv[i]);
      cout << feet << " feet is " << feet * conversion << " meters\n";

   }
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int argc, char * argv[])
{
   convert(argc, argv);
   
   return 0;
}
