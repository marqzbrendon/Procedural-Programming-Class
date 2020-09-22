/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.
*
*    Estimated:  0.45 hrs   
*    Actual:     1.00 hrs
*      I wasn't sure how to properly use the bool variable
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 * This function will do the math to confirm if the prompted
 * input fulfill the requirements to be a full tithe payer
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{
   // confirm tithe payer status
   bool tithePayer = (tithe >= (income / 10));
   return tithePayer;

}


/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}
