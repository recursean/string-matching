#include <stdio.h>
#include <time.h>
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
    double total_time_taken = 0;
    printf("\n*** Levenshtein Distance *** \n");
    for(int i = 0; i < test_word_count; i++) {
        clock_t clock_start = clock();
        char *lev_suggest = levenshtein_distance(test_words[i], command_dict);
        clock_t clock_end = clock();

        // add to total time take
        total_time_taken += (double)(clock_end - clock_start) / CLOCKS_PER_SEC;

        printf("Source: %16s    Suggest: %8s\n", test_words[i], lev_suggest);
    }
    printf("\n");
    printf("Average Execution Time: %f\n", total_time_taken / test_word_count);
    printf("\n");
}