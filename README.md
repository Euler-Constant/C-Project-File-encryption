# C-Project-File-encryption

*WHAT EVEN IS THIS C-PROJECT?*
Well, as an answer, the [C-Project] series is one I implemented to help me get much better at C through actual code implementation and Projects, thre first of which is the [File Encryption Tool]. It has the following functionality:

- File I/O: Reads from the source file and writes to a destination file.
- Key Processing: Convert the user’s key into a repeatable sequence.
- Encryption/Decryption Logic: Apply XOR to each byte. (Still figuring out the works here)
- Command-Line Interface: Accept user inputs (file paths, key, mode).

*How to use?*
- Command: ./tool encrypt secret.txt secret.enc mykey
- Process: Opens secret.txt, XORs each byte with mykey (repeating “m-y-k-e-y”), writes to secret.enc.
- Reverse: ./tool decrypt secret.enc secret.dec.txt mykey restores the original.

It was a great exercise for knowledge on writing modular code, (and modular cleaning, this code was a mess at first) along with file handling and bitwise operations in C (Of which I am still learning.  Also added a little progress check to the code, given that this does not run as a GUI operation and as a CLI operation, there had to be some way to measure the progress of it all. I'd be implementing more lines of code into the codebase as the weeks go by, However I feel this is a good starting point. The point is to make it exist.
