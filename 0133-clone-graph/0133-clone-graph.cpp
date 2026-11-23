
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        Node* clone = new Node(node->val);

        mp[node] = clone;
        q.push(node);

        while(!q.empty())
        {
            Node* no = q.front();
            q.pop();

            for(int i = 0; i < no->neighbors.size(); i++)
            {
                Node* neighbor = no->neighbors[i];

                if(mp.find(neighbor) == mp.end())
                {
                    Node* clone1 = new Node(neighbor->val);
                    mp[neighbor] = clone1;
                    q.push(neighbor);
                }

                mp[no]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};
