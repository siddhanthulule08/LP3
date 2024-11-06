def knapsack(W, weights, values, n):
    # Create a 1D DP array to store the maximum value for each capacity
    dp = [0] * (W + 1)

    # Process each item one by one
    for i in range(n):
        # Traverse backwards to avoid recomputing within the same iteration
        for w in range(W, weights[i] - 1, -1):
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]])

    return dp[W]  # The maximum value for the full capacity

# Input
n = int(input("Enter the number of items: "))
W = int(input("Enter the maximum weight capacity of the knapsack: "))
weights = list(map(int, input("Enter the weights of the items: ").split()))
values = list(map(int, input("Enter the values of the items: ").split()))

# Solve the knapsack problem
max_value = knapsack(W, weights, values, n)
print("The maximum value that can be achieved is:", max_value)