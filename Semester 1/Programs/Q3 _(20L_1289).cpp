#include iostream
using namespace std;
int FirstIndex(int aray[],int size,int search){
	for (int i=0;i=size-1;i++){
		if (aray[i]==search) {
		return i;
		}
	}
}
int SecondIndex(int aray[],int size,int search){
	int i=0,found=0;
	while (i=size-1) {
		if (aray[i]==search) {
        found=i;
		}
		i++;
	}
	return found;
}
int main(){
int n,search;
int aray[100];
cout  how many numbers you want to search ;
cin  n;
for (int i=0;i=n-1;i++){
cout  enter number   i  endl;
cin  aray[i];
}
cout  enter what to search ;
cin  search;
cout  First Index of   search   is   FirstIndex(aray,n,search) endl;
cout  Last Index of   search   is   SecondIndex(aray,n,search) endl;
system(pause);
}