/***********************************************************************
* Program:
*    Assignment 21, Debugging
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
*    Estimated:  0.45 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

double promptParking()
{

   return 0;

}


double promptInsurance()
{

   return 0;

}


double promptDevalue()
{

   return 0;
   
}


double getPeriodicCost()
{

   promptDevalue();
   promptInsurance();
   promptParking();

   return 0;

}


double promptMileage()
{

   return 0;

}


double promptGas()
{

   return 0;
   
}


double promptRepairs()
{

   return 0;

}


double promptTires()
{

   return 0;

}


double getUsageCost()
{

   promptMileage();
   promptGas();
   promptRepairs();
   promptTires();

   return 0;

}


void display(double costUsage, double costPeriodic)
{

   cout << "Success\n";

}


/**********************************************************************
* The main function determines where the program needs to start.
***********************************************************************/
int main()
{

   double costPeriodic = getPeriodicCost();

   double costUsage = getUsageCost();

   display(costUsage, costPeriodic);
   
   return 0;
}
