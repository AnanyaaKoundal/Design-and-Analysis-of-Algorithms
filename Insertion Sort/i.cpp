#include <iostream>
using namespace std;

int insertion_sort(int *a, int n){
    int count=0;
    for(int i= 1; i<n; i++){
        int j=i-1;
        int key= a[i];
        while(j>=0 && ++count && a[j]>key){
            a[j+1]= a[j];
            j--;
        }
        a[j+1]= key;

    }
    return count;
}

int main(){
    int n=5;
    int a[]= {5,4,3,2,1};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    cout<<"\n"<<insertion_sort(a, n);
    cout<<"\nSorted array: ";
    for(int i: a) cout<<i <<" ";
}