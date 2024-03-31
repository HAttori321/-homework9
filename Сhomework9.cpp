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

template <typename T>
void initMatrix(T** matrix, int size) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<T> dist(0, 100);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = dist(gen);
		}
	}
}

template <typename T>
void printMatrix(T** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void findMinMaxDiagonal(T** matrix, int size, T& min, T& max) {
	min = matrix[0][0];
	max = matrix[0][0];

	for (int i = 1; i < size; i++) {
		if (matrix[i][i] < min) {
			min = matrix[i][i];
		}
		else if (matrix[i][i] > max) {
			max = matrix[i][i];
		}
	}
}

template <typename T>
void sortRows(T** matrix, int size) {
	for (int i = 0; i < size; i++) {
		sort(matrix[i], matrix[i] + size);
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

	int size = 4;
	int** intMatrix = new int* [size];
	for (int i = 0; i < size; i++) {
	intMatrix[i] = new int[size];
	}
	initMatrix(intMatrix, size);

	cout << "Matrix int:" << endl;
	
	printMatrix(intMatrix, size);
	int intMin, intMax;
	findMinMaxDiagonal(intMatrix, size, intMin, intMax);
	cout << "Min/Max int: " << intMin << " / " << intMax << endl;
	sortRows(intMatrix, size);
}
