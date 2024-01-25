#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
// Use more libraries as necessary

#define DEBUG 0

/* ---------- Project 1 - Problem 2 - Mat-Vec Mult ----------
    This file will multiply a matrix and vector.
    Complete the TODOs left in this file.
*/ // ------------------------------------------------------ //


int main (int argc, char *argv[])
{
    // Catch console errors
    if( argc != 7)
    {
        printf("USE LIKE THIS: serial_mult_mat_vec in_mat.csv n_row_1 n_col_1 in_vec.csv n_row_2 output_file.csv \n");
        return EXIT_FAILURE;
    }

    // Get the input files
    FILE *matFile = fopen(argv[1], "r");
    FILE *vecFile = fopen(argv[4], "r");

    // Get dim of the matrix
    char* p1;
    char* p2;
    long int n_row1 = strtol(argv[2], &p1, 10 );
    long int n_col1 = strtol(argv[3], &p2, 10 );

    // Get dim of the vector
    char* p3;
    long int n_row2 = strtol(argv[5], &p3, 10 );

    // Get the output file
    FILE *outputFile = fopen(argv[6], "w");


    // TODO: Use malloc to allocate memory for the matrices
     
    // Allocate a 1D array to store all the elements in the matrix
    long int* matrix_array = (long int*)malloc((n_row1 * n_col1) * sizeof(long int));

    // Allocate a 1D array to store all the elements in the vector
    long int* vector_array = (long int*)malloc(n_row2 * sizeof(long int));


    // TODO: Parse the input CSV files

    // read in the in_mat.csv file and write the values into the matrix_array
    // define a string with the size of the number of columns to store the content of a row in the matrix file
    char matrix_row[n_col1];
    long int index = 0;

    while (feof(matFile) != true) {
        fgets(matrix_row, n_col_1, matFile);
        // returns first token
        char *token = strtok(matrix_row, ",");

        while (token != NULL) {
            matrix_array[index] = atoi(token);
            index++;
            token = strtok(NULL, ",");
        }
    }

    // read in the in_vec.csv file and write the values into the vector_array
    // define a string with the size of the number of columns to store the content of a row in the matrix file
    char vec_row[1];
    while (feof(vecFile) != true) {
        fgets(vec_row, 1, vecFile);
        // returns first token
        char *token = strtok(vec_row, ",");

        while (token != NULL) {
            vector_array[index] = atoi(token);
            index++;
            token = strtok(NULL, ",");
        }
    }

    // TODO: Perform the matrix-vector multiplication
    // ex: matrix_array = [1, -1, 2, 0, -3, 1] // size = 6
    // ex: vector_array = [2, 1, 0] // size = 3
    long int* output_array = (long int*)malloc(n_row1 * sizeof(long int));
    long int ans = 0;

    for (long int i = 0; i < n_row2; i++) {
        ans = ans + matrix_array[i] * vector_array[i]; 
    }

    // TODO: Write the output CSV file

    // TODO: Free memory

    // Cleanup
    fclose (matFile);
    fclose (vecFile);
    fclose (outputFile);
    // Free buffers here as well!

    return 0;
}
