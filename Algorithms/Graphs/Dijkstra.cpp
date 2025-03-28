#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

/*
    The following implementation of Dijkstra finds the minimum distance from one node, u
    in a weighted graph to all other nodes in the graph given there are no negative edges
    time complexity : O((v + e)log v)
*/

priority_queue<pair<long long, int>> Q;
vector<pair<int, long long>> adj[MAX+1];
bool visited[MAX+1] = {false};
long long dist[MAX+1] = {LLONG_MAX};

void dijkstra(int source) {
    
    dist[source] = 0;
    Q.push({0,source});

    while(!Q.empty()) {
        int a = Q.top().second; Q.pop();
        if(visited[a]) continue;

        visited[a] = true;

        for(auto node : adj[a]) {
            auto [b, w] = node;

            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                Q.push({-dist[b], b});
            }
        }
    }
}