#include <iostream>
using namespace std;

void fillRandom(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	int M, N;
	cout << "Enter the sizes for 1st and 2nd arrays >>> ";
	cin >> M >> N;
	
	int* array1 = new int[M];
	int* array2 = new int[N];

	fillRandom(array1, M);
	PrintArray(array1, M);
	fillRandom(array2, N);
	PrintArray(array2, N);

	int* array3 = new int[M + N];
	for (int i = 0; i < M; i++)
		array3[i] = array1[i];

	for (int i = 0; i < N; i++)
		array3[M + i] = array2[i];

	PrintArray(array3, M + N);

	delete[] array1;
	delete[] array2;
	delete[] array3;
}
