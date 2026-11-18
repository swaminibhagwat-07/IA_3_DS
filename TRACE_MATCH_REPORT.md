# Trace-Match Report
PRN: 202501100023 | S=23 | Scenario: Student Marks | Mid-square | Separate chaining | m=13

Hash rule: square the key, drop the last digit, take the next two digits (middle of the 4-digit square), then mod 13.

## Hand-predicted steps (key, key^2, middle two digits, bucket)
| key | key^2 | mid | mod 13 |
|---|---|---|---|
| 23 | 529 | 52 | 0 |
| 36 | 1296 | 29 | 3 |
| 49 | 2401 | 40 | 1 |
| 62 | 3844 | 84 | 6 |
| 75 | 5625 | 62 | 10 |
| 88 | 7744 | 74 | 9 |
| 1 | 1 | 0 | 0 |
| 14 | 196 | 19 | 6 |
| 27 | 729 | 72 | 7 |
| 40 | 1600 | 60 | 8 |
| 53 | 2809 | 80 | 2 |
| 66 | 4356 | 35 | 9 |
| 79 | 6241 | 24 | 11 |
| 92 | 8464 | 46 | 7 |
| 5 | 25 | 2 | 2 |
| 18 | 324 | 32 | 6 |
| 31 | 961 | 96 | 5 |
| 44 | 1936 | 93 | 2 |
| 57 | 3249 | 24 | 11 |
| 70 | 4900 | 90 | 12 |

## Hand-predicted final table
| Bucket | Chain |
|---|---|
| 0 | 23 -> 1 |
| 1 | 49 |
| 2 | 53 -> 5 -> 44 |
| 3 | 36 |
| 4 | - |
| 5 | 31 |
| 6 | 62 -> 14 -> 18 |
| 7 | 27 -> 92 |
| 8 | 40 |
| 9 | 88 -> 66 |
| 10 | 75 |
| 11 | 79 -> 57 |
| 12 | 70 |

## Actual output
See `output.txt` (captured from `./lab`). The final table matches the prediction in every bucket.

## Mismatches and discrepancies
1. **Attempt 1 (commit 2) vs prediction:** that version printed bucket 3 for key 23, but my hand prediction was 0 (23^2=529, mid=52, 52 mod 13=0). Cause: I used the LAST two digits of the square (29) rather than the middle ones. Fixed in commit 3.
2. **Single-digit squares (1, 5):** 1^2=1 and 5^2=25. Treated as 0001 and 0025, the middle digits are 00 and 02, giving buckets 0 and 2. The program matches since integer division by 10 handles the zero-padding implicitly.
3. **Duplicate test:** inserting 23 again is correctly ignored (commit 6).
