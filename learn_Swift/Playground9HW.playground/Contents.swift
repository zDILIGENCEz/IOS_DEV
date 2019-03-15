//: Playground - noun: a place where people can play

import Cocoa

typealias Operation = (operandOne:Float, operandTwo:Float, operation:Character)
let constant:Operation = (3.1, 33, "-")

switch constant
{
    case (_, _, "+"):
        print(constant.operandOne + constant.operandTwo)
    case (_, _, "-"):
        print(constant.operandOne - constant.operandTwo)
    case (_, _, "*"):
        print(constant.operandOne * constant.operandTwo)
    case (_, _, "/"):
        print(constant.operandOne / constant.operandTwo)
    default:
        print("Wrong operation")
}
