fn print(s: &String) {
    println!("{}", s)
}

fn main() {
    let mut v = String::from("hello");

    let w;

    w = &mut v;

    print(&v);
    
    println!("Hello, world: {}", w.len());
}
