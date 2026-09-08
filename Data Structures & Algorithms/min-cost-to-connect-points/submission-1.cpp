class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, 1e9);
        vector<bool> isInMST(n, false);

        minDist[0] = 0;
        int totalCost = 0;

        for(int count = 0; count < n; count++) {
            int curr = -1;

            for(int i = 0; i < n; i++) {
                if(!isInMST[i] && 
                   (curr == -1 || minDist[i] < minDist[curr])) {
                    curr = i;
                   }
            }
        

            isInMST[curr] = true;
            totalCost += minDist[curr];

            for(int next = 0; next < n; next++) {
                if(!isInMST[next]) {
                    int dis = abs(points[curr][0] - points[next][0]) + abs(points[curr][1] - points[next][1]);

                    minDist[next] = min(minDist[next], dis);
                }
            }
        }
        return totalCost;
    }
};
