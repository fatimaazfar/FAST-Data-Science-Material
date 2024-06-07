#include<iostream>
using namespace std;
class rectangle
{
private:
	int length;
	int width;
	int area;
public:
	void get_length(int& length)
	{
		cout << "Enter length : ";
		cin >> length;
	}
	void get_width(int& width)
	{
		cout << "Enter width : ";
		cin >> width;
	}
	void set_length(int& length)
	{
		while (length <= 0)
		{
			cout << "Length should be greater than zero." << endl;
			get_length(length);
		}
	}
	void set_width(int& width)
	{
		while (width <= 0)
		{
			cout << "Width should be greater than zero." << endl;
			get_width(width);
		}
	}
	void calculate_area(int& area,int length,int width)
	{
		area = length * width;
	}
	bool is_square(int length,int width)
	{
		if (length == width)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void set_values()
	{
		set_length(length);
		set_width(width);
	}
	void display(int area,int length,int width)
	{
		cout << "The area is " << area << endl;
		if (is_square(length,width))
		{
			cout << "It is a square." << endl;
		}
		for (int i = 0;i < length;i++)
		{
			for (int j = 0;j < width;j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};
class cuboid
{
private:
	int length;
	int width;
	int height;
	int area;
	int volume;
public:
	void get_length(int& length)
	{
		cout << "Enter length : ";
		cin >> length;
	}
	void get_width(int& width)
	{
		cout << "Enter width : ";
		cin >> width;
	}
	void get_height(int& height)
	{
		cout << "Enter height : ";
		cin >> height;
	}
	void set_length(int& length)
	{
		while (length <= 0)
		{
			cout << "Length should be greater than zero." << endl;
			get_length(length);
		}
	}
	void set_width(int& width)
	{
		while (width <= 0)
		{
			cout << "Width should be greater than zero." << endl;
			get_width(width);
		}
	}
	void set_height(int& height)
	{
		while (height <= 0)
		{
			cout << "Height should be greater than zero." << endl;
			get_height(height);
		}
	}
	void calculate_volume(int& volume,int length,int width,int height)
	{
		volume = length * width * height;
	}
	void calculate_area(int& area,int length,int width,int height)
	{
		area = 2 * ((length * height) + (length * width) + (height * width));
	}
	void set_values()
	{
		set_length(length);
		set_width(width);
		set_height(height);
	}
	bool is_cube(int length,int width,int height)
	{
		if (length == width && width == height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void display(int area,int volume,int length,int width,int height)
	{
		cout << "Surface area of the cuboid is " << area << endl;
		cout << "Volume of the cuboid is " << volume << endl;
		if (is_cube(length,width,height))
		{
			cout << "It is a cube." << endl;
		}
	}
};
int main()
{
	int length, width, area , clength , cwidth , cheight , cvolume , carea;
	rectangle rect;
	cuboid cube;
	cout << "********RECTANGLE********\n";
	rect.get_length(length);
	rect.set_length(length);
	rect.get_width(width);
	rect.set_width(width);
	rect.calculate_area(area,length,width);
	rect.display(area,length,width);
	cout << "\n*********CUBOID**********\n";
	cube.get_length(clength);
	cube.set_length(clength);
	cube.get_width(cwidth);
	cube.set_width(cwidth);
	cube.get_height(cheight);
	cube.set_height(cheight);
	cube.calculate_area(carea,clength,cwidth,cheight);
	cube.calculate_volume(cvolume,clength,cwidth,cheight);
	cube.display(carea,cvolume,clength, cwidth, cheight);
}