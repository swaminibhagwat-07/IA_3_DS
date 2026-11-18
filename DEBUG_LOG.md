# Debugging Log (PRN 202501100023)
1. **Generate dataset.** Wrote v[i] = (23 + 13*i) mod 100 for 20 values. Compiled and printed; all 20 values unique, so no duplicate fix needed.
2. **First hash attempt (FAILED approach).** Tried sq % 100 % 13, thinking "two digits of the square" was mid-square. It ran, but key 23 gave bucket 3 against my hand-computed 0. It takes the low digits, so it depends only on key mod 50-ish and is not mid-square. Abandoned.
3. **Fix hash.** Used (sq / 10) % 100 to extract the middle two digits of the 4-digit square, then mod 13. All 20 values now match the hand table.
4. **Chaining and insert.** Added vector<list<int>> and push_back per bucket. Nothing broke; printed the bucket for each insertion.
5. **Display.** Added display() printing each chain. At first I forgot the NULL for empty buckets; added it so empty buckets read clearly.
6. **Duplicates and search.** Re-inserting 23 created a second copy in bucket 0. Added a scan of the chain before push_back, plus search(). Tested search(53)=1, search(99)=0.
7. **Reports.** Added trace-match report, debug log and output capture.
