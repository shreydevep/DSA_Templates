typedef pair<long long, int> PII;
struct Prims {
  vector<bool> vis;
  vector<vector<PII>> adj;
  void init() {
    //Intialise and do pre-processing task before calling runPrims.
  }
  void runPrims(int node) {
    priority_queue<PII, vector<PII>, greater<PII> > q;
    long long minimumCost = 0;
    PII p;
    q.push(make_pair(0, node));
    while (!q.empty())
    {
      // Select the edge with minimum weight
      p = q.top();
      q.pop();
      node = p.second;
      // Checking for cycle
      if (vis[node] == true)
        continue;


      minimumCost += p.first;
      vis[node] = true;

      for (auto &child : adj[par])
      {
        if (vis[child] == false)
          q.push(child);
      }
    }
    return minimumCost;
  }
};
