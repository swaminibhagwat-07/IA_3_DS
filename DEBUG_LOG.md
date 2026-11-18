# Debugging Log

**PRN:** 202501100023

**Scenario:** Student Marks

**Hash Method:** Mid-Square Method

**Collision Handling:** Separate Chaining

**Table Size:** 13

## Commit 1 – Personalized Dataset

I created the personalized dataset using the given PRN-based formula v[i] = (S + 13×i) mod 100 with seed 23 (last four digits of the PRN). I wrote a function that generates all 20 values and prints them. The values were 23, 36, 49, 62, 75, 88, 1, 14, 27, 40, 53, 66, 79, 92, 5, 18, 31, 44, 57, 70, and all were unique. The program compiled and ran without errors.

## Commit 2 – First Hash Attempt (Low Digits of the Square)

I wrote my first hash function by squaring the key and taking `sq % 100 % 13`, thinking that this was the mid-square method. It compiled and produced indexes between 0 and 12. When I compared it with my hand calculation, key 23 gave bucket 3 instead of 0 (23² = 529, middle digits 52, 52 mod 13 = 0). I realised this function uses the last two digits of the square, not the middle digits, so it is not the mid-square method.

## Commit 3 – Correct Mid-Square Hash Function

I fixed the hash function. The key is squared, the last digit is dropped using `/ 10`, and the next two digits are taken using `% 100`. These middle two digits are then reduced with `% 13` to fit the table. All 20 computed indexes now matched my hand calculations. For example, 23 → 529 → 52 → bucket 0, and 36 → 1296 → 29 → bucket 3.

## Commit 4 – Hash Table with Separate Chaining and Insertion

I created a `HashTable` class that holds a `vector<list<int>>` of size 13, so each bucket is a linked list. The insert function calculates the index with the mid-square hash and appends the key to that bucket's list. Collisions need no special handling, because keys with the same index simply join the same chain. For example, 62, 14 and 18 all went to bucket 6. A message is printed for each insertion showing its bucket.

## Commit 5 – Display Function

I added a `display()` function that prints every bucket and its chain, such as `[6] 62 -> 14 -> 18 -> NULL`. At first I forgot to print NULL for empty buckets, which made bucket 4 look like a missing line. After adding NULL, empty buckets are shown clearly. The final table had 13 buckets and all 20 values.

## Commit 6 – Duplicate Handling and Search

While testing, I inserted 23 a second time and it created a duplicate entry in bucket 0. I changed insert so it scans the chain first and ignores the key if it is already there. I also implemented a search function that calculates the bucket and scans only that chain. I tested search(53), which was found, and search(99), which was not found. Both gave the correct results.

## Commit 7 – Trace-Match Report, Debug Log and Output

I captured the program output in `output.txt` and wrote the Trace-Match Report, comparing my predicted table with the actual output. All 13 buckets matched. The only mismatch was the abandoned first attempt from Commit 2, which is explained in the report.

## Commit 8 – Git Log Export

I exported the commit history with `git log --stat` for submission.

## Commit 9 – Cleanup

I removed a stale copy of the log export from the repository and regenerated it as `git_log_stat.txt` for submission.

## Failed Approach – Low Digits Instead of Middle Digits

Initially, I computed the hash as `(key × key) % 100 % 13`. This worked as a hash function, but it is not the mid-square method, because it uses the last two digits of the square rather than the middle ones. The results did not match my hand-calculated table (key 23 gave bucket 3 instead of 0). I abandoned it and used `(sq / 10) % 100 % 13` to extract the middle digits. After the fix, every key matched my hand prediction.
