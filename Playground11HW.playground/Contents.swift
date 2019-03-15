//: Playground - noun: a place where people can play

import Cocoa


 var dictionary:[String:[String:UInt]] = ["Dallington":["26 of september":4, "4 of october": 2], "Betrad":["1 of january": 5, "20 of february" : 4], "Galdred":["15 of march": 4, "13 of april": 1]]
var summOne:Float = 0, summOfAll:Float = 0, count = 0

for (sername,dict) in dictionary
{
    summOne = 0
    for (_, mark) in dict
    {
        summOne += Float(mark)
        summOfAll += Float(mark)
        count += 1
    }
    print("\(sername) - \(summOne/2)")
}
print("middle mark of all students = \(summOfAll/Float(count))")

