#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Student
{
private:
   string lastName, firstName;
   int totalPoints;
   static int sortKey;

public:
   static const int SORT_BY_FIRST;
   static const int SORT_BY_LAST;
   static const int SORT_BY_POINTS;
   static const int DEFAULT_POINTS;
   static const int MAX_POINTS;
   static const int MIN_POINTS;
   static const string DEFAULT_NAME;

   Student(string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
      int pts = DEFAULT_POINTS);

   string getLastName();
   string getFirstName();
   string toString();
   int getTotalPoints();
   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);
   static bool setSortKey(int key);
   static int getSortKey();
   static int compareTwoStudents(Student firstStud, Student secondStud);
  
private:
   static bool validString(string testStr);
   static bool validPoints(int testPoints);
};
const int Student::SORT_BY_FIRST = 76;
const int Student::SORT_BY_LAST = 89;
const int Student::SORT_BY_POINTS = 110;
const int  Student::DEFAULT_POINTS = 0;
const int Student::MIN_POINTS = 0;
const int Student::MAX_POINTS = 1000;
const string Student::DEFAULT_NAME = "zz-error";
int Student::sortKey = Student::SORT_BY_LAST;

class StudentArrayUtilities
{
public:
   static string toString(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[], int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
}; 

int main()
{
   int arraySize;
   Student oddClass[] =
   {
      Student("Johon","Phinncess", 117),Student("Fletcher","Ferb",15),
      Student("Bertice","Candace", 45), Student("Lewis","Berry", 470),
      Student("Thinder","Balorit", 217), Student("Cendric","Lawrence", 345),
      Student("Flynn","Linda", 115), Student("Garcia-Shapiro","Isabella", 285),
      Student("Stay","Hirano", 32), Student("Anderson","Jeremy", 221),
      Student("Terserm","Major", 76), Student("Gatarode","Aliemi", 44),
      Student("Zane-Stomm","Buford", 778)
   };
   Student evenClass[] =
   {
      Student("Johon","Phinncess", 117), Student("Fletcher","Ferb",15),
      Student("Bertice","Candace", 45), Student("Lewis","Berry", 470),
      Student("Thinder","Balorit", 217), Student("Cendric","Lawrence", 345),
      Student("Flynn","Linda", 115), Student("Garcia-Shapiro","Isabella", 285),
      Student("Stay","Hirano", 32), Student("Anderson","Jeremy", 221),
      Student("Terserm","Major", 76), Student("Gatarode","Aliemi", 44),
      Student("Zane-Stomm","Buford", 778), Student("Dooteerminetaz","Vanessa", 431)
   };
   Student smallClass[] =
   {
      Student("Casio","Sarah-Heilen", 458)
   };

   arraySize = sizeof(evenClass) / sizeof(evenClass[0]);
   cout << StudentArrayUtilities::toString("Before: ", evenClass, arraySize)
      << endl;
   StudentArrayUtilities::arraySort(evenClass, arraySize);
   cout << StudentArrayUtilities::toString("After default sort: ", evenClass,
      arraySize) << endl;

   Student::setSortKey(Student::SORT_BY_FIRST);
   StudentArrayUtilities::arraySort(evenClass, arraySize);
   cout << StudentArrayUtilities::toString("After sort by first: ", evenClass,
      arraySize) << endl;

   Student::setSortKey(Student::SORT_BY_POINTS);
   StudentArrayUtilities::arraySort(evenClass, arraySize);
   cout << StudentArrayUtilities::toString("After sort by points: ", evenClass,
      arraySize) << endl;

   Student::setSortKey(Student::SORT_BY_FIRST);
   cout << "Median of evenClass = " <<
      StudentArrayUtilities::getMedianDestructive(evenClass, arraySize) << endl;

   if (Student::getSortKey() != Student::SORT_BY_FIRST)
   {
      cout << "Failed to preserve sort key!" << endl;
   }
   cout << "Successfully preserved sort key!" << endl;

   arraySize = sizeof(oddClass) / sizeof(oddClass[0]);
   cout << "Median of oddClass = " 
      << StudentArrayUtilities::getMedianDestructive(oddClass, arraySize) 
      << endl;

   arraySize = sizeof(smallClass) / sizeof(smallClass[0]);
   cout << "Median of smallClass = "
      << StudentArrayUtilities::getMedianDestructive(smallClass, arraySize)
      << endl;
}

Student::Student(string last, string first, int points)
{
   if (!setLastName(last))
      lastName = DEFAULT_NAME;
   if (!setFirstName(first))
      firstName = DEFAULT_NAME;
   if (!setPoints(points))
      totalPoints = DEFAULT_POINTS;
}
bool Student::setLastName(string last)
{
   if (!validString(last))
      return false;
   lastName = last;
   return true;
}
bool Student::setFirstName(string first)
{
   if (!validString(first))
      return false;
   firstName = first;
   return true;
}
bool Student::setPoints(int pts)
{
   if (!validPoints(pts))
      return false;
   totalPoints = pts;
   return true;
}
bool Student::setSortKey(int key)
{
   if (key == SORT_BY_FIRST || key == SORT_BY_LAST || key == SORT_BY_POINTS)
   {
      sortKey = key;
      return true;
   }
   return false;
}
int Student::compareTwoStudents(Student firstStud, Student secondStud)
{
   int result = 0;
   switch (Student::getSortKey())
   {
   case SORT_BY_FIRST:
      result = firstStud.firstName.compare(secondStud.firstName);
      break;
   case SORT_BY_LAST:
      result = firstStud.lastName.compare(secondStud.lastName);
      break;
   case SORT_BY_POINTS:
      if (firstStud.totalPoints > secondStud.totalPoints)
         result = 1;
      else if (firstStud.totalPoints == secondStud.totalPoints)
         result = 0;
      else if (firstStud.totalPoints < secondStud.totalPoints)
         result = -1;
   }
   return result;
}
string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;
   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;
   resultString = " " + cnvrtLast.str() + ", " + cnvrtFirst.str() + " points: "
      + cnvrtPoints.str() + "\n";
   return resultString;
}
bool Student::validString(string testStr)
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}
bool Student::validPoints(int testPoints)
{
   if (testPoints >= MIN_POINTS && testPoints <= MAX_POINTS)
      return true;
   return false;
}

