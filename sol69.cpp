#include <string>
#include <vector>

using namespace std;

enum Way
{
    LOWER,
    RIGHT,
    LEFT_UPPER
};

vector<int> solution(int n) 
{
	vector<int> answer;
	vector<vector<int>> snail(n, vector<int>(n));
	int cnt = 1, y = 0, x = 0;
    Way way = LOWER;

	for (size_t i = 0; i < n; i++)
	{
		switch (way)
		{
		case LOWER:
			for (auto j = i; j < n; j++)
			{
				snail[y++][x] = cnt++;
			}
			y--;
			x++;
			way = RIGHT;
			break;
		case RIGHT:
			for (auto j = i; j < n; j++)
			{
				snail[y][x++] = cnt++;
			}
			y--;
			x -= 2;
			way = LEFT_UPPER;
			break;
		case LEFT_UPPER:
			for (auto j = i; j < n; j++)
			{
				snail[y--][x--] = cnt++;
			}
			y += 2;
			x++;
			way = LOWER;
			break;
		}
	}

	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < i + 1; j++)
		{
			answer.push_back(snail[i][j]);
		}
	}

	return answer;
}
