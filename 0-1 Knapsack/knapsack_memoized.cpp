#include <iostream>
using namespace std;

int max(int a, int b){
    if(a> b) return a;
    return b;
}

int knapsack(int *wt, int *v, int n, int W){
    int M[n+1][W+1];
    for(int i=0; i<=W; i++) M[0][i]=0;
    for(int i=1; i<=n; i++){
        for(int w=0; w<=W; w++){
            if(w<wt[i]){
                M[i][w]=M[i-1][w];
            }else{
                M[i][w]=max(M[i-1][w], v[i]+M[i-1][w-wt[i]]);
            }
        }
    }
    cout<<"Displaying iterations: ";
    for(int i=0; i<=n; i++){
        cout<<"\n"<<i<<": ";
        for(int j=0; j<=W; j++) cout<<M[i][j]<<" ";
    }
    return M[n][W];
}

int main(){
    int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val) / sizeof(val[0]);
cout <<endl<<endl<< knapsack( wt, val, n, W);
return 0;
}