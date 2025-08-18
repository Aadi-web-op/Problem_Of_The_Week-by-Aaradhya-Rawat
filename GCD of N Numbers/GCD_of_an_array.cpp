#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);

   
}

int main(){
    vector<int>nums = {1000,300,100};
    int g = nums[0];
    for(int i=1;i<nums.size();i++){
        g = gcd(g,nums[i]);
    }
    cout<<"GCD of the given array = "<<g;
}