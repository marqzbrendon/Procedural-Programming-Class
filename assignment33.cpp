/***********************************************************************
* Program:
*    Assignment 33, Pointers          (e.g. Assignment 10, Hello World)
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
#include <iomanip>
using namespace std;


void promptBalances(float *pSamAccount, float *pSueAccount)
{
   cout << "What is Sam's balance? ";
   cin >> *pSamAccount;

   cout << "What is Sue's balance? ";
   cin >> *pSueAccount;
}

void date(float *pAccount)
{
   cout << "Cost of the date:\n";
   
   cout << "\tDinner:    ";
   float dinner;
   cin >> dinner;

   cout << "\tMovie:     ";
   float movie;
   cin >> movie;

   cout << "\tIce cream: ";
   float iceCream;
   cin >> iceCream;

   float sum = dinner + movie + iceCream;

   *pAccount -= sum;
}

void displayBalance(float *pSamBalance, float *pSueBalance)
{

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "Sam's balance: $" << *pSamBalance << endl
        << "Sue's balance: $" << *pSueBalance << endl;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float samAccount;
   float sueAccount;

   float * pSamAccount = &samAccount;
   float * pSueAccount = &sueAccount;

   promptBalances(pSamAccount, pSueAccount);

   float * pAccount;
   
    if (samAccount > sueAccount)

      pAccount = &samAccount;

   else

      pAccount = &sueAccount;

   date(pAccount);

   displayBalance(pSamAccount, pSueAccount);

   return 0;
}


