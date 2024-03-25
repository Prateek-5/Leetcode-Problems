/*
Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).

 

Example 1:

Input: 
n = 10 
["call","call","call"]
Output: [10,11,12]
Explanation: 
counter() = 10 // The first time counter() is called, it returns n.
counter() = 11 // Returns 1 more than the previous time.
counter() = 12 // Returns 1 more than the previous time.
Example 2:

Input: 
n = -2
["call","call","call","call","call"]
Output: [-2,-1,0,1,2]
Explanation: counter() initially returns -2. Then increases after each sebsequent call.
 

Constraints:

-1000 <= n <= 1000
0 <= calls.length <= 1000
calls[i] === "call"

*/

/**
 * @param {number} n
 * @return {Function} counter
 */
/*
    Intution / Basic Algorithm

    Concept used of functional scope variables
    const counter = createCounter(10)
        When this statement is been executed a functional scope n is been created and initialized to the parameter been passes
        and now the counter stores the return of the createCounter function which itself is a function that's why we are been
        able to call the counter variable multiple times

    the return function has the access to the functional variable because not n is been declared in the return function scope
    so it is refering to the outter function n which was initialized to n in the start

    so every time the counter() ->the return function of the craterCounter which as the access to the n variable
    is been called the n variable is been incremented by 1 on the same memory reference

    That's the reason we are getting a parrern like
        10
        11
        12
    Note why we are not getting 11 12 13 becuase the return is 
        return n++
    Firsly the n is getting returned and then is been incremented by 1


*/

var createCounter = function(n) {
    
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */