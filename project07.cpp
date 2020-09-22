/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will display a calendar a month and year (after 1753) chosen
*    by the user. To compute the proper offset, the program will take in
*    consideration how many days have passed since January 1st 1753.  
*
*    Estimated:  4.0 hrs   
*    Actual:     4.0 hrs
*      The debugging part was the most difficult. The loops were returning
*      some weird results. It took me a couple of hours to figure out.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * promptMonth
 * 
 * This function will prompt the user for a month to be displayed in the
 * calendar. If the month is less than 1 or greater than 12, a loop will
 * continue to prompt the user for a valid month.
 ***********************************************************************/
int promptMonth()
{
   // declare variable 
   int month;
   
   // loop to prompt for a valid year
   do
   {      
      cout << "Enter a month number: ";
      cin >> month;
      
      // validating the month input
      if (month < 1 || month > 12)
         
         // error message
         cout << "Month must be between 1 and 12.\n";
   }   
   while (month < 1 || month > 12); // loop parameters
   
      // return a valid month value to main
      return month;
}

/**********************************************************************
 * promptYear
 * 
 * This function will allow the user the choose the year of the previously
 * prompted month to be displayed. However, the year has to be greater or
 * equal to 1753. Otherwise, a loop will continue to prompt for a valid year. 
 ***********************************************************************/
int promptYear()
{
   // year variable 
   int year;

   // loop to prompt for a year equal or greater to 1753
   do
   {
      cout << "Enter year: ";
      cin >> year;

      // if statement to validate year
      if (year < 1753)

         // error message
         cout << "Year must be 1753 or later.\n";
   }
   while (year < 1753);
   
   // return year to main
   return year;
}

/**********************************************************************
 * isLeapYear
 * 
 * This function determines if a certain year is or isn't a leap year.
 * This will be important for a few computations in the program.
 ***********************************************************************/
bool isLeapYear(int year)
{  
   // if statement to validate a leap year 
   if (year % 4 == 0 && year % 100 != 0 ||
       year % 100 == 0 && year % 400 == 0 ||
       year % 400 == 0)

      // return true case it is a leap year
      return true;

   else
      
      // return false if it is not a leap year
      return false;
}

/**********************************************************************
 * getDaysInYear
 * 
 * This is a function to determine how many days have passed by since
 * January 1st 1753 up to the 1st of January of the input year. 
 * 
 * Ex: input is March of 2000. This function will count the days from 
 * January 1st 1753 to December 31st 1999.
 * 
 * This is necessary to compute the offset for the calendar.
 ***********************************************************************/
int getDaysInYear(int year)
{
   // declare variable
   int numDaysYear = 0;

   // for loop to count how many days have passed
   for (int y = 1753; y < year; y++)
   {
      // if statement to determine if is a leap year (366 days) or not
      if (isLeapYear(y) != true)
        
         numDaysYear += 365;

      else

         numDaysYear += 366;
   }

   // return the amount of days that have passed
   return numDaysYear;
}

/**********************************************************************
 * getDaysInMonth
 * 
 * Similar to the function getDaysInYear, but function will count the amount
 * of days that have passed within the input year up to the 1st day of the
 * input month. 
 * 
 * Ex: input is October of 2018. This function will count from January 1st
 * 2018 to September 30th 2018. 
 ***********************************************************************/
int getDaysInMonth(int month, int year)
{
   // variable for the number of days to be added
   int numDaysMonth = 0;

   // for loop to start counting based on how many days there are in the month
   for (int m = 1; m < month; m++)
   {
      // months with 31 days   
      if (m == 1 ||
          m == 3 ||
          m == 5 ||
          m == 7 ||
          m == 8 ||
          m == 10 ||
          m == 12)
      
         numDaysMonth += 31;
         
         // months with 30 days
      else if (m == 4 ||
               m == 6 ||
               m == 9 ||
               m == 11)
         
         numDaysMonth += 30;

      // in leap years, february will have 29 
      // days instead of 28               
      else if (m == 2 && isLeapYear(year) == true)
                     
         numDaysMonth += 29;
                     
      else
                  
         // february of non-leap-years         
         numDaysMonth += 28;
   }
   
   return numDaysMonth;
}

