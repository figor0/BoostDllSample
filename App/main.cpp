#include <iostream>
#include <map>
#include <boost/dll/import.hpp> // for import_alias
#include <boost/function.hpp>
#include <boost/filesystem.hpp>

//Core/Plugin.h
#include "Plugin.h"
#include "Factory.h"
#include "IComponent.h"

typedef std::shared_ptr<Plugin> PluginPtr;
typedef PluginPtr (PluginCreator)();
typedef std::pair<PluginPtr,  boost::function<PluginCreator>> PlugnPair;

std::vector<PlugnPair> loadPlugins(const boost::filesystem::path& dirPath);


int main(int argc, char* argv[])
{
    if(argc < 2) {
        std::cerr << "Usage: DIR_PATH PLUGIN_NAME" << std::endl;
        return -1;
    };

    boost::filesystem::path dirPath(argv[1]);

    auto plugins = loadPlugins(dirPath);

    std::cout << std::endl;
    Factory factory;
    for(auto& plugin : plugins) {
        std::cout << "Register components from" << plugin.first->name() <<' '<< plugin.first->version() << std::endl;
        plugin.first->registerComponents(factory);
    }

    std::vector<std::shared_ptr<IComponent>> components;
    for(const auto& name : factory.names()) {
        components.push_back( factory.create(name) );
    }

    for(auto component : components)
        std::cout << component->name() << std::endl;

    return 0;
}



std::vector<PlugnPair> loadPlugins(const boost::filesystem::path& dirPath)
{

    std::map<std::string, boost::filesystem::path> pluginPathes;
    if( boost::filesystem::is_directory(dirPath) ) {

        std::vector<boost::filesystem::path> pathes;
        copy(boost::filesystem::directory_iterator(dirPath), boost::filesystem::directory_iterator(), std::back_inserter(pathes));

        for(const auto& path : pathes) {
            auto ext = path.extension();
            if( (ext == ".so" || ext==".dll") ) {
                if(path.filename().string().find("Plugin") != std::string::npos) {
                    pluginPathes.insert( {boost::filesystem::basename( path ), path} );
                }
            }
        }
    }


    std::vector<boost::function<PluginCreator>> pluginCreators;

    for(const auto& pluginPath : pluginPathes) {
        std::cout << "load " << pluginPath.first;
        boost::function<PluginCreator> creator;
        creator = boost::dll::import_alias<PluginCreator>(             // type of imported symbol must be explicitly specified
                  pluginPath.second,                                            // path to library
                  "create_plugin",                                                // symbol to import
                  boost::dll::load_mode::append_decorations                              // do append extensions and prefixes
        );
        if(creator) {
            pluginCreators.push_back(creator);
            std::cout << " SUCCEED" << std::endl;
        } else {
            std::cout << " FAILED" << std::endl;
        }
    }

    std::vector<PlugnPair> plugins;
    for(auto creator : pluginCreators) {
        auto plugin = creator();
        std::cout << plugin->name() << " " << plugin->version() << std::endl;
        plugins.push_back({plugin, creator});
    }

    return plugins;
}
