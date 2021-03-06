/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will add all the multiples of a given number
*    that are less than 100.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.0 hrs
*      To be honest, everything was difficult. Loops are a bit complicated
*      for me..
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * The main function determines where the program starts executing.
 ***********************************************************************/
int main()
{
   // getting the variables
   int sum = 0;
   int num;

   // prompting user for the multiples to be added
   cout << "What multiples are we adding? ";
   cin >> num;

   // for loop to sum the multiples of the input number
   for (int i = 0; i < 100; i += num)

      sum = sum + i;


   // result sent to the screen
   cout << "The sum of multiples of " << num
        << " less than 100 are: " << sum << endl;
      
   
   return 0;
}
