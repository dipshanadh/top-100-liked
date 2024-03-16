class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(nums: List[int], left: int, right: int) -> None:
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]

                left += 1
                right -= 1

        size = len(nums)
        dividor = size - 1 - (k % size)

        reverse(nums, 0, dividor)
        reverse(nums, dividor + 1, size - 1)
        reverse(nums, 0, size - 1)