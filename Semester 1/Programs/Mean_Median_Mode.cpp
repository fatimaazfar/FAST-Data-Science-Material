#include<cstdlib>
#include<iostream>
using namespace std;
void sort(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<arr[i])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void populate_randomly(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		arr[i]= 10 + rand() % 80;
	}
}

float mean(int arr[],int size)
{
	float m=0;
	for(int i=0;i<size;i++)
	{
		m+=arr[i];
	}
	m/=size;
	return m;
}

int median(int arr[], int n) 
{
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    return arr[n / 2];
}

int mode(int arr[], int n) 
{ 
    float max_count = 1, res = arr[0], count = 1;
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] == arr[i - 1])
            count++;
        else 
        {
            if (count > max_count) 
            {
                max_count = count;
                res = arr[i - 1];
            }
            count = 1;
        }
    }
    if (count > max_count)
    {
        max_count = count;
        res = arr[n - 1];
    }

    return res;
}
void print(int arr[], int size)
{
	cout<<"{ ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}"<<endl;
}
int main()
{
	int size=20, choice=0;
	int arr[size];
	populate_randomly(arr,size);
	cout<<"Your array has been populated with following random values : "<<endl;
	print(arr,size);
	cout<<"Sorted array is : "<<endl;
	sort(arr,size);
	print(arr,size);
	repeat:
	cout<<"Enter:\n1 to calculate mean\n2 to calculate median\n3 to calculate mode\nany key to exit : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Mean : "<<mean(arr,size)<<endl;
			choice=0;
			goto repeat;
			break;
		case 2:
			cout<<"Median : "<<median(arr,size)<<endl;
			choice=0;
			goto repeat;
			break;
		case 3:
			cout<<"Mode : "<<mode(arr,size)<<endl;
			choice=0;
			goto repeat;
			break;
		default:
			return 0;
	}
}

