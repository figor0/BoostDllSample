#ifndef FACTORY_H
#define FACTORY_H

#include "Core_global.h"

#include <memory>
#include <functional>

class IComponent;
class CORE_EXPORT Factory
{
public:
    typedef  std::shared_ptr<IComponent> ComponentPtr;
    typedef  std::function<ComponentPtr()> Creator;

    Factory();

    ComponentPtr create(const std::string& name) const;

    void registerComponent(const std::string& name, const Creator& creator);

    std::vector<std::string> names() const;

    ~Factory();
private:
    class Private;
    std::unique_ptr<Private> m_impl;
};



#endif // FACTORY_H
