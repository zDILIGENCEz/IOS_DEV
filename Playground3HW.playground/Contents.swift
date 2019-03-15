//: Playground - noun: a place where people can play

import Cocoa

let first:Int, secound:Float, third:Double
first = 18; secound = 16.4; third = 5.7
var result = Float(first) + secound + Float(third)
var result_2 = Int(Float(first) * secound * Float(third))
var result_3 = Double(Int(secound) % Int(third))
var result_3_2 = Double(secound).truncatingRemainder(dividingBy: third)
//adition operation with convert all types to float
print(result)
//multiply operation with convert all types to Int
print(result_2)
//% operation with convert all types to Double. We can do this operation only with Int types
print(result_3)
//But we have the method .trancatingRemainder or remainder
print(result_3_2)
