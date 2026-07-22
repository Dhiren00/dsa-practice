class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start = 0;
        int currentgas = 0;
        int values = 0;
        int v1 = 0;

        for (int value : gas)
            values += value;

        for (int value : cost)
            v1 += value;

        if (v1 > values)
            return -1;

        for (int i = 0; i < gas.size(); i++) {
            currentgas += gas[i] - cost[i];

            if (currentgas < 0) {
                currentgas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};