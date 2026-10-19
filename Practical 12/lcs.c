#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

int max(int a, int b){if(a>b){return a;}else{return b;}}

int lcsOf3(char X[], char Y[], char Z[], int m, int n, int o){
	
	//write your code here...
if(m > 0 && X[m - 1] == '\n')
			m--;
	if(n > 0 && Y[n - 1] == '\n')
		n--;
	if(o > 0 && Z[o - 1] == '\n')
		o--;

	int dp[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH] = {0};
	int i,j,k;
	for(i = 1;i<=m;i++){
		for(j = 1;j<=n;j++){
			for(k = 1;k<=o;k++){
				if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]){
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}else{
					dp[i][j][k] = max(max(dp[i - 1][j][k],dp[i][j - 1][k]),dp[i][j][k - 1]);
				}
			}
		}
	}

	return dp[m][n][o];

}

int main()
{	char x[MAX_LENGTH], y[MAX_LENGTH],z[MAX_LENGTH];
    fgets(x, MAX_LENGTH, stdin);
    fgets(y, MAX_LENGTH, stdin);
    fgets(z, MAX_LENGTH, stdin);
	printf("%d", lcsOf3(x, y, z, strlen(x), strlen(y), strlen(z)));
	
	return 0;
}