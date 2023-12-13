from random import randint


def even_num(k: int) -> bool:
    return k % 2 == 0


rand_nums = [randint(-100, 100) for x in range(10)]
amount_of_even_nums = 0

print(f'\nСписок из 10ти случайных чисел: '
      f'\n{rand_nums}\n')

for i in rand_nums:
    if even_num(i):
        amount_of_even_nums += 1

print(f'Количество чётных чисел: {amount_of_even_nums}')
