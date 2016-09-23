#ifndef POLYNOMINAL_H_
#define POLYNOMINAL_H_
#include <iostream>
#include "Term.h"
class Polynominal
{
public:
	Polynominal();
	~Polynominal();
	void AddTerms(istream& in);         //输入多项式的各项，构造多项式链表
	void Output(ostream& out)const;      //将多项式送输出流
	void PolyAdd(Polynominal& r);       //多项式相加
private:
	Term * theList;                        //单循环链表的表头指针
	friend ostream & operator << (ostream &, const Polynominal &);
	friend istream& operator >>(istream&, Polynominal &);
	friend Polynominal& operator +(Polynominal &, Polynominal &);
};
Polynominal::Polynominal()
{
	theList = new Term(0, -1);
	theList->link = theList;
}
Polynominal::~Polynominal()
{
	Term* p = theList->link;
	while (p != theList)
	{
		theList->link = p->link;
		delete p;
		p = theList->link;
	}
	delete theList;
}
void Polynominal::AddTerms(istream & in)
{
	Term *q = theList;
	int c, e;
	cout << "请依次输入一个一元整系数多项式（以空格分开，多项式变元指数为负时结束输入)"<<endl;
	for (;;)
	{
		cin>>c>>e;
		if (e<0)
		{
			break;
		}
		q = q->InsertAfter(c, e);
	}
}
void Polynominal::Output(ostream & out) const
{
	int first = 1;
	Term *p = theList->link;
	cout << "这个一元整系数多项式为： ";
	for (; p != theList; p = p->link)
	{
		if (!first && (p->coef>=0))
			out << "+";
		first = 0;
		out << *p;
	}
	cout << endl;
}
void Polynominal::PolyAdd(Polynominal & r)   //这里实现的是q(x)<-q(x)+p(x)
{
	Term* q, *q1 = theList, *p;
	p = r.theList->link;

	q = q1->link;
	while (p->exp >= 0)
	{
		while (p->exp < q->exp)
		{
			q1 = q;
			q = q->link;
		}
		if (p->exp == q->exp)
		{
			q->coef = q->coef + p->coef;
			if (q->coef == 0)
			{
				q1->link = q->link;
				delete(q);
				q = q1->link;
			}
			else
			{
				q1 = q;
				q = q->link;
			}
		}
		else
			q1 = q1->InsertAfter(p->coef, p->exp);
		p = p->link;
	}
}
ostream& operator << (ostream &out, const Polynominal &x)
{
	x.Output(out);
	return out;
}
istream &operator >> (istream &in, Polynominal &x)
{
	x.AddTerms(in);
	return in;
}
Polynominal &operator +(Polynominal &a, Polynominal &b)
{
	a.PolyAdd(b);
	return a;
}
#endif
