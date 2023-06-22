// O(v), O(1) Striver
#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 

{
    int arr[]={1,2,5,10,20,50,100,500,1000};
    int coins=0;
    int i =8;
    while(amount&& i>=0)
    {
        if(amount<arr[i])
        {
            i--;
            continue;
        }
        coins++;
        amount-=arr[i];
    }
    return coins;
}

 
// Me== tatti
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int count = 0;
    // Write your code here
    while(amount>0){
        if(amount>1000){
            amount = amount/1000;
            count++;
        }
        if(amount>500){
            amount = amount/500;
            count++;
        }
        if(amount>100){
            amount = amount/100;
            count++;
        }
        if(amount>50){
            amount = amount/50;
            count++;
        }
        if(amount>20){
            amount = amount/20;
            count++;
        }
        if(amount>10){
            amount = amount/10;
            count++;
        }
        if(amount>5){
            amount = amount/5;
            count++;
        }
        if(amount>2){
            amount = amount/2;
            count++;
        }
        if(amount>1){
            amount = amount/1;
            count++;
        }
    }
    return count;

}
