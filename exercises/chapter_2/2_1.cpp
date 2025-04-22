#include <iostream>

int main()
{
    double x, y, z;

    // Part 1: Explanation
    /* This snippet checks two conditions on x:
        1) Is x greater than y?
        2) Is x less than 5.0?
    If either condition holds (logical OR), z is assigned 4.0;
    otherwise, z becomes 2.0.
    */

    // Part 2: Evaluate z for three (x, y) pairs
    // Case A
    x = 10.0; y = -1.0;
    if ((x > y) || (x < 5.0)) {
        z = 4.0;
    } else {
        z = 2.0;
    }
    std::cout << "Case A (x=10, y=-1): z = " << z << std::endl;

    // Case B
    x = 10.0; y = 20.0;
    if ((x > y) || (x < 5.0)) {
        z = 4.0;
    } else {
        z = 2.0;
    }
    std::cout << "Case B (x=10, y=20): z = " << z << std::endl;

    // Case C
    x = 0.0; y = 20.0;
    if ((x > y) || (x < 5.0)) {
        z = 4.0;
    } else {
        z = 2.0;
    }
    std::cout << "Case C (x=0, y=20): z = " << z << std::endl;

    // Part 3: Modify the comparison to x >= y
    std::cout << "\nAfter changing '>' to '>=' in the first condition:\n";
    x = 10.0;  y = 20.0;
    if ((x >= y) || (x < 5.0)) {
        z = 4.0;
    } else {
        z = 2.0;
    }
    std::cout << "Modified Case B (x=10, y=20): z = " << z << std::endl;

    return 0;
}