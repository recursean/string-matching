#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "damerau_levenshtein_distance.h"
#include "algorithm_comparison.h"

static int calculate_damerau_levenshtein(char *source, char *target);

// debug logging flag
static bool debug = false;

/**
 * Find closest string match based on Damerau Levenshtein Distance algorithm
 * 
 * @param source String to compare
 * @return String in dictionary with lowest Damerau Levenshtein Distance from source
 */
char* damerau_levenshtein_distance(char *source, char *command_dict[]) {
    // index in dictionary of string with smallest distance
    int min_idx = INT_MAX;

    // smallest distance of all strings in dictionary
    int min_distance = INT_MAX;

    // distance of current string being processed
    int distance = -1;

    // calculate Damerau Levenshtein Distance for each string in dictionary 
    for(int i = 0; i < COMMAND_COUNT; i++) {
        distance = calculate_damerau_levenshtein(source, command_dict[i]);

        // keep track of string with smallest distance
        if(distance < min_distance) {
            min_idx = i;
            min_distance = distance;
        }
    }

    // return string in dictionary with smallest distance
    return command_dict[min_idx];
}

/**
 * Calculate Damerau Levenshtein Distance between strings
 * 
 * @param source String to compare to target
 * @param target String to compare to source
 * @return Damerau Levenshtein Distance between source and target
 */
static int calculate_damerau_levenshtein(char *source, char *target) {
    // Levenshtein 2D matrix is one row/col larger than string len
    int source_len = strlen(source) + 1;
    int target_len = strlen(target) + 1;
    int matrix[source_len][target_len];

    // populate first row and col with incrementing vals from 0 (base cases)
    for(int x = 0; x < source_len; x++) {
        matrix[x][0] = x;
    }
    for(int y = 0; y < target_len; y++) {
        matrix[0][y] = y;
    }
    
    // compare each letter in strings
    for(int x = 1; x < source_len; x++) {
        for(int y = 1; y < target_len; y++) {
            // minimum operation value to add to matrix
            int min_operation = -1;

            // 1 - insertion
            int insertion = matrix[x-1][y] + 1;
            min_operation = insertion;

            // 2 - deletion
            int deletion = matrix[x][y-1] + 1;
            if(deletion < min_operation) {
                min_operation = deletion;
            }

            // 3 - substitution
            int sub_add = source[x - 1] == target[y - 1] ? 0 : 1;
            int substitution = matrix[x-1][y-1] + sub_add;
            if(substitution < min_operation) {
                min_operation = substitution;
            }

            // 4 - transposition
            if(x > 1 && y > 1) {
                int transpose = matrix[x-2][y-2] + 1;
                if(transpose < min_operation) {
                    min_operation = transpose;
                }
            }

            // assign minimum of 4 operations 
            matrix[x][y] = min_operation;
        }
    }
    
    // print out matrix for debugging
    if(debug) {
        int distance = matrix[source_len - 1][target_len - 1];
        printf("Source: %s Target: %s Distance: %d\n", source, target, distance);

        for(int x = 0; x < source_len; x++) {
            for(int y = 0; y < target_len; y++) {
                printf("%d  ", matrix[x][y]);
            }
            printf("\n");
        }
    }

    // return Levenshtein Distance which is bottom right element in matrix
    return matrix[source_len - 1][target_len - 1];
}

// int main(int argc, char *argv[]) {
//     if(argc <= 1) {
//         printf("Usage: ./a.out <source_string>\n");
//         return 0;
//     }

//     char *source = argv[1];
//     char *suggestion = damerau_levenshtein_distance(source);

//     printf("You entered: %s Did you mean: %s?\n", source, suggestion);
// }