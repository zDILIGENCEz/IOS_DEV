//
//  ViewController.swift
//  IntroductionToSimulator
//
//  Created by DILIGENCE on 26.08.2018.
//  Copyright © 2018 DILIGENCE. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        var names = ["Masha","Nastya"]
        names.removeFirst()
        names.removeFirst()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

