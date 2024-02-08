/*
    Swap a number using recursion
        arr={1,2,3,4,5,6}
    One approch for the follwing proble is to swap using 2 pointer approch and the other approch is to use recursion

    for recursion what we can do is 
    solve(low,high){
        swap(nums[low],num[high])
        solve(low+1,high-1)
        )
    }
    Another method of the same can be if we want only 1 parameter then
        solve(i){
            if(i>n/2) return;
            else{
                swap(i,n-1-i);
                solve(i+1);
            }
        }
    Note for the following method we need the ith element to be a global varibale
    



*/