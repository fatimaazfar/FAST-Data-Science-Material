#include <iostream>
using namespace std;
int main(){
int n,temp;
float largest,Todelete;
float aray[100];
cout << "enter number 0" << endl;
cin >> aray[0];
if (aray[0]==-1) {
return 0;
}
largest=aray[0];
for (int i=1;i<=9;i++){
cout << "enter number " << i << endl;
cin >> aray[i];
if (aray[i]==-1) {
n=i-2;
i=10;
}
if (largest<aray[i]) {
return 0;
}
}
cout << "Yes, the array is sorted." << endl; 
cout << "Number to delete: ";
cin >> Todelete;
for (int i=0;i<=n;i++){
	if (aray[i]==Todelete){
		temp=i;
		for (int x=i;x<=n;x++){
		aray[temp]=aray[x];
		aray[x]=aray[x+1];
		temp=x;
		i=n;
		}	
	}
}
for (int i=0;i<=n;i++){
	cout << aray[i] << ",";
}
cout << endl;
system("pause");
}