def solve():
    n = int(input())  # Read
    if n == 1:
        print("7 6")
    elif n == 2:
        print("11 9")
    elif n == 3:
        print("7 4")
    elif n > 3:
        if n % 2 == 1:
            print(3, n ^ 3)  # XOR with 3
        else:
            print(2, n ^ 2)  # XOR with 2

def main():
    T = int(input())  # Number of test cases
    for _ in range(T):
        solve()

if __name__ == "__main__":
    main()
