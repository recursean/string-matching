#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// bigrams
#define GRAM_LEN (2)

/**
 * Split string into array of bigrams.
 * 
 * @param source String to be split
 * @param return_arr_len Pointer to where length of return array should be stored
 * @return Array of bigrams
 */
static char** create_bigrams(char *source, int *return_arr_len) {
    // return array to be filled with bigrams
    *return_arr_len = strlen(source) - GRAM_LEN + 1; 
    // char *bigrams[*return_arr_len];

    char **bigrams = malloc(*return_arr_len);

    // create bigrams for source string
    for(int i = 0; i <= strlen(source) - GRAM_LEN; i++) {
        char *bigram = malloc(GRAM_LEN + 1);
        sprintf(bigram, "%c%c", source[i], source[i+1]);
        bigrams[i] = bigram;
    }

    return bigrams;
}

int main() {
    char *word = "hello";
    int return_arr_len = 0;
    char **bigrams = create_bigrams(word, &return_arr_len);

    for(int i = 0; i < return_arr_len; i++) {
        printf("%s\n", bigrams[i]);
    }

    free(bigrams);
}