from tkinter import *
import serial
#ArduinoSerial= serial.Serial('/dev/cu.usbmodem1421',9600)


fenster =Tk()
fenster.title("getränke auswahl")
fenster.geometry("500x500")

def ausgabe1():                                                  #verschiedene Getränke Wählen
    print("1")
    ArduinoSerial.write(b'1')

def ausgabe2():
    print("2")
    ArduinoSerial.write(b'2')

def ausgabe3():
    print("3")
    ArduinoSerial.write(b'3')

def ausgabe4():
    print("4")
    ArduinoSerial.write(b'4')

def ausgabe5():
    print("5")
    ArduinoSerial.write(b'5')

def ausgabe6():
    print("6")
    ArduinoSerial.write(b'6')

def ausgabe7():
    print("7")
    ArduinoSerial.write(b'7')

    
knopf1 = Button(fenster, text="getränk1!",command= ausgabe1)
knopf1.pack()

knopf2 = Button(fenster, text="getränk2!",command= ausgabe2)
knopf2.pack()

knopf3 = Button(fenster, text="getränk3!",command= ausgabe3)
knopf3.pack()

knopf4 = Button(fenster, text="getränk4!",command= ausgabe4)
knopf4.pack()

knopf5 = Button(fenster, text="getränk5!",command= ausgabe5)
knopf5.pack()

knopf6 = Button(fenster, text="COLA-WODKA!",command= ausgabe6)
knopf6.pack()

knopf7 = Button(fenster, text="COLA-KORN!",command= ausgabe7)
knopf7.pack()



    
eingabe =(Entry(fenster) )                                       #eingabefenster für die ml wahl
eingabe.pack()


def lesen():
    print(eingabe.get())
    ArduinoSerial.write(str.encode(eingabe.get()))

knopfml = Button(fenster, text="Eingabe eingelockt",command=lesen)
knopfml.pack()

mainloop()

