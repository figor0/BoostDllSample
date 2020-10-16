#ifndef COMPONENTC_H
#define COMPONENTC_H

#include "IComponent.h"

class ComponentC final :  public IComponent
{
public:
    ComponentC();

    std::string name() const override;
};

#endif // COMPONENTC_H
