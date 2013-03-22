package main

import "os"
import "fmt"
import "simplemath"
import "strconv"

var Usage = func() {
    fmt.Println("Usage: calc command [arguments] ...")
    fmt.Println("\nThe command are:\n\tadd\tAddition of two values.\n\tsqrt\tSquare root of a non-negative value.")
}

var ErrAdd = func() {
    fmt.Println("USAGE: calc add <integer1> <integer2>")
}

func main() {
    args := os.Args
    if args ==nil || len(args) < 2 {
        Usage()
        return
    }

    switch args[0] {
        case "add":
            if len(args) != 3 {
                ErrAdd()
                return
            }
            v1, err1 := strconv.Atoi(args[1])
            v2, err2 := strconv.Atoi(args[2])

            if err1 != nil || err2 != nil {
                ErrAdd()
                return
            }
            ret := simplemath.Add(v1, v2)
            fmt.Println("result: %d ", ret)
        case "sqrt":
            if len(args) != 2 {
                fmt.Println("USAGE: calc sqrt <integer>")
                return
            }
            v, err := strconv.Atoi(args[1])

            if err != nil {
                fmt.Println("USAGE: calc sqrt <integer>")
                return
            }
            ret := simplemath.Sqrt(v)
            fmt.Println("Result: %d ", ret)
        default:
            Usage()
    }
}
