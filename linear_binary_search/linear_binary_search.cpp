#include <iostream>
using namespace std;
class Exception{
public:
    int code;
    char* name;
Exception(int code, char * name){
    this->code=code;
    this->name=name;
}
};
int linearSearch(int* arr, int num) {
    for (int i = 0; i < 5; i++) {
        if (arr[i] == num) {
            return i; }}
    Exception e(102,"Element not found in the array ^_^ ");
    throw e;
}
int linearSearchall(int* arr, int num, int* index,int &count) {
    count = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == num) {
            index[count] = i;
            count++; }}
    return count;
}
int binarySearch(int arr[], int size, int num) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {

        int mid = (start + end)/ 2;
        if (arr[mid] == num) {return mid; }
        if (arr[mid] < num) { start = mid + 1; }
        else { end = mid - 1;  }
    }
    return -1;
}
int main() {
    int arr1[5] = {3, 4, 10, 6, 2};
    int res1=linearSearch(arr1, 6);
    cout << "Element found at index " << res1 << endl;
    try { linearSearch(arr1, 8); }
    catch (Exception & e){ cout << "Exception caught: " << e.name << endl;}

    cout<<"-------------------------------------------"<<endl;

    int arr2[5] = {3, 6, 10, 6, 2};
    int index[5];
    int count=0;
    int c=linearSearchall(arr2, 6,index ,count);
    cout << "Element found at index: ";
    for (int i = 0; i < count; i++) {
        cout << index[i] << " ";}
    cout<<endl;
    cout<<endl;

    cout<<"*************************************************************************"<<endl;

    cout<<endl;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int index1 = binarySearch(arr,8,70);
    if (index1 != -1) {cout << "Element found at index " << index1 << "." << endl;}
    else {cout << "Element not found in the array" << endl;}

    cout<<"-------------------------------------------"<<endl;

    int index2 = binarySearch(arr,8,55);
    if (index2 != -1) {cout << "Element found at index " << index2 << "." << endl;}
    else {cout << "Element not found in the array" << endl;}
    cout<<endl;
    cout<<"*************************************************************************"<<endl;
    return 0;
}
