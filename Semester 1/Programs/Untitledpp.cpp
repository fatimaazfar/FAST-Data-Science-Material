#include <iostream>
using namespace std;
int main()
{
    int arr[100],temp[100],swap,size=1,fre[100],c,sizefinal=0;
    cout<<"Enter Elements in Array, enter -99 to stop :  "<<endl;
     for(int i=0; i<100; i++)
     {
        cin>>arr[i];
        fre[i]=-1;     	
		if(arr[i]==-99)
         {	
		 break;
	     }
	     size++;
	     sizefinal++;
	 }
//frequency array storing
     for(int i=0; i<size; i++)
     {
     	
     	c=1;
     	
     	for(int j=i+1; j<size; j++)
     	{
     		if(arr[i]==arr[j])
     		{
     		c++;
     		fre[j]=0;
			 }
     if(fre[i]!=0)
     {
     	fre[i]=c;
	 }}
}
//unique array storing
	     for(int i=0; i<size-1; i++)
     {
         for(int j=i+1; j<size-1; j++)
      { 
         if(arr[i]==arr[j])
         {
         	for(int k=j; k<size; k++)
			{
				arr[k]=arr[k+1];
			 }
			size--;
			j--;
		 }
       }
     }
//printing arrays
    cout<<"\nUnique Series = ";
     for(int i=0; i<size-1; i++)
      {
	  cout<<arr[i]<<" ";
       }
     cout<<"\nFrequecy Of Array : ";
	 for(int i=0; i<size; i++)
	 {
	 	if(fre[i]!=0)
	 	{
	 		cout<<fre[i]<<" ";
		 }
	 }
//sorting frequency array
	 for(int i=0; i<(size); i++)
	 {
	 	for(int j=0; j<(size); j++)
	 	{
	 		if(fre[j]<fre[j+1])
	 		{
	 			swap=fre[j+1];
	 			fre[j+1]=fre[j];
	 			fre[j]=swap;
	 			swap=arr[j+1];
	 			arr[j+1]=arr[j];
	 			arr[j]=swap;
			 }
		 }
	 }
    cout<<"\nSorted Frequency Array : ";
    
    for(int i=0; i<size-1; i++)
	 
	 	{
	 		cout<<fre[i]<<" ";
		 }
    cout<<"\nSorted unique Array : ";
    
    for(int i=0; i<size-1; i++)
	 
	 	{
	 		cout<<arr[i]<<" ";
		 }		 
//storing sorted unique array according to frequency
	 int index=0;
   for(int i=0;i<(size);i++)
   {
   	for(int j=0;j<fre[i];j++)
    	{
   		temp[index]=arr[i];
   		index++;
	   }
   }
   cout<<"\nSorted array is ";
   for(int i=0;i<(index);i++)
   {
   	cout<<temp[i]<<" ";
   }
   
  system("pause");
  return 0 ;
}
