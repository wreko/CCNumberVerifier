#include <stdio.h>

#include <iostream>

#include <math.h>



int main(void) {
    long long input = 0; //Declaring input file
    std::cout << "Enter the credit card number: " << std::endl;
    std::cin >> input;
    long long temp = input; //Creating temp variable which we'll be using in loops
    long int length = 0; //Creating length variable 
    while (temp > 0)
    {
        temp /= 10;
        length++;
    } //This while loops determines length of user inputed credit card number
    if (length != 15 && length != 16 && length != 13)
    { //This conditional statement breaks the program if the user has inputed unknown variable
        printf("INVALID\n");
        return 0;
    }
    long int hlen = length / 2; //Declaring value which is half of the length to later use in doing stuff with every second number.
    long long sum = 0;
    long int j = 1;
    long int temp1 = 0;
    long int temp2 = 0;
    long int templ = 0;
    if (length == 16 || length == 13)
    { //Program needs different hlen variable for even numbers
        hlen = hlen + 1;
    }

    for (int i = 1; i <= hlen; i++)
    {
        //Finding out whether or not double the digit (Every other digit taken from the end) has 2 digits and taking these and adding to sum
        temp1 = (2 * (((input % (long long)(pow(100, i))) / (long long)(pow(10, j)))));
        temp2 = temp1;
        do //Finding out the amount of digits from the variable above
        {
            temp2 /= 10;
            templ++;
        } while (temp2 > 0);
        if (templ > 1)
        { //If the amount is two, it will break the number down into 2 digits and combine them
            sum += temp1 % 10;
            sum += (temp1 % 100) / 10;
        }
        else
        { //if the number is a single digit, it just adds them up
            sum += temp1;
        }

        templ = 0;
        j += 2;

    } //LOG10000 = 5 LOG 1000 = 3 LOG10 = 1 Logic for J variable.

    int g = 0; //Same function as J variable did in the last one.

    if (length == 16 || length == 13)
    {
        for (int i = 1; i <= hlen * 2; i += 2)
        {
            sum += (((input % (long long)(pow(10, i))) / (long long)(pow(10, g))));
            g += 2;
        }
    }
    else
    {
        for (int i = 1; i <= (hlen + 1) * 2; i += 2)
        {
            sum += (((input % (long long)(pow(10, i))) / (long long)(pow(10, g))));
            g += 2;
        }
    }
    int lastn = sum % 10;
    long long firstn = 0;
    long long first2n = 0;
    first2n = input;
    firstn = input;
    //first2n = (input % (long long)(pow(10, hlen * 2) / (long long)(pow(10, (hlen * 2) - 2)));
    while (first2n >= 100) //determining the first number
    {
        first2n = first2n / 10;
    }
    while (firstn >= 10) {
        firstn = firstn / 10; //determining the first two numbers
    }

    if (lastn == 0)
    {
        if (lastn == 0 && (first2n == 51 || first2n == 52 || first2n == 53 || first2n == 54 || first2n == 55))
        { //If last numebr of the final sum is zero and it satisfies the mastercard starting digits
            std::cout << "MASTERCARD\n" << std::endl;;
            return 0;
        }

        if (lastn == 0 && (first2n == 34 || first2n == 37))
        {
            std::cout << "AMEX\n" << std::endl;;
            return 0;
        }

        if (lastn == 0 && (firstn == 4))
        {
            std::cout << "VISA\n" << std::endl;;
            return 0;
        }
        if (lastn == 0)
        {
            std::cout << "INVALID\n" << std::endl;;
        }
    }
    else
    {
        std::cout << "INVALID\n" << std::endl;;
    }

}
