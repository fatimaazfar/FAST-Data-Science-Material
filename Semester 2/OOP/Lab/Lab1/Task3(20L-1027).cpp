#include<iostream>
using namespace std;
square(int *num)
{
	int sqr=(*num)*(*num);
	return sqr;
}
cube(int *num)
{
	int cube=(*num)*(*num)*(*num);
	return cube;
}
half(int *num)
{
	float half=*num/2;
	return half;
}
main()
{
	int num,*p;
	cout<<"Enter an integer : ";
	cin>>num;
	p=&num;
	int sqr=square(p);
	int cub=cube(p);
	float hal=half(p);
	cout<<"Square is : "<<sqr<<endl;
	cout<<"Cube is : "<<cub<<endl;
	cout<<"Half is : "<<hal<<endl;
}
