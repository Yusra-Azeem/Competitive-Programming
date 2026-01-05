# Building an Aquarium

### Time Limit

2 seconds

### Memory Limit

256 megabytes

## Description

You love fish, that's why you have decided to build an aquarium. You have a piece of coral made of `n` columns, where the `i`-th column is `aᵢ` units tall.

You will build a tank around the coral as follows:

- Pick an integer `h ≥ 1` — the height of the tank.
- Build walls of height `h` on either side of the tank.
- Fill the tank with water so that the height of each column becomes `h`, **unless** the coral column is already taller than `h`. In that case, no water is added to that column.

The amount of water required is the total added height across all columns.

### Example

For  
`a = [3, 1, 2, 4, 6, 2, 5]` and `h = 4`  
the total water used is `8` units.

![alt text](image.png)

You can use **at most `x` units of water**, but you want to build the **tallest possible tank**.

Your task is to find the **maximum possible value of `h`** such that the total water used does not exceed `x`.

---

## Input

The first line contains a single integer `t`  
`(1 ≤ t ≤ 10⁴)` — the number of test cases.

For each test case:

- The first line contains two integers `n` and `x`  
  `(1 ≤ n ≤ 2·10⁵, 1 ≤ x ≤ 10⁹)`  
  — the number of columns and the maximum water available.
- The second line contains `n` integers `a₁, a₂, ..., aₙ`  
  `(1 ≤ aᵢ ≤ 10⁹)` — the heights of the coral columns.

The sum of `n` over all test cases does not exceed `2·10⁵`.

---

## Output

For each test case, output a single integer `h (h ≥ 1)` — the **maximum height** of the tank such that at most `x` units of water are required.

It is guaranteed that such a value of `h` always exists.

---

## Examples

### Input

```
5
7 9
3 1 2 4 6 2 5
3 10
1 1 1
4 1
1 4 3 4
6 1984
2 6 5 9 1 8
1 1000000000
1

```

### Output

```
4
4
2
335
1000000001

```
