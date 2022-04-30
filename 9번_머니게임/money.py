from queue import PriorityQueue

inp = list(input().split())
nums, op = [], []
for i in range(len(inp)):
    nums.append(int(inp[i])) if i % 2 == 0 else op.append(inp[i])

size = len(nums) + 1
dp = [[(0, 0) for _ in range(size)] for _ in range(size)]
for i in range(1, size):
    dp[i][i] = nums[i-1], nums[i-1]

def get_arith(num1, idx, num2) -> int:
    if op[idx-1] == '*': return num1 * num2
    if op[idx-1] == '+': return num1 + num2
    if op[idx-1] == '-': return num1 - num2

def get_max_min(y, x):
    max_pq = PriorityQueue()
    min_pq = PriorityQueue()

    for i in range(y, x):
        t1, t2 = dp[y][i], dp[i+1][x]
        for j in range(2):
            for k in range(2):
                max_pq.put( get_arith(t1[j], i, t2[k]))
                min_pq.put(-get_arith(t1[j], i, t2[k]))

    return (max_pq.get(), -min_pq.get())

for i in range(1, len(nums)):
    for y in range(1, len(nums) + 1):
        x = y + i
        if x <= len(nums):
            dp[y][x] = get_max_min(y, x)

print(max(dp[1][len(nums)][0], dp[1][len(nums)][1]))
