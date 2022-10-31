#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class TripleString
{
private:
   string string1, string2, string3;

private:
   static bool validString(string str);
   
public:
   TripleString();
   TripleString(string str1, string str2, string str3);

   bool setString1(string str1);
   bool setString2(string str2);
   bool setString3(string str3);

   string getString1();
   string getString2();
   string getString3();
   string toString();

   static const int MIN_LENGTH;
   static const int MAX_LENGTH;
   static const int MIN_BET;
   static const int MAX_BET;
   static const int MIN_SPACE;
   static const int MAX_SPACE;
   static const int MIN_CHERRIES;
   static const int MAX_CHERRIES;
   static const int MIN_SEVEN;
   static const int MAX_SEVEN;
   static const int MIN_BAR;
   static const int MAX_BAR;
   static const string DEFAULT_STRING;
   static const string REWARD_1;
   static const string REWARD_2;
   static const string REWARD_3;
   static const string REWARD_4;
};
int const TripleString::MIN_LENGTH = 1;
int const TripleString::MAX_LENGTH = 50;
int const TripleString::MIN_BET = 0;
int const TripleString::MAX_BET = 100;
int const TripleString::MIN_SPACE = 0;
int const TripleString::MAX_SPACE = 70;
int const TripleString::MIN_CHERRIES = 581;
int const TripleString::MAX_CHERRIES = 1000;
int const TripleString::MIN_SEVEN = 21;
int const TripleString::MAX_SEVEN = 220;
int const TripleString::MIN_BAR = 221;
int const TripleString::MAX_BAR = 580;
string const TripleString::DEFAULT_STRING = "(undefined)";
string const TripleString::REWARD_1 = "(space)";
string const TripleString::REWARD_2 = "7";
string const TripleString::REWARD_3 = "BAR";
string const TripleString::REWARD_4 = "cherries";

int getBet(int &count);
string randString();
TripleString pull();
int getPayMultiplier(TripleString thePull);
void display(TripleString thePull, int winnings);

int main()
{
   TripleString thePull;
   int userBet, winnings, count;
   bool validated;
   validated = false;
   count = 1;

   while (!validated)
   {
      userBet = getBet(count);
      if (userBet != 0)
      {
         thePull = pull();
         winnings = (getPayMultiplier(thePull) * userBet);
         display(thePull, winnings);
      }
      else
      {
         cout << endl;
         cout << " Thank you for using Casino Anderson. Have A Great Day!"
              << endl;
         return 1;
      }
   }
   return 0;
}

int getBet(int &count)
{
   int userInput_Bet;
   count;
   do
   {
      cout << count++;
      cout << ": How much would you like to bet (1 - 100) or 0 to quit? ";
      cin >> userInput_Bet;

   } while (((userInput_Bet < TripleString::MIN_BET)) ||
      ((userInput_Bet > TripleString::MAX_BET)));
  
   return userInput_Bet;
}

string randString()
{
   string result;
   int random;
   random = rand() % 1000 + 1;

   if ((random > TripleString::MIN_SPACE) &&
      (random <= TripleString::MAX_SPACE))
      result = TripleString::REWARD_1;

   else if ((random > TripleString::MIN_SEVEN) &&
      (random <= TripleString::MAX_SEVEN))
      result = TripleString::REWARD_2;

   else if ((random > TripleString::MIN_BAR) &&
      (random <= TripleString::MAX_BAR))
      result = TripleString::REWARD_3;

   else if ((random > TripleString::MIN_CHERRIES) &&
      (random <= TripleString::MAX_CHERRIES))
      result = TripleString::REWARD_4;

   return result;
}

TripleString pull()
{
   TripleString lets_Start;

   lets_Start.setString1(randString());
   lets_Start.setString2(randString());
   lets_Start.setString3(randString());

   return lets_Start;
}
int getPayMultiplier(TripleString thePull)
{
   string check1, check2, check3;
   int multiplier;
   multiplier = 0;

   check1 = thePull.getString1();
   check2 = thePull.getString2();
   check3 = thePull.getString3();

   if ((check1 == TripleString::REWARD_4) && (check2 != TripleString::REWARD_4))
      multiplier = 5;

   else if ((check1 == TripleString::REWARD_4) 
      && (check2 == TripleString::REWARD_4)
      && (check3 != TripleString::REWARD_4))
      multiplier = 15;

   else if ((check1 == TripleString::REWARD_4) 
      && (check2 == TripleString::REWARD_4)
      && (check3 == TripleString::REWARD_4))
      multiplier = 30;

   else if ((check1 == TripleString::REWARD_3) 
      && (check2 == TripleString::REWARD_3)
      && (check3 == TripleString::REWARD_3))
      multiplier = 50;

   else if ((check1 == TripleString::REWARD_2) 
      && (check2 == TripleString::REWARD_2)
      && (check3 == TripleString::REWARD_2))
      multiplier = 100;

   return multiplier;
}

