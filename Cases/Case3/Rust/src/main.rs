extern crate rand;

use rand::Rng;
use std::time::Instant;

fn main() {
    
    let mut testArray=[0;200000];
    
    //Fills testArray with random numbers between 0 and 999999
    for index in 0..testArray.len(){
        testArray[index]=rand::thread_rng().gen_range(0,1000000);
    }
    
	//SearchedNum is assigned the last value in the array to create the worst case
    let searchedNum=testArray[testArray.len()-1]; 
    let mut foundFlag = false;
    //Timer start
    let start = Instant::now();
    
	//Sequential search for searchedNum
    for index in 0..testArray.len(){
        if searchedNum==testArray[index]{
            foundFlag=true;
        }
    }
    println!("{}", foundFlag);
    println!("{}", start.elapsed().as_millis());
}

