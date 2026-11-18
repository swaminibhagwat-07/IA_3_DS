# Debugging Log

**PRN:** 202501100023

**Scenario:** Student Marks

**Hash Method:** Mid-Square Method

**Collision Handling:** Separate Chaining

**Table Size:** 11 (smallest prime greater than or equal to `(S mod 23) + 11`, where `S = 23`)

## Commit 1 – Initial Commit

I started the repository for the hash table project and created the initial project files. This commit established the starting point for development. I then added the C++ implementation and supporting assignment documents in later commits.

## Commit 2 – Create main.cpp

I created the initial C++ source file for the project. It provided the starting structure for implementing the personalized dataset and hash table. I continued developing the hashing and collision-handling logic in subsequent changes.

## Commit 3 – Create TRACE_MATCH_REPORT.md

I added the Trace-Match Report file to record the hand-predicted hash results and compare them with the program output. The report should use the same PRN-derived dataset, hash method, collision strategy, and table size as the final program.

## Commit 4 – Create DEBUG_LOG.md

I added a debugging log to document the project’s development process. The log records the implementation steps and the failed approach described below.

## Commit 5 – Update DEBUG_LOG.md

I updated the debugging log to add more information about the development process and the failed mid-square attempt. This made the record clearer about why the first calculation was incorrect and what change corrected it.

## Commit 6 – Create git_log.txt

I added `git_log.txt` to the repository. The submitted file needs to contain the actual output of `git log --stat`, including commit IDs, dates, messages, and file-change summaries; the command text by itself is not the log output.

## Commit 7 – Update README.md

I updated the README with the project description and instructions. I checked that it identifies the Student Marks scenario and explains how to build and run the C++ program.

## Commit 8 – Update main.cpp

I updated the C++ implementation as the project developed. The final source should generate the personalized dataset, use the PRN-selected mid-square hash method and separate chaining, handle duplicate keys, and display/search the table. I also corrected the table size to 11 based on the assignment’s PRN-derived rule.

## Commit 9 – Update TRACE_MATCH_REPORT.md

I updated the Trace-Match Report to reflect the program’s hash calculations and table contents. The final report and captured output must be regenerated from the corrected source using table size 11, then checked against the hand-predicted results.

## Commit 10 – Update DEBUG_LOG.md

I updated the debugging log to make it consistent with the development history. The final version should describe only work and tests that actually occurred.

## Commit 11 – Update README.md

I updated the README with the final project details. I checked that its PRN, dataset, hash method, collision strategy, and table size agree with the final source and Trace-Match Report.

## Failed Approach – Using the Last Two Digits Instead of the Middle Digits

In my first mid-square attempt, I squared each key and used the last two digits of the result. For key 23, this used 29 from 529. I compared it with the mid-square calculation: the four-digit form is 0529, so the middle two digits are 52. The two calculations produced different bucket values, showing that my first method was using the low digits instead of the middle digits. I abandoned that method and changed the hash calculation to extract the middle two digits before applying the table-size modulus. I then checked the hash results against hand calculations.

## Final Check

I need to keep the source code, README, Trace-Match Report, captured output, and debugging log consistent with the same personalization values and table size. After the final code correction, I should run the program again, update the report and captured output, and regenerate `git_log.txt` from the repository’s actual history. The assignment also requires a separate unedited screen recording of up to four minutes demonstrating the running program and explaining its output.
