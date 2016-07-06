package main

import (
	"fmt"
	"time"
)

func th() {

	a := 1
	fmt.Println("...")
	for a > 0 {
		fmt.Println("--------------------------------", time.Now())
	}

}

func main() {
	// go th()
	fmt.Println("w, ...")
}
