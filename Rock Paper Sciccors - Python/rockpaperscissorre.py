from random import choice

print('Geef "STOP" in om de game af te sluiten.')

games = 0
won = 0

while True:
    speler = input("Geef uw keuze (schaar, steen of papier): ")
    speler = speler.upper()

    if speler == "STOP":
        print("Spel afgesloten, tot ziens!")
        break

    choices = ["STEEN", "PAPIER", "SCHAAR"]

    if speler not in choices:
        print("Foutieve input, probeer opnieuw.")
        continue

    computer = choice(choices)

    if speler == computer:
        print("Gelijkspel, probeer opnieuw!")
        games += 1
        continue

    if speler == "SCHAAR" and computer == "PAPIER":
        print("Jij wint! Nog eens?")
        won += 1
        games += 1
        continue
    elif speler == "STEEN" and computer == "SCHAAR":
        print("Jij wint! Nog eens?")
        won += 1
        games += 1
        continue
    elif speler == "PAPIER" and computer == "STEEN":
        print("Jij wint! Nog eens?")
        won += 1
        games += 1
        continue
    else:
        print("Computer wint, probeer opnieuw.")
        games += 1
        continue

print("Bedankt om te spelen")

try:
    winrate = 100 * (int(won) / int(games))
    print(f"Uw winrate is {winrate:.2f}%.")
except ZeroDivisionError:
    pass