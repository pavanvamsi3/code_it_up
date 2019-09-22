class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        for(i=0; i<bits.size() - 1;) {
            if (bits[i] == 0) {
                i++;
            } else {
                i = i+2;
            }
        }
        if (i == bits.size() - 1) {
            return true;
        }
        return false;
    }
};
