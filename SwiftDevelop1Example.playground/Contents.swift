//: Playground - noun: a place where people can play

import Cocoa

let temperature = 20

switch temperature
{
case 18...23:
    print("The temperature is nice")
case Int.min...17:
    print("Too cold")
default:
    print("Too hot")
}
