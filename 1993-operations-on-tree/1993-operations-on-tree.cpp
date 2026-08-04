class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockedBy;
    vector<int> lcd;

    #define lockedDescendantCount lcd

    bool hasLockedAncestor(int num) {
        int p = parent[num];
        while (p != -1) {
            if (lockedBy[p] != -1)
                return true;
            p = parent[p];
        }
        return false;
    }

    void unlockDescendants(int num) {
        for (int child : children[num]) {
            unlockDescendants(child);
        }

        if (lockedBy[num] != -1) {
            int user = lockedBy[num];
            unlock(num, user);
        }
    }

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        children.resize(n);
        lockedBy.assign(n, -1);
        lcd.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockedBy[num] != -1)
            return false;
        lockedBy[num] = user;

        int p = parent[num];
        while (p != -1) {
            lcd[p]++;
            p = parent[p];
        }
        return true;
    }

    bool unlock(int num, int user) {
        if (lockedBy[num] != user)
            return false;
        lockedBy[num] = -1;

        int p = parent[num];
        while (p != -1) {
            lcd[p]--;
            p = parent[p];
        }
        return true;
    }

    bool upgrade(int num, int user) {
        if (lockedBy[num] != -1)
            return false;

        if (lcd[num] == 0)
            return false;

        if (hasLockedAncestor(num))
            return false;

        unlockDescendants(num);

        return lock(num, user);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */