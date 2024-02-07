#include<iostream>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i][1] == '+') val++;
            else    val--;
        }
        return val;
    }
};
int main(){

    return 0;
}