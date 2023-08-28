// lab 1 
#include <stdio.h>
#include <math.h>

int main() 
{
// problem set 1.1 - write a program to display the ASCII value of a 
// given character
  
// the char variable needed is declared 
  char c;

// the user is prompted to enter a char value
  printf("Please enter a character value: ");
  
// the char value is read in from stdin and printed in its ASCII 
// format
  scanf("%c",&c);
  printf("The ASCII value of given character of %c is %d.\n",c,c);
  printf("\n");

  
// problem set 1.2 - write a program to accept fahrenheit temperature 
// and convert it to degrees celsius

// the int variables needed are declared 
  int temp, cels;

// the user is prompted to enter an int value for the fahrenheit 
  printf("Please enter a temperature value: ");

// the int value is read in from the stdin
    scanf("%d",&temp);
  
// the the celsius value is computed with the user value and assigned 
// to the variable cels
  cels = (temp - 32) * 5/9;

// the user fahrenheit value and the computed celsius value are 
// both printed 
  printf("This Fahrenheit temperature: %d, is %d degrees in Celsius.\n",temp,cels);
  printf("\n");


// problem set 1.3 - write a program to read the radius of a circle 
// and compute its area and circumference

// the float variables are declared and defined 
  float radius, pi, area, circ;
  pi = 3.1416;

// the user is prompted to enter a float value for the radius 
  printf("Please enter a radius value: ");

// the float value is read in from the stdin 
  scanf("%f",&radius);

// the area and circumference are computed with the fixed pi variable and are 
// assinged to the variables area and circ 
  area = pow(radius,2);
  area = pi * area;
  circ = 2 * pi * radius;

// the user radius value, and the computed area and circumference are all printed 
  printf("With the given radius: %.2f, the circle's area is %.2f and the circumference is %.2f.\n", radius, area, circ);
  printf("\n");


// problem set 2.1 - write a program to read a positive integer n and check whether 
// it is odd or even, use the switch statement

// the int variables are declared
  int num, check; 

// the user is prompted to enter an int value for the integer (num)
  printf("Please enter a positive integer: ");

// the int value is read in from the stdin 
  scanf("%d",&num);

// num % 2 is assigned to the variable check: if num % 2 = 0 the number is even, 
// if num % 2 = 1 the number is odd, and if neither value is returned the user 
// input is labeled as invalid 
  check = num % 2;

// a switch statement based on the check variable is created and based on the result, 
// a certain message was printed before the program ends
  switch (check)
  {
    case 0:
      printf("This number: %d, is even.\n", num);
      break;
    case 1:
      printf("This number: %d, is odd.\n", num);
      break;
    default:
      printf("This number: %d, is invalid.\n", num);
      break;
  }
  printf("\n");

  
// problem set 2.2 - write a program to find the taxable amount of an employee:
//   a. no tax up to $100,000 per annual income
//   b. 15% tax for $100,000 to $175,000 per annual income
//   c. 25% tax for greater than $175,000 per annual income

// the float variable is declared 
  float income; 
  
// the user is prompted to enter a float value for the income 
  printf("Enter an income amount: ");

// the float value is read in from the stdin 
  scanf("%f", &income);

// if the income variable is less than/equal to 100,000, a message is printed 
// stating that the income wasn't taxable 
  if(income <= 100000)
    printf("This amount is not taxable.");
    
// if the income variable is between 100,001 and 175,000, the income is taxed 
// by 15% and the taxable amount is printed with a display message 
  else if((income > 100000) && (income <= 175000))
    printf("This amount will be taxed by 15%%, by the amount: $%.2f.", income * .15);
    
// if the income variable is greater than 175,000 the income is taxed by 25% and 
// the taxable amount is printed with a display message 
  else if(income > 175000)
    printf("This amount will be taxed by 25%%, by the  amount: $%.2f.", income * .25);

  return 0;
}
