#include <iostream>
using namespace std;

int main(int argc, char *argv[]) 
{
    double p, q, x, y;
    int j;

    // Read inputs for p, q, y and j
    cout << "Enter values for p, q, y and j: ";
    cin >> p >> q >> y >> j;

    // 1) Set x = 5 if either p >= q OR j != 10
    if ((p >= q) || (j != 10)) {
        x = 5.0;
    }
    cout << "Part 1: x = " << x << endl;

    // 2) Set x = 5 if both y >= q AND j == 20; otherwise x = p
    if ((y >= q) && (j == 20)) {
        x = 5.0;
    } else {
        x = p;
    }
    cout << "Part 2: x = " << x << endl;

    // 3) Set x according to:
    //      0, if p > q
    //      1, if p <= q AND j == 10
    //      2, otherwise
    if (p > q) {
        x = 0.0;
    } else if ((p <= q) && (j == 10)) {
        x = 1.0;
    } else {
        x = 2.0;
    }
    cout << "Part 3: x = " << x << endl;

    return 0;
}