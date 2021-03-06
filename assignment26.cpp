/***********************************************************************
* Program:
*    Assignment 26, Files          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will prompt the user for a filename, then sum the values
*    in the given file, and display the average result.
*
*    Estimated:  1.0 hrs   
*    Actual:     4.0 hrs
*      It took me a long time to figure out how to sum to total values
*      of the file.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Get File Name function
 *
 * This function will prompt the user for the name of the file to be read.
 ***********************************************************************/
void getFileName(char fileName[256])
{
   // prompt the user for the name of the file
   cout << "Please enter the filename: ";
   cin >> fileName;

}


/**********************************************************************
 * Read File function
 *
 * This function will read all the data in the file.
 ***********************************************************************/
float readFile(char fileName[256])
{
   // stream variable
   ifstream fin(fileName);   

   // variables
   float grades;
   float sum = 0;

   // variable to validate the amount of values in the file
   int counter = 0;

   // loop to sum the total of grades
   while (fin >> grades)
   {
      sum += grades;
      counter++;
      
   }

   // close stream
   fin.close();

   // validate the amount of values in the file
   if (counter != 10)
      return false;
   
   else
      return sum / 10;

}


/**********************************************************************
 * Display function
 *
 * This function will display the average result to the user.
 ***********************************************************************/
void display(float average, char fileName[256])
{

   // round up number
   cout.setf(ios::fixed);
   cout.precision(0);

   // display error case amount of values in the file is invalid
   if (average == false)
      cout << "Error reading file \"" << fileName << "\"" << endl;

   // display message with no error
   else
   
      cout << "Average Grade: " << average << "%" << endl;

}

/**********************************************************************
 * Main function
 *
 * This function determines where the program starts executing.
 ***********************************************************************/
int main()
{
   // declare char variable and call getFileName function
   char fileName[256];
   getFileName(fileName);

   // declare variable and call readFile function
   float average = readFile(fileName);

   // call function display
   display(average, fileName);
   
   return 0;
}
