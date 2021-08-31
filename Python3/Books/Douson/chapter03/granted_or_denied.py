# Granted or Denied
# Demonstrates an else clause

print("Welcome to System Security Inc.")
print("-- where security is our middle name\n")

password = input("Enter your password: ")

if password == "secret":
    print("Access Granted") # Доступ открыт
else:
    print("Access Denied") # Доступ закрыт

input("\n\nPress the enter key to exit.")
