#include<iostream>
using namespace std;

// Function to find the maximum profit
int knapsack(int n, float w[], float p[], float c){
     double maxProfit = 0.0; // Maximum profit achieved
     int currentWeight = 0;  // Current weight in the knapsack

     for(int i=0; i<n; i++){
        if(currentWeight + w[i]<= c){
            currentWeight += w[i];
            maxProfit += p[i];
        }
        else{
            int remainingweight = c - currentWeight;
            maxProfit += p[i] * ((double)remainingweight/w[i]);
            break;
        }
       
     }
    return maxProfit;
}

int main(void){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    float w[n], p[n], r[n];
    cout<<"Enter the weights of the items: ";
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    cout<<"Enter the profits of the items: ";
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    cout<<"Enter the capacity of the knapsack: ";
    float c;
    cin>>c;

    for(int i=0; i<n; i++){
        r[i] = p[i]/w[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(r[i]<r[j]){
                float temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    float maxProfit = knapsack(n, w, p, c);
    cout<<"The maximum profit is: "<<maxProfit;

}
