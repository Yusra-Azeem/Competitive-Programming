#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> cnt(n+1,0);
        for(int i=0; i<m; i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        int low=0, high = 2*m, ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalTasks=0;
            for(int i=1; i<=n; i++){
                int prof=min(cnt[i],mid);
                int leftTime = mid-prof;
                int nonProf = leftTime/2;
                totalTasks += prof+nonProf;
            }
            if(totalTasks>=m){
                ans=mid;
                high=mid-1;
            }
            else low = mid + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
