int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *r = malloc(sizeof(int) * wordsSize);
    *returnSize = 0;

    for(int i = 0; i < wordsSize; i++) {
        for(int j = 0; words[i][j] != '\0'; j++) {
            if(words[i][j] == x) {
                r[(*returnSize)++] = i;
                break;
            }
        }
    }

    return r;
}