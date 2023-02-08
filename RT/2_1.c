// Otazka: Napiste funkciu vypis spirala, ktora dostane na vstupe maticu velkosti n X m a vypise ju po spirale

// Odpoved: 

void vypis_spiralu(int **matrix, int rows, int cols) {
    int row_start = 0;
    int col_start = 0;
    int row_end = rows - 1;
    int col_end = cols - 1;

    while (row_start <= row_end && col_start <= col_end) {
        
        for (int current_col = col_start; current_col <= col_end; current_col++) {
            printf("%d ", matrix[row_start][current_col]);
        }
        row_start++;

        for (int current_row = row_start; current_row <= row_end; current_row++) {
            printf("%d ", matrix[current_row][col_end]);
        }
        col_end--;

        if (row_start <= row_end) {
            for (int current_col = col_end; current_col >= col_start; current_col--) {
                printf("%d ", matrix[row_end][current_col]);
            }
            row_end--;
        }

        if (col_start <= col_end) {
            for (int current_row = row_end; current_row >= row_start; current_row--) {
                printf("%d ", matrix[current_row][col_start]);
            }
            col_start++;
        }
    }
}
