#include<iostream>
using namespace std;
void swap(int *p, int *g){
  int aux = *p;
  *p = *g;
  *g = aux;
}
void bubsort(int arr[], int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j],&arr[j+1]);
      }
    }
  }
}
int main(){
  int arr[]={64,34,25,12,22,11,90};
  int n=sizeof(arr)/sizeof(arr[0]);
  bubsort(arr,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" "<<endl;
  }
}
