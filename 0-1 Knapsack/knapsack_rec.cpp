#include <iostream>
using namespace std;

int max(int a, int b){
    if(a> b) return a;
    return b;
}

int knapsack(int *wt, int *v, int n, int W){
    if(n==0 || W==0) return 0;
    if(W<wt[n-1]){
        return knapsack(wt, v, n-1, W);
    }else{
        return max(knapsack(wt,v,n-1,W), v[n-1]+knapsack(wt,v,n-1, W-wt[n-1]));
    }
}


int main(){
    int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val) / sizeof(val[0]);
cout <<endl<<endl<< knapsack( wt, val, n, W);
return 0;
}