/***********************************************************************
* Program:
*    Assignment 25, Loop Design          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will prompt the user for a number of days in the month,
*    then will prompt for an offset. Finally, a calendar will be displayed
*    to the user based on the info provided.
*
*    Estimated:  2.5 hrs   
*    Actual:     4.0 hrs
*      The functions to prompt for the offset and number of days in the
*      month was actually easy. However, the loop to display the calendar
*      was quite a challenge and took me a long time (and help) to do it.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int promptDays();
int promptOffSet();
void displayTable(int offSet, int daysInMonth);

/**********************************************************************
 * The main function determines where the program will start to execute.
 ***********************************************************************/
int main()
{
   // call function to prompt for the amount
   // of days in the month
   int daysInMonth = promptDays();

   // call function to prompt user for the offset
   int offSet = promptOffSet();

   // call display function
   displayTable(offSet, daysInMonth);
  
   return 0;
  
}

/**********************************************************************
 * This function will prompt the user the amount of days in the month.
 ***********************************************************************/
int promptDays()
{
   // variable
   int daysInMonth;

   // prompting a valid number of days in month
   do
   {
      do
      {
      
         cout << "Number of days: ";
         cin >> daysInMonth;
        
      }
      while (daysInMonth < 28);
   }
   while (daysInMonth > 31);
   
   return daysInMonth;
}


/**********************************************************************
 * This function will prompt the user for the offset.
 ***********************************************************************/
int promptOffSet()
{

   // variable
   int offSet;
   
   // prompting a valid number for offset
   do
   {
      
      cout << "Offset: ";
      cin >> offSet;

   }
   while (offSet > 6);

  
   return offSet;   
     
}

/**********************************************************************
 * Function to display the calendar using the prompted values in main.
 **********************************************************************/
void displayTable(int offSet, int daysInMonth)
{

   // calendar layout
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;

   // determine where the offset will be displayed
   if (offSet != 6)

      for (int i = 0; i <= offSet; i++)
      {
         cout << "    ";

      }
   
   // add the days of the month   
   for (int i = 1; i <= daysInMonth; i++)
   {
      cout << setw(4) << i;

      // if statement to jump to the next line
      if ((i + offSet + 1) % 7 == 0 && i != daysInMonth)

         cout << endl;

   }

   // jump to the next line after the loop is finished
   cout << endl;
   
   
   return;

}
