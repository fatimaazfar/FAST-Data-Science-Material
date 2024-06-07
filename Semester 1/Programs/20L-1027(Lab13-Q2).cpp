#include <iostream>
using namespace std;
wordcount(char str[])
{
	int count=0;
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		count++;
		ptr = strtok(NULL, delim);
	}
	return count;
}
alphabetcount(char str[])
{
	int count=0;
	while(arr[i]!='\0')
	{
		if(arr[i]>=65 && arr[i]<=90)
		{
			count++;
		}
	}
	return count;
}
sentencecount(char str[])
{
	int count=0;
	char delim[] = ".";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		count++;
		ptr = strtok(NULL, delim);
	}
	return count;
}
vowelfreq(char str[])
{
	int count=0;
	while(arr[i]!='\0')
	{
		if(((((arr[i]=='a' || arr[i]=='A')||(arr[i]=='e' || arr[i]=='E')) || (arr[i]=='i' || arr[i]=='I')) || (arr[i]=='u' || arr[i]=='U')) || (arr[i]=='o' || arr[i]=='O')) 
		{
			count++;
		}
	}
	return count;
}
onewordfreq(string n,char str)
{
	int count=0;
	char delim[] = " ";

	char *ptr = strtok(str, delim);

	while(ptr != NULL)
	{
		if(ptr==n)
		{
			count++;
		}
		ptr = strtok(NULL, delim);
	}
	return count;
}
int main()
{
char arr[] = &quot;computer science(sometimes called computation science or
computing science, but not to be confused with computational science or software
engineering) is the study of processes that interact with data and that can be
represented as data in the form of programs.It enables the use of algorithms to
manipulate, store, and communicate digital information.A computer scientist
studies the theory of computationand the practice of designing software systems.Its
fields can be divided into theoreticaland practical disciplines.Computational
complexity theory is highly abstract, while computer graphics emphasizes real -
world applications.Programming language theory considers approaches to the
description of computational processes, while computer programming itself
involves the use of programming languagesand complex systems.
//Human–computer interaction considers the challenges in making
computers useful, usable, and accessible.&quot;;
int a;
a=wordcount(arr);
cout<<"Word count : "<<a;
a=alphabetcount(arr);
cout<<"Alphabet count : "<<a;
a=sentencecount(arr);
cout<<"Sentence count : "<<a;
a=vowelfreq(arr);
cout<<"Vowel Frequency : "<<a;
a=onewordfreq("computer",arr);
cout<<"One word 'computer' Frequency : "<<a;
return 0;
}
