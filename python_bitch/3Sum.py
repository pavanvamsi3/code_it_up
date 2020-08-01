# This file has two Solutions: 1st is when the duplicate sets are allowed and second is when they aren't.

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            curr = nums[i]
            low = i+1
            high = len(nums)-1
            
            while (low < high):
                sum = nums[i]+nums[low]+nums[high]
                
                if sum < 0:
                    low += 1
                elif sum > 0:
                    high -= 1
                else:
                    ans.append([nums[i], nums[low], nums[high]])
                    low += 1
                    high -= 1
        return ans

# ...without duplicate sets

class Solution:
    
    def fillValues(self, nums: List[int], i:int, ans: List[List[int]]):
        low = i+1
        high = len(nums)-1
        while (low < high):
            sum = nums[i] + nums[low] + nums[high]
            if sum < 0 or (low > i + 1 and nums[low] == nums[low - 1]):
                low += 1
            elif sum > 0 or (high < len(nums) - 1 and nums[high] == nums[high + 1]):
                high -= 1
            else:
                ans.append([nums[i], nums[low], nums[high]])
                low += 1
                high -= 1
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i == 0 or nums[i-1] != nums[i]:
                self.fillValues(nums, i, ans)
        return ans
