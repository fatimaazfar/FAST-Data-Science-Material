/*
Name : Fatima Azfar
Roll no : 20L-1027
Section : BDS 3B
*/

#include <iostream>
using namespace std;

class Term//class for each term in a polynomial
{
	int exponent;
	int coefficient;
	Term* next;
public:
	friend class Poly;//making poly a friend so it can access all the private members
	Term(int e = 0, int c = 0, Term* n = nullptr) :exponent(e), coefficient(c), next(n) {}//overload,default constructor
	//setters and getters
	void setexp(int e) { exponent = e; }
	void setcoef(int c) { coefficient = c; }
	void setnext(Term* n) { next = n; }
	Term* getnext() 
	{ 
		if (this != nullptr)
			return next; 
	}
	int getexp() 
	{ 
		if (this != nullptr)
			return exponent; 
	}
	int getcoef() 
	{
		if(this != nullptr)
			return coefficient;
	}
	Term(const Term& t)//copy constructor
	{
		this->coefficient = t.coefficient;
		this->exponent = t.exponent;
	}
	Term operator = (const Term& t)//assignment operator
	{
		this->coefficient = t.coefficient;
		this->exponent = t.exponent;
		return *this;
	}
	~Term() {}//destructor
};

class Poly
{
	Term* head;
	int size;
public:
	Poly(int s = 0) :size(s), head(new Term) { head->next = nullptr; }

	void setsize(int s) { size = s; }

	int getsize() { return size; }

	void input()
	{
		/*
		this function takes input of a polynomial from the user and stores it, while keeping
		a check on all the boundary conditions so no invalid input is made
		*/
		z:
		cout << "Enter the size of polynomial : ";
		cin >> size;
		if (size > 0)
		{
			int c;
			for (int i = 0;i < size;i++)
			{
			re:
				cout << "Enter coefficient of term " << i + 1 << " : ";
				cin >> c;
				if (c != 0)//if the coefficient is 0 then we don't even need to store it so its invalid
				{
					Term* temp = head->next;
					head->next = new Term;
					head->next->next = temp;
					head->next->coefficient = c;
					cout << "Enter exponent of term " << i + 1 << " : ";
					cin >> head->next->exponent;
				}
				else
				{
					cout << "Please enter a coefficient other than '0'." << endl;
					goto re;
				}
			}
			this->sort();
			this->simplify();
		}
		else
		{
			cout << "Size cannot be less than or equal to zero, enter again." << endl;
			goto z;
		}
	}

	void print()
	{
		/*
		this function prints the polynomial in a proper way, keeps check on all the boundary conditions
		of printing like when to print a + sign and when to not print coefficients or exponents
		*/
		Term* temp = head->next;
		for (int i = 0;temp != nullptr;i++)
		{
			if (temp->getcoef() > 0 && i > 0)//to print the + sign
			{
				cout << "+";
			}
			if (temp->exponent != 0 && temp->coefficient != 0)//print full value cn^x
			{
				cout << temp->getcoef() << "n^" << temp->getexp();//prints the n in a structured form
			}
			else if (temp->exponent == 0 && temp->coefficient != 0)//if the exponent is zero then only print coefficient c
			{
				cout << temp->coefficient;
			}
			temp = temp->getnext();//moving to next term
		}
	}

	void sort()//sorts the polynomial from highest degree to lowest (takes O(n) in best case and O(n + m) in worst case)
	{
		/*
		This function sorts the polynomial in descending order of the exponents
		of the terms. It takes only 1 loop and swaps two consecutive terms if
		the next exp is larger than the prev exp, it keeps on doing this untill
		the whole list is perfectly sorted.
		*/
		Term* temp = this->head->next;
		Term* t2 = this->head->next;
		int c = 0, e = 0; // temp variables
		for (int i = 0,j = 0;temp->next != nullptr;i++)
		{
			if (temp->exponent < temp->next->exponent)
			{
				e = temp->next->exponent;
				temp->next->exponent = temp->exponent;
				temp->exponent = e;
				c = temp->next->coefficient;
				temp->next->coefficient = temp->coefficient;
				temp->coefficient = c;
				temp = t2;
			}
			else
				temp = temp->next;
			if(i > 0)
				t2 = t2->next;
			if (temp->next == nullptr && j < 2)
			{
				temp = this->head->next;
				t2 = this->head->next;
				i = 0;
				j++;
			}
		}
	}

	void deleteNextTerm(Term* t)//remove the term next to the term which you send in this function
	{
		if (t != 0 && t->next != 0)
		{
			Term* temp = t->next->next;
			delete t->next;
			t->next = temp;
		}
	}

	void simplify()//simplifies the polynomial (takes O(n) time)
	{
		/*
		adds all the terms of same exponent in a single polynomial
		it works like this: if a term has same exponent as its next term
		then add the next term's coefficient in the prev term and after
		that, delete the next term because we don't need it anymore
		*/
		Term* temp = this->head->next;
		for (int i = 0;temp != nullptr;i++)
		{
			if (temp->next != nullptr && temp->exponent == temp->next->exponent)
			{
				temp->coefficient += temp->next->coefficient;
				deleteNextTerm(temp);
				this->size--;
			}
			temp = temp->next;
		}
	}

	int evaluate(const int n)//takes an input and evaluates the polynomial with that n
	{
		/*
		calculates the power of n and then multiplies with coefficient for all terms and
		keeps adding them, is completed in O(n) time
		*/
		int res = 0;
		Term* temp = this->head->next;
		while (temp != nullptr)
		{
			res += temp->coefficient * (pow(n, temp->exponent));
			temp = temp->next;
		}
		return res;
	}

	int operator [] (const int n) // overload for evaluate, can be called like p[n]
	{
		return evaluate(n);
	}

