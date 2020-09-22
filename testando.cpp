/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int grid[4][3] =
      {//col 0    1    2
         {   8,  12,  -5 }, // row 0
         { 421,   4, 153 }, // row 1
         { -15,  20,  91 }, // row 2
         {   4, -15, 182 }, // row 3
      };
   
   int row; // vertical dimension
   int col; // horizontal dimension

   cout << "Specify the coordinates (X, Y) "; // people think in terms of X,Y
   cin >> col >> row;

   cout << grid[row][col] << endl;
       
   return 0;
}
