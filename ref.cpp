#include <iostream>
using namespace std;
#if 1

int main(int arg,char *arv[])
{
	int* pointToAnInt = new int;
	int* pNumberCopy = pointToAnInt;
	*pNumberCopy = 30;
	cout << *pointToAnInt;
	//delete pNumberCopy;
	delete pointToAnInt;
	return 0;
}

#elif  0
void GetSquare(int& number)//int& number
{
	number *= number;
}
int main(int arg,char *arv[])
{
	 cout << "Enter a number you wish to square: ";
	 int number = 0;
	 cin >> number;

	 GetSquare(number);
	 cout << "Square is: " << number << endl;
	return 0;
}
#else

void GetSquare(int* number)//int& number
{
	*number *= *number;
}
int main(int arg,char *arv[])
{
	 cout << "Enter a number you wish to square: ";
	 int number = 0;
	 cin >> number;

	 GetSquare(&number);
	 cout << "Square is: " << number << endl;
	return 0;
}
#endif
