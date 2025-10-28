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
    ResourceManager(const ResourceManager& other) : resource_ptr(new Resource(*other.resource_ptr)) {};
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* temp_resource = new Resource(*other.resource_ptr);
            resource_ptr = temp_resource;
        }
        return *this;
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