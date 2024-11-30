#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

//<-----------------------------------------------------------Quick Sort------------------------------------------->

//partition logic 
int partition(int arr[], int start, int end) {
    int pivotIndex = start;
    int pivotElement = arr[start];
    
    int count=0;
    for(int i=start+1; i<=end; i++) {
        if(arr[i] <= pivotElement) {
            count++;
        }
    }
    int rightIndex = start+count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex; //now your pivotIndex is changes means we have to check the left and right of the pivotIndex

    int i=start, j=end;
    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] < pivotElement) {
            i++;
        }
        while(arr[j] > pivotElement) {
            j--;
        }
        //when left array has greater element than pivotElement then swap
        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    //base case single element is already sorted and start > end invalid case
    if(start >= end) {
        return;
    }

    //partition logic
    int pivotIndex = partition(arr, start, end); 

    //recursive call
    quickSort(arr, start, pivotIndex-1); //left array
    quickSort(arr, pivotIndex+1, end);

}

//<--------------------------------------------------------Merge Sort------------------------------------------->

void merge(int arr[], int start, int end) {
    int mid = (start + end)/2;

    //the length of left and right dynamic array which going to create
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    //copy the elements in left and right array
    int k = start;
    for(int i=0; i<len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0; i<len2; i++) {
        right[i] = arr[k];
        k++;
    }

    //now we have to merge the two sorted array
    int leftIndex = 0, rightIndex = 0, mainIndex = start;
    while(leftIndex < len1 && rightIndex < len2) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainIndex] = left[leftIndex];
            leftIndex++;
            mainIndex++;
        }
        else {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }

    //when any of array finish first
    while(leftIndex < len1) {
        arr[mainIndex] = left[leftIndex];
        mainIndex++;
        leftIndex++;
    }

    while(rightIndex < len2) {
        arr[mainIndex] = right[rightIndex];
        mainIndex++;
        rightIndex++;
    }

}

void mergeSort(int arr[], int start, int end) {
    //base case i.e single element in an array
    if(start >= end) {
        return;
    }

    int mid = (start + end)/2;

    //recursion for two divided arrays
    mergeSort(arr, start, mid); //left array
    mergeSort(arr, mid+1, end); //right array

    //merge the two sorted array when single element is left
    merge(arr, start, end);

}

int main() {
    int choice, size;
    int arr[20];

    //input taking for array
    cout<<"Enter the size of an array : ";cin>>size;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    do{
        cout<<"<----------------x-------------->\n";
        cout<<"Enter 1 to implement Quick Sort. \n";
        cout<<"Enter 2 to implement Merge Sort. \n";
        cout<<"Enter 3 to exist the program. \n";
        cout<<"<----------------x-------------->\n";

        cout<<"Enter the choice : ";cin>>choice;
        switch(choice) {
            case 1: {
                int start = 0;
                int end = size-1;
                quickSort(arr, start, end);
                displayArray(arr,size);
                break;
            }
            case 2: {
                int start = 0;
                int end = size-1;
                mergeSort(arr, start, end);
                displayArray(arr, size);
                break;
            }
            case 3:
                cout<<"Program Exist.. \n";
                break;
            default : 
                cout<<"Invalid choice....\n";
        }
    }while(choice != 3);
}