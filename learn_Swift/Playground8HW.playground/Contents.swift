//: Playground - noun: a place where people can play

import Cocoa
typealias text = String
let first : text = "1234"
let secound : text = "4321"
let fird : text = "1a2b"
if Int(first) != nil
{
    print(first)
}
if Int(secound) != nil
{
    print(secound)
}
if Int(fird) != nil
{
    print(fird)
}
typealias TupleType = (numberOne:text?, numberTwo:text?)?
var one:TupleType = ("190", "67"), two:TupleType = ("100","nil"), thre:TupleType = ("-67", "70")
if let resOne = Int(one!.numberOne!), let resTwo = Int(one!.numberTwo!), resOne != nil && resTwo != nil
{
    print(resOne, resTwo)
}
if let resOne = Int(two!.numberOne!), let resTwo = Int(two!.numberTwo!), resOne != nil && resTwo != nil
{
    print(resOne, resTwo)
}
if let resOne = Int(thre!.numberOne!), let resTwo = Int(thre!.numberTwo!), resOne != nil && resTwo != nil
{
    print(resOne, resTwo)
}
