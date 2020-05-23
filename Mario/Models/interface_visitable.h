#ifndef INTERFACE_VISITABLE_H
#define INTERFACE_VISITABLE_H

#include "interface_visitor.h"

class Interface_Visitable
{
public:
    virtual void accept(Interface_Visitor visitor) = 0;

};

#endif // INTERFACE_VISITABLE_H
