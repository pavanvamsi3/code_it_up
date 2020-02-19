import heapq
from typing import List


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.heap = []
        self.k = k

        for i in nums:
            if len(self.heap) < k:
                heapq.heappush(self.heap, i)
            else:
                if i > self.heap[0]:
                    heapq.heappushpop(self.heap, i)

    def add(self, val: int) -> int:
        if len(self.heap) < self.k:
            heapq.heappush(self.heap, val)
        else:
            if val > self.heap[0]:
                print(val)
                damn = heapq.heappushpop(self.heap, val)
                print(damn)

        return self.heap[0]


if __name__ == '__main__':
    k = 4
    heap = [4, 2, 3, 5]
    k_obj = KthLargest(k, heap)
    print(k_obj.add(1))
    print(k_obj.add(-1))
    print(k_obj.add(-10))




