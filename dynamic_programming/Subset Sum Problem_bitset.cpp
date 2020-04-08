class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
    }
};

Explanation of the above code :
Size of bitset is the maximum sum that can be achieved by array + 1.
Ex. [5,2,4] ---> bitset of size 12 ==> 000000000001
That means initially we can achieve sum 0 with empty array subset [ ].
We have only 0's bit set.

num = 5
0 -> 5 (set 5's bit, since we can achieve sum 5.)
Now we can achieve 0 and 5 with [ ] and [ 5 ]. So by the union of both, we have 000000100001

num = 2
0->2
5->7
We can achieve 0,2,5,7 from [5,2] ==> [ ], [5], [2], [5,2]
After union our bitset is 000010100101

num = 4
0->4
2->6
5->9
7->11
We can achieve 0,2,4,5,6,7,11 from [5,2] ==> [ ], [5], [2], [4], [5,2], [2,4], [5,4], [5,2,4]
After union our bitset is 101011110101
