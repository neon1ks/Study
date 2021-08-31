# Geek Translator
# Demonstrates using dictionaries

geek = {"404": "clueless.  From the web error message 404, meaning page not found.",
        "Googling": "searching the Internet for background information on a person.",
        "Keyboard Plaque" : "the collection of debris found in computer keyboards.",
        "Link Rot" : "the process by which web page links become obsolete.",
        "Percussive Maintenance" : "the act of striking an electronic device to make it work.",
        "Uninstalled" : "being fired.  Especially popular during the dot-bomb era."}  

choice = None
while choice != "0" and choice != "":

    print("""
    Geek Translator
    
    0 - Quit (Выйти)
    1 - Look Up a Geek Term (Найти толкование термина)
    2 - Add a Geek Term (Добавить термин)
    3 - Redefine a Geek Term (Изменить толкование)
    4 - Delete a Geek Term (Удалить термин)
    5 - Print
    """
    )
    
    choice = input("Choice: ")
    print()

    # exit
    if choice == "0" or choice == "":
        print("Good-bye.")

    # get a definition
    elif choice == "1":
        term = input("What term do you want me to translate?: ")
        if term in geek:
            definition = geek[term]
            print("\n", term, "means", definition)
        else:
            print("\nSorry, I don't know", term)

    # add a term-definition pair
    elif choice == "2":
        term = input("What term do you want me to add?: ")
        if term not in geek:
            definition = input("\nWhat's the definition?: ")
            geek[term] = definition
            print("\n", term, "has been added.")
        else:
            print("\nThat term already exists!  Try redefining it.")

    # redefine an existing term
    elif choice == "3":
        term = input("What term do you want me to redefine?: ")
        if term in geek:
            definition = input("What's the new definition?: ")
            geek[term] = definition
            print("\n", term, "has been redefined.")
        else:
            print("\nThat term doesn't exist!  Try adding it.")
       
    # delete a term-definition pair
    elif choice == "4":
        term = input("What term do you want me to delete?: ")
        if term in geek:
            del geek[term]
            print("\nOkay, I deleted", term)
        else:
            print("\nI can't do that!", term, "doesn't exist in the dictionary.")
    elif choice == "5":
        for item in geek:
            print(item, "—", geek[item])
    # some unknown choice
    else:
        print("\nSorry, but", choice, "isn't a valid choice.")
  
input("\n\nPress the enter key to exit.")
