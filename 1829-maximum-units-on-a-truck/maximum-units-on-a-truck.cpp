class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return a[1] > b[1]; // sort by units per box
        });

        int total = 0;

        for (auto &box : boxTypes) {
            int boxes = min(truckSize, box[0]);
            total += boxes * box[1];
            truckSize -= boxes;

            if (truckSize == 0) break;
        }

        return total;
    }
};