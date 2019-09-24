class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        
        string result = "";
        int sum = 0;
        int carry = 0;
        while(i>=0 || j>=0 || carry) {
            int sa = 0;
            int sb = 0;
            if (i>=0) {
                sa = sa + a[i] - '0';
            } else {
                sa = 0;
            }
            if (j>=0) {
                sb = sb + b[j] - '0';
            } else {
                sb = 0;
            } 
            int sum = sa + sb + carry;
            result.push_back(sum%2 + '0');
            carry = sum/2;
            i--;j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
