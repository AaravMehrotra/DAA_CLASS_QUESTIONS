#include <stdio.h>
#include <string.h>
// Function to create LPS array
void computeLPS(char pattern[], int m, int lps[]) {
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP searching function
void KMPSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}
