#include<iostream>
#include"Polynominal.h"
#include "Term.h"
using namespace std;
int main()
{
	Polynominal p, q;
	cin >> p;
	cout << p;
	cin >> q;
	cout << q;
	q = q + p;
	cout << q;
	return 0;
}
