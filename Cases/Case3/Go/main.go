package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().Unix())
	var testArray [200000]int
	//Fills testArray with random numbers between 0 and 999999
	for index := 0; index < len(testArray); index++ {
		testArray[index] = rand.Intn(1000000)
	}
	//SearchedNum is assigned the last value in the array to create the worst case
	var searchedNum = testArray[len(testArray)-1]
	var foundFlag = false

	//Timer start
	start := time.Now()
	//Sequential search for searchedNum
	for index := 0; index < len(testArray); index++ {
		if searchedNum == testArray[index] {
			foundFlag = true
		}
	}

	fmt.Println(foundFlag)
	fmt.Println(time.Since(start))
}
