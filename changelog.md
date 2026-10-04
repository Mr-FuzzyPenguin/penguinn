# Progress updates:
## 09/28/2026:
### C-programming side:
- `multiply_matrix()` written
- `pseudo_rng()` written

### Data acquisition side:
- Dataset of 2118 different 150 x 30 images (not publicized yet)
- Annotated the data
- Hash verifies uniqueness of images
- Python scraper to expand dataset

### QoL side:
- Used ChatGPT for ideas for dataset expansion
- Help with `matplotlib` for a simple gui to help with data annotation (not publicized)
- Help with writing custom unique hash verifying algorithm using hash set
- Established rules for vibe-coding: Python, webscraping, dataset generating, and other QoL is ok, coding any C with an LLM is completely off-limits. Fuzzing C code and code-review is ok to prevent memory leaks and serious bugs.

## 09/29/2026:
### C-programming side:
- `matrix_add()` written
- `free_matrix()` written
- `silu()` written

### QoL side:
- Made Git repo and uploaded to GitHub
- Made 3 branches to work on individual components
- Used working scraper (not publicized) to download 911 new test cases but no data annotation yet (not publicized yet)

## 09/30/2026:
### C-programming side:
- Made all matrix functions able to write in-place. For example: `matrix_multiply(A, b, &A)`
- `matrix_subtract()` written
- `silu_derivative()` written
- `matrix_apply_func()` written

### QoL side:
- Cleaning up the code
- Data annotation completed for all 911 images
- Used working scraper (not publicized) to download 925 new test cases but no data annotation yet (not publicized yet)
- `silu_derivative()` written
- Delete the stale branches
- Fixed Makefile

## 10/01/2026:
### C-programming side:
- Revamped the RNG by using a struct and a custom self-updating function

### QoL side:
- Data annotation on a few images, deleted repeating hashes (and repeating images)

## 10/01/2026:
- Took a break

## 10/03/2026:
### C-programming side:
- Began: Adding layer struct
- Began: Adding layer initialization
- Added a bunch of fixes to memory allocation for matrix

### QoL side:
- ChatGPT fuzzed my code and yelled at "my matrices’ myriads, multitudes, magnificent memory-management mishaps.”