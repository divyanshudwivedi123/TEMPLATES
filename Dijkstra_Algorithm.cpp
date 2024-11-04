// Template for Dijkstra algorithm

/*
Used to find shortest path from the source node to all other nodes of the graph(both weighted and unweighted).
BFS + Priority_Queue(Heap) == Dijkstra Algorithm


=> Take a min Heap with {distance, node} 
=> Take a distance array which stores the distance of each node. Initially the distance of all the nodes will be INT_MAX.
=> We do not need to take a visited array.
=> Mark the source nodes distance as zero and put it into the heap i.e. {0, src};
=> Take it out and visit all its neighbours.
=> If the distance of the neighbour nodes comes out to be less than the distance in the visited array. Then, 
   put the {dist, node} in the heap and update its distance in the array. Remember, we only put the node in the heap 
   if the distance of the node comes out to be less than the distance in the distance array. If the distance comes out 
   to be greater than the already present distance in the dist array, then simply ignore it.

=> Repeat the process until the heap is not empty.

*/


/*
WHEN DIJKSTRA DOES NOT WORK:

=> If there is any negative weight present in the graph bcoz it will get stuck into infinite loop.
=> Time complexity : For adjacency list :  (V + E) log V , For adjacency matrix : O(V^2) , 
E = no of edges, V = no of nodes or vertices.
=> Space complexity : O(V)
*/

// CODE

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // MIN HEAP {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        // Mark the distance of all the nodes as infinity
        for(int i = 0; i < V; i++) dist[i] = 1e9;
        // distance of the source node will be zero.
        dist[S] = 0;
        // put the source node in the heap.
        pq.push({0, S});
        // do while the heap is not empty
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // visit the neighbours of the node.
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                // check if the visited distance is less or more than the distance present in the array
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

