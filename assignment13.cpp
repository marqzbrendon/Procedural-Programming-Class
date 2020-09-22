/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This is a simple program to convert Fahrenheit to Celsius.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   
   //round int up

   // cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(0);
   

   // represents the temperature in fahnrenheit
   int f;
      
   // request user input
   cout << "Please enter Fahrenheit degrees: ";

   // defines the input as the variable f
   cin >> f;
            
   // set c as a variable to calculate celsius
   float c = 5.0 / 9.0 * (f - 32.0);

   // displays the result of the expression
   cout << "Celsius: " << c << endl;
      
      
   return 0;
}
