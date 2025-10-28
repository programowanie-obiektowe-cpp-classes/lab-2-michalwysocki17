#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource_ptr;
public:
    ResourceManager() : resource_ptr(new Resource()) {}
    double get() { return resource_ptr->get(); }
    ~ResourceManager() { delete resource_ptr; }
    ResourceManager(const ResourceManager& other) = delete;
    ResourceManager& operator=(const ResourceManager& other) = delete;
    ResourceManager(ResourceManager&& other) noexcept : resource_ptr(other.resource_ptr)
    {
        other.resource_ptr = nullptr;
    }
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource_ptr = other.resource_ptr;

            other.resource_ptr = nullptr;
        }
        return *this;
    }
};