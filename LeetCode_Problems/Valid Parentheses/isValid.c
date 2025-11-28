bool isValid(char* s) {
    char stack[strlen(s)];
    int top = -1;
    char c;
    char b1 = '(', b4 = ')';
    char b2 = '[', b5 = ']';
    char b3 = '{', b6 = '}';

    for(int i = 0; i < strlen(s); i++){
        c = *(s + i);
        if((c == b4 || c == b5 || c == b6) && (top < 0)) {
            return false;
        }
        if(c == b1 || c == b2 || c == b3){
            top++;
            stack[top] = c;
        } else if(c == b4 && stack[top] == b1){
            top--;
        } else if(c == b5 && stack[top] == b2){
            top--;
        } else if(c == b6 && stack[top] == b3){
            top--;
        } else {
            return false;
        }
    }
    if (top < 0) {
        return true;
    } else {
        return false;
    }
    
}