#include<iostream>
#include<vector>
using namespace std;

int X,Y,h;
const int modulo=1000000007;

unsigned int dp[43][43][21]={0};
void solve(){
    dp[23][22][1]=1;

    for(int x=0;x<43;++x){
        for(int y=0;y<43;++y){
            for(int z=1;z<=h;++z){
                if(x-1>=0) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y][z]))%modulo;
                if(x-1>=0&&y-1>=0) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y-1][z]))%modulo;
                if(x-1>=0&&y+1<=42) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y+1][z]))%modulo;
                if(x-1>=0&&z>1) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y][z-1]))%modulo;
                if(x-1>=0&&y-1>=0&&z>1) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y-1][z-1]))%modulo;
                if(x-1>=0&&y+1<=42&&z>1) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y+1][z-1]))%modulo;
                //lower
                if(x-1>=0&&z<h) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y][z+1]))%modulo;
                if(x-1>=0&&y-1>=0&&z<h) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y-1][z+1]))%modulo;
                if(x-1>=0&&y+1<=42&&z<h) dp[x][y][z]=(dp[x][y][z]+(dp[x-1][y+1][z+1]))%modulo;
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&X,&Y,&h);
    solve();
    printf("%d \n",dp[X-1+22][Y+22][1]);
    return 0;
}