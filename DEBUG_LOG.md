# Debugging Log

**PRN:** 202501100023  
**Seed:** S = 23 (last four digits of the PRN)  
**Scenario:** Student Marks (PRN mod 3 = 1)  
**Hash Method:** Mid-square (PRN is odd)  
**Collision Handling:** Separate chaining (PRN mod 2 = 1)  
**Table Size:** m = 11, using the assignment's PRN-based rule: smallest prime greater than or equal to `(S mod 23) + 11`.

## Commit 1 – Personalized Dataset

I generated the personalized 20-value dataset with `v[i] = (S + 13*i) mod 100`, using seed `S = 23`. The dataset is `23, 36, 49, 62, 75, 88, 1, 14, 27, 40, 53, 66, 79, 92, 5, 18, 31, 44, 57, 70`. The values are unique. The program compiled and printed the dataset.

## Commit 2 – First Hash Attempt (Low Digits of the Square)

My first hash attempt squared each key and used `(sq % 100) % m`. I thought this was the mid-square method, but it takes the last two digits of the square. For key 23, it uses 29, whereas the middle two digits of the four-digit form 0529 are 52. With `m = 11`, the correct bucket for key 23 is `52 mod 11 = 8`; the low-digit attempt gives `29 mod 11 = 7`. I abandoned the low-digit method.

## Commit 3 – Correct Mid-Square Hash Function

I changed the hash function to square the key, pad the square to four digits, take the middle two digits, and reduce that value modulo 11. For example, `23² = 0529`, so the middle digits are 52 and the bucket is `52 mod 11 = 8`. For `36² = 1296`, the middle digits are 29 and the bucket is `29 mod 11 = 7`. I compared the calculated bucket for each dataset value with my hand calculation.

## Commit 4 – Hash Table with Separate Chaining and Insertion

I implemented a hash table with 11 buckets, using a vector of lists. The insert function calculates the mid-square bucket and appends the key to that bucket's chain. For example, keys 62, 14, and 18 all map to bucket 8 with this rule, so their chain is `62 -> 14 -> 18`. The program prints the bucket for each insertion.

## Commit 5 – Display Function

I added a display function that prints every bucket and its chain. At first, empty buckets were not clearly shown. I changed the display so empty buckets print `NULL` and non-empty buckets show each key followed by an arrow and `NULL`.

## Commit 6 – Duplicate Handling and Search

I tested inserting 23 a second time. The first version allowed a duplicate, so I changed insertion to scan the target chain and ignore a key already present. I also added search, which calculates the key's bucket and scans that chain. I checked that 53 is found and 99 is not found.

## Commit 7 – Trace-Match Report, Debug Log, and Program Output

I prepared the trace-match report and captured the program's console output. The hand-predicted bucket and chain results were compared with the actual output. Any mismatch found during comparison must be corrected in the code or explained in the report; the final report should match the final code using `m = 11`.

## Commit 8 – Git Log Export

I exported the repository history with `git log --stat` for submission.

## Commit 9 – Log Export Cleanup

I removed an outdated log export and regenerated the file for submission. The submitted export should reflect the current repository history.

## Table Size Correction Required

My earlier source and report used `m = 13`. Rechecking the assignment's PRN-based table-size rule gives `m = 11`: `(23 mod 23) + 11 = 11`, and 11 is prime. I need to update the source, README, trace-match report, and captured output to use 11, then commit that correction and regenerate the Git log export. The previous commit history should remain unchanged; the correction should be recorded as a new commit with its actual timestamp.

## Failed Approach – Low Digits Instead of Middle Digits

Initially, I used `(key * key) % 100` before applying the table-size modulus. This uses the low two digits, so it is not the assigned mid-square method. For key 23, it takes 29 instead of the middle digits 52. I replaced it with a method that extracts the middle two digits of a four-digit, zero-padded square, then takes the result modulo 11.
