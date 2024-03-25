/*
Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.

 

Example 1:

Input: millis = 100
Output: 100
Explanation: It should return a promise that resolves after 100ms.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
Example 2:

Input: millis = 200
Output: 200
Explanation: It should return a promise that resolves after 200ms.
 

Constraints:

1 <= millis <= 1000

*/

/**
 * @param {number} millis
 * @return {Promise}
 */
/*
    Intution / Basic Algorithm

    The basic ask of the following function is to resolve the promise after the given set of time
    as we can see in the a .then() is been associated with the following function and what the promise return is not important 
    when the following promise is been resolved is been measured 

    -> so as .then() is been executed we need the retunn of the following function as Promise
    -> The promise should resolve after millis the function argument passes in the function

    we will resolve the promise after millis using the settime out 


*/



async function sleep(millis) {
    const promise1=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("some gibbrish not important")
        },millis);
    })
    return promise1;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */