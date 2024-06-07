#pragma once
#include<iostream>
#include<vector>
using namespace std;

class List
{
	vector <float> list;
public:
	List();
	List& operator + (float num);//adds the num to array
	List& operator + (List& l);//concatenates two arrays
	int length();//returns length of array
	float operator - ();//pops the first element out of the array
	bool operator [] (float num);//returns true if the num is found in the array
	void reverse();//reverses the order of the array
	friend ostream& operator << (ostream& out, List& l);//to print the array
};