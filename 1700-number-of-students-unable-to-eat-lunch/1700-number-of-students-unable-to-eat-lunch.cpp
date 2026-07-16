class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwichStack;
        queue<int> studentQueue;

        int n = sandwiches.size();
        for (int i = n - 1; i >= 0; i--) {
            sandwichStack.push(sandwiches[i]); // reversed so sandwiches[0] ends on top
        }
        for (int s : students) {
            studentQueue.push(s);
        }

        int rotations = 0; // count of consecutive students who declined
        while (!studentQueue.empty() && rotations < studentQueue.size()) {
            if (studentQueue.front() == sandwichStack.top()) {
                studentQueue.pop();
                sandwichStack.pop();
                rotations = 0; // someone took a sandwich, reset the counter
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                rotations++;
            }
        }
        return studentQueue.size();
    }
};