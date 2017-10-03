def permute(s, new = "", answer = []):
    if len(s) <= 1:
        answer.append(new + s)
        return
    else:
        for i in range(len(s)):
            permute(s[:i] + s[i + 1:], new + s[i], answer)
        return answer

print(permute("1234"))


## time complexity => O(n!)
