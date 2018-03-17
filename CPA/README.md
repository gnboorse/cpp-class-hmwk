### Comprehensive Programming Assignment Problem 1

 You have 10 lowercase letters that you would like toarrange in alphabetical order. Create a program to determine the first letterin alphabetical order out of the 10 letters entered. (Please have your programenter the 10 letters one at a time.) This should be done in a function usingthis prototype:

 

*char firstletter(char x, char y);*

 

Make sure you use a *for*loop expression inside your function. (Hint: you can order letters using ASCIIcode, for example, a < c.)              

 

 

### Comprehensive Programming Assignment Problem 2

You are running a camp and must decide what activities toschedule. You decide to base the decision on the temperature measured indegrees Fahrenheit. If the temperature is above 85°, you schedule swimming. Ifthe temperature is above 70° and less than or equal to 85°, you schedulebaseball. If the temperature is above 32° and less than or equal to 70°, youschedule basketball. Finally, if the temperature is below 32°, you sendeveryone home.

 

Create a program that takes the temperatures as input andprovides as output your sports decision. (Assume that temperatures are onlyexpressed as integers.) In the program include 2 void functions titled *getTemp* and *printActivity,* each with an*int* argument.

 

●     The function *getTemp*should have a Reference parameter that gets the temperature in *getTemp* and then passes the value backto be printed in *main( )*, and

●     *printActivity*should have a Value parameter.

 

The function *getTemp*should prompt the user for the temperature in Fahrenheit, get the input fromthe user, and return to *main( )* whereit prints the temperature on the screen. The function *printActivity* should determine the activity and print it as outputon the screen. (Be careful and note that this problem requires you to input thetemperature into *getTemp* and notdirectly into the *main*function.)      

 

 

### Comprehensive Programming Assignment Problem 3 

Define a *class* calledRevenue that has 2 *private* members ofdemand and price. Include a constructor and a *public* function that calculates the RevenueValue of the class.

 

RevenueValue = demand * price

 

Use *public*functions of the class in a program that computes RevenueValue and displaysRevenueValue when demand is 2000 and price is 2.