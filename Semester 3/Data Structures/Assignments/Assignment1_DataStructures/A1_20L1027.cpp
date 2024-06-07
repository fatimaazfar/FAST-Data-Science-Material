/*
Name: Fatima Azfar
Roll no: 20L-1027
Section: BSDS 3B
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
	Term(int e = 0, int c = 0, Term* n = nullptr):exponent(e),coefficient(c),next(n){}//overload,default constructor
	//setters and getters
	void setexp(int e) { exponent = e; }
	void setcoef(int c) { coefficient = c; }
	void setnext(Term* n) { next = n; }
	Term* getnext() { return next; }
	int getexp() { return exponent; }
	int getcoef() { return coefficient; }
	Term(const Term& t)//copy constructor
	{
		this->coefficient = t.coefficient;
		this->exponent = t.exponent;
	}
	Term operator = (const Term& t)//assignment operator
	{
		this->coefficient = t.coefficient;
		this->exponent = t.exponent;
	}
	~Term() {}//destructor
};

class Poly//a list of terms altogether making a polynomial
{
	Term* head;
	Term* tail;
	Term* next;
	int size;
public:
	Poly(int s = 0, Term* n = nullptr, Term* h = nullptr, Term* t = nullptr) :size(s), next(n), head(h), tail(t) {}
	void setsize(int s) { size = s; }
	int getsize() { return size; }

	void input()//inputs values in a new polynomial, sorts and simplifies them
	{
	reenter:
		cout << "Enter the size of the polynomial (number of terms): ";
		cin >> size;
		if (size > 0)//if size is greater than 0 then make a new Term
		{
			head = new Term;
		}
		else//else it is an invalid input
		{
			cout << "Size cannot be less than 1. Enter again." << endl;
			goto reenter;
		}
		int c = 0, e = 0;//temporary variables
		Term* temp = head;
		for (int i = 0;i < size;i++)
		{
			cout << "Enter the exponent of term no. " << i + 1 << " : ";
			cin >> e;
			temp->setexp(e);//setting exponent
			cout << "Enter the coefficient of term no. " << i + 1 << " : ";
			cin >> c;
			temp->setcoef(c);//setting coefficient
			if (i < size - 1)
			{
				temp->setnext(new Term);
				temp = temp->getnext();
			}
			else if (i == size - 1)//this condition is for last term as the next would be nullptr
			{
				tail = temp;
				temp->setnext(nullptr);
			}
		}
		this->sort();//sorts the polynomial
		this->simplify();//simplifies it beforehand
	}

	void output()//simply prints the whole polynomial
	{
		Term* temp = head;
		for (int i = 0;temp != nullptr;i++)
		{
			if (temp->getcoef() > 0 && i > 0)//to print the + sign
			{
				cout << "+";
			}
			if (temp->coefficient != 0 &&  temp->exponent != 0)//in case there is a term with a 0 coef so it would make the whole term 0 so we wont print it
			{
				cout << temp->getcoef() << "n^" << temp->getexp();//prints the n in a structured form
			}
			else if (temp->coefficient != 0 && temp->exponent == 0)//if the exponent is zero then dont print the n^0
			{
				cout << temp->coefficient;
			}
			temp = temp->getnext();//moving to next term
		}
	}

	void sort()//sorts the polynomial from highest degree to lowest
	{
		Term* temp = this->head;
		for(int i = 0;i < this->size* 2; i++)//loop runs twice the size to double check the sort
		{
			temp = this->head;//every time the inner loop ends the temp is re-initialized
			while (temp != nullptr)
			{
				if (temp->next != 0 && temp->exponent < temp->next->exponent)//comparing exponents and checking boundary condition
				{
					int exp = temp->exponent;//temporary variable
					int cof = temp->coefficient;//temporary variable
					temp->exponent = temp->next->exponent;//swap
					temp->coefficient = temp->next->coefficient;//swap
					temp->next->exponent = exp;//give back the value
					temp->next->coefficient = cof;//give back the value
				}
				temp = temp->next;//move to next term
			}
		}
	}

	Poly operator + (const Poly o) const//adds two polynomials
	{
		Poly p;//a new polynomial in which we will store the answer
		int sizep = 0;//a temp variable which will keep track of the size of p
		p.head = new Term;//initialization of the head of p
		Term* tt = this->head;//temp for loop
		Term* tt2 = this->head;//temp for 2nd check loop
		Term* to = o.head;//temp for loop
		Term* to2 = o.head;//temp for 2nd check loop
		Term* tp = p.head;//temp for loop
		int j = 0;
		int rescof = 0;
		for (int i = 0;tt != nullptr;i++)
		{
			int count = 0;
			rescof = 0;
			for (j = 0;to != nullptr;j++)
			{
				if (tt->getexp() == to->getexp())//if the exponents are same then add
				{
					/*these checks are here because there might be many terms of same exponent 
					so we have to add them all to just one new term in the new polynomial*/
					if (count >= 1)//if condition was true for more than 1 term then only add the new value not the previous
					{
						rescof += to->getcoef();
					}
					else//if the loop didnt run the second time for one it means we have only 1 value to add and we can simply do it like this
					{
						rescof += tt->getcoef() + to->getcoef();
					}
					tp->setcoef(rescof);//after the coef is calculated we will set its value to the resulting poly
					tp->setexp(tt->getexp());//set the exponent
					count++;//terms to be added on same exponent
					sizep++;//counting the size
				}
				to = to->getnext();//move to next value
			}
			if (i < size - 1)//if the list hasn't ended
			{
				tp->setnext(new Term);
				tp = tp->getnext();
			}
			else if (i == this->size - 1 && j == o.size - 1)//if both the lists have ended set tail and set next to null
			{
				tp->setnext(nullptr);
				p.tail = tp;
			}
			if (count == 0)//in case there was an element in first poly which didn't match any element in 2nd poly then store it here
			{
				tp->setcoef(tt->getcoef());
				tp->setexp(tt->getexp());
				tp->setnext(new Term);
				tp = tp->getnext();
				sizep++;
			}
			tt = tt->getnext();//move to next
			to = o.head;//set the second polynomial term again to head
		}
		//these loops are made to check in reverse in case any element was left in 2nd poly
		while (to2 != nullptr)
		{
			int count2 = 0;
			while (tt2 != nullptr)
			{
				if (tt2->getexp() == to2->getexp())
				{
					count2++;
				}
				tt2 = tt2->getnext();
			}
			if (count2 == 0)//in case there was an element in 2nd poly which didn't match any element in 1st poly then store it here
			{
				tp->setnext(new Term);
				tp = tp->getnext();
				tp->setcoef(to2->getcoef());
				tp->setexp(to2->getexp());
				tp->setnext(nullptr);
				tp = tp->getnext();
				sizep++;
			}
			p.tail = tp;
			to2 = to2->getnext();
			tt2 = this->head;
		}
		p.setsize(sizep + 1);//set the size of new polynomial
		p.simplify();
		p.sort();
		return p;
	}

	Poly operator * (const Poly o) const//multiplies two polynomials
	{
		Term* tt = this->head;//temp
		Term* to = o.head;//temp
		Poly p;//resultant polynomial
		p.setsize(this->size * o.size);//the size would always be the product of sizes of both polys passed
		p.head = new Term;//making space for the new term in head of p
		Term* tp = p.head;//also storing it in temp
		int count = 0;//a counter to initialize the last term
		while (tt != nullptr)
		{
			to = o.head;//go to the first term of second polynomial
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
				p.tail = tp;
			}
		}
		p.simplify();//simplify the final resulting polynomial
		return p;
	}

	Poly operator = (const Poly o) const//assignment operator, it copies the data from one to another poly
	{
		Term* tt = this->head;
		Term* to = o.head;
		while (tt != nullptr)
		{
			tt = to;//calls the assignment operator for terms
			tt = tt->next;
			to = to->next;
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

	void simplify()//simplifies the polynomial
	{
		Term* temp = this->head;
		for (int i = 0;temp != nullptr;i++)
		{
			if (temp->next != nullptr && temp->exponent == temp->next->exponent)
			{
				temp->coefficient += temp->next->coefficient;
				deleteNextTerm(temp);
			}
			temp = temp->next;
		}
	}

	int evaluate(int n)//takes an input and evaluates the polynomial with that n
	{
		int res = 0;
		Term* temp = this->head;
		while (temp != nullptr)
		{
			res += temp->coefficient * (pow(n, temp->exponent));
			temp = temp->next;
		}
		return res;
	}

	//~Poly()
	//{
	//	Term* temp = this->head;
	//	while (temp != nullptr)
	//	{
	//		deleteNextTerm(temp);
	//		temp = temp->next;
	//	}
	//	//delete this->head;
	//}
};

	int main()
	{
		Poly p, p1, p2, p3, p4;
		int n = 0, ans = 0;
	menu:
		int choice = 0;
		cout << "Enter :\n1 for adding two polynomials\n2 for evaluating a single polynomial\n3 for multiplying two polynomials\n4 to exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			p.input();
			p2.input();
			p.output();
			cout << endl;
			p2.output();
			cout << endl;
			cout << "Added polynomial : ";
			(p + p2).output();
			cout << endl;
			goto menu;
		case 2:
			p1.input();
			p1.output();
			cout << endl;
			cout << "Enter the value of n : ";
			cin >> n;
			ans = p1.evaluate(n);
			cout << "Evaluated result : " << ans;
			cout << endl;
			goto menu;
		case 3:
			p3.input();
			p4.input();
			p3.output();
			cout << endl;
			p4.output();
			cout << endl;
			cout << "Multiplied polynomial : ";
			(p3 * p4).output();
			cout << endl;
			goto menu;
		case 4:
			return 0;
		default:
			goto menu;
		}
	}