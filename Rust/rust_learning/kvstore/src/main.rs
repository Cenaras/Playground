// The code is over commented as it serves as a useful note for the introductory concepts and notes for learning Rust.

fn main() {
    //std is standard library module, which inside has an "env" module, which has an 'args' method
    let mut arguments = std::env::args().skip(1); //Skip first, since first is program  
    // args is an iterator, meaning we can get elements one-by-one.


    // Notice here: arguments must be mutable for us to call .next
    let key = arguments.next().unwrap(); // Since args is an iterator, we can get the next argument by calling "next"
    // .next gives an option type, and unwrap takes that Some-type an uses it. Panicks (crashes) if the type is None

    let value = arguments.next().unwrap(); // Can use .expect(string) for panicking with error string, if option type was none.
    println!("(Key, Value) is ({}, {})", key, value);


    // Format is a macro that returns a String
    let contents = format!("{}\t{}\n", key, value);

    // Invoke standard library method again
    std::fs::write("kv.db", contents).unwrap(); // Note; result also has a expect and unwrap instead of matching...
    
    // We could store the result as let write_result = ... and not call unwrap to actually get the error.

    

}

// Structs are collections of data with named elements. They also provide a type, so the below gives us a "Database" type - closest thing we get to objects in Rust 
struct Database {

}

// This is how we add functionality to our type. We cannot declare methods directly in the struct, the struct only stores the data. But we can use the impl to add 
// data or methods for the Database type.
impl Database {

}