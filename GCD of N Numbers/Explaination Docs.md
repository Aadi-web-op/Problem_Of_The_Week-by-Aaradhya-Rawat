# GCD of an Array

## 🔹 Problem Statement
Given an array of integers, find the **Greatest Common Divisor (GCD)** of all the elements in the array.

---

## 🔹 Logic Used
1. **Euclidean Algorithm for GCD**  
   - The `gcd(a, b)` function is implemented using recursion.  
   - Base case: if `b == 0`, return `a`.  
   - Recursive step: `gcd(a, b) = gcd(b, a % b)`.

2. **Finding GCD of the Array**  
   - Start with the first element of the vector as the initial GCD.  
   - Iteratively compute the GCD of the current result with the next element in the array.  
   - At the end, the result will be the GCD of the entire array.

---

## 🔹 Complexity Analysis

### Time Complexity
- Euclidean algorithm runs in **O(log(min(a, b)))** for two numbers.  
- Since we apply it across all elements:  
  **O(n × log(max_element))**,  
  where `n` is the array size.

### Space Complexity
- Only a few variables are used.  
- Recursive calls use **O(log(min(a, b)))** space on the call stack.  
- **Overall: O(1) auxiliary space** (ignoring recursion stack).