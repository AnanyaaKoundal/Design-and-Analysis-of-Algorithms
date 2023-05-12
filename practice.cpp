#include <iostream>
#include <ctime>
using namespace std;
int count=0;

int swap(int *a, int i, int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int partition(int *a, int l, int h){
    int pivot=a[h];
    int i=l-1;
    for(int j=l; j<=h-1; j++){
        if(a[j]<=pivot){
            i++;
            swap(a,i,j);
            count++;
        }
    }
    swap(a, i+1, h);
    count++;
    return i+1;
}

int rp(int *a, int l, int h){
    srand(time(NULL));
    int r=l+rand()%(h-l);
    swap(a, r,h);
    count++;
    return partition(a,l,h);
}

int quicksort(int *a, int l, int h){
    int p;
    if(l<h){
        p=rp(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1, h);
    }
}

int main(){
    int n=5;
    int a[]= {5,4,3,2,1};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    quicksort(a,0,n-1);
    cout<<"\nSorted array: ";
    for(int i: a) cout<<i <<" ";
    cout<<"\ncount: "<<count;
}