# Hash Table Lab: Student Marks (Data Structures, Internal Activity 3)

**Subject:** Data Structures (2310212 T), MIT Academy of Engineering, Alandi
**PRN:** 202501100023
**Course Outcomes:** CO5 (searching and sorting), CO6 (hashing)

A C++ hash table that stores a personalized dataset of student marks. The project was built step by step with incremental git commits and a debugging log.

## Personalization Key (S = 23)

| Parameter | Rule | My value |
|---|---|---|
| Domain scenario | PRN mod 3 = 1 | Student marks |
| Dataset (20 values) | v[i] = (23 + 13*i) mod 100 | 23, 36, 49, 62, 75, 88, 1, 14, 27, 40, 53, 66, 79, 92, 5, 18, 31, 44, 57, 70 |
| Hash function | PRN is odd | Mid-square method |
| Collision strategy | PRN mod 2 = 1 | Separate chaining |
| Table size | Chosen by me | m = 13 |

## How the hash works

1. Square the key.
2. Drop the last digit and take the next two digits (the middle of the 4-digit square).
3. Take that number mod 13 to get the bucket.

Example: 23 -> 529 -> 52 -> 52 mod 13 = bucket 0.
Keys that land in the same bucket are stored in a linked list (a chain).

## Files

| File | Contents |
|---|---|
| `main.cpp` | C++ source with the PRN and key values in the header comment. Implements insert, duplicate check, search and display. |
| `DEBUG_LOG.md` | One entry per commit, including a failed approach (taking the low digits of the square instead of the middle digits). |
| `TRACE_MATCH_REPORT.md` | Hand-predicted table versus actual output, with discrepancies explained. |
| `git_log.txt` | Export of `git log --stat` showing the full commit history with timestamps. |
| `README.md` | This file. |

## Build and run

```bash
g++ main.cpp -o lab
./lab
```

The program prints the dataset, the bucket for each insertion, the final table, a duplicate-key test (re-inserting 23) and two search tests (53 is found, 99 is not).

## Expected final table

```
[0]  23 -> 1 -> NULL
[1]  49 -> NULL
[2]  53 -> 5 -> 44 -> NULL
[3]  36 -> NULL
[4]  NULL
[5]  31 -> NULL
[6]  62 -> 14 -> 18 -> NULL
[7]  27 -> 92 -> NULL
[8]  40 -> NULL
[9]  88 -> 66 -> NULL
[10] 75 -> NULL
[11] 79 -> 57 -> NULL
[12] 70 -> NULL
```

## Submission checklist

- [x] Source code with PRN and key values in the header comment
- [x] Git log export (`git log --stat`)
- [x] Debugging log with a failed approach
- [x] Trace-Match Report
- [ ] Screen recording (max 4 minutes) of running and explaining the program
