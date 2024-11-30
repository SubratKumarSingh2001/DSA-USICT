#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// Structure to store the LCS table
struct LCS_Table {
    int rows, cols;
    int** table;
};

// Function to create and initialize the LCS table
LCS_Table* createLCS_Table(int m, int n) {
    LCS_Table* lcs_table = (LCS_Table*)malloc(sizeof(LCS_Table));
    lcs_table->rows = m + 1;
    lcs_table->cols = n + 1;

    // Allocate memory for the table
    lcs_table->table = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        lcs_table->table[i] = (int*)malloc((n + 1) * sizeof(int));
        memset(lcs_table->table[i], 0, (n + 1) * sizeof(int));  // Initialize to 0
    }
    return lcs_table;
}

// Function to compute LCS using dynamic programming
int computeLCS(LCS_Table* lcs_table, const char* X, const char* Y) {
    int m = lcs_table->rows - 1;
    int n = lcs_table->cols - 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                lcs_table->table[i][j] = lcs_table->table[i - 1][j - 1] + 1;
            else
                lcs_table->table[i][j] = max(lcs_table->table[i - 1][j], lcs_table->table[i][j - 1]);
        }
    }
    return lcs_table->table[m][n];
}

// Function to retrieve the LCS sequence from the table
void retrieveLCS(LCS_Table* lcs_table, const char* X, const char* Y) {
    int m = lcs_table->rows - 1;
    int n = lcs_table->cols - 1;
    int index = lcs_table->table[m][n];

    char* lcs = (char*)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lcs_table->table[i - 1][j] > lcs_table->table[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
    free(lcs);
}

// Function to free the LCS table
void freeLCS_Table(LCS_Table* lcs_table) {
    for (int i = 0; i < lcs_table->rows; i++) {
        free(lcs_table->table[i]);
    }
    free(lcs_table->table);
    free(lcs_table);
}

int main() {
    const char* X = "ABCBDAB";
    const char* Y = "BDCAB";

    int m = strlen(X);
    int n = strlen(Y);

    LCS_Table* lcs_table = createLCS_Table(m, n);

    int lcs_length = computeLCS(lcs_table, X, Y);
    cout << "Length of LCS: " << lcs_length << endl;

    retrieveLCS(lcs_table, X, Y);

    freeLCS_Table(lcs_table);
    return 0;
}
