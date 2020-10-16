#ifndef PLUGIN_H
#define PLUGIN_H

#include <string>
class Factory;

class Plugin
{
public:
    virtual ~Plugin() = default;

    virtual std::string name() const = 0;

    virtual std::string version() const = 0;

    // virtual std::vector<std::name> componentName() const = 0
    // virtual Creatir componentCreator(const std::string& name) = 0;

    virtual void registerComponents(Factory& factory) const = 0;
};

#endif // PLUGIN_H
