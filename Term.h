#ifndef TERM_H_
#define TERM_H_
#include <iostream>
using namespace std;
class Polynominal;
class Term
{
public:
	Term(int c, int e);
	Term(int c, int e, Term* nxt);
	Term* InsertAfter(int c, int e);            //在this指针指示的结点后插入新结点
private:
	int coef;
	int exp;
	Term *link;
	friend ostream & operator <<(ostream & out, const Term& val);//重载"<<"，输出多项式的一项
	friend class Polynominal;
};
Term::Term(int c, int e) :coef(c), exp(e)
{
	link = 0;
}
Term::Term(int c, int e, Term *nxt) : coef(c), exp(e)
{
	link = nxt;
}
Term *Term::InsertAfter(int c, int e)                        
{                                                            
	link = new Term(c, e, link);                             
	return link;                                             
}                                                            
ostream &operator << (ostream & out, const Term& val)
{
	if (val.coef == 0)
		return out;
	out << val.coef;
	switch (val.exp)
	{
	case 0:
		break;
	case 1:out << "X";
		break;
	default:
		out << "X^" << val.exp;
		break;
	}
	return out;
}
#endif
