/* Let us define sequences similar to those of Collatz with two parameters x
and y. Given a number n, the algorithm to get the next number is:

if n is even, we move to n/2 + x;
otherwise, we move to 3n + y.
The standard Collatz sequence corresponds to x = 0 and y = 1.

Given x, y and a starting number n, compute the length of the cycle reached by
applying the above algorithm. For example, if x = 1, y = 5 and n = 8, then the
defined sequence is 8, 5, 20, 11, 38, 20, 11, 38, … so the cycle has length 3.

Since numbers can become very large, and we have no mathematical guarantee that
we will reach a cycle, we will stop if at some point the sequence reaches a
number greater than 108.

Input

Input consists of several cases, each with three natural numbers x, y and n.
Assume that both x and y do not exceed 1000, that y is odd (for the sequence to
have some interest), and that the initial n is not larger than 108.

Output

For every case, print the length of the cycle, or the first number that strictly
exceeds 108.

Observation

Take into account that the sequences usually reach fast a “short” cycle. */

#include <iostream>
#include <map>
using namespace std;

const int LIMIT = 100000000;

int main() {
    int n, x, y;
    map<int, int> collatz; //{n,rep}
    while (cin >> x >> y >> n) {
        bool repe = false;
        int result = 0;
        while (not repe && n <= LIMIT) {
            if (collatz.find(n) != collatz.end()) {
                result = result - collatz[n];
                repe = true;
            }
            result++;
            collatz[n] = result;
            n = (n%2) ? 3*n+y : n/2+x;
        }
        collatz.clear();
        cout << (repe ? result : n)  << endl;
    }
}
