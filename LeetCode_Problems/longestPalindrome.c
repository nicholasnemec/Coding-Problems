/**
5. Longest Palindromic Substring(MEDIUM)
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb" 
**/
int expandFromCenter(char *s, int left, int right){         // Helper function to identify the length of present palindromes
    int n = strlen(s);
    while(left >= 0 && right < n && s[left] == s[right]){   // While both characters around the center are within bounds and the same keep expanding the range of the palindrome
        left--;
        right++;
    }
    return right - left - 1;                                // The length of the palindrome is equal to the distance from the rightmost character to the leftmost minus 1 for the extra step
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if(n == 0){
        return "";
    }

    int start = 0;
    int maxLen = 1;

    for(int i = 0; i < n; i++){
        int len1 = expandFromCenter(s,i,i);                 // find the length of the longest palindrome with an odd center
        int len2 = expandFromCenter(s,i,i+1);               // find the length of the longest palindrome with an even center
        int len = (len1 > len2) ? len1 : len2;              // use a ternary operator to select the longer of the two lengths

        if(len > maxLen){
            maxLen = len;
            start = i - (len - 1)/2;
        }
    }
    char *result = (char*)malloc(maxLen+1);
    strncpy(result, s + start, maxLen);                     // copy the recorded longest palindrome into the result string
    result[maxLen] = '\0';                                  // add the null terminator
    return result;
}

