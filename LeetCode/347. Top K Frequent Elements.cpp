class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++; 
        }   
        vector<int> ans;
        vector<pair<int, int>> vec;
        for (auto& item: mp) {
            vec.emplace_back(make_pair(item.second, item.first));
        }
        sort(vec.rbegin(), vec.rend());
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(vec[i].second);
        }
        return ans;
    }
};
