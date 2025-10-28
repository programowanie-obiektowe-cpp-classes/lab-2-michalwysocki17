#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource_ptr;

    void cleanup()
    {
        if (resource_ptr != nullptr) {
            delete resource_ptr;
            resource_ptr = nullptr;
        }
    }

public:
    ResourceManager() : resource_ptr(new Resource()) {}

    double get() { return resource_ptr->get(); }

    ~ResourceManager() { cleanup(); }

    ResourceManager(const ResourceManager& other) : resource_ptr(new Resource(*other.resource_ptr))
    {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* temp_resource = new Resource(*other.resource_ptr);

            cleanup();

            resource_ptr = temp_resource;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource_ptr(other.resource_ptr)
    {
        other.resource_ptr = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            cleanup();

            resource_ptr = other.resource_ptr;

            other.resource_ptr = nullptr;
        }
        return *this;
    }
};