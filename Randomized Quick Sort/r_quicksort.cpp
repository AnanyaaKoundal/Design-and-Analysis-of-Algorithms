#include <iostream>
#include <ctime>
using namespace std;
int comp = 0;
void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int *a, int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a, i, j);
            comp++;
        }
    }
    swap(a, i + 1, h);
    comp++;
    return (i + 1);
}

int RPartition(int *arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    comp++;
    return partition(arr, low, high);
}

void quicksort(int *a, int l, int h)
{
    int p;
    if (l < h)
    {
        p = RPartition(a, l, h);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, h);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    quicksort(a, 0, 4);
    for (int i = 0; i <5; i++)
        cout << a[i] << " ";
        cout<<endl<<comp;
}