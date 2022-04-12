// This file contains comments on code and notes in general, to avoid obfuscating the main.rs file with note-keeping:


// Current context is: let write_result = std::fs::write("kv.db", contents);


// Write returns a result, indicating if the operation was successful or not. In Java, we'd throw an exception, 
    // but we have no exceptions in Rust, so we indicate whether the operation was a success or not via the Result type.
    // Brief explanation of the result type. It look like this: Result<(), Error>, i.e. either unit (think void) or an Error-type. 
    // We can use pattern matching to check whether we got the unit type or the error type as such:
    
    // Result can be either Ok or Err
    // match write_result {
    //     // Ok type takes nothing
    //     Ok(()) => {

    //     },
    //     // Error type takes error as argument
    //     Err(e) => {

    //     }
    // }


    // String::from is another way to go from a slice to an owned String.

    
    // How a simple match on a result type would look, if not using the ? operator.
    
    // Since match is an expression, we can use it in assignments
        
    // let contents = match std::fs::read_to_string("kv.db") {
    //     Result::Ok(c) => {c}
    //     Result::Err(e) => {return Result::Err(e);} // Return a result type, with the error as such. The "return" keyword is for the entire function, not just the match
    // };


    // Iterators are lazy - we don't get the elements a priori, we must get a collection from the iterator to get all the elements a priori

    // Alternative to 'split_once': Using splitn with an iterator
    // let mut elements = line.splitn(2, '\t');
    // let key = elements.next(); let value = elements.next();

    // Brief explanation of Result - Result is an Enum! It takes two types, Result<T, E>, and can either be Ok(T) or Err(E)
    // Enums work like enums in other languages mostly, but we can have data associated with enums in Rust, as the contents of the Ok, or the error!

    