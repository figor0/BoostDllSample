#include "PluginA.h"
#include "Factory.h"

#include "ComponentA.h"
#include "ComponentB.h"

std::string PluginA::Plugin::name() const
{
    return "PluginA";
}

std::string PluginA::Plugin::version() const
{
    return "1.0.0";
}

void PluginA::Plugin::registerComponents(Factory& factory) const
{
    factory.registerComponent("ComponentA",[]{ return std::make_shared<ComponentA>(); });
    factory.registerComponent("ComponentB",[]{ return std::make_shared<ComponentB>(); });
}

std::shared_ptr<Plugin> PluginA::Plugin::create()
{
    return std::make_shared<PluginA::Plugin>();
}
