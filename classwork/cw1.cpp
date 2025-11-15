#include <iostream>
using namespace std;

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void FillArrayRandomly(int* arr, int size, int minValue, int maxValue)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (maxValue - minValue + 1) + minValue;
	}
}

int main()
{
	// ========================================= PART I ==========================================
	srand(time(NULL));
    int M, N;
    cout << "Enter the size of first array >>> ";
    cin >> M;
    cout << "Enter the size of second array >>> ";
    cin >> N;

    int* arr1 = new int[M];
    int* arr2 = new int[N];

    int S = M + N;
	int* arr3 = new int[S];

	FillArrayRandomly(arr1, M, 1, 10);
	FillArrayRandomly(arr2, N, 1, 10);
	cout << "First array: ";
	PrintArray(arr1, M);
	cout << "Second array: ";
	PrintArray(arr2, N);

	// array 3 has to be the combination of arr1 and arr2
	for (int i = 0; i < M; i++)
	{
		arr3[i] = arr1[i];
	}
	for (int i = 0; i < N; i++)
	{
		arr3[M + i] = arr2[i];
	}

	cout << "Combined array: ";
	PrintArray(arr3, S);

    delete[] arr1;
    delete[] arr2;
	delete[] arr3;
	// ========================================== PART II ==========================================
	cout << "Enter the size of first array >>> ";
	cin >> M;
	cout << "Enter the size of second array >>> ";
	cin >> N;

	int* arr1 = new int[M];
	int* arr2 = new int[N];

	int S = M + N;
	int* arr3 = new int[S];

	FillArrayRandomly(arr1, M, 1, 10);
	FillArrayRandomly(arr2, N, 1, 10);
	cout << "First array: ";
	PrintArray(arr1, M);
	cout << "Second array: ";
	PrintArray(arr2, N);

	// array 3 has to be the combination of arr1 and arr2, with only common elements from arr1
	int index = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr1[i] == arr2[j])
			{
				arr3[index] = arr1[i];
				index++;
				break;
			}
		}
	}
	cout << "Combined array with common elements: ";
	PrintArray(arr3, index);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}
