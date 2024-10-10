#include <iostream>

using namespace std;
int removeduplicates(vector<int>& nums){
    int duplicates = 0;
    int i = 0;
    int j = i+1;
    int n = nums.size();
    int invalid = -200;

    while(i < n-1 && j<n){
        if(nums[i] != invalid && nums[i]== nums[j]){
            while(j<n && nums[i]== nums[j]){
                nums[j] = invalid;
                j++;
                duplicates++;
            }
        }
        else if(nums[i] != invalid && nums[i] != nums[j]){
            i++;
            j=i+1;
        }
        else if(nums[i] == invalid && nums[j] != invalid){
            nums[i] = nums[j];
            nums[j] = invalid;
            j++;
        }
        else {
            j++;
        }
    } 
    return duplicates;
}
int main(){
    vector<int> nums = {1, 2};
    int ans = removeduplicates(nums);
    cout<< ans;
    return 0;
}