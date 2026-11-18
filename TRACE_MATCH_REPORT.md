# Trace-Match Report

PRN: 202501100023 | S=23 | Search key=26 | Sort order=Descending | Hash table size m=11

Dataset: `76, 2, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38`

> Write this portfolio by hand for submission. This Markdown is a preparation guide; the assignment requires handwritten traces and scanned pages.

## 1. Bubble Sort (descending)

Initial: `76, 2, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38`

```text
Pass 1:  76, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38, 2
Pass 2:  76, 48, 71, 94, 25, 43, 66, 89, 20, 38, 15, 2
Pass 3:  76, 71, 94, 48, 43, 66, 89, 25, 38, 20, 15, 2
Pass 4:  76, 94, 71, 48, 66, 89, 43, 38, 25, 20, 15, 2
Pass 5:  94, 76, 71, 66, 89, 48, 43, 38, 25, 20, 15, 2
Pass 6:  94, 76, 71, 89, 66, 48, 43, 38, 25, 20, 15, 2
Pass 7:  94, 76, 89, 71, 66, 48, 43, 38, 25, 20, 15, 2
Pass 8:  94, 89, 76, 71, 66, 48, 43, 38, 25, 20, 15, 2
Pass 9:  no swaps; unchanged
Pass 10: no swaps; unchanged
Pass 11: no swaps; unchanged
```

Show each adjacent comparison and swap on your handwritten page; the lines above are pass-end states.

## 2. Insertion Sort (descending)

```text
Initial: 76, 2, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38
Insert 2: 76, 2, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38
Insert 25: 76, 25, 2, 48, 71, 94, 20, 43, 66, 89, 15, 38
Insert 48: 76, 48, 25, 2, 71, 94, 20, 43, 66, 89, 15, 38
Insert 71: 76, 71, 48, 25, 2, 94, 20, 43, 66, 89, 15, 38
Insert 94: 94, 76, 71, 48, 25, 2, 20, 43, 66, 89, 15, 38
Insert 20: 94, 76, 71, 48, 25, 20, 2, 43, 66, 89, 15, 38
Insert 43: 94, 76, 71, 48, 43, 25, 20, 2, 66, 89, 15, 38
Insert 66: 94, 76, 71, 66, 48, 43, 25, 20, 2, 89, 15, 38
Insert 89: 94, 89, 76, 71, 66, 48, 43, 25, 20, 2, 15, 38
Insert 15: 94, 89, 76, 71, 66, 48, 43, 25, 20, 15, 2, 38
Insert 38: 94, 89, 76, 71, 66, 48, 43, 38, 25, 20, 15, 2
```

Show each key comparison and each shift, including the insertion position, in the handwritten trace.

## 3. Quick Sort (descending, Lomuto partition; last element pivot)

Initial array: `76, 2, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38`

Partition sequence (subarray bounds are zero-based):

| Subarray | Pivot | Array after partition |
|---|---:|---|
| 0..11 | 38 | 76, 48, 71, 94, 43, 66, 89, 38, 15, 2, 20, 25 |
| 0..6 | 89 | 94, 89, 71, 76, 43, 66, 48, 38, 15, 2, 20, 25 |
| 2..6 | 48 | 94, 89, 71, 76, 48, 66, 43, 38, 15, 2, 20, 25 |
| 4..6 | 43 | 94, 89, 71, 76, 48, 66, 43, 38, 15, 2, 20, 25 |
| 5..6 | 66 | 94, 89, 71, 66, 48, 43, 76, 38, 15, 2, 20, 25 |
| 0..3 | 66 | 94, 89, 71, 66, 48, 43, 76, 38, 15, 2, 20, 25 |
| 0..2 | 76 | 94, 89, 76, 66, 48, 43, 71, 38, 15, 2, 20, 25 |
| 0..1 | 89 | 94, 89, 76, 66, 48, 43, 71, 38, 15, 2, 20, 25 |
| 8..11 | 25 | 94, 89, 76, 66, 48, 43, 71, 38, 25, 2, 20, 15 |
| 9..11 | 15 | 94, 89, 76, 66, 48, 43, 71, 38, 25, 20, 15, 2 |

Sorted result: `94, 89, 76, 71, 66, 48, 43, 38, 25, 20, 15, 2`

## 4. Radix Sort (LSD, descending, stable digit passes)

Pad values to two digits for digit processing. For each pass, stably order digit buckets from 9 down to 0.

