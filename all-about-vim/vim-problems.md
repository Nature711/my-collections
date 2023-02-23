## Vim editor frozen when creating / opening any file

### Context
- after a crash of an edit session
- whenever I use ```vim file.txt``` to open/create a file, the terminal just shows the file name at the bottom of page, and the rest of the page is blank. Unable to press any key afterwards and have to kill the terminal. 

### Solution
1. Locate the ```.vimrc``` file
2. Run ```mv ./vimrc ./vimrc_backup``` to rename the file 
3. Try to use vim again and see if the problem is resolved.
4. Alternatively, try ```sudo apt-get install``` to reinstall vim.

### Takeaway
- Whenever ```vim file.txt``` wasn't successful, try to run ```vim -D file.txt``` to see the debug log during the command execution
