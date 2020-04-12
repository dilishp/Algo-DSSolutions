function applyToArray(a) {
    // Write the body of the JAVASCRIPT function, applyToArray, so that it takes a single
    // argument which is an array and returns a new function.
    //
    // Input: The argument 'a' can be assumed to be an array
    // (which may or may not be empty).
    //
    // Output: applyToArray must return a function which itself takes a
    // single argument which can be assumed to be a function (which
    // we will call 'f' here). 'f' can be assumed to take a single
    // argument and return a single value. The function returned
    // by applyToArray should return an array which is the result of
    // applying the function f individually to each element of array a.
    //
    // Examples: Given the definitions of add2 and mult4 at the bottom
    // of this page, if var f1 = applyToArray([1,2,3,4]), then f1(add2)
    // returns [3,4,5,6], if var f2 = applyToArray([10,-20,8,0]),
    // f2(mult4) returns [40,-80,32,0], and if var f3 = applyToArray([]),
    // f3(add2) returns []
    // let arr;
    // a.forEach(x=>{arr.insert(f(x))});
    // return arr;

    // let fn = function x(fun)
    // {
    //     let arr = [];
    //     console.log("inside fun", a);
    //     a.forEach(x=> arr.push(fun(x)));
    //     console.log("inside fun", arr);
    //     return arr;
    // };
    // return fn;
    return ((f) => {
       // var count = 0;
        return a.map(f);
        // for(let num in a)
        // {
        //     num = f(num);
        //     //count++;
        // }
        //return a;
    });
 }
 
 var f = applyToArray([1,2,3,4]);

 function mult4(i) {
    return i*4;
 }
 
 function add2(j) {
    return j+2;
 }
 
 function square(k) {
    return k*k;
 }

 var arr =  f(mult4);
 console.log(arr);