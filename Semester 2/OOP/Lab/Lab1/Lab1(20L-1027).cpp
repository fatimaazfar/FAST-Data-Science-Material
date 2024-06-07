#include<iostream>
int myFunction ()
{
int numbers[5];
int * p;
p = numbers;
*p = 10;
p++;
*p = 20;
numbers[2];
*p = 30;
p = numbers + 3;
*p = 40;
p = numbers;
*(p+4) = 50;
return 0;
}
main()
{
myFunction();
}
