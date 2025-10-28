/**
3. Longest Substring Without Repeating Characters(MEDIUM)
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
**/
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int longestSub = 0;           // Initialize return value

    for(int i = 0; i < n; i++){
        bool seen[128] = {false}; // Initialize boolean array to track what characters have been seen on current substring
        int ssLen = 0;            // Initialize a value to track the length of the current substring

        for(int j = i; j < n; j++){
            char c = s[j];
            if(seen[(int)c]){     // Check if the current character has been yet this substring
                break;            // If it has, end the current substring and update the longest length
            }
            seen[(int)c] = true;  // Otherwise, set the current character as seen
            ssLen++;              // then increment the length of the current substring
        }
        if(ssLen > longestSub){   // Check to see if the last substring is longer than the longest recorded
            longestSub = ssLen;   // If it is, update the value of the longest seen thus far
        }
    }
    return longestSub;
}
