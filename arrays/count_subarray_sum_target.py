# LC 560

from typing import List

def subarraySum(nums: List[int], target: int) -> int:
    sum = 0
    hash = {0 : 1}
    count = 0

    for i in range(len(nums)):
        sum = sum + nums[i]
        if sum - target in hash:
            count += hash.get(sum - target)
        hash[sum] = hash.get(sum, 0) + 1

    return count

if __name__ == "__main__":
 
    nums = [1, 3, 1, 4, 23]
    target = 5

    print(subarraySum(nums, target))
