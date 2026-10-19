#include<stdio.h>
#define INF 999999
int n;
int cost[20][20];
int dp[1 << 20][20];

int tsp(int mask, int pos){
	if (mask == (1 << n) - 1)
		return cost[pos][0];

	if (dp[mask][pos] != -1)
		return dp[mask][pos];

	int ans = INF;

	for(int city = 0;city < n;city++){
		if ((mask & (1 << city)) == 0 && cost[pos][city] != -1){
			int newCost = cost[pos][city] + tsp(mask | (1 << city ),city);

			if (newCost < ans)
				ans = newCost;
		}
	}
	dp[mask][pos] = ans;
	return ans;
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == -1)
				cost[i][j] = -1;
		}
	}

	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			dp[i][j] = -1;
		}
	}
	printf("%d\n",tsp(1,0));
	return 0;
}