#include "memoryPool.h"

MemoryPool::MemoryPool(size_t size, size_t block_size): pool_size_(size), block_size_(block_size){
    pool = new char[pool_size_];
    initialize();
}

MemoryPool::~MemoryPool(){
    delete[] pool;
}

void MemoryPool::initialize(){
    allocated_.assign(pool_size_/block_size_, false);
}

void* MemoryPool::allocate(size_t size){     // size: The number of bytes requested by the thread.
    std::lock_guard<std::mutex> lock(mutex_);
    if(size > block_size_){
        return nullptr;
    }
    for(size_t i = 0; i < allocated_.size(); i++){
        if(allocated_[i] == false){
            allocated_[i] = true;
            return static_cast<void*>(pool + i * block_size_);
        }
    }
    return nullptr;
}

void MemoryPool::deallocate(void* ptr){
    std::lock_guard<std::mutex> lock(mutex_);
    if(ptr < pool || ptr >= pool + pool_size_){
        return;
    }
    size_t index = (reinterpret_cast<char*>(ptr) - pool) / block_size_;
    if(index >= 0 && index < allocated_.size()){
        allocated_[index] = false;
    }
    return;
}























int main(int, char**){
    std::cout << "Hello, from memoryPool!\n";
}
