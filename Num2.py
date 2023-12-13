def add_left_digit(k: int, d: int) -> int:
    return 10 ** (len(str(k))) * d + k


def int_verification(string: str) -> int:
    string = string.strip()
    if string.isdigit() or (string[0] == '-' and string[1:].isdigit()):
        return int(string)
    else:
        raise ValueError(f'{string} isn\'t an int.')


# user_start_digit = int_verification(input('Введите число: '))
# while True:
#     additional_digit = int_verification(input(f'Введите цифры, которые вы хотите добавить к числу {user_start_digit}: '))
#     user_start_digit = add_left_digit(user_start_digit, additional_digit)
#     print(user_start_digit)

print(int_verification('-123'))
n = '-123'
print(n[0], n[1:])