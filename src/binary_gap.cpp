//============================================================================
// Name        : binary_gap.cpp
// Author      : Claus Guttesen
// Version     :
// Copyright   : https://app.codility.com/programmers/lessons/1-iterations/
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bitset>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int solution(int N) {
    int res = 0, x = 0;
    bitset<16> tmp = N;

    do {
        x = (int)(tmp.to_ulong());
        cout << "tmp: " << tmp << ", x: " << x << endl;
        tmp>>=1;
    } while (x > 0);

    return res;
}

int main() {
    int gap = 0;
    cout << "int max-size: " << numeric_limits<int>::max() << endl;
    gap = solution(17);
    cout << "gap: " << gap << endl;
	return 0;
}
