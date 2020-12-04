package main

import (
	"fmt"
	"os"
	"strconv"
)

func stringArrToIntArr(strarr []string) []int {
	var result []int
	for _, element := range strarr {
		converted, err := strconv.Atoi(element)
		if err != nil {
			fmt.Println("NOPE: Could not convert", element, "to string!")
			os.Exit(1)
		}
		result = append(result, converted)
	}

	return result
}

func sumOnce(sumThis []int) int {
	acc := 0
	for _, element := range sumThis {
		acc += element
	}
	return acc
}

func sumOfNthSums(sumThis []int) int {
	acc := 0
	for index := 0; index < len(sumThis); index++ {
		slice := sumThis[:index+1]
		acc += sumOnce(slice)
	}
	return acc
}

func main() {
	cliArgs := os.Args[1:]
	fmt.Println("Sum of the args: ", sumOfNthSums(stringArrToIntArr(cliArgs)))
}
