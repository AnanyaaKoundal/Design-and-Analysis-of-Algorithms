#include <iostream>
using namespace std;

int counting_sort(int *a, int n, int p){
    int c[10]={0};
    int ans[n+1];
    for(int i=0; i<n; i++){
        c[(a[i]/p)%10]++;
    }
    for(int i=1; i<10; i++){
        c[i]=c[i]+c[i-1];
    }
    for(int j=n-1; j>=0; j--){
        ans[c[(a[j]/p)%10]-1]= a[j];
        c[(a[j]/p)%10]--;
    }
    for(int i=0; i<n; i++){
        a[i]=ans[i];
    }
}

int getMax(int *a, int n){
    int m=a[0];
    for(int i=1; i<n; i++){
        if(a[i]>m) m=a[i];
    }
    return m;
}

void radixsort(int *a, int n){
    int m= getMax(a,n);
    for(int p=1; m/p > 0; p*=10)
        counting_sort(a,n,p);
}

int main(){
    int a[]={171, 279, 380, 111, 135, 726, 504, 878, 112};
    int n = sizeof(a) / sizeof(a[0]);
    radixsort(a,n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}