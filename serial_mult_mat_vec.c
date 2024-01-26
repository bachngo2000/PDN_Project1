#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
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

    // check to see if the number of columns in the matrix equals the number of rows in the vector
    if (n_col1 != n_row2) {
        printf("Matrix-vector multiplication cannot be performed since the number of columns in the matrix does not equal the number of rows in the vector ");
        return EXIT_FAILURE;
    }

    // Allocate a 1D array to store all the elements in the matrix
    long int* matrix_array = (long int*)malloc((n_row1 * n_col1) * sizeof(long int));

    // Allocate a 1D array to store all the elements in the 1-column vector
    long int* vector_array = (long int*)malloc((n_row1 * n_col1) * sizeof(long int));

    // Allocate a 1D array to store the output vectors
    long int* output_array = (long int*)malloc((n_row1 * n_col1) * sizeof(long int));

    // TODO: Parse the input CSV files

    // read in the in_mat.csv file where the input matrix is stored and write the values into the matrix_array
    // define a string with the size of the number of columns to store the content of a row in the matrix file
    char matrix_row[1000];
    long int index = 0;

    while (feof(matFile) != true) {
        fgets(matrix_row, 1000, matFile);
        // returns first token
        char *token = strtok(matrix_row, ",");

        while (token != NULL && index < (n_row1 * n_col1)) {
            matrix_array[index] = atoi(token);
            index++;
            token = strtok(NULL, ",");
        }
    }

    // read in the in_vec.csv file where the single-column vector is stored and write the values into the vector_array
    // define a string with the size of the number of columns to store the content of a row in the matrix file
    char vec_row[100];
    while (fgets(vec_row, 100, vecFile)) {
        vector_array[index] = atoi(vec_row);
        index++;
    }
    
    // TODO: Perform the matrix-vector multiplication
    long int x = 0;
    long int i = 0;
    for (i = 0; i < n_row1*n_col1; i++) {
        long int ans = 0;
        long int j = 0;
        for (j = 0; j < n_row2; j++) {
            ans = ans + matrix_array[i] * vector_array[j];
            if (j != n_row2 - 1) {
                i = i + 1;
            }
        }
        output_array[x] = ans;
        x++;
    }   

    // TODO: Write the output CSV file
    long int y = 0;
    for (y = 0; y < n_row1; y++) {
        fprintf(outputFile, "%ld\n", output_array[y]);
    }

    // TODO: Free memory
    free(matrix_array);
    free(vector_array);
    free(output_array);

    // Cleanup
    fclose (matFile);
    fclose (vecFile);
    fclose (outputFile);
    // Free buffers here as well!

    return 0;
}
