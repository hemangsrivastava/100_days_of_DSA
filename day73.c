#include <stdio.h>


char firstNonRepeating(char *s) {
    int hash[26] = {0};

    // Count frequencies
    for (int i = 0; s[i] != '\0'; i++) {
        hash[s[i] - 'a']++;
    }

    // Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (hash[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[] = "geeksforgeeks";
    printf("%c\n", firstNonRepeating(s));
    return 0;
}
