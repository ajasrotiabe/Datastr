#include <iostream>
#include <vector>
using namespace std;
int rows, cols, t; cin >> rows >> cols >> t;
vector<vector<int>> triplet(t, vector<int>(3));
for (int i = 0; i < t; i++) cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
for (int i = 0; i < t; i++) swap(triplet[i][0], triplet[i][1]);
for (int i = 0; i < t; i++) cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
return 0;
}
