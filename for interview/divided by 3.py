# L is contain 0 to 9 digit. white fuction which finds the largest number that can be made
# from some of all of these digits and is divisible by 3
# if l = [3, 1, 4, 1] => 4311,  l = [3, 1, 4, 1, 5, 9] => 94311



def div_3(list):
    number = None
    list.sort()
    if len(list) == 0:
        return 0
    elif list[len(list) - 1] == 0:
        return 0
    else:
        div3, answer = sum(list)   # div3 = 45, answer = 312412
        number = int(answer)
        div1 = []
        div2 = []
        for i in list:
            if i % 3 == 1:
                div1.append(i)
            elif i % 3 == 2:
                div2.append(i)
        i = 0
        print(div1, div2)
        print(div3, answer)
        while int(div3) % 3 != 0:
            if div3 % 3 == 1:
                if len(div1) >= 1:
                    for i in range(len(answer) - 1, -1, -1):
                        if answer[i] == str(div1[0]):
                            answer = answer[:i] + answer[i + 1:]
                            break
                elif len(div1) == 0 and len(div2) == 0 or len(div2) == 1:
                    return 0
                else:
                    count = 0
                    for i in range(len(answer) - 1, -1, -1):
                        if answer[i] == str(div2[count]):
                            answer = answer[:i] + answer[i + 1:]
                            count += 1
                            if count == 2:
                                break
            else:
                if len(div2) >= 1:
                    for i in range(len(answer) - 1, -1, -1):
                        if answer[i] == str(div2[0]):
                            answer = answer[:i] + answer[i + 1:]
                            break
                elif len(div2) == 0 and len(div1) == 0 or len(div1) == 1:
                    return 0
                else:
                    count = 0
                    for i in range(len(answer) - 1, -1, -1):
                        if answer[i] == str(div1[count]):
                            answer = answer[:i] + answer[i + 1:]
                            count += 1
                            if count == 2:
                                break
            break
        return answer



def sum(list):
    divi3 = 0
    sum = 0
    k = ""
    for i in range(len(list) - 1, - 1, -1):
        k += str(list[i])
        sum += (list[i])
    return sum, k

print(div_3([0, 0, 0, 0, 3]))
