#include <iostream>
using namespace std;

void displayMatrix(int matrix[][10], int rows, int cols) {
    cout<<"Display Original Matrix \n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<< matrix[i][j] <<" ";
        }
        cout<<endl;
    }
}

int countElements(int matrix[][10], int rows, int cols) {
    int count=0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void createSparseMatrix(int sparse[][3], int matrix[][10], int rows, int cols, int nonZeroEle) {
    //first row of sparse matrix for no of rows, cols and non zero element

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZeroEle;

    // first we will check all elements in original matrix
    int k=1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(matrix[i][j] != 0) {
                //insert the element in sparse from 2nd row
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
}

void displaySparseMatrix(int sparse[][3], int nonZeroEle, int rows, int cols){
    cout<<"Sparse Matrix is \n";
    for(int i=0; i<nonZeroEle+1; i++) {
        cout<< sparse[i][0] <<" " <<sparse[i][1] <<" "<<sparse[i][2]<<endl;
    }
}

int main() {
    int rows, cols;
    cout<<"Enter the number of rows : ";cin>>rows;
    cout<<"Enter the number of columns : ";cin>>cols;
    
    int matrix[10][10];

    //input matrix
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin>>matrix[i][j];
        }
    }
    displayMatrix(matrix, rows, cols);

    /* 
    first find the non zero elements in original matrix bcz sparse matrix can only be formed if there 
    are atleast 1 non zero elements.
    */
   
    int nonZeroEle = countElements(matrix, rows, cols);
    cout<<"No. of non zero elemets in original matrix are : " << nonZeroEle<<endl;

    if(nonZeroEle > (rows*cols/4)) {
        cout<<"Sparse Matrix can't be formed \n";
        return 0;
    }
    else if(nonZeroEle == 0) {
        cout<<"Sparse matrix can't be formed as there is unavailability of non zero elements. \n";
        return 0;
    }
        
    int sparse[nonZeroEle+1][3]; // to tell ki hame kitne dimension ka sparse matrix banana hai
    createSparseMatrix(sparse, matrix, rows, cols, nonZeroEle);
    displaySparseMatrix(sparse, nonZeroEle, rows, cols);

}