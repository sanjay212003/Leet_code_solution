//Sort Characters By Frequency
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 256

char* frequencySort(char* s);

int solution_main() {
    char testStr[] = "tree";
    char* sortedStr = frequencySort(testStr);
    printf("Sorted String: %s\n", sortedStr);  // Output: "eetr"
    free(sortedStr);  // Free the dynamically allocated memory

    return 0;
}

char* frequencySort(char* s) {
    // Count the frequency
    int frequency[MAX_CHARS] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        frequency[s[i]]++;
    }

    // Generate the required answer
    char* ans = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    while (idx < len) {
        int maxFreq = 0, maxIdx = -1;
        for (int j = 0; j < MAX_CHARS; j++) {
            if (frequency[j] > maxFreq && frequency[j] > 0) {
                maxFreq = frequency[j];
                maxIdx = j;
            }
        }
        while (frequency[maxIdx] > 0) {
            ans[idx++] = maxIdx;
            frequency[maxIdx]--;
        }
    }
    ans[idx] = '\0';

    return ans;
}
