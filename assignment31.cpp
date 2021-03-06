/***********************************************************************
* Program:
*    Assignment 31, Array Design          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will prompt the user for 10 grades. Then, the grades will
*    be passed as array to a different function to get the grades average.
*    Finally, the average is display to the user. The value -1 is not taken
*    into consideration to the average. When all values are -1, the program
*    will display a customized message.
*
*    Estimated:  0.45 hrs   
*    Actual:     0.30 hrs
*      It was a simple assignment after finishing assignment30.
************************************************************************/

#include <iostream>
using namespace std;

void getGrades(int grades[]);
int averageGrades(int grades[]);

/**********************************************************************
 * main
 *
 * It determines when the program starts executing and calls the other
 * functions.
 ***********************************************************************/
int main()
{
   // declares the array variable
   int grades[10];

   // calls the function to get the grades from the user. Returns
   // the amount of grades (in this case, 10)
   getGrades(grades);

   // calls the function to get the grades average
   int average = averageGrades(grades);

   // displays the average to the user
   if (average >= 0)
      cout << "Average Grade: " << average << "%\n";

   // treats the error when all input values are -1 
   if (average < 0)
      cout << "Average Grade: ---%\n";
   
   return 0;
}

/**********************************************************************
 * getGrades
 *
 * This function prompts the user for 10 grades
 ***********************************************************************/
void getGrades(int grades[])
{
   // for loop to prompt for 10 grades

   for (int i = 0; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }
}

/**********************************************************************
 * averageGrades
 *
 * This function will sum the total of grades and get their average
 ***********************************************************************/
int averageGrades(int grades[])
{
   // for loop to sum the total of grades
   int validCount = 0;
   int sum = 0;

   
   for (int i = 0; i < 10; i++)
   {
      if (grades[i] >= 0)
         sum += grades[i];

      if (grades[i] >= 0)
         validCount++;
   }

   // returns the average when it is a positive number
   if (validCount > 0)
      return sum / validCount;

   // returns a negative value when the average is negative 
   else
      return -1;
}
