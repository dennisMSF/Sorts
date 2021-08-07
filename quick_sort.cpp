#include<iostream>
#include<ctime>
#include<string>
#include<stdlib.h>
using namespace std;
int divide(int *arr, int primero, int ultimo) {
    int left;
    int right;
    int pivot;
    int temp;
    pivot = *(arr+primero);
    left = primero;
    right = ultimo;
    while (left < right) {
        while (*(arr+right) > pivot) {
            right--;
        }
        while ((left < right) && (*(arr+left) <= pivot)) {
            left++;
        }
        if (left < right) {
            temp = *(arr+left);
            *(arr+left) = *(arr+right);
            *(arr+right) = temp;
        }
    }
    temp = *(arr+right);
    *(arr+right) = *(arr+primero);
    *(arr+primero) = temp;
    return right;
}
void quicksort(int *arr, int primero, int ultimo)
{
    int pivot;
    if (primero < ultimo) {
        pivot = divide(arr, primero, ultimo);
        quicksort(arr, primero, pivot - 1);
        quicksort(arr, pivot + 1, ultimo);
    }
}
int main(){
    unsigned t0,t1;
    srand(time(NULL));
    int arr[100000];
    for(int i=0;i<100000;i++){
        arr[i]=rand()%100000;
    }
    t0=clock();
    quicksort(arr,0,100000);
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    for(int i=0;i<100000;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Execution Time: " << time << endl;
    return 0;
}
