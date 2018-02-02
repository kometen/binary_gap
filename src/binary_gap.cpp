//============================================================================
// Name        : binary_gap.cpp
// Author      : Claus Guttesen
// Version     :
// Copyright   : https://app.codility.com/programmers/lessons/1-iterations/
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bitset>
#include <iostream>
//#include <limits>

using namespace std;

int solution(int N) {
    int x = 0, gap = 0, max = 0, current = 0, previous = 0;
    bool start_counting = false;
    bitset<32> tmp = N;
    bitset<32> one = 1;

    // Do-while loop while tmp is greater than one and count the gap when
    // current and previous last bit differs.
    do {
        current = (int)((tmp & one).to_ulong());
        x = (int)(tmp.to_ulong());
//        cout << "tmp: " << tmp << ", x: " << x << ", current: " << current << endl;

        // If the last bit is 1.
        if ((tmp & one) == one) {
//            cout << "and: " << (tmp & one) << endl;
            gap = 0;
        } else {
            if (start_counting) {
                ++gap;
            }
            // Get the largest gap.
            if (gap > max) {
                max = gap;
            }
        }

        // Move one more to the right.
        tmp >>= 1;
        previous = (int)((tmp & one).to_ulong());
        if (current != previous) {
            start_counting = true;
        }
    } while (x > 1);

    return max;
}

int main() {
    int gap = 0;
//    cout << "int max-size: " << numeric_limits<int>::max() << endl;
    gap = solution(12345);
    cout << "gap: " << gap << endl;
	return 0;
}
