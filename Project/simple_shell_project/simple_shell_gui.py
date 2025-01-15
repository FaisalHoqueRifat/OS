import os
import tkinter as tk
from tkinter import messagebox

# Function to handle the 'ls' command (list files)
def list_files():
    try:
        files = os.listdir(os.getcwd())  # Get list of files in the current directory
        return '\n'.join(files)
    except Exception as e:
        return f"Error: {e}"

# Function to handle the 'pwd' command (print current directory)
def print_working_directory():
    return os.getcwd()  # Get the current working directory

# Function to handle the 'cd' command (change directory)
def change_directory(path):
    try:
        os.chdir(path)  # Change the current directory
        return f"Changed directory to {path}"
    except FileNotFoundError:
        return f"Error: Directory {path} not found."
    except PermissionError:
        return f"Error: Permission denied to access {path}."
    except Exception as e:
        return f"Error: {e}"

# Function to execute commands from the GUI
def execute_command():
    user_input = command_entry.get()  # Get user input from the entry box
    output_text.delete(1.0, tk.END)  # Clear previous output

    # Handle the 'exit' command
    if user_input.lower() == 'exit':
        window.quit()  # Close the GUI window

    # Handle the 'pwd' command
    elif user_input.lower() == 'pwd':
        output_text.insert(tk.END, print_working_directory())

    # Handle the 'ls' command
    elif user_input.lower() == 'ls':
        output_text.insert(tk.END, list_files())

    # Handle the 'cd' command
    elif user_input.lower().startswith('cd '):
        path = user_input[3:].strip()  # Extract the path after 'cd'
        output_text.insert(tk.END, change_directory(path))

    else:
        output_text.insert(tk.END, f"Error: Command '{user_input}' not recognized.\n")

# Create the main window for the GUI
window = tk.Tk()
window.title("Simple Shell (GUI)")

# Create a label for instructions
label = tk.Label(window, text="Enter a command (pwd, ls, cd <path>, exit):")
label.pack(pady=5)

# Create a text entry box for the user to input commands
command_entry = tk.Entry(window, width=50)
command_entry.pack(pady=5)

# Create a button to execute the command
execute_button = tk.Button(window, text="Execute", width=20, command=execute_command)
execute_button.pack(pady=5)

# Create a text box to display the output of commands
output_text = tk.Text(window, height=10, width=60)
output_text.pack(pady=5)

# Run the main loop of the GUI
window.mainloop()
