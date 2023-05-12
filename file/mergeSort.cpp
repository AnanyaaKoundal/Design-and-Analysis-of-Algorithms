#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
int count=0;

void merge(int *a, int l, int mid, int h){
    int n1= mid-l+1;
    int n2=h-mid;
    int L[n1], R[n2];
    for  (int i=0; i<n1; i++) L[i]=a[l+i];
    for  (int i=0; i<n2; i++) R[i]=a[mid+i+1];
    int i=0, j=0, k= l;
    while(i<n1 && j<n2){
        count++;
        if(L[i]<R[j]){ 
            a[k] = L[i];
            k++;
            i++;
        }
        else  {
            a[k] = R[j];
            k++;
            j++;
        }
    }
    while(i<n1){ 
        a[k] = L[i];
        k++;
        i++;
    }
    while(j<n2) {
        a[k] = R[j];
        k++;
        j++;
    }
    
}
void mergesort(int *a, int l, int h){
    count++;
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a, l, mid);
        mergesort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}
int main(){
    int n=5;
    int a[]= {6,3,8,1,4};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    mergesort(a, 0, n);
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
        mergesort(array, 0, size);
        cout << " | " << setw(9) << right << count<<"|\n";

    }
   
    return 0;

}