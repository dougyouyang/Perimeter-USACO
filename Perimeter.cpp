//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
typedef pair<int, int> pii;
int mat[105][105];

void DSF(int x, int y)
{
    if(x>=103 || y>=103)
        return;
    if(mat[x][y+1]==0){
        mat[x][y+1]=1;
        DSF(x, y+1);
    }
    if(mat[x][y-1]==0 && y!=0){
        mat[x][y-1]=1;
        DSF(x, y-1);
    }
    if(mat[x+1][y]==0){
        mat[x+1][y]=1;
        DSF(x+1, y);
    }
    if(mat[x-1][y]==0 && x!=0){
        mat[x-1][y]=1;
        DSF(x-1, y);
    }
}

int main()
{
    pii loc[10005];
    int n, s=0;
    int i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> loc[i].first >> loc[i].second;
        mat[loc[i].first][loc[i].second]=2;
    }
    
    DSF(0, 0);
    for(i=0;i<n;i++){
        if(mat[loc[i].first+1][loc[i].second]==1){
            s++;
        }
        if(mat[loc[i].first-1][loc[i].second]==1){
            s++;
        }
        if(mat[loc[i].first][loc[i].second+1]==1){
            s++;
        }
        if(mat[loc[i].first][loc[i].second-1]==1){
            s++;
        }
    }
    
    cout << s << endl;
    
    return 0;
}
