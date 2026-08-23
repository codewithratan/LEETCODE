class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;
        int sumL = 0, sumR = 0, qL = 0, qR = 0;

        for (int i = 0; i < n; i++) {
            if (i < mid) {
                if (num[i] == '?') qL++;
                else sumL += num[i] - '0';
            } else {
                if (num[i] == '?') qR++;
                else sumR += num[i] - '0';
            }
        }
        return (sumL - sumR) != (qR - qL) * 4.5;
    }
};