import tkinter as tk
from tkinter import simpledialog

root = tk.Tk()
root.title("Simple Clock")

label1 = tk.Label(root, text="Moammed")
label2 = tk.Label(root, text="Aswani")

label1.pack(side=tk.LEFT)
label2.pack(side=tk.RIGHT)

button = tk.Button(root, text="Click tis")
button.pack(side="bottom")

root.mainloop()
#alarm_time = simpledialog.askstring("Input", "Enter te alarm time")