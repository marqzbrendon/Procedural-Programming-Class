/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals          (e.g. Assignment 10, Hello World)
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
using namespace std;

int getGrade()
{
   cout << "Enter number grade: ";
   int grade;
   cin >> grade;

   if (grade < 0 ||
       grade > 100)

      do
      {
         cout << "Invalid grade. Please type a number between 0 and 100.\n";

         cout << "Enter number grade: ";
         cin >> grade;
      }
      while (grade < 0 ||
             grade > 100);

   else
      
      return grade;
}


int computeLetterGrade(int grade)
{

   char letterGrade;
   
   switch (grade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;

      case 8:
         letterGrade = 'B';
         break;

      case 7:
         letterGrade = 'C';
         break;

      case 6:
         letterGrade = 'D';
         break;

      default:
         letterGrade = 'F';
         break;
   }

   return letterGrade;
}


void computeSign(int grade, char letterGrade)
{
   
   if (letterGrade == 'F')

      cout << "\n";

   else if (grade == 100)

      cout << "\n";

   else if (grade % 10 > 2 &&
            grade % 10 < 7)

      cout << "\n";

   else if (grade % 10 > 6 &&
            letterGrade == 'A')

      cout << "\n";

   else

      cout << (grade % 10 < 3 ? "-\n" : "+\n");
   
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   int grade = getGrade();

   char letterGrade = computeLetterGrade(grade);

   cout << grade
        << "% "
        << "is "
        << letterGrade;

   computeSign(grade, letterGrade);
   
   return 0;
}
