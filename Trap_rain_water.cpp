void prevGreatest(stack<int> &s, vector<int> height, vector<pair<int, int>> &map, int n)
{
    s.push(0);
    map[0].first = -1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && height[s.top()] <= height[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            map[i].first = s.top();
        }
        else
        {
            map[i].first = -1;
        }

        s.push(i);
    }
}

void nextGreatest(stack<int> &s, vector<int> height, vector<pair<int, int>> &map, int n)
{
    s.push(n - 1);
    map[n - 1].first = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && height[s.top()] <= height[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            map[i].second = s.top();
        }
        else
        {
            map[i].second = -1;
        }

        s.push(i);
    }
}
    int trap(vector<int>& height) {

    int n = height.size();
    vector<pair<int, int>> map(n, {-1, -1});
    stack<int> s;
    int ans = 0;
    prevGreatest(s, height, map, n);
    stack<int> s1;
    nextGreatest(s1, height, map, n);
    

    for(int i = 0;i<n;i++) {
        if(map[i].first!=-1 && map[i].second!=-1) {
            int curr = i;
            int curr_ans = height[map[i].first];
            while(map[curr].first!=-1 && map[curr].second!=-1) {
                curr_ans = height[map[curr].first];
                curr = map[curr].first;
            }
            int curr1 = i;
            int curr_ans1 = height[map[i].second];
            while(map[curr1].first!=-1 && map[curr1].second!=-1) {
                curr_ans1 = height[map[curr1].second];
                curr1 = map[curr1].second;
            }
            ans+=min(curr_ans,curr_ans1) - height[i];
        }
    }
    return ans;
}
