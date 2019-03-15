//: Playground - noun: a place where people can play

import Cocoa

var a = 1
var b = 2

let closureSum : () -> Int = {
    [a,b] in
    return a+b
}

let closureSum2 : () -> Int = {
    return a+b
}

closureSum()
closureSum2()

a = 3
b = 4

closureSum()
closureSum2()

