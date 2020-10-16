#ifndef PLUGINA_H
#define PLUGINA_H

#include <memory>
#include <boost/config.hpp>
#include <boost/dll/alias.hpp>

#include "Plugin.h"

namespace PluginA {
    class Plugin;
}

class PluginA::Plugin: public ::Plugin
{
public:
    std::string name() const override;

    std::string version() const override;

    void registerComponents(Factory& factory) const override;

    static std::shared_ptr<::Plugin> create();
};

BOOST_DLL_ALIAS(
    PluginA::Plugin::create,
    create_plugin
)

#endif // PLUGINA_H
