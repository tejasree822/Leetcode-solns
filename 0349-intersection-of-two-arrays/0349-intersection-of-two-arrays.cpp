class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> resultSet;
        vector<int> finalArray;

        for (int num : nums1) {
            set1.insert(num);
        }
        for (int num : nums2) {
           
            if (set1.count(num)) {
                
                resultSet.insert(num);
            }
        }
        for (int val : resultSet) {
            finalArray.push_back(val);
        }

        return finalArray;
    }
};