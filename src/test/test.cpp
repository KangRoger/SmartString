#include"../SmartString.h"
#include<iostream>
using namespace std;

int main()
{
	SmartString str;
	cout << str.getCount()<< endl;
	str = "hello";
	cout << str.getStr()<< endl;
	SmartString str2 = str;
	cout << str.getCount() << endl;
	SmartString* str3 = new SmartString(str2);
	cout << str.getCount() << endl;
	str2 = "world";
	cout << str.getCount() << endl;
	delete str3;
	cout << str.getCount() << endl;
	cout << str2;



}
