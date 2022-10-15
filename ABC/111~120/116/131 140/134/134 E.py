N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

dp = [A[0]]
for k in range(1,N):
    if min(dp) >= A[k]:
        dp.insert(0,A[k])

    elif (max(dp) < A[k]):
        dp[len(dp)-1] = A[k]

    else:
        for i in range(len(dp)):
            if (dp[i] < A[k]) and (A[k] <= dp[i+1]):
                dp[i] = A[k]
                break
    

print(len(dp))


