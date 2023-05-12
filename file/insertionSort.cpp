#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
int count=0;
void insertionSort(int *a, int n){
    for(int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && ++count && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n=5;
    int a[]= {6,3,8,1,4};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    insertionSort(a, n);
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
        insertionSort(array, size);
        cout << " | " << setw(9) << right << count<<"|\n";

    }
   
    return 0;
}
