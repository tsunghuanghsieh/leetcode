# Amazon Online Assessment Example CQ #2

At Audible, a subscriber can gift an audiobook from his/her library to any other non-subscriber to kick start their audiobook journey. The first time subscriber can receive up to a maximum of `N` audiobooks from their friends/relatives. When a non-subscriber receives an audiobook, we can infer that the two may be related. Similarly, if the non-subscriber receives gifted books from two other subscribers, we can infer that all of them are related and the three of them form a group. More formally, a group is composed of all of the people who know one another, whether directly or transitively. Audible would like your help finding out the number of such distinct groups from the input data.

**Example 0**
Consider the following input matrix M:
110
110
001
![Example 0](https://hrcdn.net/s3_pub/istreet-assets/S3PlwRCklNWnBM33jPEejw/connected_groups_example.svg)

Every row corresponds to a subscriber and the value `M[i][j]` determines if `j` was gifted a book by `i`. In the above example, user 0 has gifted a book to user 1 and so they are connected `[0][1]`, while person `2` has not received a book from anyone or gifted book to anyone. Therefore, there are `2` groups.
`M[i][j] = 1` if `i == j` (Each of the people is known to self)

Determine the number of groups represented in a matrix.

**Example 1:**
Input: [[1,1,0,0],[1,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 2
Explanation: Squares highlighting a connection between two people are highlighted in green. Each of the people is known to self, so they are highlighted in gray.
![Example 1](https://hrcdn.net/s3_pub/istreet-assets/MU3_0MB8lA0wpdl_A3ZhgA/connected_groups_sample_0.svg)
There are `n = 4`  people numbered `related[0]` through `related[3]`.
There are `2` pairs who directly know each another: `(related[0]`, `related[1])` and `(related[1],related[2])`. Because a relation is transitive, the set of people `{related[0], related[1], related[2]}` is considered a single group.
The remaining person, `related[3]`, does not know any other people and is a separate group: `{related[3]}.
There are a total of `2` groups.

**Example 2:**
[[1,0,0,0,0],[0,1,0,0,0],[0,0,1,0,0],[0,0,0,1,0],[0,0,0,0,1]]
Output: 5
![Example 2](https://ci4.googleusercontent.com/proxy/pUqFwKpe2aiamDFS1Uv7P4l86IGGpfCVhkFDl4CKDPuLAfA8Fhx0IFKjgBWLjujKsKmfKYpxcBVTgO_nHbNDKi2Gg-fYJ5uWRj3Wg4H4WsoSDvD8zLxlIoo=s0-d-e1-ft#https://hrcdn.net/s3_pub/istreet-assets/SVIPHv5WOOSkFP2bIo2_AA/rel.png)
Explanation: No direct relationships are shown so there are `5` groups: `{related[0]}, {related[1]}, {related[2]}, {related[3]}, and {related[4]}`.

**Note:**
The method signatures may vary slightly depending on the requirements of the chosen language. For example, C language will have an argument that represents the number of rows and columns in the matrix. Also, Java will receive a list rather than an array.

**Constraints:**
* `1 ≤ n ≤ 300`
* `0 ≤ i < n`
* `|related| = n`
* Each `related[i]` contains a binary string of `n` zeros and ones. `related` is a square matrix.

## Interview
04/07/2025, Amazon online assessment example CQ #2.
