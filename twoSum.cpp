#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> complementMap;

            for (size_t i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];

                if (complementMap.find(complement) != complementMap.end()) {
                    return {complementMap[complement], static_cast<int>(i)};
                }

                complementMap[nums[i]] = i;
            }

            return {};
        }
};

int main() {
    std::vector<int> nums = { 1, 2, 4 };
    int target = 6;

    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

    if (result.empty()) {
        std::cout << "No solution found" << std::endl;
    } else {
        std::cout << "[" << result[0] << "," << result[1] << "]" << std::endl;
    }
}