/**********************************************************************
 * computeOffSet
 * 
 * This is the function that determines the day of the week when the month
 * begins. We do so by adding all the days that have passed by since Jan 1st
 * 1753 and using modulo by 7.
 ***********************************************************************/
int computeOffSet(int numDaysMonth, int numDaysYear)
{
   // one simple operation is needed to compute the offset
   return (numDaysMonth + numDaysYear) % 7;
}
 
/**********************************************************************
 * numDays
 * 
 * This function is responsible to determine the amount of days there are
 * in a month. This will allow the calendar to display the correct amount
 * of days.
 ***********************************************************************/
int numDays(int month, int year)
{
   // int variable for the amount of days
   int numDays = 0;
   
   // if statement for months with 31 days
   if (month == 1 ||
       month == 3 ||
       month == 5 ||
       month == 7 ||
       month == 8 ||
       month == 10 ||
       month == 12)
      
      numDays = 31;
      
   // if statement for days with 30 days
   else if (month == 4 ||
            month == 6 ||
            month == 9 ||
            month == 11)
            
      numDays = 30;
            
   // february of leap years   
   else if (month == 2 && isLeapYear(year) == true)
                  
      numDays = 29;
                  
   else
               
      // february of non-leap-years         
      numDays = 28;

   return numDays;      
}

/**********************************************************************
 * displayTable
 * 
 * This is the function that will display the calendar to the user.
 * It has two main parts:
 * 1. An if statement to display the name of the month and year.
 * 2. Two for loops and if statements to place the offset in its proper 
 * spot and jump to the next line at the end of the week.
 ***********************************************************************/
void displayTable(int offSet, int daysCounted, int month, int year)
{
   // jump a line after prompting the month and year
   cout << endl;
   
   // 12 if statements, one for each month, to display the name of the month 
   if (month == 1)

      cout << "January, " << year << endl;

   else if (month == 2)

      cout << "February, " << year << endl;
      
   else if (month == 3)

      cout << "March, " << year << endl;

   else if (month == 4)

      cout << "April, " << year << endl;

   else if (month == 5)

      cout << "May, " << year << endl;

   else if (month == 6)

      cout << "June, " << year << endl;

   else if (month == 7)

      cout << "July, " << year << endl;

   else if (month == 8)

      cout << "August, " << year << endl;

   else if (month == 9)

      cout << "September, " << year << endl;

   else if (month == 10)

      cout << "October, " << year << endl;

   else if (month == 11)

      cout << "November, " << year << endl;

   else

      cout << "December, " << year << endl;
      
   
   
   // calendar structure message
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   
   // determine where the month will begin
   if (offSet != 6)
   
      for (int i = 0; i <= offSet; i++)
      {
         cout << "    ";       
      }
       
       // for loop to start counting the days of the week
   for (int i = 1; i <= daysCounted; i++)
   {
      cout << setw(4) << i;
         
      // if statement to jump to the next line at the end of the week
      if ((i + offSet + 1) % 7 == 0 && i != daysCounted)
            
         cout << endl;
   }
   
   // jump a line after the end of the month            
   cout << endl;
}         

/**********************************************************************
 * main
 * 
 * This function determines where the program starts to be executed. This
 * is also the function responsible for calling the other function in the
 * correct order.
 ***********************************************************************/
int main()
{
   // call all the function in the correct order:
   
   // prompt user for the month 
   int month = promptMonth();
   
   // prompt user for the year
   int year = promptYear();
   
   // compute the number of days within the input year up to the input month
   int numDaysMonth = getDaysInMonth(month, year);
   
   // compute the number of days since Jan 1st 1753 up to the input year
   int numDaysYear = getDaysInYear(year);
   
   // compute the offSet
   int offSet = computeOffSet(numDaysMonth, numDaysYear);
   
   // the number of days to be displayed in the calendar
   int daysCounted = numDays(month, year);
   
   // displays the calendar
   displayTable(offSet, daysCounted, month, year);
  
   return 0;
}
