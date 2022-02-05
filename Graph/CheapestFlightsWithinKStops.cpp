class Solution {
public:
    int findCheapestPriceDijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});
        vector<int> stops(n, INT_MAX);
        // number of stops to reach indexth node with least possible price from src node
        // as it will be calculated once the pq.top() equals to indexth node
        
        // pq.top() will always store least cost among the pq elements so if already stop is calculated 
        // and if that is greater than the cstop that means already
        // we have a path with cheaper cost as well as with less or equal number of stops
        
        while (!pq.empty()) {
            auto temp = pq.top();
            int cdist = temp[0];
            int cnode = temp[1];
            int cstop = temp[2];
            pq.pop();
            if (cstop > stops[cnode] || cstop > k + 1) continue;
            stops[cnode] = cstop;
            if (cnode == dst) {
                return cdist;
            }
            for (auto a : adj[cnode]) {
                pq.push({cdist + a.second, a.first, cstop + 1});
            }
        }
        return -1;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        int ans = INT_MAX;
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (stops <= k && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cnode = q.front().first;
                int cdist = q.front().second;
                q.pop();
                if (cdist > dist[cnode]) continue;
                dist[cnode] = cdist;
                for (auto e : adj[cnode]) {
                    // if (e.second + cdist > ans) continue;
                    if (e.first == dst) ans = min(ans, e.second + cdist);
                    q.push({e.first, e.second + cdist});
                }
            }
            stops++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
