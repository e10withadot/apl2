int len_str(char* s) {
    char c;
    int i = 0;
    do {
        c = s[i++];
    } while(c != '\0');
    return i;
}

