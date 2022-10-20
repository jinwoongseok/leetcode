class Solution:
    def groupAnagrams(self, strs):
        answer = []
        if len(strs) <= 1:
            answer.append([strs[0]])
            return answer
        sorted_list = [(''.join(sorted(word)), word) for word in strs]
        sorted_list.sort()
        l = 0
        while l < len(sorted_list):
            sub_list = [sorted_list[l][1]]
            r = l+1
            while r < len(sorted_list):
                if sorted_list[l][0]==sorted_list[r][0]:
                    sub_list.append(sorted_list[r][1])
                    r += 1
                else:
                    break
            answer.append(sub_list)
            l = r
        return answer