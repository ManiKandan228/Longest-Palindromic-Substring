#include <stdio.h>
#include <string.h>
int isCheckforPalindrome(char *s, int starting, int ending) 
{
    while (starting < ending) 
    {
        if (s[starting] != s[ending]) 
        {
            return 0;
        }
        starting++;
        ending--;
    }
    return 1;
}
void longestPalindromeCheck(char *s)
{
    int n = 0;
    while (s[n] != '\0') n++;

    int maxLen = 1; 
    int starting = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isCheckforPalindrome(s, i, j) && (j - i + 1) > maxLen) 
            {
                starting = i;
                maxLen = j - i + 1;
            }
        }
    }

    printf("The Longest Palindromic Substring: ");
    for (int i = starting; i < starting + maxLen; i++) 
    {
        putchar(s[i]);
    }
    printf("\n");
}
int main() {
    char str[100];
    printf("Enter the string to Check: ");
    scanf("%s", str);
    longestPalindromeCheck(str);
    return 0;
}
