#include"payment.h"

payment::payment(string num, string type) : paymenttype(type), cardnum(num)
{
	//overload and default constructor 
}

void payment::setcardnum(string n)
{
	cardnum = n;
}

string payment::getcardnum()
{
	return cardnum;
}

bool payment::operator==(const payment& p)
{
	if (paymenttype == p.paymenttype && cardnum == p.cardnum)
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, payment& p)
{
	out << "Payment Type : " << p.paymenttype << endl;
	if (p.paymenttype == "card" || p.paymenttype == "Card")
	{
		out << "Card number : " << p.cardnum << endl;
	}
	return out;
}
