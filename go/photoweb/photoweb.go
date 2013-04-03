package main

import {
	"io"
	"log"
	"net/http"
}
func uploadHandler(w http.ResponseWriter, r *http.Request) {
	
}

func main() {
	http.HandlerFunc("/upload", uploadHandler)
	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err.Error())
	}
	
}