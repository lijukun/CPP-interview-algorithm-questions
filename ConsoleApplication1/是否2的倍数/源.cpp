#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	if (num % 2)//Лђеп num & 0x0001
		cout << "no" << endl;
	else
		cout << "yes" << endl;
	system("pause");
	return 0;
}