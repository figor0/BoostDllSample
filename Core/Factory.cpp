#include "Factory.h"
#include <map>
class Factory::Private
{
public:
    std::map<std::string, Creator> creators;
};

Factory::Factory()
    : m_impl(std::make_unique<Private>())
{

}

Factory::ComponentPtr Factory::create(const std::string& name) const
{
    if(m_impl->creators.count(name) == 0)
        return nullptr;

    const auto& creator = m_impl->creators.at(name);
    return creator();
}

void Factory::registerComponent(const std::string& name, const Factory::Creator& creator)
{
    if(m_impl->creators.count(name) != 0)
        throw std::runtime_error("Factory::registerComponent: component with name = " + name+ "has been already registered");

    m_impl->creators.insert({name, creator});
}

std::vector<std::string> Factory::names() const
{
    std::vector<std::string> result;
    std::transform(m_impl->creators.begin(), m_impl->creators.end(), std::back_inserter(result),
        [](const auto& pair) ->std::string { return pair.first;}
    );

    return  result;
}

Factory::~Factory()
{

}
