int countAsterisks(char* s) {
    int c=2;
    int asterisks=0;
    for(int i=0;s[i];i++){
        if(s[i]=='|'){
            if(c==2) c=1;
            else c++;
        }
        else if(s[i]=='*'){
            if(c==2) asterisks++;
        }
    }
    return asterisks;
}