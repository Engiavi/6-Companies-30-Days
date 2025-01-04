# Q1:- Circle and Rectangle Overlapping

## Problem Statement
You are given a circle represented as `(radius, xCenter, yCenter)` and an axis-aligned rectangle represented as `(x1, y1, x2, y2)`, where `(x1, y1)` are the coordinates of the bottom-left corner, and `(x2, y2)` are the coordinates of the top-right corner of the rectangle.

Return `true` if the circle and rectangle are overlapped otherwise return `false`. In other words, check if there is any point `(xi, yi)` that belongs to the circle and the rectangle at the same time.

## Approach
1. **Identify the Closest Point**: For the given circle center `(xCenter, yCenter)`, identify the closest point on the rectangle to this center. This can be done by clamping the circle's center coordinates to the rectangle's boundaries.
2. **Calculate Distance**: Compute the distance between the circle's center and this closest point.
3. **Check Overlap**: If the distance is less than or equal to the circle's radius, the circle and rectangle overlap.

## Intuition
The idea is to find the point on the rectangle that is closest to the circle's center. If this point lies within the circle, then the circle and rectangle overlap. This approach leverages the properties of axis-aligned rectangles and the Euclidean distance formula.

## Dry Run Examples

### Example 1:

**Input:**
- `radius = 1`
- `xCenter = 0`, `yCenter = 0`
- `x1 = 1`, `y1 = -1`, `x2 = 3`, `y2 = 1`

**Steps:**
1. Find the closest point on the rectangle to the circle's center:
   - `closestX = max(x1, min(xCenter, x2)) = max(1, min(0, 3)) = max(1, 0) = 1`
   - `closestY = max(y1, min(yCenter, y2)) = max(-1, min(0, 1)) = max(-1, 0) = 0`

   So, the closest point is `(1, 0)`.

2. Calculate the distance squared between the circle's center and the closest point:
   - `dx = closestX - xCenter = 1 - 0 = 1`
   - `dy = closestY - yCenter = 0 - 0 = 0`

   Distance squared = `dx * dx + dy * dy = 1 * 1 + 0 * 0 = 1`

3. Check if the distance squared is less than or equal to the square of the radius:
   - `1 <= 1 * 1 = 1`

   Since this condition is true, the circle and rectangle overlap, so the output is `true`.

---

### Example 2:

**Input:**
- `radius = 1`
- `xCenter = 1`, `yCenter = 1`
- `x1 = 1`, `y1 = -3`, `x2 = 2`, `y2 = -1`

**Steps:**
1. Find the closest point on the rectangle to the circle's center:
   - `closestX = max(x1, min(xCenter, x2)) = max(1, min(1, 2)) = max(1, 1) = 1`
   - `closestY = max(y1, min(yCenter, y2)) = max(-3, min(1, -1)) = max(-3, -1) = -1`

   So, the closest point is `(1, -1)`.

2. Calculate the distance squared between the circle's center and the closest point:
   - `dx = closestX - xCenter = 1 - 1 = 0`
   - `dy = closestY - yCenter = -1 - 1 = -2`

   Distance squared = `dx * dx + dy * dy = 0 * 0 + (-2) * (-2) = 4`

3. Check if the distance squared is less than or equal to the square of the radius:
   - `4 <= 1 * 1 = 1`

   Since this condition is false, the circle and rectangle do not overlap, so the output is `false`.

---

### Example 3:

**Input:**
- `radius = 1`
- `xCenter = 0`, `yCenter = 0`
- `x1 = -1`, `y1 = 0`, `x2 = 0`, `y2 = 1`

**Steps:**
1. Find the closest point on the rectangle to the circle's center:
   - `closestX = max(x1, min(xCenter, x2)) = max(-1, min(0, 0)) = max(-1, 0) = 0`
   - `closestY = max(y1, min(yCenter, y2)) = max(0, min(0, 1)) = max(0, 0) = 0`

   So, the closest point is `(0, 0)`.

2. Calculate the distance squared between the circle's center and the closest point:
   - `dx = closestX - xCenter = 0 - 0 = 0`
   - `dy = closestY - yCenter = 0 - 0 = 0`

   Distance squared = `dx * dx + dy * dy = 0 * 0 + 0 * 0 = 0`

3. Check if the distance squared is less than or equal to the square of the radius:
   - `0 <= 1 * 1 = 1`

   Since this condition is true, the circle and rectangle overlap, so the output is `true`.


