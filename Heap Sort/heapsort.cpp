#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

#define MIN_SIZE 30
#define MAX_SIZE 1000

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
    int a[]={5,7,2,1,9,6};
    heapsort(a,5);
    for(int i=0; i<6; i++) cout<<a[i]<<" ";
     try
    {
        srand(time(0));

        int array[MAX_SIZE];
        int size, comparisons;

        ofstream fout("./results.csv");

        cout << "+------------------------------------------------+\n";
        cout << "| Input Size | Best Case | Avg Case | Worst Case |\n";
        cout << "+------------------------------------------------+\n";

        fout << "size,best,avg,worst\n";

        for (int i = 0; i < 100; i++)
        {
            // rand() % (upperBound + 1 - lowerBound) + lowerBound
            size = rand() % (MAX_SIZE + 1 - MIN_SIZE) + MIN_SIZE;

            // Input Size
            cout << "| " << setw(10) << size;
            fout << size << ",";

            // Best Case
            for (int i = 0; i < size; i++)
                array[i] = i + 1;
            comparisons = heapsort(array, size);
            cout << " | " << setw(9) << right << comparisons;
            fout << comparisons << ",";

            // Average Case
            try
            {
                ifstream fin("./random.txt");
                for (int i = 0; i < size; i++)
                    fin >> array[i];
                fin.close();
                comparisons = heapsort(array, size);
                cout << " | " << setw(8) << right << comparisons;
                fout << comparisons << ",";
            }
            catch (exception e)
            {
                cerr << e.what();
                return -1;
            }

            // Worst Case
            for (int i = 0; i < size; i++)
                array[i] = size - i;
            comparisons = heapsort(array, size);
            cout << " | " << setw(10) << right << comparisons << " |\n";
            fout << comparisons << "\n";
        }

        cout << "+------------------------------------------------+\n\n";

        fout.close();

        return 0;
    }
    catch (exception e)
    {
        cerr << e.what();
        return -1;
    }
}