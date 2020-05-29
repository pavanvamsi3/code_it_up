class Solution:

    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = []
        digit_logs = []
        
        for string in logs:
            split  = string.split()
            if not split[1].isdigit():
                letter_logs.append(string)
            else:
                digit_logs.append(string)
        letter_logs.sort(key=lambda letters: (letters.split()[1:], letters.split()[0]))   
        return letter_logs+digit_logs
