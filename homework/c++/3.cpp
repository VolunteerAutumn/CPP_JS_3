#include <iostream>
using namespace std;

int main()
{
    int M;
    cout << "Enter array size M >>> ";
    cin >> M;

    int* A = new int[M];

    cout << "Enter " << M << " elements:\n";
    for (int i = 0; i < M; i++)
        cin >> A[i];

    int choice;
    cout << "\nWhat do you want to delete?\n";
    cout << "1 - remove EVEN numbers\n";
    cout << "2 - remove ODD numbers\n";
    cout << ">>> ";
    cin >> choice;

    int* result = new int[M];
    int k = 0;

    for (int i = 0; i < M; i++)
    {
        bool isEven = (A[i] % 2 == 0);

        if (choice == 1)
        {
            if (!isEven)
                result[k++] = A[i];
        }
        else if (choice == 2)
        {
            if (isEven)
                result[k++] = A[i];
        }
    }

    cout << "\nResult: ";
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    cout << "\n";

    delete[] A;
    delete[] result;

    return 0;
}
