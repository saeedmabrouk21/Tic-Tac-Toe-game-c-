#include <bits/stdc++.h>
using namespace std;
#include <limits.h>
#include <time.h>
#ifndef mma
#define mma
class score
{
private:
    /* data */
    vector<vector<char>> answers;

public:
    score(/* args */)
    {
        answers = {{0, 1, 2},
                   {3, 4, 5},
                   {6, 7, 8},
                   {0, 4, 8},
                   {2, 4, 6},
                   {0, 3, 6},
                   {1, 4, 7},
                   {2, 5, 8}};
    }
    int calculate_score(vector<char> vec)
    {
        int score = 0;
        int is_x = 0;
        int is_o = 0;
        for (auto x : answers)
        {
            int is_x = (vec[x[0]] == 'x') +
                       (vec[x[1]] == 'x') +
                       (vec[x[2]] == 'x');

            int is_o = (vec[x[0]] == 'o') +
                       (vec[x[1]] == 'o') +
                       (vec[x[2]] == 'o');
            if (is_x == 3)
                score += 100000;
            if (is_o == 3)
                score -= 100000;
        }
        // cout<<score
        return score;
    }
};
class min_max
{
private:
    int max_depth;
    int answer;

public:
    score ss;
    min_max(int max_depth) : max_depth(max_depth), answer(-1)
    {
    }
    int decision(vector<char> vec, char mark)
    {
        srand((unsigned)time(NULL));
        if (mark == 'o')
        {
            minimize(vec, 0);
        }
        else if (mark == 'x')
        {
            maximize(vec, 0);
        }
        else
        {
            __throw_bad_exception();
        }
        return answer;
    }
    int maximize(vector<char> vec, int k)
    {
        if (k == max_depth || is_terminal(vec))
        {
            return ss.calculate_score(vec);
        }
        int maximum_score = INT_MIN;
        int arr[8];
        int idx = -1;
        for (int i = 0; i < 9; ++i)
        {
            int cur_score;
            if (vec[i] >= '1' && vec[i] <= '9')
            {
                char cur_value = vec[i];
                vec[i] = 'x';
                cur_score = minimize(vec, k + 1);
                vec[i] = cur_value;
                if (cur_score > maximum_score)
                {
                    maximum_score = cur_score;
                    arr[0] = i;
                    idx = 1;
                }
                else if (cur_score == maximum_score)
                {
                    arr[idx] = i;
                    idx++;
                }
            }
        }
        answer = arr[rand() % idx];
        return maximum_score;
    }
    int minimize(vector<char> vec, int k)
    {
        if (k == max_depth || is_terminal(vec))
        {
            return ss.calculate_score(vec);
        }
        if (k == max_depth || is_terminal(vec))
        {
            return ss.calculate_score(vec);
        }
        int minimum_score = INT_MAX;
        int arr[8];
        int idx = -1;
        for (int i = 0; i < 9; ++i)
        {
            int cur_score;
            if (vec[i] >= '1' && vec[i] <= '9')
            {
                char cur_value = vec[i];
                vec[i] = 'o';
                cur_score = maximize(vec, k + 1);
                vec[i] = cur_value;
                if (cur_score < minimum_score)
                {
                    minimum_score = cur_score;
                    arr[0] = i;
                    idx = 1;
                }
                else if (cur_score == minimum_score)
                {
                    arr[idx] = i;
                    idx++;
                }
            }
        }
        answer = arr[rand() % idx];
        return minimum_score;
    }
    bool is_terminal(vector<char> vec)
    {
        int score = ss.calculate_score(vec);
        if (score == 100000 || score == -100000)
        {
            return true;
        }
        for (auto x : vec)
        {
            if (x >= '1' && x <= '9')
            {
                return false;
            }
        }
        return true;
    }
};
#endif