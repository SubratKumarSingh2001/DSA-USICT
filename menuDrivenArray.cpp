#include <iostream>
using namespace std;

void displayArray(int arr[10], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

void traverseArray(int arr[10], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

void linearSearch(int arr[10], int key, int size) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key) {
            cout<< "Key found at index : " <<i<<endl;
            return;
        }
    }
    cout<<"The key not found in the array. \n";
}

int binarySearch(int arr[], int start, int end, int key) {
    if(start>end){
        return -1;
    }

    int mid  = start+(end-start)/2;
    if(arr[mid] == key) {
        return mid;
    }

    if(arr[mid] > key){
        return binarySearch(arr, start, mid-1, key);
    }

    else{
        return binarySearch(arr, mid+1, end, key);
    }
}

void insertionSort(int arr[10], int size) {
    for(int i=0; i<size-1; i++) {
        int value = arr[i];
        int j = i-1;
        while(j>=0) {
            if(arr[j] > value) {
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1] = value;
    }
    for(int i=0; i<size; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}

void insertElements(int arr[10], int size) {
    int position;
    cout<<"Enter the position where you want to add element : "; cin>>position;
    
    //invalid index
    if(position > 10) {
        cout<<"Invalid Index. Can't insert new element \n";
        return;
    }
    else if(position > (size+1)) {
        cout<<"Invalid Index. Can't insert new element \n";
        return;
    }
    else if(size >= 10) {
        cout<<"Array is full. Cannot insert new Elements \n";
        return;
    }
    
    else {
        int ele;
        cout<<"Enter the element that needed to be insert : "; cin>>ele;
 
        //beginning
        if(position == 1) {
            for(int i=size-1; i>=0; i--) {
                arr[i+1] = arr[i];
            }
            arr[0] = ele;
            size++;
        }

        //end
        else if(position == size+1) {
            arr[position-1] = ele;
            size++; // size ko increase kr rhe hai taki element sare show kare
        }

        //particular place;
        else {
            size++;
            for(int i=size; i>=position-1; i--) {
                arr[i] = arr[i-1];
            }
            arr[position-1] = ele;
        }
    }

    displayArray(arr, size);
}

void deleteElements(int arr[10], int size) {
    int pos;
    cout<<"Enter the position of element you want to delete : ";cin>>pos;

    if(pos > size) {
        cout<<"Invalid index. Can't delete the element. \n";
    }

    //beginning
    if(pos == 1) {
        for(int i=0; i<size; i++) {
            arr[i] = arr[i+1];
        }
        size--; //because aab 1 ele delete ho chuka hai to size kam ho jyega
    }

    //end
    if(pos == size) {
        size--;
    }

    //at specific location
    if(pos>1 && pos<size) {
        for(int i=pos-1; i<size; i++) {
            arr[i] = arr[i+1];
        }
        size--; // isme particular position delete hone ke baad ele ke aage shift krna hai then size kam krna
    }

    displayArray(arr, size);
}

int main() {

    int choice, key, start, end, value;

    do{
        cout<<"<------------X-------------> \n";
        cout<<"Enter 1 for array traversal. \n";
        cout<<"Enter 2 for linear search is array. \n";
        cout<<"Enter 3 for binary search in an array. \n";
        cout<<"Enter 4 for sorting an array through Insertion Sort. \n";
        cout<<"Enter 5 for inserting an element in an array. \n";
        cout<<"Enter 6 for deletion of an element in an array. \n";
        cout<<"<------------X-------------> \n";

        int arr[10], size;
        cout<<"Enter the size of an array : "; cin>>size;
        for(int i=0; i<size; i++) {
            cin >> arr[i];
        }

        cout<<"Enter the choice : "; cin>>choice;
        if(choice != 1 && choice !=2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && 
        choice !=7) {
            cout<<"Enter valid choice. \n";
        }
        else {
            switch (choice) {
                case 1:
                    cout<<"The array is : \n";
                    traverseArray(arr, size);
                    break;
                case 2:
                    cout<<"Enter the key need to find : ";cin>>key;
                    linearSearch(arr, key, size);
                    break;
                case 3:
                    start = 0, end = size;
                    cout<<"Enter the key need to find : ";cin>>key;
                    value = binarySearch(arr, start, end, key);
                    cout<<"The key found at index : " << value <<endl;
                    break;
                case 4:
                    insertionSort(arr, size);
                    break;
                case 5:
                    insertElements(arr, size);
                    break;
                case 6:
                    deleteElements(arr, size);
                    break;
                case 7:
                    cout<<"Program Exist";
            }
        }
    } while(choice !=7);
    
}