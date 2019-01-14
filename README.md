A customized SAT solver is developed. Multiple set of heuristics are implemented to develop various SAT solvers according to the task requirement.


Current set of Heuristics:
1) Sort the input file such that smaller formulas come above. 
2) In every line sort in decreasing order of no of time that literal appears in the whole file.
3) Unit propagation
4) DPLL
5) Pure Literal elimination


Heuristics of decomposition:
Selecting clause for decomposition: After sorting as mentioned above, pick the clause that comes above
Decomposition of the clause: Now take the first literal of the clause decompose it. This will help in unit propagation. 


Building and running: 

To run from terminal: 
g++ final.cpp
./a.out

Input: DIMACS file in .txt format

------------------------------------------------------

The other files are the task specific implementation of SAT solver. It involved 
1. Finding the solution to Sudoku
2. Generating sudoku using randomized algorithm

The corresponding files are main.cpp, decrypt.cpp.
