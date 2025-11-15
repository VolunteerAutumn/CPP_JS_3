#include <iostream>
using namespace std;

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int* arr = new int[100];
    int currentSize = 0;

    while (true) {
        cout << "Hello! Would you like to:\n\n";

        // Gray = cannot be used
        if (currentSize == 0) {
            cout << "1) Enter the array elements? (max 100)\n";
            cout << "\033[90m2) Delete the even elements from the array?\033[0m\n";
            cout << "\033[90m3) Delete the odd elements from the array?\033[0m\n";
        }
        else {
            cout << "\033[90m1) Enter the array elements? (max 100)\033[0m\n";
            cout << "2) Delete the even elements from the array?\n";
            cout << "3) Delete the odd elements from the array?\n";
        }

        cout << "4) Exit the program?\n\n";
        cout << ">>> ";

        int choice;
        cin >> choice;

        switch (choice) {

            // ENTER ELEMENTS
        case 1:
            if (currentSize != 0) {
                cout << "\033[90mThat option is disabled right now.\033[0m\n";
                break;
            }

            cout << "Enter the number of elements (max 100): ";
            cin >> currentSize;
            if (currentSize > 100) currentSize = 100;

            cout << "Enter the elements:\n";
            for (int i = 0; i < currentSize; i++) {
                cout << "Element " << i + 1 << ": ";
                cin >> arr[i];
            }

            cout << "The array now is: ";
            PrintArray(arr, currentSize);
            break;

            // DELETE EVEN
        case 2:
            if (currentSize == 0) {
                cout << "\033[90mThis option is disabled.\033[0m\n";
                break;
            }

            {
                int newSize = 0;
                for (int i = 0; i < currentSize; i++) {
                    if (arr[i] % 2 != 0) {
                        arr[newSize++] = arr[i];
                    }
                }
                currentSize = newSize;
            }

            cout << "Even elements removed! New array: ";
            PrintArray(arr, currentSize);
            break;

            // DELETE ODD
        case 3:
            if (currentSize == 0) {
                cout << "\033[90mThis option is disabled.\033[0m\n";
                break;
            }

            {
                int newSize = 0;
                for (int i = 0; i < currentSize; i++) {
                    if (arr[i] % 2 == 0) {
                        arr[newSize++] = arr[i];
                    }
                }
                currentSize = newSize;
            }

            cout << "Odd elements removed! New array: ";
            PrintArray(arr, currentSize);
            break;

            // EXIT
        case 4:
            cout << "Babai\n";
            delete[] arr;
            return 0;

        default:
            cout << "Invalid choice, try again!\n";
            break;
        }
    }
}