void display(TripleString thePull, int winnings)
{
   string str1, str2, str3;

   str1 = thePull.getString1();
   str2 = thePull.getString2();
   str3 = thePull.getString3();

   cout << "whirrrrrr .... and your pull is .... " << endl;
   cout << thePull.toString() << endl;

   if (winnings == 0)
      cout << "Sorry, you lose. " << endl << endl;
   else
      cout << "CONGRATULATIONS, YOU HAVE WON : $" << winnings << endl << endl;
}

TripleString::TripleString()
{
   string1 = DEFAULT_STRING;
   string2 = DEFAULT_STRING;
   string3 = DEFAULT_STRING;
}

TripleString::TripleString(string string1, string string2, string string3)
{
   if (!setString1(string1))
      string1 = DEFAULT_STRING;
   if (!setString2(string2))
      string2 = DEFAULT_STRING;
   if (!setString3(string3))
      string3 = DEFAULT_STRING;
}

bool TripleString::validString(string str)
{
   if ((str.length() < MIN_LENGTH) ||
      (str.length() > MAX_LENGTH))
      return false;

   return true;
}

bool TripleString::setString1(string str1)
{
   if (validString(str1) == false)
      return false;

   string1 = str1;
   return true;
   
}

bool TripleString::setString2(string str2)
{
   if (validString(str2) == false)
      return false;

   string2 = str2;
   return true;
}

bool TripleString::setString3(string str3)
{
   if (validString(str3) == false)
      return false;

   string3 = str3;
   return true;
}

string TripleString::getString1()
{
   return string1;
}

string TripleString::getString2()
{
   return string2;
}

string TripleString::getString3()
{
   return string3;
}

string TripleString::toString()
{
   string allStrings;

   allStrings = " " + string1 + " " + string2 + " " + string3;
   return allStrings;
}

/*---------------------Paste of the run #1 (At least 40 Pulls)--------------------
1: How much would you like to bet (1 - 100) or 0 to quit? 50
whirrrrrr .... and your pull is ....
 (space) BAR BAR
Sorry, you lose.

2: How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ....
 BAR 7 cherries
Sorry, you lose.

3: How much would you like to bet (1 - 100) or 0 to quit? 12
whirrrrrr .... and your pull is ....
 BAR BAR cherries
Sorry, you lose.

4: How much would you like to bet (1 - 100) or 0 to quit? 13
whirrrrrr .... and your pull is ....
 BAR cherries 7
Sorry, you lose.

5: How much would you like to bet (1 - 100) or 0 to quit? 56
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

6: How much would you like to bet (1 - 100) or 0 to quit?
3
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

7: How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ....
 cherries BAR BAR
CONGRATULATIONS, YOU HAVE WON : $25

8: How much would you like to bet (1 - 100) or 0 to quit? 56642
9: How much would you like to bet (1 - 100) or 0 to quit? 264
10: How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ....
 cherries cherries 7
CONGRATULATIONS, YOU HAVE WON : $15

11: How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ....
 BAR BAR BAR
CONGRATULATIONS, YOU HAVE WON : $100

12: How much would you like to bet (1 - 100) or 0 to quit? 214
13: How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $150

14: How much would you like to bet (1 - 100) or 0 to quit? 513
15: How much would you like to bet (1 - 100) or 0 to quit? 6
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

16: How much would you like to bet (1 - 100) or 0 to quit? 76
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

17: How much would you like to bet (1 - 100) or 0 to quit? 34
whirrrrrr .... and your pull is ....
 cherries BAR (space)
CONGRATULATIONS, YOU HAVE WON : $170

18: How much would you like to bet (1 - 100) or 0 to quit? 4
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $120

19: How much would you like to bet (1 - 100) or 0 to quit? 43
whirrrrrr .... and your pull is ....
 BAR BAR cherries
Sorry, you lose.

20: How much would you like to bet (1 - 100) or 0 to quit? 12
whirrrrrr .... and your pull is ....
 cherries 7 cherries
CONGRATULATIONS, YOU HAVE WON : $60

21: How much would you like to bet (1 - 100) or 0 to quit? 1234
22: How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ....
 BAR cherries BAR
Sorry, you lose.

23: How much would you like to bet (1 - 100) or 0 to quit? 7
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $210

24: How much would you like to bet (1 - 100) or 0 to quit? 75
whirrrrrr .... and your pull is ....
 (space) cherries cherries
Sorry, you lose.

25: How much would you like to bet (1 - 100) or 0 to quit? 57
whirrrrrr .... and your pull is ....
 cherries BAR cherries
CONGRATULATIONS, YOU HAVE WON : $285

26: How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ....
 BAR (space) 7
Sorry, you lose.

27: How much would you like to bet (1 - 100) or 0 to quit? 62
whirrrrrr .... and your pull is ....
 cherries BAR 7
CONGRATULATIONS, YOU HAVE WON : $310

28: How much would you like to bet (1 - 100) or 0 to quit? 246
29: How much would you like to bet (1 - 100) or 0 to quit? 6
whirrrrrr .... and your pull is ....
 (space) cherries BAR
Sorry, you lose.

30: How much would you like to bet (1 - 100) or 0 to quit? 46
whirrrrrr .... and your pull is ....
 cherries BAR cherries
CONGRATULATIONS, YOU HAVE WON : $230

31: How much would you like to bet (1 - 100) or 0 to quit? 46
whirrrrrr .... and your pull is ....
 cherries cherries BAR
CONGRATULATIONS, YOU HAVE WON : $690

32: How much would you like to bet (1 - 100) or 0 to quit? 34
whirrrrrr .... and your pull is ....
 BAR (space) 7
Sorry, you lose.

33: How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ....
 BAR BAR cherries
Sorry, you lose.

34: How much would you like to bet (1 - 100) or 0 to quit?
10
whirrrrrr .... and your pull is ....
 cherries 7 cherries
CONGRATULATIONS, YOU HAVE WON : $50

35: How much would you like to bet (1 - 100) or 0 to quit? 455
36: How much would you like to bet (1 - 100) or 0 to quit? 2
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $60

37: How much would you like to bet (1 - 100) or 0 to quit? 14
whirrrrrr .... and your pull is ....
 BAR cherries BAR
Sorry, you lose.

38: How much would you like to bet (1 - 100) or 0 to quit? 14
whirrrrrr .... and your pull is ....
 cherries BAR cherries
CONGRATULATIONS, YOU HAVE WON : $70

39: How much would you like to bet (1 - 100) or 0 to quit? 4
whirrrrrr .... and your pull is ....
 BAR BAR BAR
CONGRATULATIONS, YOU HAVE WON : $200

40: How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ....
 7 7 cherries
Sorry, you lose.

41: How much would you like to bet (1 - 100) or 0 to quit? 14
whirrrrrr .... and your pull is ....
 BAR cherries 7
Sorry, you lose.

42: How much would you like to bet (1 - 100) or 0 to quit? 4
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $120

43: How much would you like to bet (1 - 100) or 0 to quit? 5
whirrrrrr .... and your pull is ....
 cherries cherries BAR
CONGRATULATIONS, YOU HAVE WON : $75

44: How much would you like to bet (1 - 100) or 0 to quit? 14
whirrrrrr .... and your pull is ....
 cherries BAR (space)
CONGRATULATIONS, YOU HAVE WON : $70

45: How much would you like to bet (1 - 100) or 0 to quit? 14
whirrrrrr .... and your pull is ....
 cherries cherries 7
CONGRATULATIONS, YOU HAVE WON : $210

46: How much would you like to bet (1 - 100) or 0 to quit? 4
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

47: How much would you like to bet (1 - 100) or 0 to quit? 0

 Thank you for using Casino Anderson. Have A Great Day!

Press any key to close this window . . .


-------------------------------------------------------------------------------*/

