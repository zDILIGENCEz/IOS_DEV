//: Playground - noun: a place where people can play

import Cocoa

enum ChessmanType
{
    case King
    case Castle
    case Bishop
    case Pawn
    case Knight
    case Queen
}

enum ChessmanColor
{
    case Black
    case White
}

enum ChessmanFigure:String
{
    case KingFigureWhite = "♔"
    case CastleFigureWhite = "♖"
    case BishopFigureWhite = "♗"
    case PawnFigureWhite = "♙"
    case KnightFigureWhite = "♘"
    case QueenFigureWhite = "♕"
    case KingFigureBlack = "♚"
    case CastleFigureBlack = "♜"
    case BishopFigureBlack = "♝"
    case PawnFigureBlack = "♟"
    case KnightFigureBlack = "♞"
    case QueenFigureBlack = "♛"
}
class Chessman
{
    let type: ChessmanType
    let color: ChessmanColor
    var coordinates: (String, Int)? = nil
    let figureSymbol: ChessmanFigure
    
    init(type: ChessmanType, color: ChessmanColor, figure: ChessmanFigure)
    {
        self.type = type
        self.color = color
        self.figureSymbol = figure
    }
    
    init(type: ChessmanType, color: ChessmanColor, figure: ChessmanFigure, coordinates: (String,Int))
    {
        self.type = type
        self.color = color
        self.figureSymbol = figure
        self.setCoordinates(char: coordinates.0, num: coordinates.1)
    }
    
    func setCoordinates (char c:String, num n:Int)
    {
        self.coordinates = (c, n)
    }
    
    func kill ()
    {
        self.coordinates = nil
    }
}

class gameDesk
{
    var desk: [Int: [String:Chessman]] = [:]
    init()
    {
        for i in 1...8
        {
            desk[i] = [:]
        }
    }
    subscript(alpha: String, number: Int) -> Chessman?
    {
        get
        {
            if let chessman = self.desk[number]![alpha]
            {
                return chessman
            }
            return nil
        }
        set
        {
            if (alpha,number) == nil
            {
                Chessman.kill
            }
            self.setChessman(chess: newValue!, coordinates: (alpha, number))
        }
    }
    func setChessman(chess: Chessman, coordinates: (String, Int))
    {
        if let oldCoordinates = chess.coordinates
        {
            desk[oldCoordinates.1]![oldCoordinates.0] = nil
        }
        self.desk[coordinates.1]![coordinates.0] = chess
        chess.setCoordinates(char: coordinates.0, num: coordinates.1)
    }
    
    func printDesk(chess: Chessman,array: inout [[String]])
    {
        for i in 0...7
        {
            var flag = 0
            for j in 0...8
            {
                if flag == 0
                {
                    array[i][j] = String(i+1)
                    flag = 1
                }
                else
                {
                    var letter: Int = 0
                    switch chess.coordinates?.0 {
                    case "A":
                        letter = 1
                    case "B":
                        letter = 2
                    case "C":
                        letter = 3
                    case "D":
                        letter = 4
                    case "E":
                        letter = 5
                    case "F":
                        letter = 6
                    case "G":
                        letter = 7
                    case "H":
                        letter = 8
                    default:
                        print("Error")
                    }
                    if letter == j && chess.coordinates?.1 == i+1
                    {
                        array[i][j] = chess.figureSymbol.rawValue
                    }
                }
            }
        }
        array[8][0...8] = [" ", "A","B","C","D","E","F","G","H"]
        for i in 0...8
        {
            for j in 0...8
            {
                print(array[i][j], terminator: " ")
            }
            print()
        }
    }
}


var KingWhite = Chessman(type: .King, color: .White, figure: .KingFigureWhite)
KingWhite.setCoordinates(char: "E", num: 1)
var QueenBlack = Chessman(type: .Queen, color: .Black, figure: .QueenFigureBlack, coordinates: ("A", 6))

var game  = gameDesk()
game.setChessman(chess: QueenBlack, coordinates: ("A", 3))
game["E", 8] = QueenBlack
QueenBlack.coordinates

var arrayOfDesk = [[String]]()
arrayOfDesk = Array(repeating: Array(repeating: "-", count: 9), count: 9)
print(game.printDesk(chess: KingWhite, array: &arrayOfDesk))
print(game.printDesk(chess: QueenBlack, array: &arrayOfDesk))


