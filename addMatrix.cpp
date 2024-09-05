#include <iostream>
using namespace std;

void sumArray(int drr[][10], int err[][10], int rows, int cols) {
    int sum[10][10];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum[i][j] = drr[i][j] + err[i][j];
        }
    }

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << sum[i][j] << " ";
        }
        cout<<endl;
    }
}

void printArray(int crr[][10], int rows , int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<< crr[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main() {
    int rows1, cols1,rows2, cols2, arr[10][10], brr[10][10];
    cout<<"Enter the number of rows1 : "; cin>>rows1;
    cout<<"Enter the number of columns1 : "; cin>>cols1;
    cout<<"Enter the number of rows2 : "; cin>>rows2;
    cout<<"Enter the number of columns2 : "; cin>>cols2;

    if(rows1 != rows2 || cols1 != cols2) {
        cout<<"2D Matrix addition is not possible as rows and cols of matrices are not same. \n";
    }

    // for array arr
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols1; j++) {
            cin >> arr[i][j];
        }
        cout<<endl;
    }
    printArray(arr, rows1, cols1);
            
    //for array brr
    for(int i=0; i<rows2; i++) {
        for(int j=0; j<cols2; j++) {
            cin >> brr[i][j];
        }
        cout<<endl;
    }
    printArray(brr, rows2, cols2);
    cout<<endl;
    /* here we can pass either rows1 or rows2 or cols1 or cols2 because if rows and cols are same
       then addition could be possible without any hesitation
    */
    sumArray(arr, brr, rows1, cols1);

    return 0;
}