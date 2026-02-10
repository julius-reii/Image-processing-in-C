# Image-processing-in-C
A simple C project for reading, writing, and manipulating BMP images. This project demonstrates basic image processing techniques like grayscale conversion, negative, flipping, rotation, and more, all implemented from scratch without external libraries.

----
### 📋Features
- Read and write uncompressed BMP image files.
- Apply basic image filters:
    - Grayscale
    - Negative
    - Blur
    - Edge Detection
    - Reflect Horizontally

----

### 🛠️ Getting Started

#### Prerequisites
- GCC or any C compiler 
- Make (optional, for using Makefile)

#### Installation / Build
Clone the repository:
```
git clone https://github.com/julius-reii/Image-processing-in-C.git
cd Image-processing-in-C
```
Compile using GCC:
```
gcc -o filter filter.c helpers.c
```
Or use the provided makefile:
```
make
```
----
### 🚀 Usage
Run the program with an input 24-bit BMP file:
```
./filter [flag] input.bmp output.bmp
```

|Flag|Description|
|----|----|
|**b**   |Apply **blur** filter|
|**e**   |Apply **edge detection** filter|
|**g**   |Convert image to **grayscale**|
|**n**   |Apply **negative** filter|
|**r**   |**Reflect** horizontally|

### Example
Convert an image to grayscale:
```
./filter -g input.bmp output.bmp
```
----

### 📂 Project Structure
```
Image-processing-in-C/
│
├── bmp.h           # BMP file structures and constants
├── helpers.c       # Image processing helper functions
├── helpers.h       # Header for helper functions
├── filter.c        # Main program and filter implementations
├── Makefile        # Build instructions
└── README.md       # Project description
```
----
### ⚙️ How It Works
- Reads BMP file headers and pixel data
- Applies filters at the pixel level
- Writes the modified pixels back to a new BMP file
- Handles image padding and memory allocation for BMP scanlines
----
### 📖 References
- [BMP file format specification](https://en.wikipedia.org/wiki/BMP_file_format)
- CS50x Pset 4 (inspiration)
----
### 📝 License
This project is open-source and free to use.

----