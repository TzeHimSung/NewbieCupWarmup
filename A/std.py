def main():
    cardsNeeded = set([f'{x}{y}' for x in [1, 9] for y in ['m', 'p', 's']] + 
                      [f'{i}z' for i in range(1, 8)])
    cards = input()
    cards = set([cards[i:i + 2] for i in range(0, len(cards), 2)])
    if cards - cardsNeeded or len(cards) < 12:
        print('NO')
        return
    if len(cards) == 13:
        print('YES\n1m 1p 1s 1z 2z 3z 4z 5z 6z 7z 9m 9p 9s')
        return
    print(f'YES\n{list(cardsNeeded - cards)[0]}')


if __name__ == '__main__':
    main()
