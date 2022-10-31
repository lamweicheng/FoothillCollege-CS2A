#include <iostream>
using namespace std;
int main()
{
   int myId, numLet;
   int intResult;
   float doubleResult;

   cout << "My Family name is Lam.\n";
   cout << "My Student ID is 20422860.\n";
   cout << "The number of characters in my last name is 3.\n" << endl;

   myId = 20422860;
   numLet = 3;

   intResult = myId % 13;
   cout << "Expression #1: " << myId << " % " << "13" << " : " << intResult << endl << endl;

   intResult = (numLet + 13) % 12;
   cout << "Expression #2: (" << numLet << " + 13) % 12 : " << intResult << endl << endl;

   cout.precision(10);
   doubleResult = myId / (numLet + 70.);
   cout << "Expression #3: " << myId << " / " << "(" << numLet << " + " << "70) : " << doubleResult<< endl << endl;
   
   intResult = 1 + 2 + numLet;
   cout << "Expression #4: 1 + 2 + " << numLet << " : " << intResult << endl << endl;

   doubleResult = (myId + 4657.) / ((numLet + 20.) * (numLet + 20.));
   doubleResult = 25000. / (60. + doubleResult);
   cout << "Expression #5: 25000 / [ 60 + [ (" << myId << " + 4657) / (" << numLet << " + 20";
   cout << ")^2 ] ] : " << doubleResult << endl << endl;

   return 0;
}


/*-----------------------------------------------------------------------Paste of the Run-----------------------------------------------------------------------

My Family name is Lam.
My Student ID is 20422860.
The number of characters in my last name is 3.

Expression #1: 20422860 % 13 : 3

Expression #2: (3 + 13) % 12 : 4

Expression #3: 20422860 / (3 + 70) : 279765.2188

Expression #4: 1 + 2 + 3 : 6

Expression #5: 25000 / [ 60 + [ (20422860 + 4657) / (3 + 20)^2 ] ] : 0.6464066505


C:\Users\lamwe\OneDrive\Documents\LamWC\Foothill College\SPRING 2020\CS 2A\Assignment\Assignment_2\Debug\Assignment_2.exe (process 16088) exited with code 0.
Press any key to close this window . . .
 
 ------------------------------------------------------------------------------------------------------------------------------------------------------------  */

   












