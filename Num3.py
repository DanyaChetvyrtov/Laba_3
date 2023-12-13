def head_3(num: int, counter=1) -> int:
    if counter < 0:
        raise ValueError('Second argument can\'t be less then 0 !')
    if counter == 0:
        return num
    return head_3(10 ** (len(str(num))) * 3 + num, counter - 1)


print(head_3(3, 10))