string StudentArrayUtilities::toString(string title, Student data[], 
   int arraySize)
{
   string output = title + "\n";
   for (int k = 0; k < arraySize; k++)
      output += " " + data[k].toString();
   return output;
}
void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      if (!floatLargestToTop(array, arraySize - 1 - k))
         return;
}
double StudentArrayUtilities::getMedianDestructive(Student array[], int arraySize)
{
   int clientSort, halfArraySize;
   double median;
   halfArraySize = (arraySize - 1) / 2;
   clientSort = Student::getSortKey();
   Student::setSortKey(Student::SORT_BY_POINTS);
   StudentArrayUtilities::arraySort(array, arraySize);

   if (arraySize == 1)
      median = array[0].getTotalPoints();

   else if (arraySize % 2 == 0)
      median = (array[halfArraySize].getTotalPoints() +
         array[halfArraySize + 1].getTotalPoints()) / 2;

   else
      median = array[halfArraySize].getTotalPoints();
 
   Student::setSortKey(clientSort);
   return median;
}

bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;

   for (int k = 0; k < top; k++)
      if (Student::compareTwoStudents(data[k], data[k + 1]) > 0)
      {
         mySwap(data[k], data[k + 1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student& a, Student& b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}
string Student::getLastName() 
{
   return lastName; 
}
string Student::getFirstName()
{
   return firstName;
}
int  Student::getTotalPoints() 
{ 
   return totalPoints;
}
int Student::getSortKey() 
{ 
   return sortKey; 
}
/*------------------------------Paste of Run #1-----------------------------------
Before:
  Johon, Phinncess points: 117
  Fletcher, Ferb points: 15
  Bertice, Candace points: 45
  Lewis, Berry points: 470
  Thinder, Balorit points: 217
  Cendric, Lawrence points: 345
  Flynn, Linda points: 115
  Garcia-Shapiro, Isabella points: 285
  Stay, Hirano points: 32
  Anderson, Jeremy points: 221
  Terserm, Major points: 76
  Gatarode, Aliemi points: 44
  Zane-Stomm, Buford points: 778
  Dooteerminetaz, Vanessa points: 431

After default sort:
  Anderson, Jeremy points: 221
  Bertice, Candace points: 45
  Cendric, Lawrence points: 345
  Dooteerminetaz, Vanessa points: 431
  Fletcher, Ferb points: 15
  Flynn, Linda points: 115
  Garcia-Shapiro, Isabella points: 285
  Gatarode, Aliemi points: 44
  Johon, Phinncess points: 117
  Lewis, Berry points: 470
  Stay, Hirano points: 32
  Terserm, Major points: 76
  Thinder, Balorit points: 217
  Zane-Stomm, Buford points: 778

After sort by first:
  Gatarode, Aliemi points: 44
  Thinder, Balorit points: 217
  Lewis, Berry points: 470
  Zane-Stomm, Buford points: 778
  Bertice, Candace points: 45
  Fletcher, Ferb points: 15
  Stay, Hirano points: 32
  Garcia-Shapiro, Isabella points: 285
  Anderson, Jeremy points: 221
  Cendric, Lawrence points: 345
  Flynn, Linda points: 115
  Terserm, Major points: 76
  Johon, Phinncess points: 117
  Dooteerminetaz, Vanessa points: 431

After sort by points:
  Fletcher, Ferb points: 15
  Stay, Hirano points: 32
  Gatarode, Aliemi points: 44
  Bertice, Candace points: 45
  Terserm, Major points: 76
  Flynn, Linda points: 115
  Johon, Phinncess points: 117
  Thinder, Balorit points: 217
  Anderson, Jeremy points: 221
  Garcia-Shapiro, Isabella points: 285
  Cendric, Lawrence points: 345
  Dooteerminetaz, Vanessa points: 431
  Lewis, Berry points: 470
  Zane-Stomm, Buford points: 778

Median of evenClass = 167
Successfully preserved sort key!
Median of oddClass = 117
Median of smallClass = 458

Press any key to close this window . . .

-------------------------------------------------------------------------------*/