#include <iostream>
#include <string>

using namespace std;

class TripleString
{
private:
   string string1, string2, string3 ;
   bool validString(string str);

public:
   TripleString();
   TripleString(string str1, string str2, string str3);

   bool setString1(string str1);
   bool setString2(string str2);
   bool setString3(string str3);

   string getString1();
   string getString2();
   string getString3();
   string display();

   static const int MIN_LENGTH = 1;
   static const int MAX_LENGTH = 50;
   static const string DEFAULT_STRING;
};
const string TripleString::DEFAULT_STRING = "(undefined)";

int main()
{
   TripleString string_1, string_2, string_3, string_4;
   
   cout << "All Object default strings: "
        << endl;
   cout << "String#1 " << string_1.display() << endl << endl;
   cout << "String#2 " << string_2.display() << endl << endl;
   cout << "String#3 " << string_3.display() << endl << endl;
   cout << "String#4 " << string_4.display() << endl << endl;

   string_1.setString1("Hello Foothill Student. I don't like this ,"
      "i am just trying to add more characters"
      "so it unable to set to the string i want.");
   string_1.setString3("I am Anderson Lam.");
   string_2.setString1("I am 17 Years Old and");
   string_2.setString2("I'm a freshman here in Foothill");
   string_3.setString2("Majoring in Engineering and");
   string_3.setString3("Computer Science.");
   string_4.setString1("Hope I can transfer in");
   string_4.setString3("FALL 2022 to UC BERKELEY!");

   cout << endl;
   cout << "All Object default strings after mutated some of the members: "
        << endl;
   cout << "String#1 " << string_1.display() << endl << endl;
   cout << "String#2 " << string_2.display() << endl << endl;
   cout << "String#3 " << string_3.display() << endl << endl;
   cout << "String#4 " << string_4.display() << endl << endl;

   cout << "Mutator Tests for : " << endl;

   cout << "String#1- String 1: " << endl;
   if (!string_1.setString1("Hello Foothill Student.I don't like this ,"
      "i am just trying to add more characters"
      "so it unable to set to the string i want."))
      cout << "ERROR! Unable to set string to"
      "\"Hello Foothill Student.I don't like this ,"
      "i am just trying to add more characters "
      "so it unable to set to the string i want.\"" << endl;
   else
      cout << "String is sucessfully set to"
      "\"Hello Foothill Student.I don't like this ,"
      "i am just trying to add more characters "
      "so it unable to set to the string i want.\"" << endl;

   cout << endl;

   cout << "String#2- String 2: " << endl;
   if (!string_2.setString2("I'm a freshman here in Foothill"))
      cout << "ERROR !! Unable to set string to"
         "\"I'm a freshman here in Foothill.\"" << endl;
   else
      cout << "String is successfully set to " 
      "\"I'm a freshman here in Foothill.\"" << endl;

   cout << endl;
   cout << "Two accessors: " << endl;
   cout << "String #1 - string3: " << string_1.getString3() << endl;
   cout << "String #2 - string1: " << string_2.getString1() << endl << endl;

   return 0;
}

TripleString::TripleString()
{
   string1 = DEFAULT_STRING;
   string2 = DEFAULT_STRING;
   string3 = DEFAULT_STRING;
}

TripleString::TripleString (string string1, string string2, string string3)
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
 
   str = str;
   return true;
}

bool TripleString::setString1(string str1)
{
   validString(str1);

   if (validString(str1) == false)
      return false;

   else
   {
      string1 = str1;
      return true;
   }
}

bool TripleString::setString2(string str2)
{
   if (validString(str2) == false)
      return false;

   else
   {
      string2 = str2;
      return true;
   }
}

bool TripleString::setString3(string str3)
{
   if (validString(str3) == false)
      return false;

   else
   {
      string3 = str3;
      return true;
   }
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

string TripleString::display()
{
   string displayStrings;
   const string INDENT = "         ";

   displayStrings = "- String 1 : " + string1 + "\n" +
       INDENT + "- String 2 : " + string2 + "\n" +
       INDENT + "- String 3 : " + string3;
 
   return displayStrings;
}

/*---------------------------Paste Of the Run #1---------------------------------
All Object default strings:
String#1 - String 1 : (undefined)
         - String 2 : (undefined)
         - String 3 : (undefined)

String#2 - String 1 : (undefined)
         - String 2 : (undefined)
         - String 3 : (undefined)

String#3 - String 1 : (undefined)
         - String 2 : (undefined)
         - String 3 : (undefined)

String#4 - String 1 : (undefined)
         - String 2 : (undefined)
         - String 3 : (undefined)


All Object default strings after mutated some of the members:
String#1 - String 1 : (undefined)
         - String 2 : (undefined)
         - String 3 : I am Anderson Lam.

String#2 - String 1 : I am 17 Years Old and
         - String 2 : I'm a freshman here in Foothill
         - String 3 : (undefined)

String#3 - String 1 : (undefined)
         - String 2 : Majoring in Engineering and
         - String 3 : Computer Science.

String#4 - String 1 : Hope I can transfer in
         - String 2 : (undefined)
         - String 3 : FALL 2022 to UC BERKELEY!

Mutator Tests for :
String#1- String 1:
ERROR! Unable to set string to"Hello Foothill Student.I don't like this ,i am just trying to add more characters so it unable to set to the string i want."

String#2- String 2:
String is successfully set to "I'm a freshman here in Foothill."

Two accessors:
String #1 - string3: I am Anderson Lam.
String #2 - string1: I am 17 Years Old and

Press any key to close this window . . .

--------------------------------------------------------------------------------*/

