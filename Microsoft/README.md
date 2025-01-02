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