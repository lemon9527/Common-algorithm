# Unique Maximum Number
arraysize = input("Please input array size: ")

# 把数字分别存入numbers 列表中
numbers = [int(n) for n in input('Enter number: ').split()]
print(numbers)
new_numbers = []

# 遍历列表，对每个元素统计个数, 把仅出现一次的元素放到新的列表 new_numbers
# 如果没有只出现一次的元素，则返回 -1
for number in numbers:
    if numbers.count(number) == 1:
        new_numbers.append(number)

new_numbers.sort(reverse=True)  # 降序
print(new_numbers[0])

if len(new_numbers) == 0:       # 如果没有仅出现一次的元素，输出 -1
    print(-1)
