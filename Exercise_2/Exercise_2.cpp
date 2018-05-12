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

	int CaseQuantity;
	cin >> CaseQuantity;
	vector<int> *Case = new vector<int>[CaseQuantity];
	for (int _case = 0; _case < CaseQuantity; _case++)
	{
		string elementsStr;
		int IUseVectors;
		cin >> IUseVectors;
		cin.ignore();
		getline(cin, elementsStr);
		istringstream is(elementsStr);
		vector<int> v((istream_iterator<int>(is)), istream_iterator<int>());
		v.erase(v.begin() + IUseVectors, v.end());
		Case[_case] = v;
	}

	for (int i = 0; i < CaseQuantity; i++)
	{
		int Left=Case[i].at(0), Right=0;
		for (int element = 2; element < Case[i].size(); element++)
		{
			Right += Case[i].at(element);
		}
		for (int element = 1; element < Case[i].size() && Left != Right; element++)
		{
			Left += Case[i].at(element);
			Right -= Left;
		}
		if (Left == Right || Case[i].size()==1)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}

	delete[] Case;
	_getch();
    return 0;
}

