#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

class shape
{
public:
	shape(string c = "") : color(c)
	{
		//overload constructor
	}
	string color;
	virtual float area()
	{
		return 0.0;
	}
	friend istream& operator >> (istream& in, shape& s)
	{
		cout << "Enter color : ";
		in >> s.color;
		return in;
	}
	friend ostream& operator << (ostream& out, shape& s)
	{
		out << "Color : " << s.color;
		return out;
	}
	virtual ~shape()
	{
		cout << "~shape() called." << endl;
	}
};
class rectangle: public shape
{
	float height,width;
public:
	rectangle(int h, int w, string s):height(h),width(w)
	{
		color = s;
		//overload constructor
	}
	float area()
	{
		return height * width;
	}
	friend istream& operator >> (istream& in, rectangle& s)
	{
		cout << "Enter color : ";
		in >> s.color;
		cout << "Enter height : ";
		in >> s.height;
		cout << "Enter width : ";
		in >> s.width;
		return in;
	}
	friend ostream& operator << (ostream& out, rectangle& s)
	{
		out << "Enter color : " << s.color << endl;
		out << "Enter height : " << s.height << endl;
		out << "Enter width : " << s.width << endl;
		return out;
	}
	~rectangle()
	{
		cout << "~rectangle() called." << endl;
	}
};
class triangle: public shape
{
	float base,height;
public:
	triangle(int h, int b, string s) :height(h), base(b)
	{
		color = s;
		//overload constructor
	}
	float area()
	{
		return (base * height)/2;
	}
	friend istream& operator >> (istream& in, triangle& s)
	{
		cout << "Enter color : ";
		in >> s.color;
		cout << "Enter height : ";
		in >> s.height;
		cout << "Enter base : ";
		in >> s.base;
		return in;
	}
	friend ostream& operator << (ostream& out, triangle& s)
	{
		out << "Enter color : " << s.color << endl;
		out << "Enter height : " << s.height << endl;
		out << "Enter base : " << s.base << endl;
		return out;
	}
	~triangle()
	{
		cout << "~triangle() called." << endl;
	}
};
class circle: public shape
{
public:
	float radius;
	circle(int r = 0, string s = ""):radius(r)
	{
		color = s;
		//overload constructor
	}
	float area()
	{
		return 3.14 * (radius * radius);
	}
	friend istream& operator >> (istream& in, circle& s)
	{
		cout << "Enter color : ";
		in >> s.color;
		cout << "Enter radius : ";
		in >> s.radius;
		return in;
	}
	friend ostream& operator << (ostream& out, circle& s)
	{
		out << "Enter color : " << s.color << endl;
		out << "Enter radius : " << s.radius << endl;
		return out;
	}
	~circle()
	{
		cout << "~circle() called." << endl;
	}
};

class sphere : public circle
{
public:
	sphere(int r, string c)
	{
		radius = r;

	}
	float volume()
	{
		float vol =  radius * radius * radius * 1.33 * 3.14;
		return vol;
	}
};

float sumarea(shape& a, shape& b)
{
	return a.area() + b.area();
}

void checkShape(shape* s)
{
	cout << "Color : " << s->color;
	sphere* sp = dynamic_cast <sphere*> (s);
	if (sp != nullptr)
	{
		cout << sp->volume();
	}
	else
		cout << "Area : " << s->area();
}

int main()
{
	cout << "EXERCISE 1 AND 2 OUTPUT : " << endl << endl;
	triangle t1(1.0, 9.0, "Red");
	circle c1(2, "Blue");
	rectangle r1(6, 2, "Orange");
	cout << t1.area() << endl;
	cout << c1.area() << endl;
	cout << r1.area() << endl;
	shape* sptr1 = &t1;
	shape& sref = r1;
	cout << sptr1->area() << endl;
	cout << sptr1->color << endl;
	cout << sref.color << endl;
	cout << sref.area() << endl << endl;
	cout << "EXERCISE 3a OUTPUT : " << endl << endl;
	shape s1("Purple");
	cout << sumarea(t1, c1) << endl;
	cout << sumarea(s1, r1) << endl;
	cout << sumarea(s1, t1) << endl << endl;
	cout << "EXERCISE 3b OUTPUT : " << endl << endl;
	int size = 3;
	shape** arr = new shape*[size];
	int choice;
	triangle* t = new triangle(2, 2, "");
	circle* c = new circle(2, "");
	rectangle* r = new rectangle(2, 2, "");
	for (int i = 0;i < size;i++)
	{
		cout << "Press:\n1 for regtangle\n2 for circle\n3 for triangle : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> *r;
			arr[i] = r;
			break;
		case 2:
			cin >> *c;
			arr[i] = c;
			break;
		case 3:
			cin >> *t;
			arr[i] = t;
			break;
		default:
			break;
		}
	}
	for (int i = 0;i < size;i++)
	{
		cout << arr[i]->area() << endl;
	}
	delete r;
	delete t;
	delete c;
	delete[] arr;
	cout << "\nEXERCISE 4 OUTPUT : " << endl << endl;
	shape* s2 = new triangle(1.0, 9.0, "Red");
	delete s2;
	cout << "\n\nEXERCISE 5 OUTPUT : " << endl << endl;
	shape s3("red");
	s3.area();
	cout << "\n\nEXERCISE 6 OUTPUT : " << endl << endl;
	triangle t4(1.0, 9.0, "Red");
	circle c4(2, "Blue");
	rectangle r4(6, 2, "Orange");
	sphere s4(4, "green");
	checkShape(&t4);
	checkShape(&c4);
	checkShape(&r4);
	checkShape(&s4);

	return 0;
}