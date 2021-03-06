/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.45 hrs   
*    Actual:     0.30 hrs
*      This assignment specifically wasn't all that bad
*       to figure out. I'm just not sure if the order of
*       the functions have direct impact on the program.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Function questionPeter() in which Peter ask the Lord
* how many times does he need to forgive
***********************************************************************/
int questionPeter()
{

   //Peter's question
   cout << "Lord, how oft shall my brother sin against me, "
        << "and I forgive him?\n"
        << "Till seven times?\n";
   
   // this function has no return
   return 0;
}




/**********************************************************************
 * Function responseLord() in which the Lord replies to Peter
 ***********************************************************************/
int responseLord()
{
   // expression return
   return 70 * 7;
}



/**********************************************************************
 * You are not allowed to change MAIN in any way; just implement the two
 * functions: questionPeter() and responseLord()
 ***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}

