import PySimpleGUI as sg
import pandas as pd


sg.theme('DarkTeal9')


EXCEL_FILE = "Book1.xlsx"



df = pd.read_excel(EXCEL_FILE)
# df = pd.read_excel(EXCEL_FILE, engine='openpyxl') 

layout = [
    [sg.Text('Please fill out the following fields', font=('Helvetica', 16))],
    [sg.Text('Name', size=(15,1)), sg.InputText(key='Name')],
    [sg.Text('Age', size=(15, 1)), sg.InputText(key='Age', enable_events=True)],
    [sg.Text('DOB', size=(15, 1)), sg.InputText(key='DOB', enable_events=True)], 
    [sg.Text('Phone no', size=(15, 1)), sg.InputText(key='Phone number', enable_events=True)],
    [sg.Text('Address', size=(15,1)), sg.Multiline(key='Address', size=(45, 3))],
    [sg.Text('Pincode', size=(15,1)), sg.InputText(key='PinCode', enable_events=True)], 
    [sg.Text('Occupation', size=(15,1)), sg.InputText(key='Occupation')],
    
    [sg.Submit(), sg.Button('Clear'), sg.Exit()]
]


window = sg.Window('Entry form', layout)

def clear_input(window):
    for key in values:
        window[key]('')  
    return None


while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Exit':
        break
    if event == 'Clear':
        clear_input(window)
    if event == 'Submit':
        # print(event, values)
     
        new_row = pd.DataFrame([values])
        # df = df.append(values, ignore_index=True)
        df = pd.concat([df, new_row], ignore_index=True)
        
        df.to_excel(EXCEL_FILE, index=False)
        
        sg.popup("Data saved!")
        
        clear_input(window)

    
window.close()