# Q2:- Find the Winner of the Circular Game
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

### Rules of the Game:
1. Start at the 1st friend.
2. Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.

Given the number of friends, n, and an integer k, return the winner of the game.

### Approach:
The problem can be solved using the Josephus problem solution. We can use an iterative approach to find the winner.

1. Initialize the result as 0.
2. Iterate from 2 to n (inclusive).
3. Update the result using the formula: `res = (res + k) % player_num`.
4. Return `res + 1` as the winner.

### Dry Run Examples

#### Example 1:

**Input:**
- `n = 5`
- `k = 2`

**Steps:**
1. Initialize `res = 0`.
2. For `player_num = 2`: `res = (0 + 2) % 2 = 0`
3. For `player_num = 3`: `res = (0 + 2) % 3 = 2`
4. For `player_num = 4`: `res = (2 + 2) % 4 = 0`
5. For `player_num = 5`: `res = (0 + 2) % 5 = 2`

So, the winner is `res + 1 = 2 + 1 = 3`.

**Output:** `3`

#### Example 2:

**Input:**
- `n = 6`
- `k = 5`

**Steps:**
1. Initialize `res = 0`.
2. For `player_num = 2`: `res = (0 + 5) % 2 = 1`
3. For `player_num = 3`: `res = (1 + 5) % 3 = 0`
4. For `player_num = 4`: `res = (0 + 5) % 4 = 1`
5. For `player_num = 5`: `res = (1 + 5) % 5 = 1`
6. For `player_num = 6`: `res = (1 + 5) % 6 = 0`

So, the winner is `res + 1 = 0 + 1 = 1`.

**Output:** `1`

# Q3:- Image Smoother
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

### Approach:
1. Initialize the dimensions `m` and `n` of the image.
2. Create a new 2D vector `image` of the same dimensions to store the smoothed values.
3. Iterate through each cell `(i, j)` of the image.
4. For each cell, initialize `sum` and `cnt` to 0.
5. Iterate through the 3x3 grid centered at `(i, j)` using two nested loops with offsets `k` and `l` ranging from -1 to 1.
6. For each cell in the 3x3 grid, check if it is within the bounds of the image.
7. If it is within bounds, add its value to `sum` and increment `cnt`.
8. After processing the 3x3 grid, set `image[i][j]` to the integer division of `sum` by `cnt`.
9. Return the smoothed image.

### Dry Run Examples

#### Example 1:

**Input:**
- `img = [[1,1,1],[1,0,1],[1,1,1]]`

**Steps:**
1. Initialize `m = 3`, `n = 3`.
2. Create `image = [[0,0,0],[0,0,0],[0,0,0]]`.
3. Iterate through each cell `(i, j)`:
   - For `(0, 0)`: sum = 3, cnt = 4, image[0][0] = 3 // 4 = 0
   - For `(0, 1)`: sum = 4, cnt = 6, image[0][1] = 4 // 6 = 0
   - For `(0, 2)`: sum = 3, cnt = 4, image[0][2] = 3 // 4 = 0
   - For `(1, 0)`: sum = 4, cnt = 6, image[1][0] = 4 // 6 = 0
   - For `(1, 1)`: sum = 8, cnt = 9, image[1][1] = 8 // 9 = 0
   - For `(1, 2)`: sum = 4, cnt = 6, image[1][2] = 4 // 6 = 0
   - For `(2, 0)`: sum = 3, cnt = 4, image[2][0] = 3 // 4 = 0
   - For `(2, 1)`: sum = 4, cnt = 6, image[2][1] = 4 // 6 = 0
   - For `(2, 2)`: sum = 3, cnt = 4, image[2][2] = 3 // 4 = 0

**Output:** `[[0,0,0],[0,0,0],[0,0,0]]`

#### Example 2:

**Input:**
- `img = [[100,200,100],[200,50,200],[100,200,100]]`

