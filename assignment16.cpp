/***********************************************************************
* Program:
*    Assignment 16, If Statement
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

int taxBracket(float yearlyIncome);

/**********************************************************************
 * The main function informs where the program will begin to be executed.
 ***********************************************************************/
int main()
{
   
   // prompt yearly income from user
   float yearlyIncome;
   cout << "Income: ";
   cin >> yearlyIncome;
   
   // yearly income variable
   int newTaxBracket = taxBracket(yearlyIncome);
   
   cout << "Your tax bracket is " << newTaxBracket << "%" << endl;
   
}

/**********************************************************************
 * This function will determine the tax bracket the user will be included
 * based on his yearly income.
 ***********************************************************************/
int taxBracket(float yearlyIncome)
{
   // variable to tax bracket result
   int bracket;
      
   // if statement to define tier
   if (yearlyIncome >= 336550.0)
      bracket = 35;
      
   else if (yearlyIncome >= 188450.0)
      bracket = 33;
      
   else if (yearlyIncome >= 123700.0)
      bracket = 28;
      
   else if (yearlyIncome >= 61300.0)
      bracket = 25;
      
   else if (yearlyIncome >= 15100.0)
      bracket = 15;
      
   else
      bracket = 10;

   return bracket;
}
