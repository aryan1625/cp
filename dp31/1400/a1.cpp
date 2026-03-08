#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

// ATTENTION: This solution uses 64-bit integers (long long) as requested.
// According to the problem's maximum constraints, the final result might
// become larger than what a long long can store, which could lead to
// integer overflow errors. For a solution that works for all possible inputs
// under the given constraints, a 128-bit integer type would be necessary.

struct graphy {
    int nC;
    int mL;
    vector<vector<int>> conn;
    vector<vector<int>> par;
    vector<int> dep;
    vector<int> ownS;
    vector<long long> pathsum;
    graphy(int count) : nC(count) {
        mL = (nC > 1) ? ceil(log2(nC)) + 1 : 2;
        conn.resize(nC + 1);
        par.assign(nC + 1, vector<int>(mL, 0));
        dep.resize(nC + 1, 0);
        ownS.resize(nC + 1, 0);
        pathsum.resize(nC + 1, 0LL);
    }
    void dfs(int curr, int prev, int curDep, long long runSum) {
        dep[curr] = curDep;
        par[curr][0] = prev;
        
        runSum += ownS[curr];
        pathsum[curr] = runSum;

        for (int i = 1; i < mL; ++i) {
            if (par[curr][i-1] != 0) {
                par[curr][i] = par[par[curr][i-1]][i-1];
            }
        }
        for (int i : conn[curr]) {
            if (i != prev) {
                dfs(i, curr, curDep + 1, runSum);
            }
        }
    }

    int findLca(int nodeA, int nodeB) {
        if (dep[nodeA] < dep[nodeB]) swap(nodeA, nodeB);
        for (int i = mL - 1; i >= 0; --i) {
            if (par[nodeA][i] != 0 && dep[nodeA] - (1 << i) >= dep[nodeB]) {
                nodeA = par[nodeA][i];
            }
        }
        if (nodeA == nodeB) return nodeA;
        for (int i = mL - 1; i >= 0; --i) {
            if (par[nodeA][i] != 0 && par[nodeB][i] != 0 && par[nodeA][i] != par[nodeB][i]) {
                nodeA = par[nodeA][i];
                nodeB = par[nodeB][i];
            }
        }
        return par[nodeA][0];
    }
};

int main() {
    // Faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    vector<long long> Ratings(M);
    for (int i = 0; i < M; ++i) {
        cin >> Ratings[i];
    }

    graphy network(M);

    for (int i = 0; i < M - 1; ++i) {
        int loc1, loc2;
        cin >> loc1 >> loc2;
        network.conn[loc1].push_back(loc2);
        network.conn[loc2].push_back(loc1);
    }
    
    // Assign owner sign based on location index parity
    for(int i = 1; i <= M; ++i) {
        if (i % 2 != 0) network.ownS[i] = 1;
        else network.ownS[i] = -1;
    }

    // Run the preprocessing DFS from root (location 1)
    if (M > 0) {
        network.dfs(1, 0, 0, 0LL);
    }

    // Calculate the score difference from initial ratings
    long long finalScoreDifference = 0;
    for (int i = 0; i < M; ++i) {
        if ((i + 1) % 2 != 0) { // Alice's location
            finalScoreDifference += Ratings[i];
        } else { // Charlie's location
            finalScoreDifference -= Ratings[i];
        }
    }

    int R;
    cin >> R;

    for (int i = 0; i < R; ++i) {
        int startLoc, endLoc;
        long long increaseValue;
        cin >> startLoc >> endLoc >> increaseValue;
        
        int commonAncestor = network.findLca(startLoc, endLoc);
        
        // Calculate the net owner value along the path from start to end
        long long pathParity = network.pathsum[startLoc] + network.pathsum[endLoc] - 2 * network.pathsum[commonAncestor] + network.ownS[commonAncestor];
        
        // Add the resulting change to the final difference
        finalScoreDifference += increaseValue * pathParity;
    }

    cout << abs(finalScoreDifference) << endl;

    return 0;
}