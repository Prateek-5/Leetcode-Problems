/*
Write code that enhances all arrays such that you can call the array.last() method on any array and it will return the last element. If there are no elements in the array, it should return -1.

You may assume the array is the output of JSON.parse.

 

Example 1:

Input: nums = [null, {}, 3]
Output: 3
Explanation: Calling nums.last() should return the last element: 3.
Example 2:

Input: nums = []
Output: -1
Explanation: Because there are no elements, return -1.
 

Constraints:

arr is a valid JSON array
0 <= arr.length <= 1000

*/

/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    //console.log(this);  // [ null, {}, 3 ]
    /*
        The above code represents the pictorial representation of the this keyword in Javascript
        Basically using the this key word we are refering to the caller object in javascript

        [ null, {}, 3 ]

        Write code that enhances all arrays such that you can call the array.last() method on any array 
        And as we want to inchance the feature to all the Array object basically attach the folloien function

        we will us prototype for the same on the 
        Array.prototype.last=function(){

        }
        Array.prototype.last //this is the functional expression
        function(){

        }               Function declaration

    Apart from this the whole code is self explanatory and can be undestand easly


    */
    if(this.length==0){
        return -1;
    }
    else{
        return this[this.length-1];
    }


};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */