// We use DP so as to avoid "Overlapping SubProblems" (the problem that was previously solved)
//(Eg in Recursion we finding the value of f(4) through recursion where we 
// already find f(3) but when f(4) we again start to find f(3)
//                                          f(5)
//                                         /    \
//                                       f(4)   f(3)
//                                      /    \       
//                                   f(3)    f(2) 
// ***** So we use Mamoization where we tend to store the "Value of SubProblems" in some Map/Table


// ______________________________________________
// Generally based on Qusetions like
//  -->> Count Path
//  -->> Count Path with obstacles
//  -->> Min Path Sum
//  -->> Max Path Sum
//  -->> Triangle
//  -->> 2 Star Problem
// ______________________________________________
// ______________________________________________________

// ___________  APPROACH  ________________________________
// 1 --> Try to represent the problem in terms of index
// 2 --> Do all possible stuffs on that and in a/c to the problem statement
// 3 --> Sum of all stuffs -->> Count all ways
//      --> Min(all stuffs) -->> Find min
// ______________________________________________________


