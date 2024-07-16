// We use DP so as to avoid "Overlapping SubProblems" (the problem that was previously solved)
//(Eg in Recursion we finding the value of f(4) through recursion where we 
// already find f(3) but when f(4) we again start to find f(3)
//                                          f(5)
//                                         /    \
//                                       f(4)   f(3)
//                                      /    \       
//                                   f(3)    f(2) 
// ***** So we use Mamoization where we tend to store the "Value of SubProblems" in some Map/Table

// Subsequence  -->> May or may not be CONSECUTIVE
// Substring  -->> Always CONSECUTIVE

// ______________________________________________
// Generally based on Qusetions like 1D Array
//     -->> Comparison
//     -->> Replaces / Edit
// ______________________________________________________

// ___________  APPROACH  ________________________________
// 1 --> Try to represent the problem in terms of index
// 2 --> Do all possible stuffs on that and in a/c to the problem statement
// 3 --> Sum of all stuffs -->> Count all ways
//      --> Min(all stuffs) -->> Find min
// ______________________________________________________
// Greedy is not used as it should be used when there is uniformity increase/decrease in the value
// When there are multiple options to go with then greedy will certainly lose option and won't give accurate output.



// ________  Question Type 2D Array  ________________
// Count Path
// Count Path with obstacles
// Min Path Sum
// Max Path Sum
// Triangle
// 2 Star Problem
// ______________________________________________