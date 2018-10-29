/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C++ Programming
/   PROGRAM NAME: lab1A.cpp
/   PROGRAM DESCRIPTION: Performance lab 1 - Fi Phi Fo Fum
/   INSTRUCTIONS:
        A number is considered to be relatively prime to another if the greatest common denominator of both is 1.
        Euler's Totient Function – phi(n) – tallies up all the numbers that are relatively prime to a number n
        I have provided a program that implements Euler’s Totient Function to find a count of all numbers {1, 2, 3, …, n} that are relatively prime to a number n.
        Two functions (other than main()) to solve this problem have been provided but need to be completed.
        int phi(unsigned int n) – this function should iterate through the number set to tally all numbers relative prime to n.
        int gcd(const int, const int b) – this function should return the greatest common denominator of two numbers.
        Try using some of the new C++ features we covered. Experiment with auto, decltype, const, and references.
            
        CPP: Lab 1
        - This is a very casual lab designed to introduce you to C++. Mess around with some of it's features we kind of
        hinted at. 
        - Ensure to set this up as a C++ project in Visual Studio or compile using G++ if using another editor or Linux
        Instructions:
        - A number is considered to be relatively prime to another if the greatest common denominator of both is 1.
        - Euler's Totient Function – phi(n) – tallies up all the numbers that are relatively prime to a number n
        - I have provided a program that implements Euler’s Totient Function to find a count of all numbers {1, 2, 3, …, n} that are relatively prime to a number n.
        - Two functions to solve this problem have been provided but need to be completed, as well as a main().
        -- int phi(unsigned int n) – this function should iterate through the number set to tally all numbers relative prime to n.
        -- int gcd(const int, const int b) – this function should return the greatest common denominator of two numbers.
        - Try using some of the new C++ features we covered. Experiment with auto, decltype, const, and references.



**********************************************************************************************************************/

#include <iostream>

int gcd(const int a, const int b);
int phi(unsigned int n);

int main()
{
    auto n = 0;
    for (n = 1; n <= 10; n++)
        printf("phi(%d) = %d\n", n, phi(n));

    return 0;
}

//Function: gcd()
//Arguments: const int a, const int b - two int arguments to determine the gcd of 
//Return value: the greatest common denominator of two numbers 
int gcd(const int a, const int b)
{
    auto r =0;
    auto tempA = a;
    auto tempB = b;
    //error checking
    if(b>a)
    {
        printf("Error b>a\n");
        return 0;
    }
    //more error checking
    else if(a == 0 || b ==0)
    {
        printf("Error either a or b is 0\n");
        return 0;
    }
    else{
       //uses euclidian algorithm to find the GCD - ([A = B*q +r] if r is 0 then b is the GCD)
       //do this loop until there is no remainder and then return the remainder of the previous calculation
        while(tempA%tempB != 0)
        {
            r = tempA % tempB;
            tempA=tempB;
            tempB=r;

        }

    return r;
    }
    
}

//Function: phi()
//Arguments: unsigned int n - a number that we want to find all numbers relative prime to 
//Return: the count of all numbers relative prime to n 
int phi(unsigned int n)
{
    //start at 1 because everything is prime to 1
    auto count = 1;
    //loop through every number up to n and find the GCD to it. 
    for(int i = 1; i< n; i++)
    {
        //If the GCD is 1 then the number is prime to n so increase the count
        if(gcd(n,i) == 1)
        {
            count++;
        }

    }

    return count;
}