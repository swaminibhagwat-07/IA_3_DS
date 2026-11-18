# Hash Table Lab Project – Student Marks

**Course:** Data Structures (2310212 T)  
**Activity:** Internal Activity 3, Question 2  
**Institution:** MIT Academy of Engineering, Alandi  
**PRN:** 202501100023

This project implements a hash table for the personalized Student Marks dataset required by Question 2.

## Personalization Key

| Parameter | Rule | Value for this PRN |
|---|---|---|
| Seed | Last four digits of PRN | `S = 23` |
| Scenario | PRN mod 3: 0 = cold-drink flavours, 1 = student marks, 2 = mango varieties | Student Marks |
| Dataset | `v[i] = (S + 13*i) mod 100`, `i = 0..19` | `23, 36, 49, 62, 75, 88, 1, 14, 27, 40, 53, 66, 79, 92, 5, 18, 31, 44, 57, 70` |
| Hash function | Even PRN: division; odd PRN: mid-square | Mid-square |
| Collision handling | Even PRN: linear probing; odd PRN: separate chaining | Separate chaining |
| Table size | Same PRN personalization rule as Question 1: smallest prime `>= (S mod 23) + 11` | `m = 11` |

## Hash Function

For each key, square it, represent the square as four digits by padding with leading zeroes when necessary, take the middle two digits, then take that value modulo 11.

Examples:

- `23² = 0529`; middle digits `52`; `52 mod 11 = 8`.
- `36² = 1296`; middle digits `29`; `29 mod 11 = 7`.

Keys with the same bucket index are stored in the same linked-list chain, in insertion order. Duplicate keys are ignored.

## Files

| File | Purpose |
|---|---|
| `main.cpp` | C++ source with PRN and personalization details in its header comment. |
| `DEBUG_LOG.md` | One debugging entry per development commit, including a genuine failed approach and its correction. |
| `TRACE_MATCH_REPORT.md` | Hand-predicted hash results compared with the program's actual output, with discrepancies explained. |
| `output.txt` | Captured console output from running the final program. |
| `git_log.txt` | Git history exported with `git log --stat`, including timestamps. |
| Screen recording | Unedited recording, maximum four minutes, showing the program running and explaining the output. |

## Build and Run

```bash
g++ -std=c++17 -Wall -Wextra -o lab main.cpp
./lab
```

The program prints the personalized dataset, each insertion and bucket, the final table, a duplicate-key check, and search results.

## Expected Final Table

This table follows the mid-square rule above and insertion order from the personalized dataset.

```text
[0]  36 -> 57 -> NULL
[1]  79 -> NULL
[2]  25 -> 48 -> 66 -> 18 -> NULL
[3]  88 -> 92 -> NULL
[4]  14 -> 31 -> NULL
[5]  49 -> 53 -> 5 -> NULL
[6]  62 -> 70 -> NULL
[7]  23 -> 40 -> NULL
[8]  75 -> NULL
[9]  27 -> 44 -> NULL
[10] 1 -> 94 -> 15 -> NULL
```

## Submission Checklist

- [ ] `main.cpp` uses the correct PRN-derived values and table size `m = 11`.
- [ ] The program was run after the final code change and `output.txt` contains that run's output.
- [ ] `TRACE_MATCH_REPORT.md` matches the final code and actual output.
- [ ] `DEBUG_LOG.md` accurately describes the real development steps and commits, including the failed approach.
- [ ] `git_log.txt` was regenerated from the final repository using `git log --stat`.
- [ ] The unedited screen recording (maximum four minutes) was recorded and included.
- [ ] All submitted filenames and personalization values agree across the source, report, logs, and README.

**Important:** If your current code or repository history still uses `m = 13`, update the implementation and related report/output, record the correction in a new commit, and regenerate the Git log. Preserve the real commit history and timestamps; do not backdate or rewrite them.
