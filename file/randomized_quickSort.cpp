#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
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
    cout<<"\ncount: "<<count<<"\n\n\n";

    cout<<"For 100 different size arrays\n\n";

     srand(time(0));
    int array[1000];
    int size, Count;
    cout << "| Input Size | Comparisons |\n";
    for (int i = 0; i < 100; i++)
    {
        size = rand() % 971 + 30;

        cout << "| " << setw(10) << size;

        for (int i = 0; i < size; i++)
            array[i] =rand()%100;
        quicksort(array, 0, size-1);
        cout << " | " << setw(9) << right << count<<"|\n";

    }
   
    return 0;
}