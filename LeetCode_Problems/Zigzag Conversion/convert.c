/**
6. Zigzag Conversion(MEDIUM)
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
**/
char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1 || numRows >= n) return s;     // no zigzag needed

    char** rows = malloc(numRows * sizeof(char*));  // create an array of strings
    for (int i = 0; i < numRows; i++) {
        rows[i] = calloc(n + 1, sizeof(char));      // allocate enough space per row
    }

    int currRow = 0;
    bool goingDown = false;

    for (int i = 0; i < n; i++) {
        int len = strlen(rows[currRow]);
        rows[currRow][len] = s[i];                  // append current char to that row
        rows[currRow][len + 1] = '\0';              // also stick a null terminator

        if (currRow == 0 || currRow == numRows - 1) // flip direction at top or bottom
            goingDown = !goingDown;

        currRow += goingDown ? 1 : -1;              // decide which row to move to next based on the direction in the zigzag were at
    }

    char* result = calloc(n + 1, sizeof(char));     // allocate memory for the result string
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);                    // concatenate the row into the resultant string
        free(rows[i]);                              // free the memory used by the concatenated row
    }
    free(rows);                                     // free the rest of the memory used by our list of strings

    return result;
}
