#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

void displayArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void displayArrayFloat(float arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

//<--------------------------------------------Heap Sort------------------------------------>
void heapify(int arr[], int size, int root) {
    int largest = root;  // Initialize largest as root
    int left = 2 * root + 1;  // Left child index
    int right = 2 * root + 2;  // Right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // One by one extract elements from the heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }

    displayArray(arr, size);
}


//<-------------------------------------------Count Sort------------------------------------>

void countSort(int arr[], int size) {
    //find the max element in an array
    int max = INT_MIN;
    for(int i=0; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    //create a frequency array of size count+1
    int freqArr[max+1];
    for(int i=0; i<max+1; i++) {
        freqArr[i] = 0;
    }
    for(int i=0; i<size; i++) {
        freqArr[arr[i]]++; 
    }

    //create a cumulative frequency 
    for(int i=1; i<max+1; i++) {
        freqArr[i] = freqArr[i] + freqArr[i-1];
    }

    //create a ans array which will store the stored array
    int ans[size];
    for(int i=size-1; i>=0; i--) {
        ans[--freqArr[arr[i]]] = arr[i];
    }

    //copy to original array
    for( int i=0; i<size; i++) {
        arr[i] = ans[i];
    }

    displayArray(arr, size);
}

//<------------------------------------------Radix Sort------------------------------------->

void countSortForRadix(int arr[], int size, int pos) {
    //skip the maximum ele find part done in radix sort, as every single digit range for 0-9 so create freq arr of size 10
    int freqArr[10];
    for(int i=0; i<10; i++) {
        freqArr[i] = 0;
    }
    for(int i=0; i<size; i++) {
        freqArr[(arr[i]/pos)%10]++;
    }

    //cumulative frequency
    for(int i=1; i<10; i++) {
        freqArr[i] = freqArr[i] + freqArr[i-1];
    }

    //ans array create
    int ans[size];
    for(int i=size-1; i>=0; i--){
        ans[--freqArr[(arr[i]/pos)%10]] = arr[i];
    }

    //copy to original
    for(int i=0; i<size; i++) {
        arr[i] = ans[i];
    }
}

void radixSort(int arr[], int size) {
    //first for how many times loop run, we need to find the maximum element
    int max = INT_MIN;
    for(int i=0; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    //sorting the individual digits of all elements present in an array
    for(int pos=1; (max/pos)>0; pos*=10) {
        countSortForRadix(arr, size, pos);
    }

    displayArray(arr, size);
}


//<-----------------------------------------Bucket Sort------------------------------------->

void bucketSort(float arr[], int size) {
    //first create a bucket of size of an array, each bucket can have multiple value basically 2D array
    float bucket[20][20];
    int bucketCount[20] = {0}; // to check the number of elements in each bucket useful for sorting, 1D Array index accessing

    //now insert the element into the bucket
    for(int i=0; i<size; i++) {
        int index = arr[i] * size;
        bucket[index][bucketCount[index]++] = arr[i];
    }

    //sorting the individual bucket 
    for(int i=0; i<size; i++) {
        if(bucketCount[i] > 0) {
            sort(bucket[i], bucket[i]+ bucketCount[i]);
        }
    }

    //add every bucket element to original array
    int k = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<bucketCount[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }

    displayArrayFloat(arr, size);

}

int main() {
    int choice, size;

    do {
        cout<<"<--------------------x--------------> \n";
        cout<<"Enter 1 to Implement the Heap Sort. \n";
        cout<<"Enter 2 to Implement the Count Sort. \n";
        cout<<"Enter 3 to Implement Radix Sort. \n";
        cout<<"Enter 4 to Implement Bucket Sort. \n";
        cout<<"Enter 5 to Exist to Program. \n";
        cout<<"<--------------------x--------------> \n";

        cout<<"Enter the choice : ";cin>>choice;
        switch(choice) {
            case 1: {
                int arr[20];
                cout<<"Enter the size of an array : ";cin>>size;
                for(int i=0; i<size; i++) {
                    cin>>arr[i];
                }
                heapSort(arr,size);
                break;
            }
            case 2: {
                int arr[20];
                cout<<"Enter the size of an array : ";cin>>size;
                for(int i=0; i<size; i++) {
                    cin>>arr[i];
                }
                countSort(arr, size);
                break;
            }
            case 3: {
                int arr[20];
                cout<<"Enter the size of an array : ";cin>>size;
                for(int i=0; i<size; i++) {
                    cin>>arr[i];
                }
                radixSort(arr, size);
                break;
            }
            case 4: {
                float arr[20];
                cout<<"Enter the size of an array :";cin>>size;
                for(int i=0; i<size; i++) {
                    cin>>arr[i];
                }
                bucketSort(arr, size);
                break;
            }
            case 5: 
                cout<<"Program Exist....\n";
                break;
            default :
                cout<<"Invalid Choice. Enter the valid choice. \n";
        }
    }while(choice != 5);
}