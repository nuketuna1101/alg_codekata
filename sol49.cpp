#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows1 = arr1.size();
    int cols1 = arr1[0].size();
    int cols2 = arr2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return result;
}
