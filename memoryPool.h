#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <iostream>
#include <vector>
#include <mutex>

class MemoryPool{
public:
    static MemoryPool& getInstance(){
        static MemoryPool instance{1024 * 1e6, 1024};
        return instance;
    }

    void* allocate(size_t size);
    void deallocate(void* ptr);

    MemoryPool(MemoryPool const&) = delete;
    MemoryPool& operator=(MemoryPool const&) = delete;

private:
    size_t pool_size_;
    size_t block_size_;
    char* pool = nullptr;
    std::vector<bool> allocated_;
    std::mutex mutex_;

    MemoryPool(size_t size, size_t block_size);
    ~MemoryPool();

    void initialize();
};


#endif