#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
void buble(int *arr,int len){
    bool swapp=true;
    int start=0;
    int endd=len-1;
    while(swapp){
        swapp=false;
        for(int j=start;j<endd;j++){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                swapp=true;
            }
        }
        if(!swapp){
            break;
        }
        swapp=false;
        --endd;
        for(int i=endd;i>=start;--i){
            if(arr[i]>arr[i+1]){
                int tmp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=tmp;
                swapp=true;
            }
        }
        start++;
        if(!swapp){
            break;
        }
    }
}
int main(){
    unsigned t0,t1;
    srand(time(NULL));
    int arr[10000];
    for(int i=0;i<10000;i++){
        arr[i]=rand()%10000;
    }
    t0=clock();
    buble(arr,10000);
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    for(int i=0;i<10000;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"Execution Time: " << time << endl;
    return 0;
}
