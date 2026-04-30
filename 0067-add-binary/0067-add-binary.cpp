class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';

        string ans = "";

        if (a.size() < b.size()) {
            a = string(b.size() - a.size(), '0') + a;
            cout << a << endl;
        } else if (b.size() < a.size()) {
            b = string(a.size() - b.size(), '0') + b;
            cout << b << endl;
        }

        int n = a.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            if (carry == '0') {
                if (a[i] == '1' && b[i] == '1') {
                    ans = ans + '0';
                    carry = '1';
                }
                if (a[i] == '1' && b[i] == '0')
                    ans += '1';
                if (a[i] == '0' && b[i] == '1')
                    ans += '1';
                if (a[i] == '0' && b[i] == '0')
                    ans += '0';
            } else if (carry == '1') {
                if (a[i] == '1' && b[i] == '1') {
                    ans = ans + '1';
                    carry = '1';
                }
                if (a[i] == '1' && b[i] == '0') {
                    ans += '0';
                    carry = '1';
                }
                if (a[i] == '0' && b[i] == '1') {
                    ans += '0';
                    carry = '1';
                }
                if (a[i] == '0' && b[i] == '0') {
                    ans += '1';
                    carry = '0';
                };
            }
        }

        if (carry == '1')
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};