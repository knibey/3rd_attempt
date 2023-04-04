#include <iostream>
#include <vector>
using std::vector;

vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 1, k = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[k] + nums[i] == target) {
                return vector<int>{k, i};
            }
        }
        k++;
    }
    return vector<int>(0,0);
}

int numberSyllables(std::string word) {
    int count = 0;
    for (int i = 0; i != word.length(); i++) {
        if (word[i] == '-') {
            count += 1;
        }
    }
    return count + 1;
}

/*ector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 1, k = 0; i < nums.size(); ++i) {
        if (nums[k] + nums[i] == target) {
            return vector<int>{k, i};
        }
        k++;
    }
    return vector<int>{0, 0};
}*/

int maintestee() {

    vector<int> nums{ 3,2,3 };

    vector<int> result = twoSum(nums, 6);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }

    std::cout << numberSyllables("mon-u-men-tal");

    return 0;
}