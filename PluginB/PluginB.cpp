#include "PluginB.h"

#include "Factory.h"
#include "ComponentC.h"

std::string PluginB::Plugin::name() const
{
    return "PluginB";
}

std::string PluginB::Plugin::version() const
{
    return "1.0.1";
}

void PluginB::Plugin::registerComponents(Factory& factory) const
{
    factory.registerComponent("ComponentC", []{return  std::make_shared<ComponentC>();});
}

std::shared_ptr<Plugin> PluginB::Plugin::create()
{
    return std::make_shared<PluginB::Plugin>();
}
