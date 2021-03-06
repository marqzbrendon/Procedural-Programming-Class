/***********************************************************************
* Program:
*    Test 3, Reverse a file          (e.g. Assignment 10, Hello World)
*    Brother Christensen, CS124
* Author:
*    Brendon Marques
* Summary: 
*    This program will display the characters in a file in reverse order.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Get the fin.get() to work properly.
************************************************************************/

#include <iostream>
#include <fstream> // library to work with files
using namespace std;


/**********************************************************************
 * getFileName will prompt the user for a file.
 ***********************************************************************/
void getFileName(char filename[])
{
   // prompt for file name and passing as array
   cout << "Please enter the filename: ";
   cin >> filename;
}

/**********************************************************************
 * readFile() will read the characters from the file and pass it as
 * array to display().
 ***********************************************************************/
int readFile(char data[])
{
   // declaring the variable and passing to getFileName()
   char filename[256];
   getFileName(filename);

   // stream variable
   ifstream fin(filename);
   if (fin.fail()) // condition if fails to read from file
   {
      cout << "Error reading the file.\n";

      return 0;
   }

   int count = 0; // counting the number of words

   // for loop to pass the characters from the file
   // to the array
   // for (int i = 0; !fin.eof(); i++)
   //{
   //fin.get(data[i]);

   //count++;
   //}
   while(fin.get(data[count]))
   {
      count++;
   }
   // closing the file
   fin.close();

   // returning the number of words, minus eof
   return count - 1;
}

/**********************************************************************
 * Function to display the characters in reverse order
 ***********************************************************************/
void display(char data[], int c)
{

   // for loop to display in reverse
   for (c; c >= 0; c--)
   {
      cout << data[c];
   }

   // jump a line at the end
   cout << "\n";
}

/**********************************************************************
 * The program driver. That's it!
 ***********************************************************************/
int main()
{
   // declare array variable
   char data[4000];

   // calling readFile() passing the array
   int count = readFile(data);

   // calling display function
   display(data, count);

   // no errors!
   return 0;
}
