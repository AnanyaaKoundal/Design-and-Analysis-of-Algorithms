#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
int count=0;
#define MIN_SIZE 30
#define MAX_SIZE 1000

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
    int a[]= {5,4,3,2,1};
    cout<<"Unsorted array: ";
    for(int i: a) cout<<i <<" ";
    mergesort(a, 0, n);
    cout<<"\nSorted array: ";
    for(int i: a) cout<<i <<" ";
    cout<<"\ncount: "<<count;
    //  try
    // {
    //     srand(time(0));

    //     int array[MAX_SIZE];
    //     int size, count;

    //     ofstream fout("./results.csv");

    //     cout << "+------------------------------------------------+\n";
    //     cout << "| Input Size | Best Case | Avg Case | Worst Case |\n";
    //     cout << "+------------------------------------------------+\n";

    //     fout << "size,best,avg,worst\n";

    //     for (int i = 0; i < 100; i++)
    //     {
    //         count=0;
    //         // rand() % (upperBound + 1 - lowerBound) + lowerBound
    //         size = rand() % (MAX_SIZE + 1 - MIN_SIZE) + MIN_SIZE;

    //         // Input Size
    //         cout << "| " << setw(10) << size;
    //         fout << size << ",";

    //         // Best Case
    //         for (int i = 0; i < size; i++)
    //             array[i] = i + 1;
    //         mergesort(array, 0, size);
    //         cout << " | " << setw(9) << right << count;
    //         fout << count << ",";

    //         // Average Case
    //         try
    //         {
    //             ifstream fin("./random.txt");
    //             for (int i = 0; i < size; i++)
    //                 fin >> array[i];
    //             fin.close();
    //             mergesort(array, 0, size);
    //             cout << " | " << setw(8) << right << count;
    //             fout << count << ",";
    //         }
    //         catch (exception e)
    //         {
    //             cerr << e.what();
    //             return -1;
    //         }

    //         // Worst Case
    //         for (int i = 0; i < size; i++)
    //             array[i] = size - i;
    //         mergesort(array,0, size);
    //         cout << " | " << setw(10) << right << count << " |\n";
    //         fout << count << "\n";
    //     }

    //     cout << "+------------------------------------------------+\n\n";

    //     fout.close();

    //     return 0;
    // }
    // catch (exception e)
    // {
    //     cerr << e.what();
    //     return -1;
    // }
}