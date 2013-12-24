//
//  ArduinoParam.h
//  ArduinoParam
//
//  Created by Kris Temmerman on 15/12/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef __ArduinoParam__ArduinoParam__
#define __ArduinoParam__ArduinoParam__

#include "arduino.h"
#include <LiquidCrystal.h>
#include "Node.h"

class ArduinoParam :public Node
{
public:
   
    //NodeVector <int> childPositions;
    Node *currentNode;
    Node *currentParent;
    ArduinoParam(){
        lcd =new LiquidCrystal(32, 30, 28, 26, 24, 22);
        lcd->begin(16, 2);
        // Print a message to the LCD.
        
        //childPositions.push_back(0);
        currentParent =this;
       
    };
    void start(){
        currentNode =children[0];
        updateDisplay();
    }
    LiquidCrystal *lcd;
    void goUp();
    void goDown();
    void back();
    void select();
    void updateDisplay();

};

#endif /* defined(__ArduinoParam__ArduinoParam__) */
