# Word Search in 2D Matrix

## Problem Statement
Given an m x n grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may **not** be used more than once.

---

## Approach: DFS + Backtracking

### Idea
The problem can be solved using **Depth First Search (DFS)** with **backtracking**:

1. Start from every cell in the grid.
2. If the current cell matches the first character of the word, recursively try all four directions:
   - Up
   - Down
   - Left
   - Right
3. During DFS:
   - Mark the current cell as **visited** (e.g., temporarily replace it with `'#'`).
   - If all characters of the word are matched → return `true`.
   - If a path fails, **backtrack** by restoring the character and continue exploring other directions.
4. If no path leads to a match, return `false`.

---

## Time Complexity

- Let:
  - `M` = number of rows in the board
  - `N` = number of columns in the board
  - `L` = length of the target word

### Step 1: Starting Points
We can start a DFS from every cell in the grid.  
That gives us `M * N` possible starting positions.

### Step 2: DFS Exploration
At each character, we try moving in **4 directions** (`up, down, left, right`).  
- In the **worst case**, all paths are explored until length `L`.  
- This gives a branching factor of `4` and depth `L`.  

So, DFS complexity per starting cell = `O(4^L)`

### Step 3: Combine
Total complexity: O(M * N * 4^L)

## Space Complexity

1. **Recursion Stack (DFS depth):**  
   - In the worst case, DFS goes as deep as the length of the word (`L`).  
   - So, recursion stack = `O(L)`.

2. **Visited Marking:**  
   - Instead of extra memory, the algorithm modifies the board in-place (marks a cell as `'#'` temporarily).  
   - No extra data structures used.  
   - Hence, `O(1)` extra space.

---

## Final Complexity

- **Time Complexity:** `O(M * N * 4^L)`  
- **Space Complexity:** `O(L)` (recursion stack)