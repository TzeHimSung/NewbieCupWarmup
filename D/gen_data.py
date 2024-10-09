import os
import random


def generate_random_integers():
    n = random.randint(1, 1000000000)
    x = random.randint(1, n)
    y = random.randint(1, n)
    return n, x, y


if not os.path.exists("data"):
    os.makedirs("data")

# 生成 10 份文件
for i in range(1, 11):
    file_name = f"data/{i}.in"
    with open(file_name, "w") as f:
        n, x, y = generate_random_integers()
        f.write(f"{n} {x} {y}\n")
        print(f"{file_name} done.")

print("All done.")
