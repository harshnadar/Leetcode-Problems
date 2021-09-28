
class Solution {
public:
    struct node
    {
        int mx;
    };
    struct segmentTree
    {
        int size;
        vector<node> d;

        node NEUTRAL_VALUE = {INT_MIN};

        void init(int n)
        {
            size = 1;
            while (size < n)
                size *= 2;
            d.resize(2 * size);
        }

        node merge(node a, node b)
        {
            return {max(a.mx,b.mx)};
        }

        node single(int v)
        {
            return {v};
        }

        void build(vector<int> &a, int x, int tl, int tr)
        {
            if (tr - tl == 1)
            {
                if (tl < (int)a.size())
                {
                    d[x] = single(a[tl]);
                }else{
                    d[x] = NEUTRAL_VALUE;
                }
                return;
            }
            int tm = (tl + tr) / 2;
            build(a, 2 * x + 1, tl, tm);
            build(a, 2 * x + 2, tm, tr);
            d[x] = merge(d[2 * x + 1], d[2 * x + 2]);
        }

        void build(vector<int> &a)
        {
            build(a, 0, 0, size);
        }


        int first(int v, int l, int x, int lx, int rx){
            if(d[x].mx < v){
                return -1;
            }
            if(rx <= l){
                return -1;
            }
            if(rx - lx == 1){
                return lx;
            }
            int m  = (lx + rx)/2;
            int res = first(v, l, 2*x+1, lx, m);
            if(res == -1){
                res = first(v, l, 2*x+2, m, rx);
            }
            return res;
        }
        int first(int v, int l){
            return first(v, l, 0, 0, size);
        }

    };
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& q) {
        segmentTree s;
        segmentTree s2;

        int n = rooms.size();

        s.init(n);
        s2.init(n);

        sort(rooms.begin(),rooms.end(),cmp);

        vector<int> temp;
        for(auto x : rooms){
            temp.push_back(x[1]);
        }

        s.build(temp);
        reverse(temp.begin(),temp.end());
        s2.build(temp);

        vector<int> ans;

        int k = q.size();

        vector<int> idd;
        for(auto x : rooms) idd.push_back(x[0]);

        map<int,int> m;
        int i =0;
        for(auto x : rooms){
            m[i] = x[0];
            i++;
        }

        for(int i=0;i<k;i++){
            int x = q[i][1];
            int id = q[i][0];

            int old_id = id;
            id = lower_bound(idd.begin(),idd.end(),id) - idd.begin();

            int ans1 = s.first(x,id);
            int ans2 = s2.first(x,n-1-id+1);


            if(ans2 != -1) ans2 = n-1-ans2;

            if(ans1 == -1 && ans2 == -1){
                ans.push_back(-1);
            }else if(ans1 == -1){
                ans.push_back(m[ans2]);
            }else if(ans2 == -1){
                ans.push_back(m[ans1]);
            }else{
                if(abs(m[ans1]-old_id) < abs(m[ans2]-old_id)){
                    ans.push_back(m[ans1]);
                }else{
                    ans.push_back(m[ans2]);
                }
            }
        }

        return ans;
    }
};