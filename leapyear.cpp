/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth, Helfrich}, CS124
* Author:
*    your name
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   int year;

   cout << "Enter year: ";
   cin >> year;

   if (year % 400 == 0 ||
       year % 100 == 0 && year % 400 == 0 ||
       year % 4 == 0 && year % 100 != 0)

//      year % 4 == 0 && year % 100 != 0 ||
      //     year % 100 == 0 && year % 400 == 0 ||
      //year % 400 != 0)

      cout << year << " is a leap year.\n";

   else

      cout << year << " is not a leap year.\n";
   

   return 0;
}