```text
Initial:       76, 02, 25, 48, 71, 94, 20, 43, 66, 89, 15, 38
Units pass:    89, 48, 38, 76, 66, 25, 15, 94, 43, 02, 20, 71
Tens pass:     94, 89, 76, 71, 66, 48, 43, 38, 25, 20, 15, 02
```

## 5. Search traces

For binary and Fibonacci search use ascending array: `2, 15, 20, 25, 38, 43, 48, 66, 71, 76, 89, 94`. Search key: `26` (not present).

### Linear Search

```text
Index:value comparisons
0:2, 1:15, 2:20, 3:25, 4:38, 5:43, 6:48, 7:66, 8:71, 9:76, 10:89, 11:94
Result: not found after 12 comparisons.
```

### Binary Search

| Step | low | high | mid | A[mid] | Update |
|---:|---:|---:|---:|---:|---|
| 1 | 0 | 11 | 5 | 43 | 26 < 43, high=4 |
| 2 | 0 | 4 | 2 | 20 | 26 > 20, low=3 |
| 3 | 3 | 4 | 3 | 25 | 26 > 25, low=4 |
| 4 | 4 | 4 | 4 | 38 | 26 < 38, high=3 |

Stop when `low=4 > high=3`: not found.

### Fibonacci Search

Array length 12; initial Fibonacci numbers `F_m=13, F_(m-1)=8, F_(m-2)=5`; offset `-1`.

| Probe | Index | Value | Decision / update |
|---:|---:|---:|---|
| 1 | 4 | 38 | 26 < 38; narrow left interval (`F_m=8`, `F_(m-1)=5`, `F_(m-2)=3`), offset remains -1 |
| 2 | 2 | 20 | 26 > 20; offset=2; remaining Fibonacci sizes 3,2,1 |
| 3 | 3 | 25 | 26 > 25; offset=3; remaining Fibonacci sizes 1,1,0 |

No element remains to inspect; key 26 is not found. (If your class uses a specific Fibonacci Search variant, follow its exact variable-update convention.)

## 6. Hashing

For Question 1 use `h(key)=key mod 11`. Insert in the original dataset order. Linear probing uses `(h(key)+j) mod 11` for `j=0...10`; separate chaining appends each key to the bucket list.

### Linear probing insertion trace

| Key | Initial hash | Probe sequence | Result |
|---:|---:|---|---|
| 76 | 10 | 10 | slot 10 |
| 2 | 2 | 2 | slot 2 |
| 25 | 3 | 3 | slot 3 |
| 48 | 4 | 4 | slot 4 |
| 71 | 5 | 5 | slot 5 |
| 94 | 6 | 6 | slot 6 |
| 20 | 9 | 9 | slot 9 |
| 43 | 10 | 10, 0 | slot 0 |
| 66 | 0 | 0, 1 | slot 1 |
| 89 | 1 | 1, 2, 3, 4, 5, 6, 7 | slot 7 |
| 15 | 4 | 4, 5, 6, 7, 8 | slot 8 |
| 38 | 5 | 5, 6, 7, 8, 9, 10, 0, 1, 2, 3, 4 | table full; cannot insert |

Final table: `[0]=43, [1]=66, [2]=2, [3]=25, [4]=48, [5]=71, [6]=94, [7]=89, [8]=15, [9]=20, [10]=76`.

### Separate chaining insertion trace

| Key | Bucket | Bucket chain after insertion |
|---:|---:|---|
| 76 | 10 | 10: 76 |
| 2 | 2 | 2: 2 |
| 25 | 3 | 3: 25 |
| 48 | 4 | 4: 48 |
| 71 | 5 | 5: 71 |
| 94 | 6 | 6: 94 |
| 20 | 9 | 9: 20 |
| 43 | 10 | 10: 76 -> 43 |
| 66 | 0 | 0: 66 |
| 89 | 1 | 1: 89 |
| 15 | 4 | 4: 48 -> 15 |
| 38 | 5 | 5: 71 -> 38 |

Final table:

| Bucket | Chain |
|---:|---|
| 0 | 66 |
| 1 | 89 |
| 2 | 2 |
| 3 | 25 |
| 4 | 48 -> 15 |
| 5 | 71 -> 38 |
| 6 | 94 |
| 7 | empty |
| 8 | empty |
| 9 | 20 |
| 10 | 76 -> 43 |
```
