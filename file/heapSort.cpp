#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

void swap(int *a, int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int heapify(int*a, int n, int i){
    int largest=i, c=0;
    int l=2*i;
    int r=2*i+1;
    if(l<=n && a[l]>a[largest]){
        largest=l;
    }
    if(r<=n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        c++;
        swap(a,i,largest);
        c+=heapify(a,n,largest);
    }
    return c;
}

int buildheap(int *a, int n){
    int c=0;
    for(int i=n/2; i>=0; i--){
        c+=heapify(a,n,i);
    }
    return c;
}

int heapsort(int *a, int n){
    int c=0;
    c+=buildheap(a,n);
    for(int i=n; i>0;i--){
        swap(a,0,i);
        c+=heapify(a,i-1,0);
    }
    return c;
}

int main(){
    int n=5;
    int a[]= {6,3,8,1,4};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    int count= heapsort(a, n-1);
    cout<<"\nSorted array: ";
    for(int i: a) cout<<i <<" ";
    cout<<"\ncount: "<<count<<"\n\n\n";

    cout<<"For 100 different size arrays\n\n";

     srand(time(0));
    int array[1000];
    int size;
    cout << "| Input Size | Comparisons |\n";
    for (int i = 0; i < 100; i++)
    {
        size = rand() % 971 + 30;

        cout << "| " << setw(10) << size;

        for (int i = 0; i < size; i++)
            array[i] =rand()%100;
        count=heapsort(array,size-1);
        cout << " | " << setw(9) << right << count<<"|\n";

    }
   
    return 0;
}