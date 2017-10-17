/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
