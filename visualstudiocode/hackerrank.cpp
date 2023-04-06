    //#include <iostream>
    //#include <cstdio>
    //using namespace std;

    //int main() {
    //    // Complete the code.

    //    int a;
    //    std::cin >> a;
    //    int b;
    //    std::cin >> b;

    //    int max_number = 9;

    //    if (max_number > b) {
    //        max_number = b;
    //    }

    //    for (int i = a; i <= max_number; i++) {
    //        if (i == 1) {
    //            std::cout << "one" << std::endl;
    //        }
    //        else if (i == 2) {
    //            std::cout << "two" << std::endl;
    //        }
    //        else if (i == 3) {
    //            std::cout << "three" << std::endl;
    //        }
    //        else if (i == 4) {
    //            std::cout << "four" << std::endl;
    //        }
    //        else if (i == 5) {
    //            std::cout << "five" << std::endl;
    //        }
    //        else if (i == 6) {
    //            std::cout << "six" << std::endl;
    //        }
    //        else if (i == 7) {
    //            std::cout << "seven" << std::endl;
    //        }
    //        else if (i == 8) {
    //            std::cout << "eight" << std::endl;
    //        }
    //        else if (i == 9) {
    //            std::cout << "nine" << std::endl;
    //        }
    //        else {
    //            std::cout << "nine" << std::endl;
    //        }
    //    }

    //    for (int i = max_number; i < b; ++i) {
    //        if (i % 2 == 0) {
    //            std::cout << "odd" << std::endl;
    //        }
    //        else {
    //            std::cout << "even" << std::endl;
    //        }
    //    }
    //    return 0;
    //}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int mainhackerrank() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    constexpr int size{4};
    /*std::cin >> size;*/

    int arr[size]{1,4,3,2};

    /*for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }*/


    for (int i = size - 1; i > 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[0];


    return 0;
}
