//: Playground - noun: a place where people can play

import Cocoa

typealias Chessman = [String: (alpha:Character, num: Int)?]
var Chessmans:Chessman = ["white king": ("a",3), "black pawn": ("b",6), "white quin": nil]

func changeOfChess ( dictionary: inout [String: (alpha: Character, num: Int)?], newName: String, newLetterAndNum: (newLetter: Character, newNum: Int)?) -> Void
{
    for (nameOfChess,var info) in dictionary
    {
        if newName == nameOfChess
        {
            info!.alpha = newLetterAndNum!.newLetter
            info!.num = newLetterAndNum!.newNum
        }
        else
        {
            dictionary.updateValue((newLetterAndNum?.newLetter, newLetterAndNum?.newNum) as? (alpha: Character, num: Int), forKey: newName)
        }
    }
}

changeOfChess(dictionary: &Chessmans, newName: "white horse", newLetterAndNum: (newLetter: "c", newNum: 6))
changeOfChess(dictionary: &Chessmans, newName: "black pawn", newLetterAndNum: (newLetter: "b", newNum: 7))

