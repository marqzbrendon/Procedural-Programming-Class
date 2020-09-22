/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Cook, Comeau, Falin, Lilya, Honeycutt, Unsicker, Peterson, Phair, Ellsworth, Helfrich}, CS124
* Author:
*    your name
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
#include <csignal>
using namespace std;


void sigHandler(int signum)
{
   cout << signum << endl;
   cout << "So you want to kill me?\n";
}


int main()
{
   signal(SIGINT, sigHandler);

   char pass;
   do
   {
      cout << "What is the password? ";
      cin >> pass;

   }
   while (pass != 't');
   
   return 0;
}
