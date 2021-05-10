import tkinter as tk
from tkinter import *
import os

# Creating Window
root = Tk()
root.title('Git Automation Registration')
root.iconbitmap('icon.ico')
root.geometry("500x400")
root.resizable(False,False)

#  Heading
heading = Label(root, text="Git Automation Registration", font=("arial", 20,"bold")).pack(pady=15)


# Taking Inputs

github_token = Label(root, text="Enter the Github Token: ", font=("arial", 12,"bold")).pack(pady=(20,0))
github_token = Entry(root,width=50)
github_token.pack()
github_token.get()

github_user = Label(root, text="Enter the Github Username: ", font=("arial", 12,"bold")).pack(pady=(20,0))
github_user = Entry(root,width=50)
github_user.pack()
github_user.get()

repo_path = Label(root, text="Enter the Path: ", font=("arial", 12,"bold")).pack(pady=(20,0))
repo_path = Entry(root,width=50)
repo_path.pack()
repo_path.get()

#  Submit Function and creating .env file
def Submit():

    # creating exit window
    top =Toplevel()
    top.title('Registration Completed')
    top.iconbitmap('icon.ico')
    top.geometry("310x100")
    top.resizable(False,False)

    if os.path.isfile(".env"):
        os.remove(".env")
        os.system(f'echo GITHUB_TOKEN="{github_token.get()}" >> .env')
        os.system(f'echo GITHUB_USER="{github_user.get()}" >> .env')
        os.system(f'echo REPO_PATH="{repo_path.get()}" >> .env')
        message = Label(top, text="Updated Successfully", font=("arial", 12,"bold")).pack(pady=(20,0))
        Finish = Button(top, text="Finish", command=root.quit).pack( padx=(25,10), pady=(20,10))
    else:
        os.system(f'echo GITHUB_TOKEN="{github_token.get()}" >> .env')
        os.system(f'echo GITHUB_USER="{github_user.get()}" >> .env')
        os.system(f'echo REPO_PATH="{repo_path.get()}" >> .env')
        message = Label(top, text="Registration Completed Successfully", font=("arial", 12,"bold")).pack(pady=(20,0))
        Finish = Button(top, text="Finish", command=root.quit).pack( padx=(25,10), pady=(20,10))


btn = Button(root, text="Submit", command=Submit).pack(pady=(20,0))

root.mainloop()