#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int optimal_weight(int W, const int wt[], int n) {
  
   // item_index, current_sack_capacity
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            // if no item, no sack
            if (i == 0 || w == 0) {K[i][w] = 0;}

            // if item lighter than sack capacity, add the optimal item for the remaining sack capacity
            else if (wt[i - 1] <= w) {K[i][w] = max(wt[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);}

            // if item too heavy for the sack, use the one before
            else {K[i][w] = K[i - 1][w];}
        }
    }
  return K[n][W];
    
}

int main() {
    // sack capacity, num_of_objects
    int W, n;
    cin >> W >> n;
    
    int wt[n];
    for (int i = 0; i < n; i++) {cin >> wt[i];}
    
    cout << optimal_weight(W, wt, n) << '\n';

}
