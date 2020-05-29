class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.priority = []
    
    def get(self, key: int) -> int:
        if key not in self.priority:
            return -1
        self.priority.remove(key)
        self.priority.append(key)
        return self.cache[key]
    
    def put(self, key: int, value: int) -> None:
        if key in self.priority:
            self.priority.remove(key)
        else:
            if len(self.cache) == self.capacity:
                removedElement = self.priority.pop(0)
                self.cache.pop(removedElement)
        self.priority.append(key)
        self.cache[key] = value

if __name__ == '__main__':
    lru =  LRUCache(3)

    for i in range(4):
        lru.put(i, i*2)
    lru.get(2)
    print(lru.get(1))
        