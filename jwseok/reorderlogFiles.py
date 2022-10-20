class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit_log = []
        let_log = []
        for log in logs:
            idx = 0
            while log[idx] != ' ':
                idx += 1
            identifier = log[:idx]
            if log[idx+1].isdigit():
                digit_log.append(log)
            else:
                contents = log[idx+1:]
                let_log.append([identifier, contents, log])
        let_log.sort(key=lambda x:(x[1], x[0]))
        ret = [let[2] for let in let_log]
        ret.extend(digit_log)
        return ret