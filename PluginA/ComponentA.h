#ifndef COMPONENTA_H
#define COMPONENTA_H

#include "IComponent.h"

class ComponentA final : public  IComponent
{
public:
    ComponentA();

    std::string name() const override;
};

#endif // COMPONENTA_H
