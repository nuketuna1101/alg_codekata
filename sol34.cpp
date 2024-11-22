#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    pair<int, int> cur;

    int pX = park.size();
    // 초기화
    for (int i = 0; i < pX; i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
                cur = make_pair(i, j);
        }
    }

    // 입력에 대해서
    for (int i = 0; i < routes.size(); i++)
    {
        char dir = routes[i][0];
        int dist = routes[i][2] - '0';
        int dirY = 0, dirX = 0;

        switch (dir)
        {
        case 'E':
            dirX = 1;
            break;
        case 'W':
            dirX = -1;
            break;
        case 'S':
            dirY = 1;
            break;
        case 'N':
            dirY = -1;
            break;
        };

        if ((cur.first + (dirY * dist) < pX 
        && cur.first + (dirY * dist) >= 0) 
        && (cur.second + (dirX * dist) < park[0].size() 
        && cur.second + (dirX * dist) >= 0))
        {
            int j;
            for (j = 1; j <= dist; j++)
            {
                if (park[cur.first + (dirY * j)][cur.second + (dirX * j)] == 'X')
                    break;
                
                
            }

            if (j > dist)
            {
                cur.first += (dirY * dist);
                cur.second += (dirX * dist);
            }
        }
    }

    answer = {cur.first, cur.second};
    return answer;
}