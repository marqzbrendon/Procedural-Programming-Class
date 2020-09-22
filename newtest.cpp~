/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    Create a program to display a monthly budget.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part was to understand that in order to use setw(),
       we first have to add the lines:
                cout.setf(ios::fixed);
                cout.setf(ios::showpoint);
                cout.precision(2);.

Also, it took me a little but to understand how to end line after a number.
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
   
   cout << "\tItem           " << "Projected\n";
   cout << "\t=============  " << "==========\n";
   cout << setw(13) << "\tIncome         " << "$" <<  setw(9) << 1000.00;
   cout << "\n";
   cout << setw(13) << "\tTaxes          " << "$" <<  setw(9) << 100.00;
   cout << "\n";
   cout << setw(13) << "\tTithing        " << "$" <<  setw(9) << 100.00;
   cout << "\n";
   cout << setw(13) << "\tLiving         " << "$" <<  setw(9) << 650.00;
   cout << "\n";
   cout << setw(13) << "\tOther          " << "$" <<  setw(9) << 90.00;
   cout << "\n";      
   cout << "\t=============  " << "==========\n";
   cout << setw(13) << "\tDelta          " << "$" <<  setw(9) << 60.00;
   cout << "\n";


   return 0;
}
