//: Playground - noun: a place where people can play

import Cocoa

var first_cortage = (my_favorite_film: "film", my_favorite_number: 55, my_favorite_dinner: "spagetti")
let film = first_cortage.my_favorite_film, number = first_cortage.my_favorite_number, dinner = first_cortage.my_favorite_dinner
var secound_cortage = ("film_2", 100, "sosages")
var another_cortage: (String, Int, String)
another_cortage = first_cortage
first_cortage = secound_cortage
secound_cortage = another_cortage
var new_cortage = (first_cortage.my_favorite_number, secound_cortage.1, first_cortage.my_favorite_number-secound_cortage.1)
print(first_cortage)
print(secound_cortage)
print(new_cortage)
