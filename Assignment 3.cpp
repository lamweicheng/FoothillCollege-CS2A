#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   const string FIRSTFOOD_NAME = "Pepperoni";
   const int FIRSTFOOD_CALORIES_P100G = 494;
   const double FIRSTFOOD_CABOHYDRATE_P100G = .0;
   const double FIRSTFOOD_TOTALFAT_P100G = 44.;
   const double FIRSTFOOD_PROTEIN_P100G = 22.7;
   const double FIRSTFOOD_VITAMIN_C_P100G = 0.0007;
   const double FIRSTFOOD_CALCIUM_P100G = 0.022;

   const string SECONDFOOD_NAME = "Bacon";
   const int SECONDFOOD_CALORIES_P100G = 458;
   const double SECONDFOOD_CABOHYDRATE_P100G = .7;
   const double SECONDFOOD_TOTALFAT_P100G = 45.;
   const double SECONDFOOD_PROTEIN_P100G = 11.6;
   const double SECONDFOOD_VITAMIN_C_P100G = 0.;
   const double SECONDFOOD_CALCIUM_P100G = 0.006;

   const string THIRDFOOD_NAME = "Mushrooms";
   const int THIRDFOOD_CALORIES_P100G = 22;
   const double THIRDFOOD_CABOHYDRATE_P100G = 3.3;
   const double THIRDFOOD_TOTALFAT_P100G = .3;
   const double THIRDFOOD_PROTEIN_P100G = 3.1;
   const double THIRDFOOD_VITAMIN_C_P100G = 0.0021;
   const double THIRDFOOD_CALCIUM_P100G = 0.003;

   const string FOURTHFOOD_NAME = "Onions";
   const int FOURTHFOOD__CALORIES_P100G = 40;
   const double FOURTHFOOD_CABOHYDRATE_P100G = 9.3;
   const double FOURTHFOOD_TOTALFAT_P100G = .1;
   const double FOURTHFOOD_PROTEIN_P100G = 1.1;
   const double FOURTHFOOD_VITAMIN_C_P100G = 0.0074;
   const double FOURTHFOOD_CALCIUM_P100G = 0.023;

   const string FIFTHFOOD_NAME = "Spinach";
   const int FIFTHFOOD_CALORIES_P100G = 14;
   const double FIFTHFOOD_CABOHYDRATE_P100G = 2.5;
   const double FIFTHFOOD_TOTALFAT_P100G = .2;
   const double FIFTHFOOD_PROTEIN_P100G = 1.5;
   const double FIFTHFOOD_VITAMIN_C_P100G = 0.033;
   const double FIFTHFOOD_CALCIUM_P100G = 0.058;

   const string INDENT = "   ";
   const int MIN_RECIPESERVING = 0;
   const int MAX_RECIPESERVING = 15;
   const int MIN_GRAMS = 0;
   const int MAX_GRAMS = 1500;


   string recipe_Name, userInputStr, recipeServings_String;
   int userInputInt, recipeServings_Int;
   double totalCals, totalCabohydrate, totalFat, totalProtein,
          totalVitaminC, totalCalcium;

   totalCals = 0.;
   totalCabohydrate = 0.;
   totalFat = 0.;
   totalProtein = 0.;
   totalVitaminC = 0.;
   totalCalcium = 0.;

   cout << " ------------------ List Of Ingredients ------------------ "
        << endl;
   cout << INDENT << "Food #1: " << FIRSTFOOD_NAME << endl;
   cout << INDENT << "Food #2: " << SECONDFOOD_NAME << endl;
   cout << INDENT << "Food #3: " << THIRDFOOD_NAME << endl;
   cout << INDENT << "Food #4: " << FOURTHFOOD_NAME << endl;
   cout << INDENT << "Food #5: " << FIFTHFOOD_NAME << endl << endl;

   cout << "What do you want to name this recipe as? : ";
   getline(cin, recipe_Name);

   cout << endl;
   cout << "How many servings that this recipe can serve? : ";
   getline(cin, recipeServings_String);
   istringstream(recipeServings_String) >> recipeServings_Int;
   {
      if ((recipeServings_Int < MIN_RECIPESERVING) || 
         (recipeServings_Int > MAX_RECIPESERVING))
      {
         cout << "-------------ERROR! ERROR! ERROR!-----------" << endl;
         cout << "You have entered inappropriate value, Please Try Again! \n";
         cout << "Please enter again servings between 1 to 15. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }
   cout << endl << endl;

   cout << "How many grams of " << FIRSTFOOD_NAME << " ? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   {
      if ((userInputInt < MIN_GRAMS ) || (userInputInt > MAX_GRAMS))
      {
         cout << "-----------------ERROR! ERROR! ERROR!---------------------"
              << endl;
         cout << "You have entered inappropriate value, Please Try Again. \n";
         cout << "Please enter amount for ingredients between 0g to 1500g. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }
   totalCals += userInputInt * (FIRSTFOOD_CALORIES_P100G / 100.);
   totalCabohydrate += userInputInt * (FIRSTFOOD_CABOHYDRATE_P100G / 100.);
   totalFat += userInputInt * (FIRSTFOOD_TOTALFAT_P100G / 100.);
   totalProtein += userInputInt * (FIRSTFOOD_PROTEIN_P100G / 100.);
   totalVitaminC += userInputInt * (FIRSTFOOD_VITAMIN_C_P100G / 100.);
   totalCalcium += userInputInt * (FIRSTFOOD_CALCIUM_P100G / 100.);

   cout << "How many grams of " << SECONDFOOD_NAME << " ? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   {
      if ((userInputInt < MIN_GRAMS) || (userInputInt > MAX_GRAMS))
      {
         cout << "-----------------ERROR! ERROR! ERROR!---------------------"
              << endl;
         cout << "You have entered inappropriate value, Please Try Again. \n";
         cout << "Please enter amount for ingredients between 0g to 1500g. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }
   totalCals += userInputInt * (SECONDFOOD_CALORIES_P100G / 100.);
   totalCabohydrate += userInputInt * (SECONDFOOD_CABOHYDRATE_P100G / 100.);
   totalFat += userInputInt * (SECONDFOOD_TOTALFAT_P100G / 100.);
   totalProtein += userInputInt * (SECONDFOOD_PROTEIN_P100G / 100.);
   totalVitaminC += userInputInt * (SECONDFOOD_VITAMIN_C_P100G / 100.);
   totalCalcium += userInputInt * (SECONDFOOD_CALCIUM_P100G / 100.);

   cout << "How many grams of " << THIRDFOOD_NAME << " ? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   {
      if ((userInputInt < MIN_GRAMS) || (userInputInt > MAX_GRAMS))
      {
         cout << "-----------------ERROR! ERROR! ERROR!---------------------"
              << endl;
         cout << "You have entered inappropriate value, Please Try Again. \n";
         cout << "Please enter amount for ingredients between 0g to 1500g. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }
   totalCals += userInputInt * (THIRDFOOD_CALORIES_P100G / 100.);
   totalCabohydrate += userInputInt * (THIRDFOOD_CABOHYDRATE_P100G / 100.);
   totalFat += userInputInt * (THIRDFOOD_TOTALFAT_P100G / 100.);
   totalProtein += userInputInt * (THIRDFOOD_PROTEIN_P100G / 100.);
   totalVitaminC += userInputInt * (THIRDFOOD_VITAMIN_C_P100G / 100.);
   totalCalcium += userInputInt * (THIRDFOOD_CALCIUM_P100G / 100.);

   cout << "How many grams of " << FOURTHFOOD_NAME << " ? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   {
      if ((userInputInt < MIN_GRAMS) || (userInputInt > MAX_GRAMS))
      {
         cout << "-----------------ERROR! ERROR! ERROR!---------------------"
              << endl;
         cout << "You have entered inappropriate value, Please Try Again. \n";
         cout << "Please enter amount for ingredients between 0g to 1500g. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }
   totalCals += userInputInt * (FOURTHFOOD__CALORIES_P100G / 100.);
   totalCabohydrate += userInputInt * (FOURTHFOOD_CABOHYDRATE_P100G / 100.);
   totalFat += userInputInt * (FOURTHFOOD_TOTALFAT_P100G / 100.);
   totalProtein += userInputInt * (FOURTHFOOD_PROTEIN_P100G / 100.);
   totalVitaminC += userInputInt * (FOURTHFOOD_VITAMIN_C_P100G / 100.);
   totalCalcium += userInputInt * (FOURTHFOOD_CALCIUM_P100G / 100.);

   cout << "How many grams of " << FIFTHFOOD_NAME << " ? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;
   {
      if ((userInputInt < MIN_GRAMS) || (userInputInt > MAX_GRAMS))
      {
         cout << "-----------------ERROR! ERROR! ERROR!---------------------"
              << endl;
         cout << "You have entered inappropriate value, Please Try Again. \n";
         cout << "Please enter amount for ingredients between 0g to 1500g. \n";
         cout << "Thank you. " << endl;

         return 1;
      }
   }

   totalCals += userInputInt * (FIFTHFOOD_CALORIES_P100G / 100.);
   totalCabohydrate += userInputInt * (FIFTHFOOD_CABOHYDRATE_P100G / 100.);
   totalFat += userInputInt * (FIFTHFOOD_TOTALFAT_P100G / 100.);
   totalProtein += userInputInt * (FIFTHFOOD_PROTEIN_P100G / 100.);
   totalVitaminC += userInputInt * (FIFTHFOOD_VITAMIN_C_P100G / 100.);
   totalCalcium += userInputInt * (FIFTHFOOD_CALCIUM_P100G / 100.);

   cout << endl << endl;
   cout << "Nutrition for " << recipe_Name << " for " << recipeServings_Int
        << " servings in grams ----" << endl;
   cout << INDENT << "Calories    : " << totalCals << endl;
   cout << INDENT << "Cabohydrate : " << totalCabohydrate << endl;
   cout << INDENT << "Total Fat   : " << totalFat << endl;
   cout << INDENT << "Protein     : " << totalProtein << endl;
   cout << INDENT << "Vitamin C   : " << totalVitaminC << endl;
   cout << INDENT << "Calcium     : " << totalCalcium << endl << endl << endl;

   cout << "Nutrition for " << recipe_Name << " per serving in grams -----"
        << endl;

   totalCals        /= recipeServings_Int;
   totalCabohydrate /= recipeServings_Int;
   totalFat         /= recipeServings_Int;
   totalProtein     /= recipeServings_Int;
   totalVitaminC    /= recipeServings_Int;
   totalCalcium     /= recipeServings_Int;

   cout << INDENT << "Calories    : " << totalCals        << endl;
   cout << INDENT << "Cabohydrate : " << totalCabohydrate << endl;
   cout << INDENT << "Total Fat   : " << totalFat         << endl;
   cout << INDENT << "Protein     : " << totalProtein     << endl;
   cout << INDENT << "Vitamin C   : " << totalVitaminC    << endl;
   cout << INDENT << "Calcium     : " << totalCalcium     << endl;

   return 0;

}


/*----------------------------- Paste of the #1 Run----------------------------

  ------------------ List Of Ingredients ------------------
   Food #1: Pepperoni
   Food #2: Bacon
   Food #3: Mushrooms
   Food #4: Onions
   Food #5: Spinach

What do you want to name this recipe as? : Wei Cheng's Spinach Pizza

How many servings that this recipe can serve? : 5


How many grams of Pepperoni ? 300
How many grams of Bacon ? 150
How many grams of Mushrooms ? 500
How many grams of Onions ? 400
How many grams of Spinach ? 1400


Nutrition for Wei Cheng's Spinach Pizza for 5 servings in grams ----
   Calories    : 2635
   Cabohydrate : 89.75
   Total Fat   : 204.2
   Protein     : 126.4
   Vitamin C   : 0.5042
   Calcium     : 0.994


Nutrition for Wei Cheng's Spinach Pizza per serving in grams -----
   Calories    : 527
   Cabohydrate : 17.95
   Total Fat   : 40.84
   Protein     : 25.28
   Vitamin C   : 0.10084
   Calcium     : 0.1988

Press any key to close this window . . .

------------------------------------------------------------------------------*/



/*----------------------------- Paste of the #2 Run----------------------------

 ------------------ List Of Ingredients ------------------
   Food #1: Pepperoni
   Food #2: Bacon
   Food #3: Mushrooms
   Food #4: Onions
   Food #5: Spinach

What do you want to name this recipe as? : Wei Cheng's Mushroom Soup

How many servings that this recipe can serve? : 8


How many grams of Pepperoni ? 0
How many grams of Bacon ? 500
How many grams of Mushrooms ? 1500
How many grams of Onions ? 450
How many grams of Spinach ? 0


Nutrition for Wei Cheng's Mushroom Soup for 8 servings in grams ----
   Calories    : 2800
   Cabohydrate : 94.85
   Total Fat   : 229.95
   Protein     : 109.45
   Vitamin C   : 0.0648
   Calcium     : 0.1785


Nutrition for Wei Cheng's Mushroom Soup per serving in grams -----
   Calories    : 350
   Cabohydrate : 11.8563
   Total Fat   : 28.7437
   Protein     : 13.6813
   Vitamin C   : 0.0081
   Calcium     : 0.0223125

Press any key to close this window . . .

------------------------------------------------------------------------------*/



/*----------------------------- Paste of the #3 Run----------------------------

 ------------------ List Of Ingredients ------------------
   Food #1: Pepperoni
   Food #2: Bacon
   Food #3: Mushrooms
   Food #4: Onions
   Food #5: Spinach

What do you want to name this recipe as? : Lam's Pepperoni Fried Rice

How many servings that this recipe can serve? : 5


How many grams of Pepperoni ? 500
How many grams of Bacon ? 0
How many grams of Mushrooms ? 300
How many grams of Onions ? 200
How many grams of Spinach ? 300


Nutrition for Lam's Pepperoni Fried Rice for 5 servings in grams ----
   Calories    : 2658
   Cabohydrate : 36
   Total Fat   : 221.7
   Protein     : 129.5
   Vitamin C   : 0.1236
   Calcium     : 0.339


Nutrition for Lam's Pepperoni Fried Rice per serving in grams -----
   Calories    : 531.6
   Cabohydrate : 7.2
   Total Fat   : 44.34
   Protein     : 25.9
   Vitamin C   : 0.02472
   Calcium     : 0.0678

Press any key to close this window . . .

------------------------------------------------------------------------------*/



/*---------------- Paste of the #4 Run (Servings Input Error)--------------------

 ------------------ List Of Ingredients ------------------
   Food #1: Pepperoni
   Food #2: Bacon
   Food #3: Mushrooms
   Food #4: Onions
   Food #5: Spinach

What do you want to name this recipe as? : Lam's Fried Noodles

How many servings that this recipe can serve? : 20
-------------ERROR! ERROR! ERROR!-----------
You have entered inappropriate value, Please Try Again!
Please enter again servings between 1 to 15.
Thank you.

Press any key to close this window . . .

------------------------------------------------------------------------------*/




/*------------------ Paste of the #5 Run (Amount Input Error)--------------------

 ------------------ List Of Ingredients ------------------
   Food #1: Pepperoni
   Food #2: Bacon
   Food #3: Mushrooms
   Food #4: Onions
   Food #5: Spinach

What do you want to name this recipe as? : Anderson's Pie Recipe

How many servings that this recipe can serve? : 5


How many grams of Pepperoni ? 350
How many grams of Bacon ? 500
How many grams of Mushrooms ? 2500
-----------------ERROR! ERROR! ERROR!---------------------
You have entered inappropriate value, Please Try Again.
Please enter amount for ingredients between 0g to 1500g.
Thank you.

Press any key to close this window . . .

------------------------------------------------------------------------------*/