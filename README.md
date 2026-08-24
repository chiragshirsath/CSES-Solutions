# 🏆 CSES Problem Set Solutions

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CSES](https://img.shields.io/badge/CSES-Problem%20Set-1a1a2e?style=for-the-badge)
![Problems](https://img.shields.io/badge/Solved-115-4CAF50?style=for-the-badge)
![Lines](https://img.shields.io/badge/Lines%20of%20Code-4967-2196F3?style=for-the-badge)

**My solutions to the [CSES Problem Set](https://cses.fi/problemset/) in C++ — with detailed question understanding, intuition, and approach documented for every problem.**

</div>

---

## 📊 Progress Overview

```
Overall Progress: ████████████████████░░░░░░░░░░  115 / 300  (38.3%)
```

| Section | Solved | Total | Progress | Status |
|---------|:------:|:-----:|----------|:------:|
| [Introductory Problems](#-introductory-problems) | **24** | 24 | `████████████████████ 100%` | ✅ Complete |
| [Sorting and Searching](#-sorting-and-searching) | **35** | 35 | `████████████████████ 100%` | ✅ Complete |
| [Dynamic Programming](#-dynamic-programming) | **17** | 23 | `██████████████░░░░░░  74%` | 🔶 In Progress |
| [Graph Algorithms](#-graph-algorithms) | **31** | 36 | `█████████████████░░░  86%` | 🔶 In Progress |
| [Range Queries](#-range-queries) | **8** | 22 | `███████░░░░░░░░░░░░░  36%` | 🔶 In Progress |

### 📈 Stats at a Glance

| Metric | Value |
|--------|-------|
| **Total Problems Solved** | 115 |
| **Total Lines of Code** | 4,967 |
| **Avg Lines per Solution** | ~43 |
| **Sections Completed** | 2 / 5 |
| **Language** | C++17 |

---

## 📝 Solution Style

Every solution includes a comment block documenting my thought process:

```cpp
/*
Question : 
input : <constraints and input format>
output : <expected output>
intution : <how I thought about the problem>
soln : <solution approach>

// For DP problems:
state : dp[...] represents ...
transition : dp[...] = ...
initialization : ...
*/
```

---

## 📂 Introductory Problems

> **24 / 24 solved** — ✅ Complete

| # | Problem | Solution | Technique |
|:-:|---------|:--------:|-----------|
| 1 | Weird Algorithm | [📄](Introductory%20Problems/1_Weird_Algorithm.cpp) | Simulation (Collatz Conjecture) |
| 2 | Missing Number | [📄](Introductory%20Problems/2_Missing_Number.cpp) | Sum Formula |
| 3 | Repetitions | [📄](Introductory%20Problems/3_Repetitions.cpp) | String Traversal |
| 4 | Increasing Array | [📄](Introductory%20Problems/4_Increasing_Array.cpp) | Greedy |
| 5 | Permutations | [📄](Introductory%20Problems/5_Permutations.cpp) | Construction |
| 6 | Number Spiral | [📄](Introductory%20Problems/6_Number_Spiral.cpp) | Math / Pattern |
| 7 | Two Knights | [📄](Introductory%20Problems/7_Two_Knights.cpp) | Combinatorics |
| 8 | Two Sets | [📄](Introductory%20Problems/8_Two_Sets.cpp) | Math / Greedy |
| 9 | Bit Strings | [📄](Introductory%20Problems/9_Bit_Strings.cpp) | Modular Exponentiation |
| 10 | Trailing Zeros | [📄](Introductory%20Problems/10_Trailing_Zeros.cpp) | Math (Legendre's Formula) |
| 11 | Coin Piles | [📄](Introductory%20Problems/11_Coin_Piles.cpp) | Math / Divisibility |
| 12 | Palindrome Reorder | [📄](Introductory%20Problems/12_Palindrome_Reorder.cpp) | Frequency Count |
| 13 | Gray Code | [📄](Introductory%20Problems/13_Gray_Code.cpp) | Bit Pattern |
| 14 | Tower of Hanoi | [📄](Introductory%20Problems/14_Tower_of_Hanoi.cpp) | Recursion |
| 15 | Creating Strings | [📄](Introductory%20Problems/15_Creating_Strings.cpp) | Permutations |
| 16 | Apple Division | [📄](Introductory%20Problems/16_Apple_Division.cpp) | Brute Force / Recursion |
| 17 | Chessboard and Queens | [📄](Introductory%20Problems/17_Chessboard_and_Queens.cpp) | Backtracking (N-Queens) |
| 18 | Raab Game I | [📄](Introductory%20Problems/18_Raab_Game_I.cpp) | Constructive |
| 19 | Mex Grid Construction | [📄](Introductory%20Problems/19_Mex_Grid_Construction.cpp) | Construction |
| 20 | Knight Moves Grid | [📄](Introductory%20Problems/20_Knight_Moves_Grid.cpp) | BFS / Grid |
| 21 | Grid Coloring I | [📄](Introductory%20Problems/21_Grid_Coloring_I.cpp) | Construction |
| 22 | Digit Queries | [📄](Introductory%20Problems/22_Digit_Queries.cpp) | Math |
| 23 | String Reorder | [📄](Introductory%20Problems/23_String_Reorder.cpp) | Greedy / Construction |
| 24 | Grid Path Description | [📄](Introductory%20Problems/24_Grid_Path_Description.cpp) | Backtracking + Pruning |

---

## 🔍 Sorting and Searching

> **35 / 35 solved** — ✅ Complete

| # | Problem | Solution | Technique |
|:-:|---------|:--------:|-----------|
| 1 | Distinct Numbers | [📄](Sorting%20and%20Searching/1_Distinct_Numbers.cpp) | Sorting |
| 2 | Apartments | [📄](Sorting%20and%20Searching/2_Apartments.cpp) | Two Pointers |
| 3 | Ferris Wheel | [📄](Sorting%20and%20Searching/3_Ferris_Wheel.cpp) | Greedy + Multiset |
| 4 | Concert Tickets | [📄](Sorting%20and%20Searching/4_Concert_Tickets.cpp) | Multiset + Lower Bound |
| 5 | Restaurant Customers | [📄](Sorting%20and%20Searching/5_Restaurant_Customers.cpp) | Event Sorting |
| 6 | Movie Festival | [📄](Sorting%20and%20Searching/6_Movie_Festival.cpp) | Greedy (Activity Selection) |
| 7 | Sum of Two Values | [📄](Sorting%20and%20Searching/7_Sum_of_Two_Values.cpp) | Map + Binary Search |
| 8 | Maximum Subarray Sum | [📄](Sorting%20and%20Searching/8_Maximum_Subarray_Sum.cpp) | Kadane's Algorithm |
| 9 | Stick Lengths | [📄](Sorting%20and%20Searching/9_Stick_Lengths.cpp) | Median |
| 10 | Missing Coin Sum | [📄](Sorting%20and%20Searching/10_Missing_Coin_Sum.cpp) | Greedy + Sorting |
| 11 | Collecting Numbers | [📄](Sorting%20and%20Searching/11_Collecting_Numbers.cpp) | Position Tracking |
| 12 | Collecting Numbers II | [📄](Sorting%20and%20Searching/12_Collecting_Numbers_II.cpp) | Position Tracking + Updates |
| 13 | Playlist | [📄](Sorting%20and%20Searching/13_Playlist.cpp) | Sliding Window + Set |
| 14 | Towers | [📄](Sorting%20and%20Searching/14_Towers.cpp) | Multiset / Greedy |
| 15 | Traffic Lights | [📄](Sorting%20and%20Searching/15_Traffic_Lights.cpp) | Set + Multiset |
| 16 | Distinct Values Subarrays | [📄](Sorting%20and%20Searching/16_Distinct_Values_Subarrays.cpp) | Sliding Window |
| 17 | Distinct Values Subsequences | [📄](Sorting%20and%20Searching/17_Distinct_Values_Subsequences.cpp) | DP / Counting |
| 18 | Josephus Problem I | [📄](Sorting%20and%20Searching/18_Josephus_Problem_I.cpp) | Simulation |
| 19 | Josephus Problem II | [📄](Sorting%20and%20Searching/19_Josephus_Problem_II.cpp) | Ordered Set / BIT |
| 20 | Nested Ranges Check | [📄](Sorting%20and%20Searching/20_Nested_Ranges_Check.cpp) | Sorting + Prefix Max/Suffix Min |
| 21 | Nested Ranges Count | [📄](Sorting%20and%20Searching/21_Nested_Ranges_Count.cpp) | Sorting + BIT |
| 22 | Room Allocation | [📄](Sorting%20and%20Searching/22_Room_Allocation.cpp) | Greedy + Set |
| 23 | Factory Machines | [📄](Sorting%20and%20Searching/23_Factory_Machines.cpp) | Binary Search |
| 24 | Tasks and Deadlines | [📄](Sorting%20and%20Searching/24_Tasks_and_Deadlines.cpp) | Greedy Sorting |
| 25 | Reading Books | [📄](Sorting%20and%20Searching/25_Reading_Books.cpp) | Greedy |
| 26 | Sum of Three Values | [📄](Sorting%20and%20Searching/26_Sum_of_Three_Values.cpp) | Sorting + Two Pointers |
| 27 | Sum of Four Values | [📄](Sorting%20and%20Searching/27_Sum_of_Four_Values.cpp) | Map + Pairs |
| 28 | Nearest Smaller Values | [📄](Sorting%20and%20Searching/28_Nearest_Smaller_Values.cpp) | Stack |
| 29 | Subarray Sums I | [📄](Sorting%20and%20Searching/29_Subarray_Sums_I.cpp) | Prefix Sum + Map |
| 30 | Subarray Sums II | [📄](Sorting%20and%20Searching/30_Subarray_Sums_II.cpp) | Prefix Sum + Map |
| 31 | Subarray Divisibility | [📄](Sorting%20and%20Searching/31_Subarray_Divisibility.cpp) | Prefix Sum + Modular |
| 32 | Distinct Values Subarrays II | [📄](Sorting%20and%20Searching/32_Distinct_Values_Subarrays_II.cpp) | Sliding Window + BIT |
| 33 | Array Division | [📄](Sorting%20and%20Searching/33_Array_Division.cpp) | Binary Search |
| 34 | Movie Festival II | [📄](Sorting%20and%20Searching/34_Movie_Festival_II.cpp) | Greedy + Multiset |
| 35 | Maximum Subarray Sum II | [📄](Sorting%20and%20Searching/35_Maximum_Subarray_Sum_II.cpp) | Prefix Sum + Multiset |

---

## 💡 Dynamic Programming

> **17 / 23 solved** — 🔶 74%

| # | Problem | Solution | Technique |
|:-:|---------|:--------:|-----------|
| 1 | Dice Combinations | [📄](Dynamic%20Programming/1_Dice_Combinations.cpp) | Linear DP |
| 2 | Minimizing Coins | [📄](Dynamic%20Programming/2_Minimizing_Coins.cpp) | Unbounded Knapsack |
| 3 | Coin Combinations I | [📄](Dynamic%20Programming/3_Coin_Combinations_I.cpp) | Unbounded Knapsack (Count) |
| 4 | Coin Combinations II | [📄](Dynamic%20Programming/4_Coin_Combinations_II.cpp) | Bounded Knapsack (Ordered) |
| 5 | Removing Digits | [📄](Dynamic%20Programming/5_Removing_Digits.cpp) | Greedy DP |
| 6 | Grid Paths | [📄](Dynamic%20Programming/6_Grid_Paths_I.cpp) | Grid DP |
| 7 | Book Shop | [📄](Dynamic%20Programming/7_Book_Shop.cpp) | 0/1 Knapsack |
| 8 | Array Description | [📄](Dynamic%20Programming/8_Array_Description.cpp) | DP on States |
| 9 | Counting Towers | [📄](Dynamic%20Programming/9_Counting_Towers.cpp) | Linear DP (2 states) |
| 10 | Edit Distance | [📄](Dynamic%20Programming/10_Edit_Distance.cpp) | Classic 2D DP |
| 11 | Longest Common Subsequence | [📄](Dynamic%20Programming/11_Longest_Common_Subsequence.cpp) | Classic LCS |
| 12 | Rectangle Cutting | [📄](Dynamic%20Programming/12_Rectangle_Cutting.cpp) | 2D DP (Interval) |
| 13 | Minimal Grid Path | [📄](Dynamic%20Programming/13_Minimal_Grid_Path.cpp) | Greedy BFS |
| 14 | Money Sums | [📄](Dynamic%20Programming/14_Money_Sums.cpp) | Subset Sum (Boolean DP) |
| 15 | Removal Game | [📄](Dynamic%20Programming/15_Removal_Game.cpp) | Interval DP (Game Theory) |
| 16 | Two Sets II | [📄](Dynamic%20Programming/16_Two_Sets_II.cpp) | Subset Sum + Mod Inverse |
| 17 | Mountain Range | [📄](Dynamic%20Programming/17_Mountain_Range.cpp) | Stack + DP |
| 18 | Increasing Subsequence | ⬜ | — |
| 19 | Projects | ⬜ | — |
| 20 | Elevator Rides | ⬜ | — |
| 21 | Counting Tilings | ⬜ | — |
| 22 | Counting Numbers | ⬜ | — |
| 23 | Increasing Subsequence II | ⬜ | — |

---

## 🌐 Graph Algorithms

> **31 / 36 solved** — 🔶 86%

| # | Problem | Solution | Technique |
|:-:|---------|:--------:|-----------|
| 1 | Counting Rooms | [📄](Graph%20Algorithms/1_Counting_Rooms.cpp) | BFS Flood Fill |
| 2 | Labyrinth | [📄](Graph%20Algorithms/2_Labyrinth.cpp) | BFS + Path Reconstruction |
| 3 | Building Roads | [📄](Graph%20Algorithms/3_Building_Roads.cpp) | DSU (Union-Find) |
| 4 | Message Route | [📄](Graph%20Algorithms/4_Message_Route.cpp) | BFS Shortest Path |
| 5 | Building Teams | [📄](Graph%20Algorithms/5_Building_Teams.cpp) | BFS Bipartite Check |
| 6 | Round Trip | [📄](Graph%20Algorithms/6_Round_Trip.cpp) | DFS Cycle Detection |
| 7 | Monsters | [📄](Graph%20Algorithms/7_Monsters.cpp) | Multi-source BFS |
| 8 | Shortest Routes I | [📄](Graph%20Algorithms/8_Shortest_Routes_I.cpp) | Dijkstra's Algorithm |
| 9 | Shortest Routes II | [📄](Graph%20Algorithms/9_Shortest_Routes_II.cpp) | Floyd-Warshall |
| 10 | High Score | [📄](Graph%20Algorithms/10_High_Score.cpp) | Bellman-Ford (Neg. Cycle) |
| 11 | Flight Discount | [📄](Graph%20Algorithms/11_Flight_Discount.cpp) | Dijkstra (Layered Graph) |
| 12 | Cycle Finding | [📄](Graph%20Algorithms/12_Cycle_Finding.cpp) | Bellman-Ford |
| 13 | Flight Routes | [📄](Graph%20Algorithms/13_Flight_Routes.cpp) | K-Shortest Paths (Dijkstra) |
| 14 | Round Trip II | [📄](Graph%20Algorithms/14_Round_Trip_II.cpp) | DFS (Directed Cycle) |
| 15 | Course Schedule | [📄](Graph%20Algorithms/15_Course_Schedule.cpp) | Topological Sort (Kahn's) |
| 16 | Longest Flight Route | [📄](Graph%20Algorithms/16_Longest_Flight_Route.cpp) | Topo Sort + DP |
| 17 | Game Routes | [📄](Graph%20Algorithms/17_Game_Routes.cpp) | Topo Sort + DP (Counting) |
| 18 | Investigation | [📄](Graph%20Algorithms/18_Investigation.cpp) | Dijkstra (Multi-track) |
| 19 | Planets Queries I | [📄](Graph%20Algorithms/19_Planets_Queries_I.cpp) | Binary Lifting |
| 20 | Planets Queries II | [📄](Graph%20Algorithms/20_Planets_Queries_II.cpp) | Binary Lifting + Cycle Detection |
| 21 | Planets Cycles | [📄](Graph%20Algorithms/21_Planets_Cycles.cpp) | Functional Graph DFS |
| 22 | Road Reparation | [📄](Graph%20Algorithms/22_Road_Reparation.cpp) | Kruskal's MST |
| 23 | Road Construction | [📄](Graph%20Algorithms/23_Road_Construction.cpp) | DSU + Size Tracking |
| 24 | Flight Routes Check | [📄](Graph%20Algorithms/24_Flight_Routes_Check.cpp) | Kosaraju's SCC |
| 25 | Planets and Kingdoms | [📄](Graph%20Algorithms/25_Planets_and_Kingdoms.cpp) | Kosaraju's SCC |
| 26 | Giant Pizza | [📄](Graph%20Algorithms/26_Giant_Pizza.cpp) | 2-SAT (SCC) |
| 27 | Coin Collector | [📄](Graph%20Algorithms/27_Coin_Collector.cpp) | SCC Condensation + DAG DP |
| 28 | Mail Delivery | [📄](Graph%20Algorithms/28_Mail_Delivery.cpp) | Euler Circuit (Hierholzer) |
| 29 | De Bruijn Sequence | [📄](Graph%20Algorithms/29_De_Bruijn_Sequence.cpp) | Euler Circuit on De Bruijn Graph |
| 30 | Teleporters Path | [📄](Graph%20Algorithms/30_Teleporters_Path.cpp) | Euler Path (Hierholzer) |
| 31 | Hamiltonian Flights | [📄](Graph%20Algorithms/31_Hamiltonian_Flights.cpp) | 🚧 TODO |
| 32 | Knight's Tour | ⬜ | — |
| 33 | Download Speed | ⬜ | — |
| 34 | Police Chase | ⬜ | — |
| 35 | School Dance | ⬜ | — |
| 36 | Distinct Routes | ⬜ | — |

---

## 📏 Range Queries

> **8 / 22 solved** — 🔶 36%

| # | Problem | Solution | Technique |
|:-:|---------|:--------:|-----------|
| 1 | Static Range Sum Queries | [📄](Range%20Queries/1_Static_Range_Sum_Queries.cpp) | Prefix Sum |
| 2 | Static Range Minimum Queries | [📄](Range%20Queries/2_Static_Range_Minimum_Queries.cpp) | Sparse Table |
| 3 | Dynamic Range Sum Queries | [📄](Range%20Queries/3_Dynamic_Range_Sum_Queries.cpp) | Segment Tree |
| 4 | Dynamic Range Minimum Queries | [📄](Range%20Queries/4_Dynamic_Range_Minimum_Queries.cpp) | Segment Tree |
| 5 | Range Xor Queries | [📄](Range%20Queries/5_Range_Xor_Queries.cpp) | Sparse Table (XOR) |
| 6 | Range Update Queries | [📄](Range%20Queries/6_Range_Update_Queries.cpp) | Difference Array + Segment Tree |
| 7 | Forest Queries | [📄](Range%20Queries/7_Forest_Queries.cpp) | 2D Prefix Sum |
| 8 | Hotel Queries | [📄](Range%20Queries/8_Hotel_Queries.cpp) | Segment Tree + Binary Search |
| 9 | List Removals | ⬜ | — |
| 10 | Salary Queries | ⬜ | — |
| 11 | Prefix Sum Queries | ⬜ | — |
| 12 | Pizzeria Queries | ⬜ | — |
| 13 | Subarray Sum Queries | ⬜ | — |
| 14 | Distinct Values Queries | ⬜ | — |
| 15 | Increasing Array Queries | ⬜ | — |
| 16 | Forest Queries II | ⬜ | — |
| 17 | Range Updates and Sums | ⬜ | — |
| 18 | Polynomial Queries | ⬜ | — |
| 19 | Range Queries and Copies | ⬜ | — |

---

## 🧠 Techniques Used

| Category | Techniques |
|----------|-----------|
| **Fundamentals** | Brute Force, Simulation, Math, Modular Arithmetic |
| **Sorting & Searching** | Binary Search, Two Pointers, Sliding Window, Greedy |
| **Data Structures** | Set, Multiset, Map, Stack, Priority Queue, DSU, Segment Tree, Sparse Table, BIT |
| **Dynamic Programming** | Knapsack, Interval DP, Grid DP, Game Theory DP, Bitmask DP |
| **Graphs** | BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort, SCC (Kosaraju), Euler Circuits, Binary Lifting |
| **Other** | 2-SAT, Backtracking, Pruning, Construction |

---

## 🚀 How to Use

```bash
# Compile any solution
g++ -std=c++17 -O2 "Graph Algorithms/8_Shortest_Routes_I.cpp" -o sol

# Run with input
echo "3 4
1 2 5
1 3 2
2 3 1
1 3 7" | ./sol
```

---

## 📌 Notes

- All solutions are written in **C++17** using `bits/stdc++.h`
- Every solution includes a **comment header** with question understanding, intuition, and approach
- DP solutions additionally document **state, transition, and initialization**
- Solutions are ordered by their position in the [CSES Problem Set](https://cses.fi/problemset/)

---

<div align="center">

**⭐ Star this repo if you find it helpful!**

</div>
