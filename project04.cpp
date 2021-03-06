/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary:
*    Create a program where the user can input variables to calculate
*    monthly income.
*    Estimated:  2.0 hrs
*    Actual:     2.5 hrs
*    The most difficult part was to understand how to send and receive
*    values from one function to another.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

  // prototypes for functions
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualOther();
double getActualTithing();
double getActualTax();
void display(double income, double budgetLiving, double actualTax, 
          double actualTithing, double actualLiving, double actualOther);

/**********************************************************************
 * The function main tells the program where to begin execution.
 ***********************************************************************/
int main()
{

   cout.setf(ios::fixed);      // no scientific notation
   cout.setf(ios::showpoint);  // always show the decimal point
   cout.precision(2);          // two digits for money

  // Start lines of the program
   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl ;
   
   
   double income = getIncome();    // income
   double budgetLiving = getBudgetLiving();  // budgeted living
   double actualLiving = getActualLiving();    // actual living
   double actualTax = getActualTax();     // taxes
   double actualTithing = getActualTithing();   // tithing
   double actualOther = getActualOther();     // other expenses   
   
   display(income, budgetLiving, actualTax, actualTithing, 
           actualLiving, actualOther); 
   
}

/**********************************************************************
 * Function to prompt user income.
 ***********************************************************************/
double getIncome()
{

  // Input for Income
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;

}

/**********************************************************************
 * Function to prompt user budgeted living expenses.
 ***********************************************************************/
double getBudgetLiving()
{

  // Input for budgeted living expenses
   double budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;

}

/**********************************************************************
 * Function to prompt user actual living expenses.
 ***********************************************************************/
double getActualLiving()
{

  // Input for actual living expenses
   double actualLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
   
}

/**********************************************************************
 * Function to prompt user actual taxes.
 ***********************************************************************/
double getActualTax()
{
   
  // Input for taxes
   double actualTax;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;
   return actualTax;

}

/**********************************************************************
 * Function to prompt user actual tithing.
 ***********************************************************************/
double getActualTithing()
{

  // Input for tithe offerings
   double actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   return actualTithing;
   
}

/**********************************************************************
 * Function to prompt user actual other expenses.
 ***********************************************************************/
double getActualOther()
{
   
  // Input for other expenses
   double actualOther;
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   return actualOther;

}

/**********************************************************************
 * Function to compute taxes.
 ***********************************************************************/
double computeTax(double income)
{
   
  // compute taxes
   double yearlyIncome = income * 12.0;
   double yearlyTax;
   
   if (yearlyIncome >= 336550.0)
      yearlyTax = 91043.0 + 0.35 * (yearlyIncome - 336550.0);

   else if (yearlyIncome >= 188450.0)
      yearlyTax = 42170.0 + 0.33 * (yearlyIncome - 188450.0);

   else if (yearlyIncome >= 123700.0)
      yearlyTax = 24040.0 + 0.28 * (yearlyIncome - 123700.0);

   else if (yearlyIncome >= 61300.0)
      yearlyTax = 8440.0 + 0.25 * (yearlyIncome - 61300.0);

   else if (yearlyIncome >= 15100.0)
      yearlyTax = 1510.0 + 0.15 * (yearlyIncome - 15100.0);

   else if (yearlyIncome >= 0.0)
      yearlyTax = yearlyIncome * 0.10;

   double monthlyTax = yearlyTax / 12.0;
   
   return monthlyTax;

}

/**********************************************************************
 * Function compute user's tithing.
 ***********************************************************************/
double computeTithing(double income)
{

  // compute tithing
   double budgetTithing = income * 0.1;
   return budgetTithing;

}

/**********************************************************************
 * Function to display the program results.
 ***********************************************************************/
void display(double income, double budgetLiving, double actualTax, 
             double actualTithing, double actualLiving, double actualOther)
{

  // variables calculation.
   double budgetTax = computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   double actualDifference = income - actualTax - actualTithing
          - actualLiving - actualOther;
   double budgetDifference = 0.0;

   
  // The report
   cout << endl;
   cout << "The following is a report on your monthly expenses\n";

  // Report structure
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";

  // Report results

  // income
   cout << "\tIncome          $" << setw(11) << income << "    $"
        << setw(11) << income << endl;

  // taxes
   cout << "\tTaxes           $" << setw(11) << budgetTax << "    $"
        << setw(11) << actualTax << endl;

  // tithing
   cout << "\tTithing         $" << setw(11) << budgetTithing << "    $"
        << setw(11) << actualTithing << endl;

  // living
   cout << "\tLiving          $" << setw(11) << budgetLiving << "    $"
        << setw(11) << actualLiving << endl;

  // other
   cout << "\tOther           $" << setw(11) << budgetOther << "    $"
        << setw(11) << actualOther << endl;

  // Final structure
   cout << "\t=============== =============== ===============\n";

  // difference result
   cout << "\tDifference      $" << setw(11) << budgetDifference << "    $"
        << setw(11) << actualDifference << endl;
   
   return;
}
