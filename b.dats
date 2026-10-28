#include "share/atspre_define.hats"
#include "share/atspre_staload.hats"

fun fact (n: llint): llint=
    if n <= 0LL then 1LL
    else n * fact(n - 1LL)
    
implement main0()=

println!("" , fact(20LL))
