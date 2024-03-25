#include <iostream>
using namespace std;
int nums(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return nums(b, a % b);
	}
}
int main()
{
	int a, b;
	cout << "Enter 1 num : ";
	cin >> a;
	cout << "Enter 2 num : ";
	cin >> b;
	int result = nums(a, b);
	cout << "common divisor of two integers : " << result << endl;
}