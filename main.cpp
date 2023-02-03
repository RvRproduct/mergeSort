#include <iostream>

using namespace std;

// merge sort sorting algorithm

void mergeSort(int arr[], const int size, int l, int r);
void merge(int arr[], const int size, int l, int m, int r);

// merge function
void merge(int arr[], const int size, int l, int m, int r) {
    
    // acting like pointers
    int i = l; // starting index for left subarray
    int j = m + 1; // starting index for right subarray
    int k = l; // starting index for temporary
    
    int temp[size]; // temporary
    
    while(i <= m && j <= r) {
        
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i]; // arr[i] is smaller than arr[j]
            i++;
            k++;
        }
        else {
            temp[k] = arr[j]; // arr[j] is smaller than arr[i]
            j++;
            k++;
        }
    }
    
    while(i <= m) {
        temp[k] = arr[i]; // copying all elements from left subarray to temp as it is
        i++;
        k++;
    }
    
    while(j <= r) {
        temp[k] = arr[j]; // copying all elements from right subarray to temp as it is
        j++;
        k++;
    }
    
    for(int s = l; s <= r; s++) {
        arr[s] = temp[s];
    }
}

// merge sort function
void mergeSort(int arr[], const int size, int l, int r) {
    
    if(l<r) {
        int m = (l+r) / 2;
        mergeSort(arr, size, l, m);
        mergeSort(arr, size, m + 1, r);
        merge(arr, size, l, m, r);
    }
}


int main(){
    
    // int myarr[5] = {4, 6, 1, 2, 7};
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    
    int myarr[size];
    cout << "Enter " << size << " no of elements in the array: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> myarr[i];
    }
    
    cout << "Before Merge Sort: " << endl;
    for(int i = 0; i < size; i++) {
        cout << myarr[i] << " ";
    }
    
    cout << endl;
    // mergesort function
    mergeSort(myarr, size, 0, (size - 1));
    
    cout << "After Merge Sort: " << endl;
    for(int i = 0; i < size; i++) {
        cout << myarr[i] << " ";
    }
    
    cout << endl;
    return 0;
}