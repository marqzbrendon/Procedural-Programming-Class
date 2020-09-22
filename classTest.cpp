/*********************************************************
* Program:  
*    Test 1, Converting Currencies
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This is a program to convert dollars into Euros so that our
*    friend Sue can enjoy her vacations!
***************************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


// functions prototypes
double promptUser();
double convertDollarsToEuros(double dollars);
void display(double euros);



/*********************************************************
* Main determines where the program starts.
***************************************************************/
int main()
{

  // how the doubles will be displayed
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);


  // variable for the dollars prompted
   double dollars = promptUser();

  // call the function to convert to Euros
   double euros = convertDollarsToEuros(dollars);

  // function to display the results
   display(euros);

   return 0;

}

/*********************************************************
* This function will prompt the user for US dollars value
***************************************************************/
double promptUser()
{

  // prompt user and add value of dollars to the variable
   double dollars;
   cout << "Please enter the amount in US Dollars: $";
   cin >> dollars;
  
   return dollars;
  
}

/*********************************************************
* This function will convert dollars to euros
***************************************************************/
double convertDollarsToEuros(double dollars)
{

  // convert dollars to euros
   double euros = dollars / 1.41;

   return euros;

}

/*********************************************************
* This is the function to output the results
***************************************************************/
void display(double euros)
{
  // if function to add "()" to negative values
   if (euros >= 0)
      cout << "\tEuros: " << euros << endl;
      
   else
      cout << "\tEuros: (" << euros << ")" << endl;
        
}


// may the force be with you