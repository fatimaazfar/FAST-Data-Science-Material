#include<iostream>
using namespace std;
int main()
{
int array[100],index=0,i,mansoor[100],size=0,element;
cout<<"please enter the elements of the array"<<endl;
  for(i=0;i<100;i++)
  {
  	cin>>element;
    array[i]=element;
      if(array[i]==-1)
       { 
         break;
       }
    size++;
   }
   cout<<"\noriginal array"<<endl;
for (int i=0;i<size;i++) 
{
cout<<array[i]<<"  ";
}/* index=0;
  for(i=0;i<size;i++)
  {
   	if(i%2==0){
	   mansoor[index]=array[i];
	   index++;}
	else{
	   mansoor[index]=array[i];
	   index++;}
  }
  cout<<"\nsorted array"<<endl;
for (int i=0;i<size;i++) 
{
cout<<mansoor[i]<<"  ";
} } 
  */
  //increasing even sort
   	for(i=0;i<size;i+=2)
	{
		for(int j=i+2;j<size;j+=2)
	{
		if(array[j]<array[i] && i!=size-1)
		{
			int hold=array[i];
		    array[i]=array[j];
		    array[j]=hold;
		}
	}
	}
	//decreasing odd sort	
	   	for(i=1;i<size;i+=2)
	{
		for(int j=i+2;j<size;i+=2)
	{
		if(array[j]>array[i] && i!=size-1)
		{
			int hold=array[i];
		    array[i]=array[j];
		    array[j]=hold;
		}
	}	
	}
cout<<"sorted array"<<endl;
for (int i=0;i<size;i++) 
{
cout<<array[i]<<"  ";
}}
 
