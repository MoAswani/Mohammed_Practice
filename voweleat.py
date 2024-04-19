word = input("Enter a word: ")
novowelword = ""
vowels = ['a','e','i','o','u']

for x in word:
    if x in vowels:
        continue
    else:
        pass

    novowelword+=x
print(novowelword)

email = input("Enter a valid email: ")
print(email)
if '@' or '.' not in email:
    print(email+" is not a valid email, try anoter one")

else:
    print('proceed')