**Steps:**
1. Initialize `m = 3`, `n = 3`.
2. Create `image = [[0,0,0],[0,0,0],[0,0,0]]`.
3. Iterate through each cell `(i, j)`:
   - For `(0, 0)`: sum = 550, cnt = 4, image[0][0] = 550 // 4 = 137
   - For `(0, 1)`: sum = 850, cnt = 6, image[0][1] = 850 // 6 = 141
   - For `(0, 2)`: sum = 550, cnt = 4, image[0][2] = 550 // 4 = 137
   - For `(1, 0)`: sum = 850, cnt = 6, image[1][0] = 850 // 6 = 141
   - For `(1, 1)`: sum = 1250, cnt = 9, image[1][1] = 1250 // 9 = 138
   - For `(1, 2)`: sum = 850, cnt = 6, image[1][2] = 850 // 6 = 141
   - For `(2, 0)`: sum = 550, cnt = 4, image[2][0] = 550 // 4 = 137
   - For `(2, 1)`: sum = 850, cnt = 6, image[2][1] = 850 // 6 = 141
   - For `(2, 2)`: sum = 550, cnt = 4, image[2][2] = 550 // 4 = 137

**Output:** `[[137,141,137],[141,138,141],[137,141,137]]`


# Minimum Cost to Convert String

## Problem Statement
Given two strings `source` and `target` of the same length, and three arrays `original`, `changed`, and `cost` where `original[i]` can be converted to `changed[i]` with a cost of `cost[i]`, find the minimum cost to convert `source` to `target`. If it is not possible to convert `source` to `target`, return `-1`.

## Approach
1. **Graph Representation**: Represent the conversion rules as a graph where each character is a node, and edges represent the conversion cost.
2. **Shortest Path Calculation**: Use Dijkstra's algorithm to calculate the shortest path between all pairs of nodes.
3. **Cost Calculation**: Calculate the total cost to convert `source` to `target` using the precomputed shortest paths.

## Algorithm
1. Initialize an adjacency list `adj` for the graph.
2. Populate the adjacency list using the `original`, `changed`, and `cost` arrays.
3. Initialize a 2D array `dist` to store the shortest path costs between all pairs of characters.
4. For each character, use Dijkstra's algorithm to compute the shortest path to all other characters.
5. Initialize `ans` to 0 to store the total conversion cost.
6. Iterate through each character of `source` and `target`:
   - Calculate the indices `x` and `y` corresponding to the characters in `source` and `target` respectively.
   - If `x` is not equal to `y`:
     - If `dist[x][y]` is equal to a large value (indicating no possible conversion), return `-1`.
     - Otherwise, add `dist[x][y]` to `ans`.
7. Return `ans` as the minimum cost.

## Dry Run

### Example 1:
**Input:**
- `source = "abcd"`
- `target = "acbe"`
- `original = ["a","b","c","c","e","d"]`
- `changed = ["b","c","b","e","b","e"]`
- `cost = [2,5,5,1,2,20]`

**Steps:**
1. Build the adjacency list:
   - `a -> b (2)`
   - `b -> c (5)`
   - `c -> b (5)`
   - `c -> e (1)`
   - `e -> b (2)`
   - `d -> e (20)`
2. Compute shortest paths using Dijkstra's algorithm.
3. Calculate the total cost:
   - `a -> c`: `a -> b -> c` (2 + 5 = 7)
   - `b -> c`: `b -> c` (5)
   - `c -> b`: `c -> e -> b` (1 + 2 = 3)
   - `d -> e`: `d -> e` (20)
   - Total cost = 7 + 0 + 3 + 20 = 28
4. Return `28`.

### Example 2:
**Input:**
- `source = "aaaa"`
- `target = "bbbb"`
- `original = ["a","c"]`
- `changed = ["c","b"]`
- `cost = [1,2]`

**Steps:**
1. Build the adjacency list:
   - `a -> c (1)`
   - `c -> b (2)`
2. Compute shortest paths using Dijkstra's algorithm.
3. Calculate the total cost:
   - `a -> b`: `a -> c -> b` (1 + 2 = 3)
   - Total cost = 3 + 3 + 3 + 3 = 12
4. Return `12`.

### Example 3:
**Input:**
- `source = "abcd"`
- `target = "abce"`
- `original = ["a"]`
- `changed = ["e"]`
- `cost = [10000]`

**Steps:**
1. Build the adjacency list:
   - `a -> e (10000)`
2. Compute shortest paths using Dijkstra's algorithm.
3. Calculate the total cost:
   - `d -> e`: No direct or indirect path
   - Return `-1`.

## Time and Space Complexity
- **Time Complexity** : 𝑂 ( 𝐸 + 𝑛 ) O(E+n), where 𝐸 E is the number of transformation rules and 𝑛 n is the length of the source string. 
- **Space Complexity**: 𝑂 ( 𝐸 ) O(E).