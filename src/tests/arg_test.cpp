#include <bits/stdc++.h>

using namespace std;
vector<int> graph[10];
void print(char a[8][8]){
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) printf("%c", a[i][j]);
}

int main(){
    char ans[8][8];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) ans[i][j] = 'x';
    print(ans);

    return 0;
}