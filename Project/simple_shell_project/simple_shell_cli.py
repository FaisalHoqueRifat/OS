import os

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

# Function to handle the command execution in CLI
def execute_command(user_input):
    # Handle the 'exit' command
    if user_input.lower() == 'exit':
        print("Exiting shell...")
        return True  # Stop the shell loop

    # Handle the 'pwd' command
    elif user_input.lower() == 'pwd':
        print(print_working_directory())

    # Handle the 'ls' command
    elif user_input.lower() == 'ls':
        print(list_files())

    # Handle the 'cd' command
    elif user_input.lower().startswith('cd '):
        path = user_input[3:].strip()  # Extract the path after 'cd'
        print(change_directory(path))

    else:
        print(f"Error: Command '{user_input}' not recognized.")
    return False  # Continue the loop

# Main function to run the CLI shell
def simple_shell():
    while True:
        # Display the shell prompt with the current directory
        current_dir = os.getcwd()
        user_input = input(f"{current_dir} > ")

        # Execute the command and check if we should exit
        if execute_command(user_input):
            break  # Exit the shell if the 'exit' command was typed

# Run the CLI shell
if __name__ == "__main__":
    simple_shell()
