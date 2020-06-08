#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    enum color{WHITE, BLACK, GRAY};
    vector <color> state;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        state = vector <color>(numCourses, WHITE);
    }
};