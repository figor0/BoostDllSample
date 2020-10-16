#ifndef PLUGINB_H
#define PLUGINB_H

#include <memory>
#include <boost/config.hpp>
#include <boost/dll/alias.hpp>

#include "Plugin.h"

namespace PluginB {
    class Plugin;
}

class PluginB::Plugin: public ::Plugin
{
public:
    std::string name() const override;

    std::string version() const override;

    void registerComponents(Factory& factory) const override;

    static std::shared_ptr<::Plugin> create();
};

BOOST_DLL_ALIAS(
    PluginB::Plugin::create,
    create_plugin
)
#endif // PLUGINB_H
