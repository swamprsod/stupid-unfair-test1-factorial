fn fac(n: i128) -> i128 {
    match n {
        0 => 1,
        _ => n * fac(n -1)
    }
}

fn main () {
    println!("{}", fac(20));
}
