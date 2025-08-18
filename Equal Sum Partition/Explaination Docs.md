# Partition Equal Subset Sum

## Problem
Given an integer array `nums`, return `true` if the array can be partitioned into two subsets such that the sum of the elements in both subsets is equal.

---

## Logic / Approach

1. **Total Sum Check**  
   - Compute the sum of all elements: `total = sum(nums)`.  
   - If `total` is **odd**, partitioning is impossible → return `false`.  

2. **Target Subset Sum**  
   - We need to check if there exists a subset of `nums` whose sum is `target = total / 2`.  
   - If such a subset exists, the other subset will also have sum `target`.  

3. **Dynamic Programming (Subset Sum)**  
   - We use a boolean DP array `dp` of size `target + 1`.  
   - `dp[s] = true` means there exists a subset of `nums` that sums to `s`.  
   - Initialize `dp[0] = true` (empty subset gives sum `0`).  

4. **Transition**  
   - For each number `num` in `nums`:  
     - Traverse possible sums `s` from `target` down to `num`:  
       - If `dp[s - num]` is `true`, set `dp[s] = true`.  
   - This ensures we don’t reuse the same number multiple times.  

5. **Final Answer**  
   - Return `dp[target]`.  
   - If `true`, then the array can be partitioned into two equal subsets.

---

## Example Walkthrough

Input:  
nums = [1, 5, 11, 5]

- `total = 22` → even 
- `target = 11`  

Processing numbers:  
- After `1`: possible sums = `{0, 1}`  
- After `5`: possible sums = `{0, 1, 5, 6}`  
- After `11`: possible sums = `{0, 1, 5, 6, 11}` → found `11` 


## Complexity Analysis

- **Time Complexity:**  
  - `O(n * target)`  
  - Where `n` is the number of elements, and `target = total/2`.  
  - Each number potentially updates up to `target` states.  

- **Space Complexity:**  
  - `O(target)`  
  - We only keep a 1D DP array of size `target + 1`.  