int finalValueAfterOperations(char** oper, int n) {
    int8_t x = 0;

    for(int i = 0; i < n; i++) {
        // if(!strcmp(operations[i], "--X") || !strcmp(operations[i], "X--")) x--;
        if(oper[i][1] == '-') x--;
        else x++;
    }

    return x;
}