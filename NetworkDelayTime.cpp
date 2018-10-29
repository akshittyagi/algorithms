class Solution {
public:
    class Compare{
        public:
            bool operator()(pair<int, int> a, pair<int, int> b)
            {
                return a.second > b.second;
            }
    };
    
    int dijsktra(unordered_map< int , unordered_map< int , int > > &graph, int K, int N)
    {
        priority_queue< pair<int, int> , vector<pair<int, int>>, Compare > pq;
        unordered_map< int, int > umap;
        umap[K] = 0;
        pq.push(make_pair(K, 0));
        int max = INT_MIN;
        while(!pq.empty())
        {
            pair<int , int> curr_pair = pq.top();
            pq.pop();
            int node = curr_pair.first;
            int distance = curr_pair.second;
            if(umap.find(node) != umap.end() and umap[node] < distance)
                continue;
            unordered_map< int, int > edges = graph[node];
            for (const auto &edge: edges)
            {
                int new_dist = distance + edge.second;
                int target_node = edge.first;
                if (umap.find(target_node)!=umap.end() and umap[target_node] <= new_dist)
                    continue;
                umap[target_node] = new_dist;
                pq.push(make_pair(target_node, new_dist));
            }
        }
        
        for (const auto &distances: umap)
        {
            if (distances.second > max)
                max = distances.second;
        }
        
        return umap.size() == N ? max : -1;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map< int , unordered_map< int , int > > graph;
        for( int i = 0; i < times.size() ; i++)
        {
            if (graph.find(times[i][0]) != graph.end())
                graph[times[i][0]][times[i][1]] = times[i][2];
            else
            {
                unordered_map< int, int > umap;
                umap[times[i][1]] = times[i][2];
                graph[times[i][0]] = umap;
            }
        }
        
        return dijsktra(graph, K, N);
    }
};