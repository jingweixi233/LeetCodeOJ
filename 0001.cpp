/*
quickSort
for i
binary search target - i
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int trans[10000];
    void quickSort(vector<int>& nums, int l, int r){

        int i = l;
        int j = r;
        
        int x = nums[l];
        int y = trans[l];

        if(l < r){
            while(i < j){
                while(i < j && nums[j] > x){
                    j--;
                }
                if(i < j){
                    nums[i] = nums[j];
                    trans[i] = trans[j];
                    i++;
                }
                while(i < j && nums[i] < x){
                    i++;
                }
                if(i < j){
                    nums[j] = nums[i];
                    trans[j] = trans[i];
                    j--;
                }
            }
            nums[i] = x;
            trans[i] = y;
            quickSort(nums, l, i - 1);
            quickSort(nums, i + 1, r);
        }
    }

    int binarySearch(vector<int>& nums, int ll, int rr, int x){
        int l = ll, r = rr;
        int mid = (l + r) / 2;
        while(l <= r){
            if(nums[mid] > x){
                r = mid - 1;
            }
            else{
                if(nums[mid] == x){
                    return mid;
                }
                else{
                    l = mid + 1;
                }
            }
            mid = (l + r) / 2;
        }
        return -1;

    }

    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i;
        int len = nums.size();

        for(i = 0; i < len; i++){
            trans[i] = i;
        }
        quickSort(nums, 0, len - 1);
        vector<int> ans;
        for(i = 0; i < len; i++){
            int aim = target - nums[i];
            int flag = binarySearch(nums, i + 1, len - 1, aim);
            if(flag != -1){
                if(trans[i] < trans[flag]){
                    ans.push_back(trans[i]);
                    ans.push_back(trans[flag]);
                }
                else{
                    ans.push_back(trans[flag]);
                    ans.push_back(trans[i]);
                }

                break;
            }
        }
        return ans;
    }  
};

/*
idea2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> answer;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int needed_num = target - nums[i];
            
            if (cache.find(needed_num) != cache.end())
            {
                // We found it
                answer.push_back(cache[needed_num]);
                answer.push_back(i);
                return answer;
            }
            else
            {
                // Didn't find it
                cache.insert(make_pair(nums[i], i));
            }
        }
        return answer;
    }
};
*/


int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3); 
    vector<int> a = s.twoSum(nums, 6);
    cout << a[0] << ' ' << a[1] << endl;
}



