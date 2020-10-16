#ifndef COMPONENTB_H
#define COMPONENTB_H


#include "IComponent.h"
class ComponentB final : public IComponent
{
public:
    ComponentB();

    std::string name() const override;
};

#endif // COMPONENTB_H
