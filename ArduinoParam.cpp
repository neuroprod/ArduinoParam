//
//  ArduinoParam.cpp
//  ArduinoParam
//
//  Created by Kris Temmerman on 15/12/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#include "ArduinoParam.h"
void ArduinoParam::goUp(){
    if(currentNode->selected==1)
    {
        *currentNode->val +=currentNode->step;
        if(*currentNode->val>currentNode->max)*currentNode->val =currentNode->max;
    }else
    {
        currentParent = currentNode->parent;
        currentParent->position++;
        if( currentParent->position>=currentParent->children.size())
        {
            currentParent->position =currentParent->children.size()-1;
        }
        currentNode = currentParent->children[currentParent->position];
    }
    updateDisplay();
};
void ArduinoParam::goDown(){
    if(currentNode->selected==1)
    {
        *currentNode->val -=currentNode->step;
        if(*currentNode->val<currentNode->min)*currentNode->val =currentNode->min;
    }else
    {
        currentParent = currentNode->parent;
        currentParent->position--;
        if( currentParent->position<0)
        {
            currentParent->position =0;
        }
        currentNode = currentParent->children[currentParent->position];
    
    
    }

    updateDisplay();

};
void ArduinoParam::back(){
    if(currentNode->selected==1)
    {
        currentNode->selected=0;
    }
    else if( currentNode->parent != (Node *)this)
    {
        currentNode =currentNode->parent;
    }
  
     updateDisplay();
};
void ArduinoParam::select(){
   
    if(currentNode->children.size()>0)
    {
    
        currentNode->position =0;
        currentNode =currentNode->children[0];
    
    
    
    }else if(currentNode->type==1)
    {
        
        if(currentNode->selected==0)currentNode->selected=1;
        
        
        
    }
    updateDisplay();
 
};

void ArduinoParam::updateDisplay()
{
    if(children.size()==0)return;
    
    
    lcd->clear();
    String a ="";
    a =currentNode->name;
    if(currentNode->children.size()>0)
    {
        a+="~";
    }else if(currentNode->type==1)
    {
        a+=":";
        
    }
    Node * p = currentNode->parent;
    while(p != (Node*) this)
    {
        a =p->name +"~"+a;
        p=p->parent;
    }

    lcd->print(a);
    if(currentNode->selected==1)
    {
        lcd->write(255);
    }

    if(currentNode->type==1)
    {
        lcd->setCursor(0, 1);
       
      
        lcd->print(*currentNode->val);
    }


}