//Include both a win of cherries cherries cherries and a win of BAR BAR BAR,
//full cherries in line 17 , full bar in line 13
/* -----------Paste of the run #2(Fullfill requirements above)------------------- 

1: How much would you like to bet (1 - 100) or 0 to quit? 50
whirrrrrr .... and your pull is ....
 (space) BAR BAR
Sorry, you lose.

2: How much would you like to bet (1 - 100) or 0 to quit? 10
whirrrrrr .... and your pull is ....
 BAR 7 cherries
Sorry, you lose.

3: How much would you like to bet (1 - 100) or 0 to quit? 300
4: How much would you like to bet (1 - 100) or 0 to quit? 212
5: How much would you like to bet (1 - 100) or 0 to quit? 4
whirrrrrr .... and your pull is ....
 BAR BAR cherries
Sorry, you lose.

6: How much would you like to bet (1 - 100) or 0 to quit? 13
whirrrrrr .... and your pull is ....
 BAR cherries 7
Sorry, you lose.

7: How much would you like to bet (1 - 100) or 0 to quit? 12
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

8: How much would you like to bet (1 - 100) or 0 to quit? 1
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

9: How much would you like to bet (1 - 100) or 0 to quit? 300
10: How much would you like to bet (1 - 100) or 0 to quit? 300
11: How much would you like to bet (1 - 100) or 0 to quit? 50
whirrrrrr .... and your pull is ....
 cherries BAR BAR
CONGRATULATIONS, YOU HAVE WON : $250

12: How much would you like to bet (1 - 100) or 0 to quit? 20
whirrrrrr .... and your pull is ....
 cherries cherries 7
CONGRATULATIONS, YOU HAVE WON : $300

13: How much would you like to bet (1 - 100) or 0 to quit? 32
whirrrrrr .... and your pull is ....
 BAR BAR BAR
CONGRATULATIONS, YOU HAVE WON : $1600

14: How much would you like to bet (1 - 100) or 0 to quit? 1006
15: How much would you like to bet (1 - 100) or 0 to quit? 450
16: How much would you like to bet (1 - 100) or 0 to quit? 101
17: How much would you like to bet (1 - 100) or 0 to quit? 30
whirrrrrr .... and your pull is ....
 cherries cherries cherries
CONGRATULATIONS, YOU HAVE WON : $900

18: How much would you like to bet (1 - 100) or 0 to quit? 304
19: How much would you like to bet (1 - 100) or 0 to quit? 40
whirrrrrr .... and your pull is ....
 BAR cherries cherries
Sorry, you lose.

20: How much would you like to bet (1 - 100) or 0 to quit?
-------------------------------------------------------------------------------*/