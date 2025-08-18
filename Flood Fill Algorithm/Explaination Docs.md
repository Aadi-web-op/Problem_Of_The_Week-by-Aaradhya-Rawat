# Flood Fill Algorithm (Recursive DFS)

## 🔹 Logic
The problem is to perform a **flood fill** on a 2D image starting from a given pixel `(sr, sc)` and replacing all connected pixels of the same original color with a new color.

1. **Identify the original color**:
   - Store the color at `(sr, sc)` as `og`.

2. **Check for redundant fill**:
   - If `og` is the same as the new `color`, nothing needs to be done.

3. **Depth-First Search (DFS)**:
   - From the starting cell `(sr, sc)`, recursively explore its **four neighbors** (up, down, left, right).
   - At each step:
     - Check if the current pixel is within bounds and has the same color as `og`.
     - Change its color to the new `color`.
     - Recurse into its neighbors.

4. **Termination**:
   - The recursion stops when:
     - We go out of bounds, OR
     - The current pixel has a different color than `og`.

5. **Result**:
   - After DFS finishes, all connected pixels of the original color are updated to the new color.

---

## 🔹 Time Complexity
- Each pixel is **visited at most once**.
- For an image of size `m x n`:
  - **O(m × n)** in the worst case (if we need to fill the entire grid).

---

## 🔹 Space Complexity
- The recursion depth can go as deep as the number of pixels.
- Worst case: **O(m × n)** (when the fill spreads to the entire grid).
- For most cases, it’s proportional to the size of the connected component being filled.

---