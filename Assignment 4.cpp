#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
   int initialCredit;
   int creditEarnedINT, totalCredit;
   string userChoice_InputSTRING, creditEarnedSTRING;

   const int CREDITTOREDEEM = 7;
   const string INDENT = "   ";
   const char SHUTDOWN = 'S';
   const char shutdown = 's';
   const char PURCHASE = 'P';
   const char purchase = 'p';
   const char YES = 'Y';
   const char NO = 'N';

   initialCredit = 0;
   totalCredit = initialCredit;


   while (1)
   {
      cout << endl;
      cout << "Welcome to Anderson Frozen Yogurt!" << endl << endl;
      cout << "Menu: " << endl;
      cout << INDENT << "P/p (Process Purchase)" << endl;
      cout << INDENT << "S/s (Shut Down)" << endl << endl;
      cout << "Your choice is : ";
      getline(cin, userChoice_InputSTRING);
      {
         while (!((userChoice_InputSTRING[0] == PURCHASE) ||
            (userChoice_InputSTRING[0] == purchase) ||
            (userChoice_InputSTRING[0] == SHUTDOWN) ||
            (userChoice_InputSTRING[0] == shutdown)))
         {
            cout << "Please re-enter again with P/p or S/s. ";

            cout << endl << endl;
            cout << "Welcome to Anderson Frozen Yogurt!" << endl << endl;
            cout << "Menu: " << endl;
            cout << INDENT << "P/p (Process Purchase)" << endl;
            cout << INDENT << "S/s (Shut Down)" << endl << endl;
            cout << "Your choice is : ";
            getline(cin, userChoice_InputSTRING);
         }

         if ((userChoice_InputSTRING[0] == SHUTDOWN) ||
            (userChoice_InputSTRING[0] == shutdown))
         {
            cout << "Goodbye See you Again!" << endl;
            cout << "--------------------Shutting Down-----------------" 
                 << endl;
            break;
         }

         do
         {
            string userInput;
            if (totalCredit >= CREDITTOREDEEM)
            {
               cout << endl;
               cout <<"You are qualify for a free yogurt."
                    <<"Do you want to redeem it?"<< endl;
               cout << "Enter Y for Yes and N for No: ";
               getline(cin, userInput);
              
               {
                  if (userInput[0] == NO)
                  {
                     cout <<"If you would not like to redeem, "
                          <<"How many yogurts would you like to buy today? : ";
                     getline(cin, creditEarnedSTRING);
                     istringstream(creditEarnedSTRING) >> creditEarnedINT;

                     if (creditEarnedINT < 1 || creditEarnedINT > 15)
                     {
                        cout << "You have entered an inappopriate number." << endl;
                        cout << "Please enter values between 1 to 15!" << endl;
                        break;
                     }

                     totalCredit += creditEarnedINT;

                     cout << "You have just earned " << creditEarnedINT
                          << " credits and have a total of " << totalCredit
                          << " credits" << endl;
                  }

                  else if (userInput[0] == YES)
                  {
                     totalCredit -= 7;
                     cout << "You have just used 7 credits and have " 
                          << totalCredit << " left." << endl << endl;
                     cout << "Enjoy your free yogurt and "
                          << "Come Back again next time.Goodbye!" << endl;
                  }

               }
            }
            else
            {
               cout << "How many yogurts would you like to buy?  : ";
               getline(cin, creditEarnedSTRING);
               istringstream(creditEarnedSTRING) >> creditEarnedINT;
               
               if (creditEarnedINT < 1 || creditEarnedINT > 15) 
               {
                  cout << "You have entered an inappopriate number." << endl;
                  cout << "Please enter values between 1 to 15!" << endl;
                  break;
               }

               totalCredit += creditEarnedINT ;

               cout << "You have just earned " << creditEarnedINT
                  << " credits and have a total of " << totalCredit 
                  << " credits." << endl;
            }
            cout << endl;
            cout << "Welcome to Anderson Frozen Yogurt!" << endl;
            cout << "Menu: " << endl;
            cout << INDENT << "P/p (Process Purchase)" << endl;
            cout << INDENT << "S/s (Shut Down)" << endl << endl;

            cout << "Your choice is : ";
            getline(cin, userChoice_InputSTRING);

            if ((userChoice_InputSTRING[0] == SHUTDOWN) ||
               (userChoice_InputSTRING[0] == shutdown))
            {
               cout << "Goodbye See you Again!" << endl;
               cout << "--------------------Shutting Down-----------------"
                    << endl;
               return 0;
            }

         }while((userChoice_InputSTRING[0] == PURCHASE) ||
            (userChoice_InputSTRING[0] == purchase));

      }
   }
   return 0;
}

/*-----------------------------Paste of the Run #1-------------------------------


Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 10
You have just earned 10 credits and have a total of 10 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : p

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: N
If you would not like to redeem, How many yogurts would you like to buy today? : 2
You have just earned 2 credits and have a total of 12 credits

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: Y
You have just used 7 credits and have 5 left.

Enjoy your free yogurt and Come Back again next time.Goodbye!

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 5
You have just earned 5 credits and have a total of 10 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: N
If you would not like to redeem, How many yogurts would you like to buy today? : 10
You have just earned 10 credits and have a total of 20 credits

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: Y
You have just used 7 credits and have 13 left.

Enjoy your free yogurt and Come Back again next time.Goodbye!

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: 1

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: Y
You have just used 7 credits and have 6 left.

Enjoy your free yogurt and Come Back again next time.Goodbye!

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 3
You have just earned 3 credits and have a total of 9 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P

You are qualify for a free yogurt.Do you want to redeem it?
Enter Y for Yes and N for No: Y
You have just used 7 credits and have 2 left.

Enjoy your free yogurt and Come Back again next time.Goodbye!

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is :

-------------------------------------------------------------------------------*/


/*-------------------------Paste of the Run #2 (Shutting Down)------------------


Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 5
You have just earned 5 credits and have a total of 5 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 10
You have just earned 10 credits and have a total of 15 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : S
Goodbye See you Again!
--------------------Shutting Down-----------------

Press any key to close this window . . .


-----------------------------------------------------------------------------*/

/*-------------------Paste of the run #3 (Choice Invalid Input)------------------


Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : BUY
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : ORDER
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : yogurt
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : deal
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : buying
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : Quit
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : quit
Please re-enter again with P/p or S/s.

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : PURCHASE
How many yogurts would you like to buy?  : 5
You have just earned 5 credits and have a total of 5 credits.

Welcome to Anderson Frozen Yogurt!
Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is :
-------------------------------------------------------------------------------*/

/*--------------------Paste of the Run #4 (Out of Range Error)-------------------

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 100000
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 30
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 16
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : -10
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : -0
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : 0
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is : P
How many yogurts would you like to buy?  : LOL
You have entered an inappopriate number.
Please enter values between 1 to 15!

Welcome to Anderson Frozen Yogurt!

Menu:
   P/p (Process Purchase)
   S/s (Shut Down)

Your choice is :
------------------------------------------------------------------------------*/






