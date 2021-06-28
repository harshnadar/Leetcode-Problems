#define f(a,b,i) for(int i=a;i<b; i++)
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // int n=word.size();
        long long int count[3000]={1};
        long long int mask=0;
        long long int result=0;
        for(char it: word){
            mask^=(1<<(it-'a'));
            result+=count[mask];
            f(0,11,i){
                result+=count[mask^(1<<i)];
            }
            count[mask]++;
        }
        return result;
    }
};