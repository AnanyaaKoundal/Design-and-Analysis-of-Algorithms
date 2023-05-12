#include <iostream>
using namespace std;

int insertionSort(int *a, int n){
    int count=0;
    for(int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && ++count && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return count;
}

/*int main()
{
    srand(time(0));
    int array[1000];
    int size, comparisons;
    cout << "| Input Size | No of Comparisons |\n";
    for (int i = 0; i < 100; i++)
    {
        size = rand() % 971 + 30;

        cout << "| " << setw(10) << size;

        for (int i = 0; i < size; i++)
            array[i] =rand()%100;
        comparisons = insertionSort(array, size);
        cout << " | " << setw(9) << right << comparisons<<"\n";

    }
    return 0;
}
*/

// int n;
    // cout<<"\nEnter the size: ";
    // cin>>n;
    // int a[n];
    // cout<<"Enter the elements of the array: ";
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }
    // mergesort(a, 0, n);
    // cout<<"\nSorted array: ";
    // for(int i: a) cout<<i <<" ";
    // cout<<"\ncount: "<<count;
