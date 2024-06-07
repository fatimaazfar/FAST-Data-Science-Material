#include <string.h>
#include<iostream>
using namespace std;
int main()
{
	char string[50],delim[] = ",";
	cout<<"Enter string : ";
	cin.getline(string,50);
	char *a = strtok(string, delim);
	while(a != NULL)
	{
		printf("%s\n",a);
		a = strtok(NULL, delim);
	}
	return 0;
}
