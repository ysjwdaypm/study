#coding=utf-8

"""
import Tkinter
import tkMessageBox


top = Tkinter.Tk()

def hello():
    tkMessageBox.showinfo("hello python","Hello world!")
btn = Tkinter.Button(top,text=" 人生往往不是你可以掌握的",command=hello,activebackground=True)
btn.pack()

top.mainloop()
"""
#top.mainloop()

g = lambda x : x+2
info = [g(x) for x in range(10)]
print info