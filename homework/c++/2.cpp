#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillRandom(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;
}

bool contains(int* arr, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return true;
    return false;
}

int main()
{
    srand(time(NULL));

    int M, N;
    cout << "Enter sizes M and N >>> ";
    cin >> M >> N;

    int* A = new int[M];
    int* B = new int[N];

    fillRandom(A, M);
    fillRandom(B, N);

    int* C = new int[min(M, N)];
    int k = 0;

    for (int i = 0; i < M; i++)
    {
        if (contains(B, N, A[i]) && !contains(C, k, A[i]))
        {
            C[k] = A[i];
            k++;
        }
    }

    cout << "\nA: ";
    for (int i = 0; i < M; i++) cout << A[i] << " ";

    cout << "\nB: ";
    for (int i = 0; i < N; i++) cout << B[i] << " ";

    cout << "\nC (common, no dups): ";
    for (int i = 0; i < k; i++) cout << C[i] << " ";
    cout << "\n";

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
