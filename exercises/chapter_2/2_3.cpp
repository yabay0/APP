#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
    int value;
    int sum;

    // Part 1: Sum until sentinel -1
    sum = 0;
    cout << "Part 1: Enter positive integers (enter -1 to finish):" << endl;
    while (cin >> value && value != -1) {
        sum += value;
    }
    cout << "Sum = " << sum << endl;

    // Part 2: Terminate when sum exceeds 100 or sentinel -1
    sum = 0;
    cout << "\nPart 2: Enter positive integers (stop if sum > 100 or enter -1 to finish):" << endl;
    while (cin >> value) {
        if (value == -1) {
            break;
        }
        sum += value;
        if (sum > 100) {
            cout << "Sum exceeded 100. Terminating input." << endl;
            break;
        }
    }
    cout << "Sum = " << sum << endl;

    // Part 3: Allow reset with sentinel -2, end with -1
    sum = 0;
    cout << "\nPart 3: Enter positive integers (enter -2 to reset sum, -1 to finish):" << endl;
    while (cin >> value && value != -1) {
        if (value == -2) {
            sum = 0;
            cout << "Sum has been reset to 0. Continue entering:" << endl;
            continue;
        }
        sum += value;
    }
    cout << "Sum = " << sum << endl;

    return 0;
}
