#include <stdio.h>
#include "algorithm_comparison.h"
#include "levenshtein_distance.h"

// dictionary of commands that can be suggested
char *command_dict[] = {
    "cat",
    "dog",
    "bird"
};

// words to test as input
int test_word_count = 3;
char *test_words[] = {
    "bat",
    "lard",
    "hogg"
};

int main() {
    // Levenshtein Distance
    printf("\n*** Levenshtein Distance *** \n");
    for(int i = 0; i < test_word_count; i++) {
        char *lev_suggest = levenshtein_distance(test_words[i], command_dict);
        printf("Source: %16s    Suggest: %8s\n", test_words[i], lev_suggest);
    }
    printf("\n");
}