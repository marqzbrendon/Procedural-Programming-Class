/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    A program in which the user inserts an input..
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part was to find the places where I forgot to
        add ";".
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The function main tells the program where to begin execution.
 ***********************************************************************/

int main()
{

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   float income;

   
   cout << "\tYour monthly income: ";
   
   cin >> income;

   cout << "Your income is: " << "$" << setw(9) << income << endl;


   return 0;
}
