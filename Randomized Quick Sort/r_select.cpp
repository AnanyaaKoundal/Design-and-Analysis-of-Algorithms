#include <iostream>
#include <ctime>
using namespace std;
int comp=0;
void swap(int *a, int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
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

int r_select(int *a, int p, int r, int i){
    if(p==r) return a[p];
    int q=RPartition(a,p,r);
    int k=q-p+1;
    if(i==k) return a[q];
    else if(i<k){
        return r_select(a,p,q-1,i);
    }else{
        return r_select(a,q+1, r, i-k);
    }
}

int main(){
    int a[]={5,4,3,2,1,8};
    cout<<"\n"<<r_select(a,0,5,9);
}