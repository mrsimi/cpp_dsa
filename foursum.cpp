#include <iostream>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > ans;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == target){
                    vector<int> values = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(values);
                    k++;
                    l--;

                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l++;
                }
                else if(sum > target) l--;
                else k++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {5,5,3,5,1,-5,1,-2};
    int target = 4;
    vector<vector<int> > ans = fourSum(nums, target);
    for(auto it : ans){
        cout<< "[";
        for(auto el: it){
            cout << el << " ";
        }
        cout<< "]";
    }
    return 0;
}