#ifndef INTERFACE_VISITOR_H
#define INTERFACE_VISITOR_H





class Entity;
class Interface_Visitor
{
public:
    virtual void paint(Entity *entity) = 0;
};

#endif // INTERFACE_VISITOR_H
