#include <iostream>
#include <cstring>

using namespace std;

// A utility function to get max of two integers
int max(int x, int y) { return (x > y) ? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str) {
    u_int64_t n = strlen(str);
    u_int64_t i, j, subs;
    int L[n][n];  // Create a table to store results of subproblems


    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
        L[i][i] = 1;

    // substring
    for (subs = 2; subs <= n; subs++) {
        for (i = 0; i < n - subs + 1; i++) {
            j = i + subs - 1;
            if (str[i] == str[j] && subs == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i + 1][j - 1] + 2;
            else
                L[i][j] = max(L[i][j - 1], L[i + 1][j]);
        }
    }

    return L[0][n - 1];
}


int main() {

    char str[2048];
    cin >> str;

    while (!cin.eof()){
        cout << lps(str) << endl;
        cin >> str;
    }

    return 0;
}