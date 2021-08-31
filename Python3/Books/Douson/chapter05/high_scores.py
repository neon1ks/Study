# High Scores (рекорды)
# Demonstrates list methods (Демонстрирует списочные методы)

scores = []
choice = None

while choice != "0":

    print(
    """
    High Scores (Рекорды)
    
    0 - Exit (Выйти)
    1 - Show Scores (Показать рекорды)
    2 - Add a Score (Добавить рекорд)
    3 - Remove a Score (Удалить рекорд)
    4 - Sort Scores (Сортировать список)
    """
    )
    
    choice = input("Choice (ваш выбор): ")
    print()

    # exit
    if choice == "0":
        print("Good-bye (До свидания).")

    # list high-score table
    elif choice == "1":
         print("High Scores (Рекорды)")
         for score in scores:
            print("    ", end="")
            print(score)

    # add a score
    elif choice == "2":
        score = int(input("What score did you get? (Впишите свой рекорд): "))
        scores.append(score)

    # remove a score
    elif choice == "3":
        score = int(input("Remove which score? (Какой из рекордов удалить): "))
        if score in scores:
            scores.remove(score)
        else:
            print(score, "isn't in the high scores list. (рекорда нет в списке)")

    # sort scores
    elif choice == "4":
        scores.sort(reverse=True)

    # some unknown choice (непонятный пользовательский ввод)
    else:
        print("Sorry, but", choice, "isn't a valid choice. (Введенного пункта нет в списке")
  
input("\n\nPress the enter key to exit.")
