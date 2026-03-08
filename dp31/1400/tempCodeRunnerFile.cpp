#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

/**
 * NOTE: Using `long long` for this problem might lead to integer overflow
 * given the maximum constraints (R up to 10^6, w up to 10^9). The final difference
 * can exceed the capacity of a 64-bit integer (~9e18). This implementation
 * uses `long long` as requested but may not pass all test cases on a platform
 * that strictly enforces the upper bounds of the constraints.
 */

struct TreeProcessor {
    int M;
    int LOGN;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;
    std::vector<int> val; // +1 for Alice's nodes, -1 for Charlie's
    std::vector<long long> path_val_sum;

    TreeProcessor(int m) : M(m) {
        LOGN = (M > 1) ? ceil(log2(M)) + 1 : 2;
        adj.resize(M + 1);
        parent.assign(M + 1, std::vector<int>(LOGN, 0));
        depth.resize(M + 1, 0);
        val.resize(M + 1, 0);
        path_val_sum.resize(M + 1, 0LL);
    }

    void dfs_precomputation(int u, int p, int d, long long current_path_sum) {
        depth[u] = d;
        parent[u][0] = p;
        
        current_path_sum += val[u];
        path_val_sum[u] = current_path_sum;

        for (int i = 1; i < LOGN; ++i) {
            if (parent[u][i-1] != 0) {
                parent[u][i] = parent[parent[u][i-1]][i-1];
            }
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs_precomputation(v, u, d + 1, current_path_sum);
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) std::swap(u, v);
        for (int i = LOGN - 1; i >= 0; --i) {
            if (parent[u][i] != 0 && depth[u] - (1 << i) >= depth[v]) {
                u = parent[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (parent[u][i] != 0 && parent[v][i] != 0 && parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }
};

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;

    std::vector<long long> Ratings(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> Ratings[i];
    }

    TreeProcessor tree(M);

    for (int i = 0; i < M - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree.adj[u].push_back(v);
        tree.adj[v].push_back(u);
    }
    
    // Set up val array (+1 for Alice, -1 for Charlie)
    for(int i = 1; i <= M; ++i) {
        if (i % 2 != 0) tree.val[i] = 1;
        else tree.val[i] = -1;
    }

    // Precompute LCA table and path value sums by DFS from root 1
    if (M > 0) {
        tree.dfs_precomputation(1, 0, 0, 0LL);
    }

    // Calculate initial difference
    long long total_difference = 0;
    for (int i = 0; i < M; ++i) {
        if ((i + 1) % 2 != 0) { // Alice's location
            total_difference += Ratings[i];
        } else { // Charlie's location
            total_difference -= Ratings[i];
        }
    }

    int R;
    std::cin >> R;

    for (int i = 0; i < R; ++i) {
        int s, t;
        long long w;
        std::cin >> s >> t >> w;
        
        int lca = tree.get_lca(s, t);
        
        // Calculate the sum of val[] along the path s-t
        long long path_value = tree.path_val_sum[s] + tree.path_val_sum[t] - 2 * tree.path_val_sum[lca] + tree.val[lca];
        
        // Add the change to the total difference.
        // This is the line where overflow is most likely to occur.
        total_difference += w * path_value;
    }

    std::cout << std::abs(total_difference) << std::endl;

    return 0;
}