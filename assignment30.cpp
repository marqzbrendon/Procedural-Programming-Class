/***********************************************************************
* Program:
*    Assignment 30, Array Syntax          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will prompt the user for 10 grades. Then, the grades will
*    be passed as array to a different function to get the grades average.
*    Finally, the average is display to the user.
*
*    Estimated:  0.45 hrs   
*    Actual:     3.00 hrs
*      Working with arrays was difficult. It was hard to get the syntax
*      right. I needed some tutoring assistance.
************************************************************************/

#include <iostream>
using namespace std;

int getGrades(int grades[]);
int averageGrades(int grades[], int num);

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
   int num = getGrades(grades);

   // calls the function to get the grades average
   int average = averageGrades(grades, num);

   // displays the average to the user
   cout << "Average Grade: " << average << "%\n"; 
   
   return 0;
}

/**********************************************************************
 * getGrades
 *
 * This function prompts the user for 10 grades
 ***********************************************************************/
int getGrades(int grades[])
{
   // for loop to prompt for 10 grades
   int i = 0;
   for (i; i < 10; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> grades[i];
   }

   // returns the amount of grades in the array. In this case, 10
   return i;
}

/**********************************************************************
 * averageGrades
 *
 * This function will sum the total of grades and get their average
 ***********************************************************************/
int averageGrades(int grades[], int num)
{
   // for loop to sum the total of grades
   int sum = 0;
   for (int i = 0; i < 10; i++)
   {
      sum += grades[i];
   }

   // returns the sum total divided by 10
   return sum / num;
}
