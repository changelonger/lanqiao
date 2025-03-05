dp = [0]*23
for i in range(1,23):
    dp[i] = i-1

print(dp[20]*dp[22]+dp[10]+dp[22]+4)
