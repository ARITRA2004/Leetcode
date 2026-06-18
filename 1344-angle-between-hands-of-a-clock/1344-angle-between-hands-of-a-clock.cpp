class Solution {
public:
    double angleClock(int hour, int minutes) {
        int min_hand = minutes*6;
        double hr_hand = 0.5*minutes;

        int hr_to_deg = (hour%12)*30;

        double hr_min = abs(min_hand - hr_hand);

        double res = abs(hr_min - hr_to_deg);

        if(res > 180) return 360-res;
        return res;
    }
};