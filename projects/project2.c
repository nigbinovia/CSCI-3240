// project2.c -- Naomi Igbinovia
// this program is the C conversion of all the 
// given mystery functions originally written in
// assembly code
#include <stdio.h>

long MysteryFunction1(long, int);
unsigned int MysteryFunction2(unsigned int);
long MysteryFunction3(long*, int);
int MysteryFunction4(unsigned long);
unsigned int MysteryFunction5(unsigned int, unsigned int);

int main()
{
    int answer1;
    unsigned int answer2, answer5;
    long answer3;
    unsigned long answer4;

    answer1 = MysteryFunction1(3, 9);
    printf("Mystery Function 1 returns: %d\n", answer1);

    answer2 = MysteryFunction2(35);
    printf("Mystery Function 2 returns: %u\n", answer2);

    long b[] = {122, 41, 19, 32};
    int c = sizeof(b) / sizeof(b[0]);
    answer3 = MysteryFunction3(b, c);
    printf("Mystery Function 3 returns: %ld\n", answer3);

    answer4 = MysteryFunction4(15);
    printf("Mystery Function 4 returns: %lu\n", answer4);

    answer5 = MysteryFunction5(2, 20);
    printf("Mystery Function 5 returns: %u\n", answer5);

    return 0;
}


long MysteryFunction1(long b, int c)
{
// the function variables are initalized
  unsigned long a,d;
  
// the rax value is set to 1
  a = 1;

// the difference of the rsi value and the rax value is 
// stored in rdx
  d = c - 1;

// while the desired exponent hasn't been reached 
    while (c > 0)
    {
// the base (b) is built onto until the desired has been 
// obtained 
        a = a * b;
        c = d;
        d = c - 1;
    }
  
// once the count value is equal to 0, the result is returned
// to the main function
    return a;
}


unsigned int MysteryFunction2(unsigned int b)
{
// the rdx and rcx valyes are set to 0
    unsigned int a = 0;
    unsigned int d = 0;
    unsigned int e = 0;
    

// while e (the count) is within the 32-bit range
    while (e <= 31)
    {
// if e exceeds this range, the program stops
        if (e > 31)
            break;
      
// the rax value is assigned to 1
        a = 1;

// the rax value is multipled by the count 
        a = a << e;

// if both the values of rax and rdi are equal to 0
        if ((a & b) == 0)
        {
// increase the count by 1 and continue the program
            e++;
            continue;
        }
// the smallest signed number is stored in the rax value, 
// shifted to the right by the count, and it's checked to 
// assign this new shifted number to d
        a = 1 << 31;
        a = a >> e;
        d = d | a;

// the count is incremented again 
        e++;
    }
// the final bit manipulation is returned 
    a = d;
    return a;
}


long MysteryFunction3(long* b, int c)
{
// the array and size variable are declared and 
// initalized; e = the first value in the array
    long e = b[0];
    int a = 1;

//while the size of the array hasn't been reached
    while (a < c)
    {
//d is set to the next value in the array
        long d = b[a];

//if the next value is greater than the current 
// value, the "greatest" value for the array is 
// adjusted for
        if (d > e)
        {
            e = d;
        }
//the array is moved through by one increment
        a++;
    }
//the greatest value of the array is returned 
    return e;
}


int MysteryFunction4(unsigned long b)
{
// the function variables are initalized
  unsigned long a, d;

// the loop counter is set to 0
  a = 0;

// while the given value (b) isn't equal to 0
  while (b != 0)
  {
// b is reassigned to d, the AND operation is used 
// between d and 1 to check if d is odd or not, if so
// a is increased by 1, and the b value is divided by 
// 2
    d = b;
    d = d & 1;
    a = a + d;
    b = b >> 1;
           
    }
// once b is equal to 0, the loop counter is returned 
  return a;
}

unsigned int MysteryFunction5(unsigned int b, unsigned int c)
{
// the function variables are initalized
  unsigned long a, d;

// the result of the XOR operation between the b and c
// values are stored in rdi
  b = (b ^ c);
  
// the loop counter is set to 0
  a = 0;

// while b is not equal to 0
  while (b != 0)
    {
// the AND operation is used between d and 1 to check 
// if d is odd or not, if so a is increased by 1, and 
// the b value is divided by 2
      d = b & 1;
      a = a + d;
      b = b  >> 1;
    }
    
// once b is equal to 0, the loop counter is returned 
  return a;
} 
