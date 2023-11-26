class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_nums = {}

        for i, num in enumerate(nums):
            req = target - num

            if req in seen_nums:
                return [i, seen_nums[req]]
            
            seen_nums[num] = i

        return []
        