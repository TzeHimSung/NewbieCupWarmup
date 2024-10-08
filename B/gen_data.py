import os
import random


def generate_random_string(min_length=1, max_length=100000):
    length = random.randint(min_length, max_length)
    return "".join(random.choices("abcd", k=length))


if not os.path.exists("data"):
    os.makedirs("data")

for i in range(1, 11):
    file_name = f"./data/{i}.in"
    with open(file_name, "w") as f:
        for _ in range(4):
            random_string = generate_random_string()
            f.write(random_string + "\n")
        print(f"{file_name} done.")

print("All done.")
