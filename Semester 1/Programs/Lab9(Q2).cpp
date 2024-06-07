#include <iostream>
using namespace std;
void encrypt(char a[])
{
	for(int i = 0; (i < 100 && a[i] != '\0'); i++)
        a[i] = a[i] + 2; 
    cout << "\nEncrypted string: " << a << endl;
}
void decrypt(char a[])
{
	for(int i = 0; (i < 100 && a[i] != '\0'); i++)
        a[i] = a[i] - 2; //the key for encryption is that 3 is subtracted to ASCII value     
    cout << "\nDecrypted string: " << a << endl;
}
int main()
{
   char str[100];
   cout << "Please enter a string terminating with 0:\t";
   cin.getline(str,100,'0');
   encrypt(str);
   decrypt(str);
}
