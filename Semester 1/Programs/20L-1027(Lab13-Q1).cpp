#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char str[100];
	cout<<"Enter text : ";
	cin>>str;
	char delim[] = ",";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		cout<<ptr<<endl;
		ptr = strtok(NULL, delim);
	}

	return 0;
}
