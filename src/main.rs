fn print(s: &mut String) {
    println!("{}", s);
    s.clear()
}

fn main() {
    let mut v = String::from("hello");

    print(&mut v);

    let w = &v;

    //v.clear();
    
    println!("v.len: {}", w.len());
}
