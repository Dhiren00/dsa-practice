class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        sort(stones.begin(), stones.end()); // Ascending

        while (stones.size() > 1) {

            int h1 = stones[stones.size() - 1];
            int h2 = stones[stones.size() - 2];

            stones.pop_back();
            stones.pop_back();

            if (h1 != h2) {
                stones.push_back(h1 - h2);
            }

            sort(stones.begin(), stones.end());
        }

        if (stones.empty())
            return 0;

        return stones[0];
    }
};