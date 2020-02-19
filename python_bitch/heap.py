from typing import List
import heapq


def make_it_a_heap(h: List, n: int) -> List:
    top = []
    for t in h:
        if len(top) < 3:
            heapq.heappush(top, -1*t)
        else:
            top.pop()
            heapq.heappush(top, -1*t)
    return top


if __name__ == '__main__':
    heap = make_it_a_heap([3, 2, 1, 5], 3)
    while len(heap) != 0:
        print(heapq.heappop(heap))