int firstUniqChar(char *s) {
    int n = strlen(s);
    if (n == 0) {
        return -1;
    }

    int charCount[256] = {0}; // Assuming ASCII characters

    for (int i = 0; i < n; i++) {
        charCount[s[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}
