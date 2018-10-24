#include<iostream>
#include<conio.h>
using namespace std;
int Max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int p[],int wt[],int n,int W){
    int i,j;
    int K[n+1][W+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0||j==0)
                K[i][j] = 0;
            else{
                    if(j>=wt[i])
                        K[i][j] = Max(K[i-1][j],(p[i]+K[i-1][j-wt[i]]));
                    else
                        K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][W];
}
int main(){
    int profit[10],weight[10],i,n,W;
    cout<<"enter the number of weight";
    cin >> n;
    cout << "enter the maximun weight that can be carried by in the Bag";
    cin >> W;
    cout << "enter the weight : \n";
    for(i=0;i<n;i++){
        cin >> weight[i];
    }
    cout << "enter the profits associate with weight\n";
    for(i=0;i<n;i++){
        cin >> profit[i];
    }
    cout << "the total profit that can be carried is : ";

        cout << knapsack(profit,weight,n,W);

}
