#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (find(path.begin(), path.end(), nums[i]) != path.end()) {
            continue; // skip if number already used
        }
        path.push_back(nums[i]);
        backtrack(nums, path, res);
        path.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, path, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (auto& v : res) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
