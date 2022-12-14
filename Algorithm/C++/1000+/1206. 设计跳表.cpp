static const int level = 8; 
struct Node {
    int val; 
    vector<Node*> next; 
    Node(int _val) : val(_val) {
        next.resize(level, NULL);
    }
};
typedef struct Node *NodePtr, Node;

class Skiplist {
public:
    NodePtr head;
    Skiplist() {
        head = new Node(-1);
    }

    ~Skiplist() {
        delete head;
    }

    void find(int target, vector<Node*>& pre) {
        auto p = head; 
        for (int i = level - 1; i >= 0; i -- ) {
            while (p->next[i] && p->next[i]->val < target) p = p->next[i];
            pre[i] = p;
        }
    }
    
    bool search(int target) {
        vector<Node*> pre(level);
        find(target, pre);
        
        auto p = pre[0]->next[0];
        return p && p->val == target;
    }
    
    void add(int num) {
        vector<Node*> pre(level);
        find(num, pre);

        auto p = new Node(num);
        for (int i = 0; i < level; i ++ ) {
            p->next[i] = pre[i]->next[i]; 
            pre[i]->next[i] = p;
            if (rand() % 2) break; // 50%
        }
    }
    
    bool erase(int num) {
        vector<Node*> pre(level);
        find(num, pre); 

        auto p = pre[0]->next[0];
        if (!p || p->val != num) return false;

        for (int i = 0; i < level && pre[i]->next[i] == p; i ++ ) {
            pre[i]->next[i] = p->next[i]; // 单链表删除
        }

        delete p;
        return true;
    }
};