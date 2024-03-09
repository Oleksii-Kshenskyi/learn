package main

import "fmt"

func fib(n uint64) uint64 {
	if n == 0 || n == 1 {
		return n
	} else {
		return fib(n-1) + fib(n-2)
	}
}

func main() {
	var n uint64 = 42
	fmt.Printf("Fib %d is %d", n, fib(n))
}
