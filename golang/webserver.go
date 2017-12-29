package main

import "net/http"
import "fmt"

func index(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "Hello Wolrd")
}

func main() {
	http.HandleFunc("/", index)
	http.ListenAndServe(":8099", nil)
}
