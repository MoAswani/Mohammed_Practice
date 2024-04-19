# Ask user to enter text to encrypt and shift value
def get_text():
    text = input("Enter text to encrypt: ")
    shift = int(input("Enter shift value between 1 and 25: "))

    if shift < 1 or shift > 25:
        print("Enter a valid shift value between 1 and 25")

    return text, shift

# Perfom encryption and return encrypted text
def encrypt(text, shift):
    encrypted_text = ''
    for letter in text:
        if letter.isalnum():
            if letter.isupper():
                #new_letter = chr(ord(letter)+ shift)
                new_letter = chr((ord(letter) - ord('A') + shift) % 26 + ord('A'))
                encrypted_text += new_letter
            elif letter.islower():
                # new_letter = chr(ord(letter)+ shift)
                new_letter = chr((ord(letter) - ord('a') + shift) % 26 + ord('a'))
                encrypted_text += new_letter
            elif letter.isdigit():
                encrypted_text += letter
        else:
            encrypted_text += letter
     
    return encrypted_text


user_text, user_shift =(get_text())
print(encrypt(user_text, user_shift))