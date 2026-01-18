class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        pos = haystack.find(needle)
        return pos 

  
haystack = "sadbutsad"
needle = "sad"

obj = Solution()
print(obj.strStr(haystack, needle))