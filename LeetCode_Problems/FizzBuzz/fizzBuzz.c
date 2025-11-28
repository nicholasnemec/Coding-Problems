/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char **answer = (char**)malloc((n) * sizeof(char*));
    char buffer[10];
    for(int i = 1; i <= n; i++){
        if((i%3 == 0) && (i%5 == 0)){
            strcpy(buffer,"FizzBuzz");
        } else if((i%3) == 0){
            strcpy(buffer,"Fizz");
        } else if((i%5) == 0){
            strcpy(buffer,"Buzz");
        } else {
            sprintf(buffer, "%d", i);
        }
        *(answer + i - 1) = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(*(answer +  i - 1), buffer);
    }
    return answer;
}