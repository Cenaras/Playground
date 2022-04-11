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