#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "Core_global.h"

#include <string>

class CORE_EXPORT IComponent
{
public:
    virtual ~IComponent() = default;

    virtual std::string name() const = 0;
};


#endif // ICOMPONENT_H
