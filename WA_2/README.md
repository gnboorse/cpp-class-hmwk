**Written Assignment 2**

Written Assignment 2 includes two programming exercises. Both are required to gain credit for Written Assignment 2.

**Exercise 1 for Written Assignment 2**

Create three arrays of 20 integers each. Fill in two arrays with data, leaving the third blank. From *main*, pass these three arrays into a function. Inside the function, add the value of each array element and store it in the third.

*third_array[i] = second_array[i] + first_array[i]*

Back in main, print out the value of every element in the third/sum array. Excellent output on this assignment might show something like:

| *Array 1* | *+*  | *Array 2* | *=*  | *Array 3* |
| --------- | ---- | --------- | ---- | --------- |
| *5*       | *+*  | *3*       | *=*  | *8*       |
| *10*      | *+*  | *4*       | *=*  | *14*      |

 

**Exercise 2 for Written Assignment 2**

Design and run a program that takes a numerical score and outputs a letter grade. Specific numerical scores and letter grades are listed below:

In this program, create two void functions titled *getScore* and *printGrade* with an *int* argument. The function *getScore*should have a Reference parameter and *printGrade* should have a Value parameter.

| 90-100 | =    | Grade A |
| ------ | ---- | ------- |
| 80-89  | =    | Grade B |
| 70-79  | =    | Grade C |
| 60-69  | =    | Grade D |
| 0-59   | =    | Grade F |

 The function *getScore* will prompt the user for the numerical score, get the input from the user, and print the numerical score.The function *printGrade* will calculate the course grade and print the course grade. (Be careful and note that the assignment requires you to input the grade into *getScore* and not directly into the *main* function.)