	Poly operator = (const Poly o)//assignment operator, it copies the data from one to another poly
	{
		/*
		assigns the data in o poly to the this poly, while keeping in check the boundary conditions
		like if the size differs how to assign data to new terms
		*/
		Term* tt = this->head->next;
		Term* to = o.head->next;
		while (tt != nullptr)
		{
			*tt = *to;//calls the assignment operator for terms
			tt = tt->next;
			to = to->next;
		}
		if (this->size <= o.size)
		{
			int s = this->size - o.size;
			for (int i = 0;to != nullptr;i++)
			{
				tt = new Term;
				tt->coefficient = to->coefficient;
				tt->exponent = to->exponent;
				tt = tt->next;
				to = to->next;
			}
		}
		else
		{
			tt->next = nullptr;
		}
		return *this;
	}

	Poly add(const Poly o) // adds two polynomials
	{
		return *this + o;
	}

	Poly operator + (const Poly o) const//adds two polynomials (takes O(n + m))
	{
		/*
		this function first concatenates the two polynomials in a new polynomial and
		then it sends that new poly to the simplify and sort function
		O(n + m) for the loop in this + function
		O(n + m) for the loop in the simplify function
		O(n) for the sort function
		approx 3O(n + m) in total, we can ignore the '3' coefficient because it 
		makes no huge difference in BigO, the resulting polynomial is constructed in big O(n + m) time
		*/
		Poly p;//a new polynomial in which we will store the answer
		int sizep = 0;//a temp variable which will keep track of the size of p
		p.head = new Term;//initialization of the head of p
		p.head->next = new Term;
		p.size = this->size + o.size;
		Term* tp = p.head->next;
		Term* tt = this->head->next;
		Term* to = o.head->next;
		int count = 0;
		for (int i = 0;i < p.size;i++)
		{
			if (count < this->size)
			{
				tp->coefficient = tt->coefficient;
				tp->exponent = tt->exponent;
				tt = tt->next;
				if (i < p.size - 1)
					tp = tp->next = new Term;
				count++;
			}
			else if (count >= this->size)
			{
				if (to != nullptr)
				{
					tp->coefficient = to->coefficient;
					tp->exponent = to->exponent;
					to = to->next;
					if (i < p.size - 1)
						tp = tp->next = new Term;
				}
			}
		}
		p.sort();
		p.simplify();
		return p;
	}

	Poly(const Poly& p) // copy constructor
	{
		/*
		simply copies the whole p poly in a newly built polynomial
		*/
		this->size = p.size;
		Term* tp = p.head->next;
		Term* tt = this->head = new Term;
		while (tp != nullptr)
		{
			tt = tt->next = new Term;
			tt->coefficient = tp->coefficient;
			tt->exponent = tp->exponent;
			tp = tp->next;
		}
	}

	Poly multiply(const Poly o) // multiplies two polynomials
	{
		return *this * o;
	}

	Poly operator * (const Poly o) const//multiplies two polynomials
	{
		/*
		this function simply runs a nested loop, outer loop runs for 'n' and inner loop for 'm'
		each term of first poly is multiplied by each term of second poly and sent to the
		simplify and sort function which takes O(n) time, hence O(n * m) + O(n) would basically equal to O(n * m) 
		as it is the bigger one hence the multiplication is completed in O(n * m) time
		*/
		Term* tt = this->head->next;//temp
		Term* to = o.head->next;//temp
		Poly p;//resultant polynomial
		p.setsize(this->size * o.size);//the size would always be the product of sizes of both polys passed
		p.head = new Term;//making space for the new term in head of p
		p.head->next = new Term;
		Term* tp = p.head->next;//also storing it in temp
		int count = 0;//a counter to initialize the last term
		while (tt != nullptr)
		{
			to = o.head->next;//go to the first term of second polynomial
			while (to != nullptr)//multiplies each term of 1st poly with all terms of 2nd poly 
			{
				tp->setexp(tt->exponent + to->exponent);
				tp->setcoef(tt->coefficient * to->coefficient);
				tp->next = new Term;
				tp = tp->next;
				to = to->next;
				count++;
			}
			tt = tt->next;//move to the next term of the first polynomial
			if (count == (this->size * o.size) - 1)//initialize tail in the last iteration
			{
				tp->next = nullptr;
			}
		}
		p.sort();//sort the resulting poly
		p.simplify();//simplify the final resulting polynomial
		return p;
	}

	void clear() // deletes a whole polynomial (takes O(n))
	{
		if (head != nullptr) {
			while (this->head->next != nullptr)
			{
				deleteNextTerm(head);
			}
		}
	}

	~Poly() // destructor
	{
		clear();
	}

};

int main()
{
	Poly p, p1, p2, p3, p4;
	int n = 0, ans = 0, choice = 0;
menu:
	cout << "Enter :\n1 for adding two polynomials\n2 for evaluating a single polynomial\n3 for multiplying two polynomials\n4 to exit\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		p.input();
		p2.input();
		p.print();
		cout << endl;
		p2.print();
		cout << endl;
		cout << "Added polynomial : ";
		(p + p2).print();
		cout << endl;
		p.clear();
		p2.clear();
		goto menu;
	case 2:
		p1.input();
		p1.print();
		cout << endl;
		cout << "Enter the value of n : ";
		cin >> n;
		ans = p1[n];
		cout << "Evaluated result : " << ans;
		cout << endl;
		p1.clear();
		goto menu;
	case 3:
		p3.input();
		p4.input();
		p3.print();
		cout << endl;
		p4.print();
		cout << endl;
		cout << "Multiplied polynomial : ";
		(p3 * p4).print();
		cout << endl;
		p3.clear();
		p4.clear();
		goto menu;
	case 4:
		return 0;
	default:
		goto menu;
	}
}