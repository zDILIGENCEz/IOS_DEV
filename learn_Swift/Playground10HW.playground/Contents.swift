//: Playground - noun: a place where people can play

import Cocoa

typealias Chessman = [String: (alpha:Character, num: Int)?]
var Chessmans:Chessman = ["white king": ("a",3), "black pawn": ("b",6), "white quin": nil]

/*
 First HW
if (Chessmans["white king"]??.alpha) != nil
{
    print("coordinates of white king = \((Chessmans["white king"]??.alpha)!):\((Chessmans["white king"]??.num)!)")
}
else
{
    print("the white king is dead")
}
if (Chessmans["black pawn"]??.alpha) != nil
{
    print("coordinates of black pawn = \((Chessmans["black pawn"]??.alpha)!):\((Chessmans["black pawn"]??.num)!)")
}
else
{
    print("the black pawn is dead")
}
if (Chessmans["white quin"]??.alpha) != nil
{
    print("coordinates of white quin = \((Chessmans["white quin"]??.alpha)!):\((Chessmans["white quin"]??.num)!)")
}
else
{
    print("white quin is dead")
}
*/
/*
 Secound HW
for (name, info) in Chessmans
{
    if info != nil
    {
        print("coordinates of \(name) = \(info!.alpha) : \(info!.num)")
    }
    else
    {
        print("\(name) is dead")
    }
}
*/

func chessAnalizer (dictionary: [String: (alpha:Character, num:Int)?]) -> Void
{
    for (name, info) in dictionary
    {
        if info != nil
        {
            print("coordinates of \(name) = \(info!.alpha) : \(info!.num)")
        }
        else
        {
            print("\(name) is dead")
        }
    }
}
chessAnalizer(dictionary: Chessmans)
