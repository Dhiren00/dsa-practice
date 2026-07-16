class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }

        int time = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            curr.first--;
            time++;

            if (curr.first == 0) {
                if (curr.second == k)
                    return time;
            } else {
                q.push(curr);
            }
        }

        return time;
    }
};