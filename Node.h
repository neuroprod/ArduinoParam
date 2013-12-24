//
//  Node.h
//  ArduinoParam
//
//  Created by Kris Temmerman on 15/12/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef ArduinoParam_Node_h
#define ArduinoParam_Node_h
#include "arduino.h"
#include "NodeVector.h"
class Node
{
public:
    Node(){position =0;selected=0;val=0;};
    
    NodeVector<Node *>children ;
    Node * parent;
  
    String name;
    int selected;
    int type;
    int position;
    float * val;
    float step;
    float min;
    float max;
    Node * addMenu(String name )
    {
        Node *n =new Node();
        n->name =name;
        n->parent =this;
        n->type = 0;
        
        children.push_back(n);
        return n;
    }
    
    
    
    
    Node * addFloat(String name,float * _val,float _step =1.1,float _min =0, float _max=100)
    {
        Node *n =new Node();
        n->name =name;
        n->parent =this;
        n->type = 1;
        n->val = _val;
        
        n->step =_step;
        n-> min =_min;
        n->max =_max;
        children.push_back(n);
        return n;
    }
    
   


};
#endif
