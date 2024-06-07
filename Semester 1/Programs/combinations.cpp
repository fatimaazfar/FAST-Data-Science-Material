#include<iostream>
using namespace std;
int main()
{
	int weight;
	cout<<"Enter total weight : ";
	cin>>weight;
	for(int w1=1;w1<weight;w1++)
	{
		for(int w2=1;w2<weight;w2++)
		{
			for(int w3=w2+1;w3<weight;w3++)
			{
				if(w1+w2+w3==weight)
				{
					cout<<w1<<" "<<w2<<" "<<w3<<endl;
				}
			}
		}
	}
}
