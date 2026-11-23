#include <stdio.h>
#include <string.h>
#define d 256
#define q 101
void rabinKarp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int i, j;
    int p = 0;  // Hash value of pattern
    int t = 0;  // Hash value of text
    int h = 1;

    // Calculate h = d^(m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (i = 0; i <= n - m; i++) {

        // Check hash values
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate next window hash
        if (i < n - m) {
            t = (d * (t - text[i] * h)
                 + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";

    rabinKarp(text, pattern);

    return 0;
}