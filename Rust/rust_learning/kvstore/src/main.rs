// The code is over commented as it serves as a useful note for the introductory concepts and notes for learning Rust.
use std::collections::HashMap;

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

    // Calling a method on a struct is done in the following way - we can create the method using the impl keyword as below.
    let database = Database::new().expect("An error occured while reading the provided .db file"); // Extract the Database from ResultType and throw error if it is Err

}

// Structs are collections of data with named elements. They also provide a type, so the below gives us a "Database" type - closest thing we get to objects in Rust 
struct Database {
    // std has an implementation for hashmaps that we can use.
    map: HashMap<String, String>, // Generic type arguments must be provided. We implement std::collections::HashMap to avoid writing it every time
}

// This is how we add functionality to our type. We cannot declare methods directly in the struct, the struct only stores the data. But we can use the impl to add 
// data or methods for the Database type.
impl Database {

    // Syntax for function call with return type Result<Database, Err>. Notice that Database is a recongized type, since we declared it so.
    // The return type here
    fn new() -> Result<Database, std::io::Error> {

        let mut map = HashMap::new();

        // read the contents, or throw error if Result type is wrong.
        // shorthand syntax for matching on Result types, returning Err or Ok depending on the result
        let contents = std::fs::read_to_string("kv.db")?;



        // Lines gives an iterator - we can use loops over iterators as such
        for line in contents.lines() {
            // split line on first delimiter. Returns Option(a, b) - None if delimiter is not present
            // Decontruction of tuple directly - could write: let kv_pair = ... and get a (&str, &str) type
            let (key, value) = line.split_once('\t').expect("Corrupt database"); 
            map.insert(key.to_owned(), value.to_owned()); // Essentially copies the memory from the borrowed slice into an owned String with .to_owned()



        }
        
    
        println!("Contents is not free'd here and is {}", contents);
        
        // Notice here that the type of key, value is &str and not String. Let us dive a bit into this. The idea behind this concept is called borrowing.
        /*
            Rust does not have a garbage collector. We have ownership instead. The type String represents some data in memory. When this memory is no longer used, we want to free it.
            In Rust, each item in memory has an owner. I.e. the String key, value from main() is owned by the variables key, value respectively.
            Ownership means: When the variable binding goes out of scope, (i.e. at the end of main), the memory it has ownership over (i.e. the contents) is free'd.
            Thus, when we leave the main function, the memory for key, value is free'd, since they go out of scope.

            However: We can transfer ownership between scopes. The hashmap is moved into the Database struct, which is moved into the database binding, which then when
            we leave main, is free'd. Thus, first the "map" owns the hashmap, and then the Database struct owns it (since it is moved) and then the "database" variable
            owns it...

            Now notice, contents is of type String, i.e. contents owns the String value. Now the &str is a reference/view into the owned string. What does this mean?
            It means that key owns a REFERENCE to a string - it doesn't own the actual String. Thus, when the &str variable is dropped, nothing happens - since we did not own the String!
            So: Contents owns the memory storing the String content. (key, value) owns a pointer - when we leave their scope (after the for loop), the memory is NOT free'd
            since they just own pointers to the actual memory! Otherwise, we'd lose the data in contents, after the for loop...
                What this also means is that the (key, value) can NOT be used, when contents is dropped, since the owner has destroyed the contents and thus the references. 
                This gives us some memory safety - once the memory value is destroyed, other variables with references CANNOT access the memory.
                For this example, this might not make sense, since we syntatically cannot do this anyway, but in some cases it would be possible...
            
            We call String an owned variable, and &str a slice.
            
        */
        
        
        // Return a new struct - notice we can omit the "return", the last expression is returned from a function
        // Notice, since we're using Result as return type, we must return Ok(Database)
        Ok(Database { 
            map: map, // Our HashMap wants to own the strings with String, and not slices/views/references to the strings.
        })
    }

}