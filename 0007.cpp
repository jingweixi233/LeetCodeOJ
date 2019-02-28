/*
record '-'

while(num > 0)
num
s = num % 10;
num = num / 10;
sum = sum * 10 + s;

*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x > 2147483647 || x <= -2147483648){
            return 0;
        }
        int flag = 0;
        if(x < 0){
            flag = 1;
            x = -x;
        }
        int num = x;
        int addNum = num % 10;
        num = num / 10;
        int sum = addNum;
        while(num > 0){
            addNum = num % 10;
            num = num / 10;
            if(sum > 214748364.7){
                return 0;
            }
            sum = sum * 10 + addNum;
        }
        if(flag == 1){
            sum = -sum;
        }
        return sum;
    }
};

int main(){
    Solution s;
    int a = s.reverse(-123);
    cout << a << endl;
}
