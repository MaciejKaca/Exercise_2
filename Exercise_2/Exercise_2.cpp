// Exercise_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
	struct CaseStruct {
		int Center;
		vector<int> Elements;
	};

	int CaseQuantity;
	vector <int> Eelements;
	cin >> CaseQuantity;
	CaseStruct *Case = new CaseStruct[CaseQuantity];
	cin.ignore();
	for (int _case = 0; _case < CaseQuantity; _case++)
	{
		string elementsStr;
		getline(cin, elementsStr);
		istringstream is(elementsStr);
		vector<int> v((istream_iterator<int>(is)), istream_iterator<int>());
		Case[_case].Elements = v;
	}

	delete[] Case;
	_getch();
    return 0;
}

